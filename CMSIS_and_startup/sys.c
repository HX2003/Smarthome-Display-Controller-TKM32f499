#include "sys.h"  
#include "HAL_misc.h"

void  RemapVtorTable(void)
{ 
	int i;
    RCC->AHB1ENR |= 1<<13;//bkp clk,enable sram
	//��ROM���ж�
    for(i = 0;i<90;i++)
    { 
        NVIC_DisableIRQ((IRQn_Type)i); 
    }
	SCB->VTOR = 0;
	SCB->VTOR |= 0x1<<29;
	for(i = 0;i < 512;i+=4)
	*(u32*)(T_SRAM_BASE + i) = *(u32*)(T_SDRAM_BASE+i);

}

void  AI_Responder_enable(void)
{
  AI_Responder->ADDR1= 0x70807040;
//	AI_Responder->ADDR0 = 0x70027080;
  AI_Responder->ADDR1 = 0;
  AI_Responder->CCR &= ~(0x3<<3);
  AI_Responder->CCR |= 1;
  while((AI_Responder->SR & 0x3) != 2);
}
void  AI_Responder_disable(void)
{
    AI_Responder->CCR &= ~1;
}


//�ⲿ�ж����ú���
//ֻ���GPIOA~E
//����:
//GPIOx:0~4,����GPIOA~E
//BITx:��Ҫʹ�ܵ�λ������PB12������ 12;
//TRIM:����ģʽ,1,�½���;2,������;3�������ƽ����
//�ú���һ��ֻ������1��IO��,���IO��,���ε���
//�ú������Զ�������Ӧ�ж�,�Լ�������   	    
void Ex_NVIC_Config(u8 GPIOx,u8 BITx,u8 TRIM) 
{ 
	u8 EXTOFFSET=(BITx%4)*4;  
	RCC->APB2ENR|=1<<14;  						//ʹ��SYSCFGʱ��  
	SYSCFG->EXTICR[BITx/4]&=~(0x000F<<EXTOFFSET);//���ԭ�����ã�����
	SYSCFG->EXTICR[BITx/4]|=GPIOx<<EXTOFFSET;	//EXTI.BITxӳ�䵽GPIOx.BITx 
	//�Զ�����
	EXTI->IMR|=1<<BITx;					//����line BITx�ϵ��ж�(���Ҫ��ֹ�жϣ��򷴲�������)
	if(TRIM&0x01)EXTI->FTSR|=1<<BITx;	//line BITx�¼��½��ش���
	if(TRIM&0x02)EXTI->RTSR|=1<<BITx;	//line BITx�¼������ش���
} 	


//THUMBָ�֧�ֻ������
//�������·���ʵ��ִ�л��ָ��WFI  
void WFI_SET(void)
{
	__ASM volatile("wfi");		  
}
//�ر������ж�(���ǲ�����fault��NMI�ж�)
void INTX_DISABLE(void)
{
	__ASM volatile("cpsid i");
}
//���������ж�
void INTX_ENABLE(void)
{
	__ASM volatile("cpsie i");		  
}
//����ջ����ַ  __set_MSP(0x70002000);

//�������ģʽ	  
void Sys_Standby(void)
{ 
	SCB->SCR|=1<<2;		//ʹ��SLEEPDEEPλ (SYS->CTRL)	   
	RCC->APB1ENR|=1<<28;//ʹ�ܵ�Դʱ�� 
	PWR->CSR|=1<<8;     //����WKUP���ڻ���
	PWR->CR|=1<<2;      //���Wake-up ��־
	PWR->CR|=1<<1;      //PDDS��λ   	
	WFI_SET();			//ִ��WFIָ��,�������ģʽ		 
}	     
//ϵͳ��λ   
void Sys_Soft_Reset(void)
{   
	SCB->AIRCR =0X05FA0000|(u32)0x04;	  
} 		 
   
//		TK499_NVIC_Init(2,2,TK80_IRQn,2);
//����NVIC 
//NVIC_PreemptionPriority:��ռ���ȼ�
//NVIC_SubPriority       :��Ӧ���ȼ�
//NVIC_Channel           :�жϱ��
//NVIC_Group             :�жϷ��� 0~4
//ע�����ȼ����ܳ����趨����ķ�Χ!����������벻���Ĵ���
//�黮��:
//��0:0λ��ռ���ȼ�,4λ��Ӧ���ȼ�
//��1:1λ��ռ���ȼ�,3λ��Ӧ���ȼ�
//��2:2λ��ռ���ȼ�,2λ��Ӧ���ȼ�
//��3:3λ��ռ���ȼ�,1λ��Ӧ���ȼ�
//��4:4λ��ռ���ȼ�,0λ��Ӧ���ȼ�
//NVIC_SubPriority��NVIC_PreemptionPriority��ԭ����,��ֵԽС,Խ����	   
void TK499_NVIC_Init(u8 NVIC_PreemptionPriority,u8 NVIC_SubPriority,u8 NVIC_Channel,u8 NVIC_Group)	 
{
	u32 temp;	  
	NVIC_SetPriorityGrouping(NVIC_Group);//���÷���
	temp=NVIC_PreemptionPriority<<(4-NVIC_Group);	  
	temp|=NVIC_SubPriority&(0x0f>>NVIC_Group);
	temp&=0xf;								//ȡ����λ
	NVIC->ISER[NVIC_Channel/32]|=1<<NVIC_Channel%32;//ʹ���ж�λ(Ҫ����Ļ�,����ICER��ӦλΪ1����)
	NVIC->IP[NVIC_Channel]|=temp<<4;				//������Ӧ���ȼ����������ȼ�   	    	  				   
}

void TK80_IRQHandler(void)
{
    if(TK80->SR & 0x1)
    {
    
    }
    if(TK80->SR & 0x2)
    {
    
    }
    if(TK80->SR & 0x4)
    {
    
    }
    if(TK80->SR & 0x8)
    {
    
    }
    TK80->SR |= 0;
}

//���ú���
//#define T_SRAM_FUN1 0x20000400
//copyAtoB((u32)LCD_PutPixel&0xFFFFFFFE,T_SRAM_FUN1,800);//���غ�����SRAM
//void copyAtoB(u32 srcAdd,u32 dstAdd,u16 len)
//{
//    len = (len + 3)/4;
//    while(len--)
//    {
//        *(u32*)dstAdd = *(u32*)srcAdd;
//        dstAdd += 4 ;
//        srcAdd +=4 ;
//    }
//}














