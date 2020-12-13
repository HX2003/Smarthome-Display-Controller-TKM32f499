/**
 * @file scifi_clock.h
 *
 */

#ifndef LV_SCIFI_CLOCK_H
#define LV_SCIFI_CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "lvgl/lvgl.h"
#include "reflow_oven_theme.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef void (*scifi_clock_format_cb_t)(lv_obj_t * gauge, char * buf, int bufsize, int32_t value);

/*Data of gauge*/
typedef struct {
    lv_arc_ext_t arc; /*Ext. of ancestor*/
    /*New data for this type */
    int32_t * values;        /*Array of the set values (for needles) */
    lv_style_list_t style_thick_needle;
    lv_style_list_t style_thin_needle;
    scifi_clock_format_cb_t format_cb;
} scifi_clock_ext_t;

/*Styles*/
enum {
    SCIFI_CLOCK_PART_MAIN = LV_LINEMETER_PART_MAIN,
    SCIFI_CLOCK_PART_THICK_NEEDLE,
    SCIFI_CLOCK_PART_THIN_NEEDLE,
};
typedef uint8_t scifi_clock_style_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a gauge objects
 * @param par pointer to an object, it will be the parent of the new gauge
 * @param copy pointer to a gauge object, if not NULL then the new object will be copied from it
 * @return pointer to the created gauge
 */
lv_obj_t * scifi_clock_create(lv_obj_t * par, const lv_obj_t * copy);

/*=====================
 * Setter functions
 *====================*/

/**
 * Set the value of a needle
 * @param gauge pointer to a gauge
 * @param needle_id the id of the needle
 * @param value the new value
 */
void scifi_clock_set_value(lv_obj_t * gauge, uint8_t needle_id, int32_t value);

/*=====================
 * Getter functions
 *====================*/

/**
 * Get the value of a needle
 * @param gauge pointer to gauge object
 * @param needle the id of the needle
 * @return the value of the needle [min,max]
 */
int32_t scifi_clock_get_value(const lv_obj_t * gauge, uint8_t needle);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_SCIFI_CLOCK_H*/
