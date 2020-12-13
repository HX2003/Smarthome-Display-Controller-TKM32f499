#include "tk499.h" 
#include "LCD.h"
#include "ASCII.h"
#include "GB1616.h"	//16*16汉字字模
void TK80_DMA_Init(u32 srcAdd ,u32 len)	 //TK80的DMA配置函数，srcAdd是源地址，len是数据长度，一次能搬运42亿点
{   
    DMA2_Channel2->CNDTR = len;
    DMA2_Channel2->CMAR = srcAdd;
    DMA2_Channel2->CCR |= 1|(0<<12);//3 启用中断
		TK80->CR |= 1;
} 
/*
初始化各种IO口，包括TK80接口初始化
*/
void LCD_TK80_init(void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC->AHB2ENR |= RCC_AHB2Periph_TK80;    //打开 TK80 clock
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOD | RCC_AHBPeriph_GPIOE | RCC_AHBPeriph_DMA2, ENABLE);
	
	// CS=PB11, RS=PB10, WR=PB9, RD=PB8
	GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//PE0~PE23在用24位1600万色时，全部作为液晶屏数据线;如果是用18位，则只需要初始化低18位;如果是用16位，则只初始化16位，以此类推
  GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_All;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOB, GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11, GPIO_AF_TK80_SDIO); //PB8~11复用为TK80的控制信号线
	GPIO_PinAFConfig(GPIOE, GPIO_Pin_All, GPIO_AF_TK80_SDIO); //GPIOE所有的IO全部复用为TK80的数据线

	//lcd_reset:PD6      (LCD_Black_Light On Off  :PD8, now set in timer.c)
	GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_6 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	
	//========== PA15 设置为 通用推免输出 用于点LED灯
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		//TK80用的DMA2 准备成32位
		DMA2_Channel2->CCR = 0xa90;//  32位  16位=0x3590
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
static void LCD_Reset(void)//液晶屏复位函数（通常触摸屏与液晶屏共用复位）
{
	LCD_RST(0);
	LCD_delay(100);					   
	LCD_RST(1);		 	 
	LCD_delay(100);
}
void LCD_delay(int time)  //简单软件 延时函数
{
	unsigned short i,j;
	for(i=0;i<time;i++)
		for(j=0;j<1000;j++)	;
}

void WriteComm(unsigned char CMD) //写命令
{
	TK80->CMDIR = CMD;while(TK80->SR & 0x10000);
}

void WriteData(u32 dat) //写数据
{
	TK80->DINR = dat;while(TK80->SR & 0x10000);
}
/******************************************
函数名：  Lcd写命令函数
功能：    向Lcd指定位置写入应有命令或数据
入口参数：Index 要寻址的寄存器地址
          ConfigTemp 写入的数据或命令值
******************************************/
void LCD_WR_REG(u16 Index,u16 CongfigTemp)
{
	TK80->CMDIR = Index;
	while(TK80->SR & 0x10000);
	TK80->DINR = CongfigTemp;
	while(TK80->SR & 0x10000);
}
/**********************************************
函数名：开窗函数

入口参数：XStart x方向的起点
          Xend   x方向的终点
					YStart y方向的起点
          Yend   y方向的终点

这个函数的意义是：开一个矩形框，方便接下来往这个框填充数据
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
函数名：Lcd矩形填充函数

入口参数：xStart x方向的起始点
          ySrart y方向的终止点
          xLong 要选定矩形的x方向长度
          yLong  要选定矩形的y方向长度
返回值：无
***********************************************/
void Lcd_ColorBox(u16 xStart,u16 yStart,u16 xLong,u16 yLong,u32 Color)
{
	BlockWrite(xStart,xStart+xLong-1,yStart,yStart+yLong-1);
	TK80->CFGR3 = xLong*yLong;
	TK80->DINR = Color;
	while(TK80->SR & 0x10000);
}
void LCD_Initial(void) //LCD初始化函数
{
	LCD_TK80_init();  //初始化液晶屏相关GPIO
	LCD_Reset();      //复位液晶屏
	GPIO_SetBits(GPIOD, GPIO_Pin_8);	//打开背光
	
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
函数名：Lcd图像填充
功能：向Lcd指定位置填充图像
入口参数：
					(x,y): 图片左上角起始坐标
					(pic_H,pic_V): 图片的宽高
					 pic  指向存储图片数组的指针
******************************************/
void LCD_Fill_Pic(u16 x, u16 y,u16 pic_H, u16 pic_V, u32* pic)
{
	//DMA 方式
	BlockWrite(x,x+pic_H-1,y,y+pic_V-1);
	TK80_DMA_Init((u32)pic,pic_H*pic_V);//DMA初始化
	while((DMA2->ISR & 0x20)==0);
	DMA2->IFCR |=1<<5;
	
	//========= 轮询方式=========//
//  unsigned long i;
//	unsigned long j;
//	BlockWrite(x,x+pic_H-1,y,y+pic_V-1);
//	j= pic_H*pic_V;
//	for (i = 0; i <j; i++)  {TK80->DINR = pic[i];while(TK80->SR & 0x10000);}
}
//=============== 在x，y 坐标上打一个颜色为Color的点 ===============
void DrawPixel(u16 x, u16 y, int Color)
{
	BlockWrite(x,x,y,y); 
  TK80->DINR = Color;						  
}

/**********8*16字体 ASCII码 显示*************
(x,y): 显示字母的起始坐标
num:   要显示的字符:" "--->"~"
fColor 前景色
bColor 背景色
flag:  有背景色(1)无背景色(0)
*********************************************/
void SPILCD_ShowChar(unsigned short x,unsigned short y,unsigned char num, unsigned int fColor, unsigned int bColor,unsigned char flag) 
{       
	unsigned char temp;
	unsigned int pos,i,j;  

	num=num-' ';//得到偏移后的值
	i=num*16; 	
	for(pos=0;pos<16;pos++)
		{
			temp=nAsciiDot[i+pos];	//调通调用ASCII字体
			for(j=0;j<8;j++)
		   {                 
		        if(temp&0x80)
							DrawPixel(x+j,y,fColor);
						else 
							if(flag) DrawPixel(x+j,y,bColor); //如果背景色标志flag为1
							temp<<=1; 
		    }
			 y++;
		}		 
}  

/**********写一个16x16的汉字*****************
(x,y): 显示汉字的起始坐标
c[2]:  要显示的汉字
fColor 前景色
bColor 背景色
flag:  有背景色(1)无背景色(0)
*********************************************/
void PutGB1616(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int fColor,unsigned int bColor,unsigned char flag)
{
	unsigned int i,j,k;
	unsigned short m;
	for (k=0;k<64;k++) { //64标示自建汉字库中的个数，循环查询内码
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
/**********显示一串字*****************
(x,y): 字符串的起始坐标
*s:    要显示的字符串指针
fColor 前景色
bColor 背景色
flag:  有背景色(1)无背景色(0)
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
