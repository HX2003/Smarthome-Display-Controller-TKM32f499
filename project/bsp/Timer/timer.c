#include "timer.h"
#include "touch_CTP.h"
#include "stdio.h"
extern  volatile u16 TIM_lvgl;
extern void lv_tick_inc(uint32_t);

void TIM8_Config(u16 arr,u16 psc)
{
   TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
   NVIC_InitTypeDef NVIC_InitStruct;        //???????
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM8,ENABLE); //TIM8????
   TIM_TimeBaseStructure.TIM_Period = arr; //????        
   TIM_TimeBaseStructure.TIM_Prescaler =psc; //????
   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //??,???
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //????
   TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); //???
        //?????NVIC?? 
   TIM_ITConfig(TIM8,TIM_IT_Update,ENABLE ); //??TIM8??,??????
   NVIC_InitStruct.NVIC_IRQChannel = TIM8_IRQn;  //TIM8??
   NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 7;  //?????0
   NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;  //????0
   NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; //IRQ?????
   NVIC_Init(&NVIC_InitStruct);  //???NVIC???
        
   TIM_Cmd(TIM8, ENABLE);  //??TIM8 
}

u32 timr;
void TIM8_IRQHandler(void)
{
   if (TIM_GetITStatus(TIM8, TIM_IT_Update) != RESET)  //??TIM8????????
	{		
		 	if(xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED)
	    {
		     xPortSysTickHandler();
	    }
		  timr ++;
	}
	TIM_ClearITPendingBit(TIM8, TIM_IT_Update);  //??TIM8??????
}


void TIM3_Config(u16 arr,u16 psc)
{
   TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
   NVIC_InitTypeDef NVIC_InitStruct;        //中断参数结构体
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE); //TIM8时钟使能
   TIM_TimeBaseStructure.TIM_Period = arr; //重装载值        
   TIM_TimeBaseStructure.TIM_Prescaler =psc; //预分频值
   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //不懂，不用管
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数
   TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //初始化
        //中断优先级NVIC设置 
   TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //使能TIM8中断，允许更新中断
   NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;  //TIM6中断
   NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;  //占先优先级0
   NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;  //次优先级0
   NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
   NVIC_Init(&NVIC_InitStruct);  //初始化NVIC寄存器
        
   TIM_Cmd(TIM3, ENABLE);  //使能TIM8 
}
volatile unsigned int touch_time=0;
extern volatile unsigned char	touchInfo_flag;
void TIM3_IRQHandler(void)   //TIM3??
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
		{	
				lv_tick_inc(1);
//			if ((GPIOB->IDR & GPIO_Pin_3) == 0)if(touch_time%50==0)I2C1->IC_DATA_CMD = 0x01;
			if(touch_time%50==1)
			{
//				if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)==0)GUI_TOUCH_Measure();
				if ((GPIOB->IDR & GPIO_Pin_3) == 0)GUI_TOUCH_Measure();
				else touchInfo_flag = 0;//触摸无效
			}
			touch_time++;
		}
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //清除TIMx更新中断标志
}

void TIM10_Config(u16 arr,u16 psc)
{
   TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
   NVIC_InitTypeDef NVIC_InitStruct;        //中断参数结构体
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM10,ENABLE); //TIM8时钟使能
   TIM_TimeBaseStructure.TIM_Period = arr; //重装载值        
   TIM_TimeBaseStructure.TIM_Prescaler =psc; //预分频值
   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //不懂，不用管
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数
   TIM_TimeBaseInit(TIM10, &TIM_TimeBaseStructure); //初始化
        //中断优先级NVIC设置 
   TIM_ITConfig(TIM10,TIM_IT_Update,ENABLE ); //使能TIM8中断，允许更新中断
   NVIC_InitStruct.NVIC_IRQChannel = TIM10_IRQn;  //中断通道为 TIM10_IRQn
   NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;  //占先优先级0
   NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;  //次优先级0
   NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
   NVIC_Init(&NVIC_InitStruct);  //初始化NVIC寄存器
        
   TIM_Cmd(TIM10, ENABLE);  //使能TIM8 
}
void TIM10_IRQHandler(void)
{
   if (TIM_GetITStatus(TIM10, TIM_IT_Update) != RESET)//检查TIM10更新中断发生与否
	{	
		printf("\n TIM10_IRQn \n");
	}
	TIM_ClearITPendingBit(TIM10, TIM_IT_Update); //清除TIM10更新中断标志 
}

//TIM2-CH4
//PD8
void TIM2_GPIO_Config(void)
{        
	GPIO_InitTypeDef  GPIO_InitStructure;        
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM2, ENABLE);         
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);            
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;         
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // ??????       
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       
  GPIO_Init(GPIOD,&GPIO_InitStructure);  
	
	//??????
	GPIO_PinAFConfig(GPIOD, GPIO_Pin_8, GPIO_AF_TIM_1_2); //PD8???PWM??
}

void TIM2_Mode_Config(u16 arr,u16 psc)
{              
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;              
	TIM_OCInitTypeDef  TIM_OCInitStructure;  
  TIM2_GPIO_Config();	   
  TIM2->CCR4 = 0;	
	TIM_TimeBaseStructure.TIM_Period = arr;  //?????0???999,??1000?,???????       
	TIM_TimeBaseStructure.TIM_Prescaler = psc;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //??????    
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ; //????????:???                 
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //???PWM??2                           
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //?????????CCR1_Val?????
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	
	TIM_OC4Init(TIM2, &TIM_OCInitStructure); //????4  
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);    
	
	TIM_ARRPreloadConfig(TIM2, ENABLE);  // ??TIM2?????ARR    	
	TIM_CtrlPWMOutputs(TIM2,ENABLE); 	
	TIM_Cmd(TIM2,ENABLE);  

//	TIM2->DIER |= 1<<4; //??????
//	NVIC_SetPriority(TIM2_CC_IRQn,3);
//	NVIC_EnableIRQ(TIM2_CC_IRQn);
} 

void Times_Pwm_Config(u16 psc,u16 arr,u16 ccr)
{

	TIM2_GPIO_Config();

	TIM2->CNT = 0;
	TIM2->ARR = arr;
	TIM2->PSC = psc;
	TIM2->CCR4 = ccr;
	TIM2->CR1 = 0;
//	TIM2->CR1 |= 1<<7; //???????
  TIM2->CCMR2 = 0;
	TIM2->CCMR2 |= (0x7<<12);
	TIM2->CCMR2 |= (0x1<<11);
	TIM2->CCER = 0;
	TIM2->CCER |= 1<<12; //????4
	TIM2->BDTR |=1<<15; //?????
	TIM2->EGR |= 1<<4; //??????4??
	TIM2->EGR |= 1<<0; //??????
	TIM2->CR1 |= 1<<0; //?????
  TIM2->DIER |= 1<<4; //??????
	TIM2->DIER |= 1<<0; //??????
}






