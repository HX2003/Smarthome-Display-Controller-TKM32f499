#include "led.h"

void LED_Init(void)
{
	//���ȶ�LED���г�ʼ����Ҳ��������GPIO ��ģʽ
	GPIO_InitTypeDef GPIO_InitStructure;//����GPIO��ʼ���ṹ�����
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);
	//��������LED��GPIOΪ�������ģʽ
	GPIO_InitStructure.GPIO_Pin    =  GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed  = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode   = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOD, GPIO_Pin_8);	
}
