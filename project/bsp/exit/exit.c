#include "exit.h"
//#include "Key.h"
#include "HAL_conf.h"
#include "sys.h"
#include "stdio.h"
#include "LCD.h"
//#include "Tk499.h" ///

char  EXTI_BUFF[YLCD][XLCD];
volatile unsigned short    EXTI_X;  //320240XY,��������ܻᱻ���벻���ظı�,ʹ�Õrֱ�Ӵ�ȡԭʼ�ڴ��ַ
volatile unsigned short    EXTI_Y;
volatile unsigned short ie,je;
volatile char ae,be,*pe;

void EXITLCD_Init(void)
{
		char i,j,a;	
	EXTI_X=80;                   //ģ��320240���Ͻ�XY����
	EXTI_Y=150;
	  ie=je=0;
	  i=j=0;
	a=0x30;
  be=0x3A;
  //pe=&a;
	for(i=0;i<YLCD;i++) 
			{
				for(j=0;j<XLCD;j++)
				{ 
					 EXTI_BUFF[i][j]=a;
				 a++;	
					if(a==0x7E)	
					 a=0x30;			
				
				}
		//a++;
	    }
}

void EXIT_KEY_Init(void)
{

	NVIC_InitTypeDef   NVIC_InitStructure;														//����NVIC����Ľṹ��

   /* Configure PA0 pin as input floating */
	//KEY_Init();
	
  Ex_NVIC_Config(0,0,1); //����һ��I/O��  ��������BITx:�ж���  ������ ��TRIM:����ģʽ,1,������;2,�Ͻ���;3�������ƽ����/0,20,3

  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_Init( & NVIC_InitStructure);


}

void EXITLCD_Show(void)
{
			//LCD_PutString(80,150,EXTI_BUFF,Red,Yellow,1);   //ǰ̨��ʾEXTI_BUFF����//��ά����תһά����
		char  BUFF[XLCD+1]={0x39,0};

		int im,jm,jj=0;
		char aa;
		char *pp;
					   pp= &EXTI_BUFF[0][0];
  

								LCD_PutString(80,120,BUFF,Red,Yellow,1);
    for (im=0; im<YLCD; im++)  //15-1
    {		

        for (jm=0; jm<XLCD; jm++)  //40
        {
					
					  aa=pp[jj];
					  BUFF[jm]=aa;
					  jj++;
		  		  if(jj==(XLCD*YLCD))
		   				jj=0;
					
					
        }
						LCD_PutString(EXTI_X,EXTI_Y,BUFF,Red,Yellow,1);  //80+320,150+240-16 
				    if(EXTI_Y<(((YLCD*16)+150)-16))//    if(EXTI_Y<374)
						{ EXTI_Y=EXTI_Y+16; }
						else 
						{	EXTI_Y=150;  }
		}	

  
}
	


//uint32_t it;
void EXTI0_IRQHandler(void)
{    
//char b=0x41;
     //*p++;
					//for(it=0;it<1000;it++);  //��ʱ
	  LCD_PutString(200,80,"EXIT-in",Red,Yellow,1);



      
	  if(EXTI_GetITStatus(EXTI_Line0)!=RESET)  //�����жϺ󣬲�����0      
					   EXTI_BUFF[je][ie]=be; 
										ie++;
	
					 	if(ie==XLCD)
						{ ie=0; je++;		}
					      	if(je==YLCD)
								    je=0;				 								 			
        be++;
				if(be==0x5B)
					 be=0x3A;
				LCD_PutString(200,80,"EXIT---out",Yellow,Blue,1);

	    EXTI_ClearITPendingBit(EXTI_Line0); //���LINE0�ϵ��жϱ�־λ 
}


