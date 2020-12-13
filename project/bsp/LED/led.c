#include "led.h"

void LED_Init(void)
{
	//首先对LED进行初始化，也就是设置GPIO 的模式
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体变量
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);
	//配置连接LED的GPIO为推挽输出模式
	GPIO_InitStructure.GPIO_Pin    =  GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOD, GPIO_Pin_8);	
}
