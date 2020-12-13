#ifndef __EXIT_H
#define __EXIT_H

#include "HAL_conf.h"
#define XLCD 40   //40*8=320
#define YLCD  15 //15*16=240
void EXITLCD_Init(void);
void EXIT_KEY_Init(void);
void EXITLCD_Show(void);
#endif
