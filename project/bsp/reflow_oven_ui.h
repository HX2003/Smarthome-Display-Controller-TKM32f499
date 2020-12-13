/**
 * @file reflow_oven_ui.h
 *
 */

#ifndef REFLOW_OVEN_UI_H
#define REFLOW_OVEN_UI_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include "stdio.h"
#include "stdarg.h"
#include "stdlib.h"
#include "uart.h"
#include "FreeRTOS.h"
#include "task.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void reflow_oven_ui(void);
void reflow_complete();
void reflow_oven_error_popup(char* msg, uint8_t error_code_val);
/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*REFLOW_OVEN_UI_H*/
