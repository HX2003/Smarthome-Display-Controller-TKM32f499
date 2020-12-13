
//#ifdef  use_capacitive_touch_panel
#include "touch_CTP.h"
#include "HAL_rcc.h"
#include "LCD.h"
#if USE_CTP	

u8 buf[10];
volatile int GUI_Value_X,GUI_Value_Y;
volatile unsigned char	touchInfo_flag; 
int GUI_TOUCH_Measure(void)
{
	I2CTXByte(I2C1,CMD_WRITE,0x01);
	
	for(int i=0;i<6;i++) 
		{
			buf[i]=I2CRXByte(I2C1);//库函数法读取IIC数据
		}
		
		GUI_Value_Y = (int16_t)(buf[4] & 0x0F)<<8 | (int16_t)buf[5];
		GUI_Value_X = (int16_t)(buf[2] & 0x0F)<<8 | (int16_t)buf[3];
		touchInfo_flag = 1;//触摸有效
//	}
//	else
//	{
//		touchInfo_flag = 0;
//		GUI_Value_X =8000;
//		GUI_Value_Y =8000;		
//	}
}

/****************************************************************************************
																	电容屏 FTXXXX全系列通用芯片驱动

***************************************************************************************/
/*
void Touch_Test(void)
{
	char i,j;
	u8 buf[32];
	u16 touchX=0,touchY=0;
//	I2C1->IC_DATA_CMD =FT6206_ADDR | 0x200;//写入从机地址，开启起始信号
	I2CTXByte(I2C1,CMD_WRITE,0x01);
	for(i=0;i<6;i++) 
		{
			*(buf+i)=I2CRXByte(I2C1);//库函数法读取IIC数据
		}
		j = buf[1]&0x0f;
		if(j>5) return ;
		for(i=6;i<6*j;i++) 
		{
			*(buf+i)=I2CRXByte(I2C1);//库函数法读取IIC数据
		}
		for(i=0;i<j;i++)
	{
		
		touchY = (int16_t)(buf[4+6*i] & 0x0F)<<8 | (int16_t)buf[5+6*i];//x坐标
		touchX = (int16_t)(buf[2+6*i] & 0x0F)<<8 | (int16_t)buf[3+6*i];//y坐标
		
		if((touchX>0)&&(touchX<2048))
		{
		if(i>2)Lcd_ColorBox(touchX,touchY,2,2,Yellow >>(8*(i-3)));
		 else Lcd_ColorBox(touchX,touchY,2,2,Red>>(8*i));

//		printf("touchX= %d \r\n",touchX);
//		printf("touchY= %d \r\n",touchY);
		}
	}

}*/
#endif