
#ifndef  __TOUCH_CTP_H__
#define  __TOUCH_CTP_H__
#include "tk499.h"
#include "HAL_conf.h"
#include "TK499_I2C.h"
#include "stdio.h"

#define  USE_CTP 1
#define FT6206_ADDR		0x70		//��ַΪ0x38Ҫ��һλ 
//#define FT6206_ADDR		0x94		//��ַΪ 0x4a<<1, Ҫ��һλ 
extern volatile unsigned char touchInfo_flag; 
int GUI_TOUCH_Measure(void); 


void Touch_Test(void);

#endif                                     

