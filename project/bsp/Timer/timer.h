#ifndef _TIME_H_
#define _TIME_H_
#include "main.h"
#include "HAL_conf.h"
#include "UART.h"
void TIM8_Config(u16 arr,u16 psc);
void TIM3_Config(u16 arr,u16 psc);
void TIM10_Config(u16 arr,u16 psc);
void Times_Pwm_Config(u16 psc,u16 arr,u16 ccr);
extern void touchpad_Scan(void);  //定时读取触摸
extern volatile u16	touchTime_flag;	//中断计时
#endif
