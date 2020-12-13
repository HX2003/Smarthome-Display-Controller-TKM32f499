/**
 * @file scifi_cont.h
 *
 */

#ifndef SCIFI_CONT_H
#define SCIFI_CONT_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef enum {
    SCIFI_CONT_VERT_LINE_FULL,
    SCIFI_CONT_VERT_LINE_PARTIAL
}scifi_cont_vert_line_t;
/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * scifi_cont_create(lv_obj_t * parent);

lv_obj_t * scifi_cont_get_content(lv_obj_t * win);
/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*SCIFI_CONT_H*/
