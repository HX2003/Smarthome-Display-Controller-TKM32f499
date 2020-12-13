#define USE_RTP 1

// 物理显示尺寸定义
//#define XSIZE_PHYS 800
//#define YSIZE_PHYS 480

// Touch screen
//触摸屏校验值
//==============RTP 电阻触摸==============//
//#if USE_RTP 
//#define TOUCH_X_MIN 3900
//#define TOUCH_X_MAX 460
//#define TOUCH_Y_MIN 500
//#define TOUCH_Y_MAX 3750
//#endif

#if USE_RTP 
#define TOUCH_X_MIN 3900
#define TOUCH_X_MAX 250
#define TOUCH_Y_MIN 500
#define TOUCH_Y_MAX 3750
#endif
#if USE_RTP
void GUI_TOUCH_X_ActivateX(void) {}
void GUI_TOUCH_X_ActivateY(void) {}
int ADC_Value_X,ADC_Value_Y;
static u16 Temp_Value_X[10],Temp_Value_Y[10],flag_ADC=0,LED_flag=0;
static u32	temp_led=0;
void TOUCHPAD_IRQHandler()
{
	
	if(TOUCHPAD->TPCR & (0x1<<16))
	{
//		TOUCHPAD->TPCR &= (~0x2);// 禁用A/D触摸屏中断
//		TOUCHPAD->TPCR |= 0x1<<16;// 比较标志位,写1清零
		


//			ADC_Value_X = TOUCHPAD->TPYDR;
//			ADC_Value_Y = TOUCHPAD->TPXDR;
		Temp_Value_X[flag_ADC] = TOUCHPAD->TPYDR;
		Temp_Value_Y[flag_ADC] = TOUCHPAD->TPXDR;
		if(flag_ADC==9) 
		{
			u16 k,cou,temp;
			flag_ADC = 0;
			//将数据升序排列
			for(k=0;k<8;k++)
			{	  
				for(cou=0;cou<8-k;cou++)
				{
					if(Temp_Value_Y[cou]>Temp_Value_Y[cou+1])
					{
						temp=Temp_Value_Y[cou+1];
						Temp_Value_Y[cou+1]=Temp_Value_Y[cou];
						Temp_Value_Y[cou]=temp;
					}  
				}
			}
//			if((Temp_Value_Y[8]>TOUCH_Y_MAX)||(Temp_Value_Y[0]<TOUCH_Y_MIN)) {ADC_Value_Y=8000;goto restart_ADC;}
			if(Temp_Value_Y[7]-Temp_Value_Y[2]>200) goto restart_ADC; 
			for(k=0;k<8;k++)
			{	  
				for(cou=0;cou<8-k;cou++)
				{
					if(Temp_Value_X[cou]>Temp_Value_X[cou+1])
					{
						temp=Temp_Value_X[cou+1];
						Temp_Value_X[cou+1]=Temp_Value_X[cou];
						Temp_Value_X[cou]=temp;
					}  
				}
			}
//			if((Temp_Value_X[8]>TOUCH_X_MIN)||(Temp_Value_X[0]<TOUCH_X_MAX)) {ADC_Value_X=8000;goto restart_ADC;}
			if(Temp_Value_X[7]-Temp_Value_X[2]>200) goto restart_ADC; 
			
			ADC_Value_X = (Temp_Value_X[3] + Temp_Value_X[4] + Temp_Value_X[5] +Temp_Value_X[6])>>2;
			ADC_Value_Y = (Temp_Value_Y[3] + Temp_Value_Y[4] + Temp_Value_Y[5] +Temp_Value_Y[6])>>2;

			
//			if(ADC_Value_X>2100) ADC_Value_X = ADC_Value_X-200*(ADC_Value_X-2100)/((3700-500)/2);
//			if(ADC_Value_X<2100) ADC_Value_X = ADC_Value_X-(50*(2100-ADC_Value_X)/((3700-500)/2));
//			
//			if(ADC_Value_Y>2100) ADC_Value_Y = ADC_Value_Y+100*(ADC_Value_Y-2100)/((3900-280)/2);
//			if(ADC_Value_Y<2100)  ADC_Value_Y = ADC_Value_Y-(100*(2100-ADC_Value_Y)/((3900-280)/2));

			
			restart_ADC:
			flag_ADC = 0;
//			if(temp_led%100==0)
//			{
//				if(LED_flag){GPIOD->BSRR = 0x100;LED_flag=0;}
//				else {GPIOD->BRR = 0x100;LED_flag=1;}
//			}
//		temp_led++;
			 
		}
		else flag_ADC++;
		
		
		TOUCHPAD->TPCR |= 0x2;//重新使能A/D触摸屏中断
//		TOUCHPAD->ADCR |= 0x1<<8;  //A/D转换开始 (ADC start)
		
//		if(ADC_Value_X&(0x1<<21))
//		{
//			flag_x = 1;
//		}
//		ADC_Value_Y = TOUCHPAD->TPYDR;
//		if(ADC_Value_Y&(0x1<<21))
//		{
//			flag_y = 1;
//		}
		
	}

}
int  GUI_TOUCH_X_MeasureX(void)
{
	return ADC_Value_X;
}
int  GUI_TOUCH_X_MeasureY(void)
{
	return ADC_Value_Y;
}
#endif