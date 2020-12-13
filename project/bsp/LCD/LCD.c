#include "tk499.h" 
#include "LCD.h"
#include "ASCII.h"
#include "GB1616.h"	//16*16������ģ
void TK80_DMA_Init(u32 srcAdd ,u32 len)	 //TK80��DMA���ú�����srcAdd��Դ��ַ��len�����ݳ��ȣ�һ���ܰ���42�ڵ�
{   
    DMA2_Channel2->CNDTR = len;
    DMA2_Channel2->CMAR = srcAdd;
    DMA2_Channel2->CCR |= 1|(0<<12);//3 �����ж�
		TK80->CR |= 1;
} 
/*
��ʼ������IO�ڣ�����TK80�ӿڳ�ʼ��
*/
void LCD_TK80_init(void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;//����GPIO��ʼ���ṹ�����
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC->AHB2ENR |= RCC_AHB2Periph_TK80;    //�� TK80 clock
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOD | RCC_AHBPeriph_GPIOE | RCC_AHBPeriph_DMA2, ENABLE);
	
	// CS=PB11, RS=PB10, WR=PB9, RD=PB8
	GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//PE0~PE23����24λ1600��ɫʱ��ȫ����ΪҺ����������;�������18λ����ֻ��Ҫ��ʼ����18λ;�������16λ����ֻ��ʼ��16λ���Դ�����
  GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_All;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOB, GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11, GPIO_AF_TK80_SDIO); //PB8~11����ΪTK80�Ŀ����ź���
	GPIO_PinAFConfig(GPIOE, GPIO_Pin_All, GPIO_AF_TK80_SDIO); //GPIOE���е�IOȫ������ΪTK80��������

	//lcd_reset:PD6      (LCD_Black_Light On Off  :PD8, now set in timer.c)
	GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_6 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	
	//========== PA15 ����Ϊ ͨ��������� ���ڵ�LED��
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		//TK80�õ�DMA2 ׼����32λ
		DMA2_Channel2->CCR = 0xa90;//  32λ  16λ=0x3590
		DMA2_Channel2->CPAR = (u32)&(TK80->DINR);
		
	/*NVIC_InitStructure.NVIC_IRQChannel = DMA2_Channel2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	DMA_ITConfig(DMA2_Channel2, DMA_IT_TC, ENABLE);		*/		


		TK80->CFGR1 = 0x05050102;
    TK80->CFGR2 = 0x0501;
}
static void LCD_Reset(void)//Һ������λ������ͨ����������Һ�������ø�λ��
{
	LCD_RST(0);
	LCD_delay(100);					   
	LCD_RST(1);		 	 
	LCD_delay(100);
}
void LCD_delay(int time)  //����� ��ʱ����
{
	unsigned short i,j;
	for(i=0;i<time;i++)
		for(j=0;j<1000;j++)	;
}

void WriteComm(unsigned char CMD) //д����
{
	TK80->CMDIR = CMD;while(TK80->SR & 0x10000);
}

void WriteData(u32 dat) //д����
{
	TK80->DINR = dat;while(TK80->SR & 0x10000);
}
/******************************************
��������  Lcdд�����
���ܣ�    ��Lcdָ��λ��д��Ӧ�����������
��ڲ�����Index ҪѰַ�ļĴ�����ַ
          ConfigTemp д������ݻ�����ֵ
******************************************/
void LCD_WR_REG(u16 Index,u16 CongfigTemp)
{
	TK80->CMDIR = Index;
	while(TK80->SR & 0x10000);
	TK80->DINR = CongfigTemp;
	while(TK80->SR & 0x10000);
}
/**********************************************
����������������

��ڲ�����XStart x��������
          Xend   x������յ�
					YStart y��������
          Yend   y������յ�

��������������ǣ���һ�����ο򣬷����������������������
***********************************************/
void BlockWrite(unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend) 
{
	WriteComm(0x2a);
	WriteData(Xstart>>8);
	WriteData(Xstart);
	WriteData(Xend>>8);
	WriteData(Xend);

	WriteComm(0x2b);   
	WriteData(Ystart>>8);
	WriteData(Ystart);
	WriteData(Yend>>8);
	WriteData(Yend);
	
	WriteComm(0x2c);
}
/**********************************************
��������Lcd������亯��

��ڲ�����xStart x�������ʼ��
          ySrart y�������ֹ��
          xLong Ҫѡ�����ε�x���򳤶�
          yLong  Ҫѡ�����ε�y���򳤶�
����ֵ����
***********************************************/
void Lcd_ColorBox(u16 xStart,u16 yStart,u16 xLong,u16 yLong,u32 Color)
{
	BlockWrite(xStart,xStart+xLong-1,yStart,yStart+yLong-1);
	TK80->CFGR3 = xLong*yLong;
	TK80->DINR = Color;
	while(TK80->SR & 0x10000);
}
void LCD_Initial(void) //LCD��ʼ������
{
	LCD_TK80_init();  //��ʼ��Һ�������GPIO
	LCD_Reset();      //��λҺ����
	GPIO_SetBits(GPIOD, GPIO_Pin_8);	//�򿪱���
	
WriteComm(0xFF); // EXTC Command Set enable register 
WriteData(0xFF); 
WriteData(0x98); 
WriteData(0x06); 

WriteComm(0xBA); // SPI Interface Setting 
WriteData(0xE0); 

WriteComm(0xBC); // GIP 1 
WriteData(0x03); 
WriteData(0x0F); 
WriteData(0x63); 
WriteData(0x69); 
WriteData(0x01); 
WriteData(0x01); 
WriteData(0x1B); 
WriteData(0x11); 
WriteData(0x70); 
WriteData(0x73); 
WriteData(0xFF); 
WriteData(0xFF); 
WriteData(0x08); 
WriteData(0x09); 
WriteData(0x05); 
WriteData(0x00);
WriteData(0xEE); 
WriteData(0xE2); 
WriteData(0x01); 
WriteData(0x00);
WriteData(0xC1); 

WriteComm(0xBD); // GIP 2 
WriteData(0x01); 
WriteData(0x23); 
WriteData(0x45); 
WriteData(0x67); 
WriteData(0x01); 
WriteData(0x23); 
WriteData(0x45); 
WriteData(0x67); 

WriteComm(0xBE); // GIP 3 
WriteData(0x00); 
WriteData(0x22); 
WriteData(0x27); 
WriteData(0x6A); 
WriteData(0xBC); 
WriteData(0xD8); 
WriteData(0x92); 
WriteData(0x22); 
WriteData(0x22); 

WriteComm(0xC7); // Vcom 
WriteData(0x1E);
 
WriteComm(0xED); // EN_volt_reg 
WriteData(0x7F); 
WriteData(0x0F); 
WriteData(0x00); 

WriteComm(0xC0); // Power Control 1
WriteData(0xE3); 
WriteData(0x0B); 
WriteData(0x00);
 
WriteComm(0xFC);
WriteData(0x08); 

WriteComm(0xDF); // Engineering Setting 
WriteData(0x00); 
WriteData(0x00); 
WriteData(0x00); 
WriteData(0x00); 
WriteData(0x00); 
WriteData(0x02); 

WriteComm(0xF3); // DVDD Voltage Setting 
WriteData(0x74); 

WriteComm(0xB4); // Display Inversion Control 
WriteData(0x00); 
WriteData(0x00); 
WriteData(0x00); 

WriteComm(0xF7); // 480x854
WriteData(0x81); 

WriteComm(0xB1); // Frame Rate 
WriteData(0x00); 
WriteData(0x10); 
WriteData(0x14); 

WriteComm(0xF1); // Panel Timing Control 
WriteData(0x29); 
WriteData(0x8A); 
WriteData(0x07); 

WriteComm(0xF2); //Panel Timing Control 
WriteData(0x40); 
WriteData(0xD2); 
WriteData(0x50); 
WriteData(0x28); 

WriteComm(0xC1); // Power Control 2 
WriteData(0x17);
WriteData(0X85); 
WriteData(0x85); 
WriteData(0x20); 

WriteComm(0xE0); 
WriteData(0x00); //P1 
WriteData(0x0C); //P2 
WriteData(0x15); //P3 
WriteData(0x0D); //P4 
WriteData(0x0F); //P5 
WriteData(0x0C); //P6 
WriteData(0x07); //P7 
WriteData(0x05); //P8 
WriteData(0x07); //P9 
WriteData(0x0B); //P10 
WriteData(0x10); //P11 
WriteData(0x10); //P12 
WriteData(0x0D); //P13 
WriteData(0x17); //P14 
WriteData(0x0F); //P15 
WriteData(0x00); //P16 

WriteComm(0xE1); 
WriteData(0x00); //P1 
WriteData(0x0D); //P2 
WriteData(0x15); //P3 
WriteData(0x0E); //P4 
WriteData(0x10); //P5 
WriteData(0x0D); //P6 
WriteData(0x08); //P7 
WriteData(0x06); //P8 
WriteData(0x07); //P9 
WriteData(0x0C); //P10 
WriteData(0x11); //P11 
WriteData(0x11); //P12 
WriteData(0x0E); //P13 
WriteData(0x17); //P14 
WriteData(0x0F); //P15 
WriteData(0x00); //P16

WriteComm(0x35); //Tearing Effect ON 
WriteData(0x00); 

WriteComm(0x36); 
WriteData(0x60); 

WriteComm(0x3A); 
WriteData(0x77); 

WriteComm(0x11); //Exit Sleep 
LCD_delay(120); 
WriteComm(0x29); // Display On 
LCD_delay(10);

}
/******************************************
��������Lcdͼ�����
���ܣ���Lcdָ��λ�����ͼ��
��ڲ�����
					(x,y): ͼƬ���Ͻ���ʼ����
					(pic_H,pic_V): ͼƬ�Ŀ��
					 pic  ָ��洢ͼƬ�����ָ��
******************************************/
void LCD_Fill_Pic(u16 x, u16 y,u16 pic_H, u16 pic_V, u32* pic)
{
	//DMA ��ʽ
	BlockWrite(x,x+pic_H-1,y,y+pic_V-1);
	TK80_DMA_Init((u32)pic,pic_H*pic_V);//DMA��ʼ��
	while((DMA2->ISR & 0x20)==0);
	DMA2->IFCR |=1<<5;
	
	//========= ��ѯ��ʽ=========//
//  unsigned long i;
//	unsigned long j;
//	BlockWrite(x,x+pic_H-1,y,y+pic_V-1);
//	j= pic_H*pic_V;
//	for (i = 0; i <j; i++)  {TK80->DINR = pic[i];while(TK80->SR & 0x10000);}
}
//=============== ��x��y �����ϴ�һ����ɫΪColor�ĵ� ===============
void DrawPixel(u16 x, u16 y, int Color)
{
	BlockWrite(x,x,y,y); 
  TK80->DINR = Color;						  
}

/**********8*16���� ASCII�� ��ʾ*************
(x,y): ��ʾ��ĸ����ʼ����
num:   Ҫ��ʾ���ַ�:" "--->"~"
fColor ǰ��ɫ
bColor ����ɫ
flag:  �б���ɫ(1)�ޱ���ɫ(0)
*********************************************/
void SPILCD_ShowChar(unsigned short x,unsigned short y,unsigned char num, unsigned int fColor, unsigned int bColor,unsigned char flag) 
{       
	unsigned char temp;
	unsigned int pos,i,j;  

	num=num-' ';//�õ�ƫ�ƺ��ֵ
	i=num*16; 	
	for(pos=0;pos<16;pos++)
		{
			temp=nAsciiDot[i+pos];	//��ͨ����ASCII����
			for(j=0;j<8;j++)
		   {                 
		        if(temp&0x80)
							DrawPixel(x+j,y,fColor);
						else 
							if(flag) DrawPixel(x+j,y,bColor); //�������ɫ��־flagΪ1
							temp<<=1; 
		    }
			 y++;
		}		 
}  

/**********дһ��16x16�ĺ���*****************
(x,y): ��ʾ���ֵ���ʼ����
c[2]:  Ҫ��ʾ�ĺ���
fColor ǰ��ɫ
bColor ����ɫ
flag:  �б���ɫ(1)�ޱ���ɫ(0)
*********************************************/
void PutGB1616(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int fColor,unsigned int bColor,unsigned char flag)
{
	unsigned int i,j,k;
	unsigned short m;
	for (k=0;k<64;k++) { //64��ʾ�Խ����ֿ��еĸ�����ѭ����ѯ����
	  if ((codeGB_16[k].Index[0]==c[0])&&(codeGB_16[k].Index[1]==c[1]))
			{ 
    	for(i=0;i<32;i++) 
			{
				m=codeGB_16[k].Msk[i];
				for(j=0;j<8;j++) 
				{		
					if((m&0x80)==0x80) {
						DrawPixel(x+j,y,fColor);
						}
					else {
						if(flag) DrawPixel(x+j,y,bColor);
						}
					m=m<<1;
				} 
				if(i%2){y++;x=x-8;}
				else x=x+8;
		  }
		}  
	  }	
	}
/**********��ʾһ����*****************
(x,y): �ַ�������ʼ����
*s:    Ҫ��ʾ���ַ���ָ��
fColor ǰ��ɫ
bColor ����ɫ
flag:  �б���ɫ(1)�ޱ���ɫ(0)
*********************************************/
void LCD_PutString(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor,unsigned char flag) 
	{
		unsigned char l=0;
		while(*s) 
			{
				if( *s < 0x80) 
						{
							SPILCD_ShowChar(x+l*8,y,*s,fColor,bColor,flag);
							s++;l++;
						}
				else
						{
							PutGB1616(x+l*8,y,(unsigned char*)s,fColor,bColor,flag);
							s+=2;l+=2;
						}
			}
	}
