/**
* @file scifi_clock.c
*
*/

/*********************
 *      INCLUDES
 *********************/
#include "scifi_clock.h"
#include <stdio.h>
#include <string.h>

/*********************
 *      DEFINES
 *********************/
#define LV_OBJX_NAME "scifi_clock"

#define SCIFI_CLOCK_DEF_NEEDLE_COLOR LV_COLOR_RED
#define SCIFI_CLOCK_DEF_ANGLE 270

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_design_res_t scifi_clock_design(lv_obj_t * gauge, const lv_area_t * clip_area, lv_design_mode_t mode);
static lv_res_t scifi_clock_signal(lv_obj_t * gauge, lv_signal_t sign, void * param);
static lv_style_list_t * scifi_clock_get_style(lv_obj_t * gauge, uint8_t part);
static void scifi_clock_draw_needle(lv_obj_t * gauge, const lv_area_t * clip_area);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_design_cb_t ancestor_design;
static lv_signal_cb_t ancestor_signal;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void scifi_clock_allocate_values(lv_obj_t * gauge);
/**
 * Create a gauge objects
 * @param par pointer to an object, it will be the parent of the new gauge
 * @param copy pointer to a gauge object, if not NULL then the new object will be copied from it
 * @return pointer to the created gauge
 */
lv_obj_t * scifi_clock_create(lv_obj_t * par, const lv_obj_t * copy)
{
    LV_LOG_TRACE("gauge create started");

    /*Create the ancestor gauge*/
    lv_obj_t * gauge = lv_arc_create(par, copy);
    LV_ASSERT_MEM(gauge);
    if(gauge == NULL) return NULL;

    /*Allocate the gauge type specific extended data*/
    scifi_clock_ext_t * ext = lv_obj_allocate_ext_attr(gauge, sizeof(scifi_clock_ext_t));
    LV_ASSERT_MEM(ext);
    if(ext == NULL) {
        lv_obj_del(gauge);
        return NULL;
    }

    /*Initialize the allocated 'ext' */
    ext->values        = NULL;
    ext->format_cb     = NULL;

    if(ancestor_signal == NULL) ancestor_signal = lv_obj_get_signal_cb(gauge);
    if(ancestor_design == NULL) ancestor_design = lv_obj_get_design_cb(gauge);

    lv_style_list_init(&ext->style_thick_needle);
    lv_style_list_init(&ext->style_thin_needle);

    /*The signal and design functions are not copied so set them here*/
    lv_obj_set_signal_cb(gauge, scifi_clock_signal);
    lv_obj_set_design_cb(gauge, scifi_clock_design);

    /*Init the new gauge gauge*/
    if(copy == NULL) {
        lv_arc_set_bg_angles(gauge, 0, 360);
        lv_arc_set_angles(gauge, 0, 0);
        scifi_clock_allocate_values(gauge);
        lv_theme_apply(gauge, THEME_SCIFI_GAUGE);
    }
    /*Copy an existing gauge*/
    else {
        scifi_clock_ext_t * copy_ext = lv_obj_get_ext_attr(copy);
        scifi_clock_allocate_values(gauge);

        lv_style_list_copy(&ext->style_thick_needle, &copy_ext->style_thick_needle);
        lv_style_list_copy(&ext->style_thin_needle, &copy_ext->style_thin_needle);

        uint8_t i;
        for(i = 0; i < 2; i++) {
            ext->values[i] = copy_ext->values[i];
        }
        ext->format_cb   = copy_ext->format_cb;

        /*Refresh the style with new signal function*/
        lv_obj_refresh_style(gauge, LV_OBJ_PART_ALL, LV_STYLE_PROP_ALL);
    }

    LV_LOG_INFO("gauge created");

    return gauge;
}

/*=====================
 * Setter functions
 *====================*/
void scifi_clock_allocate_values(lv_obj_t * gauge)
{
    LV_ASSERT_OBJ(gauge, LV_OBJX_NAME);

    scifi_clock_ext_t * ext = lv_obj_get_ext_attr(gauge);

    if(ext->values == NULL) {
        ext->values = lv_mem_realloc(ext->values, 2 * sizeof(ext->values[0]));
        LV_ASSERT_MEM(ext->values);
        if(ext->values == NULL) return;

        uint8_t n;
        for(n = 0; n < 2; n++) {
            ext->values[n] = 0;
        }
     }
}

/**
 * Set the value of a needle
 * @param gauge pointer to a gauge
 * @param needle_id the id of the needle
 * @param value the new value
 */
void scifi_clock_set_value(lv_obj_t * gauge, uint8_t needle_id, int32_t value)
{
    LV_ASSERT_OBJ(gauge, LV_OBJX_NAME);

    scifi_clock_ext_t * ext = lv_obj_get_ext_attr(gauge);

    if(needle_id >= 2) return;
    if(ext->values[needle_id] == value) return;

    int16_t min = 0;
    int16_t max = 360;

    if(value > max)
        value = max;
    else if(value < min)
        value = min;

    int32_t old_value = ext->values[needle_id];
    ext->values[needle_id] = value;

    lv_style_int_t left = lv_obj_get_style_pad_left(gauge, SCIFI_CLOCK_PART_MAIN);
    lv_style_int_t right = lv_obj_get_style_pad_right(gauge, SCIFI_CLOCK_PART_MAIN);
    lv_style_int_t top = lv_obj_get_style_pad_top(gauge, SCIFI_CLOCK_PART_MAIN);

    lv_style_int_t pad;
    lv_coord_t needle_w;

    if(needle_id==0){
        pad = lv_obj_get_style_pad_inner(gauge, SCIFI_CLOCK_PART_THICK_NEEDLE);
        needle_w = lv_obj_get_style_line_width(gauge, SCIFI_CLOCK_PART_THICK_NEEDLE);
    }else{
        pad = lv_obj_get_style_pad_inner(gauge, SCIFI_CLOCK_PART_THIN_NEEDLE);
        needle_w = lv_obj_get_style_line_width(gauge, SCIFI_CLOCK_PART_THIN_NEEDLE);
    }

    lv_coord_t r = (lv_obj_get_width(gauge) - left - right) / 2 - pad;
    lv_coord_t x_ofs  = gauge->coords.x1 + r + left + pad;
    lv_coord_t y_ofs  = gauge->coords.y1 + r + top + pad;
    lv_point_t p_mid;
    lv_point_t p_end;


    p_mid.x = x_ofs;
    p_mid.y = y_ofs;

    p_end.y = (_lv_trigo_sin(old_value - 90) * r) / LV_TRIGO_SIN_MAX + y_ofs;
    p_end.x = (_lv_trigo_sin(old_value) * r) / LV_TRIGO_SIN_MAX + x_ofs;

    lv_area_t a;
    a.x1 = LV_MATH_MIN(p_mid.x, p_end.x) - needle_w;
    a.y1 = LV_MATH_MIN(p_mid.y, p_end.y) - needle_w;
    a.x2 = LV_MATH_MAX(p_mid.x, p_end.x) + needle_w;
    a.y2 = LV_MATH_MAX(p_mid.y, p_end.y) + needle_w;
    lv_obj_invalidate_area(gauge, &a);

    p_end.y = (_lv_trigo_sin(value - 90) * r) / LV_TRIGO_SIN_MAX + y_ofs;
    p_end.x = (_lv_trigo_sin(value) * r) / LV_TRIGO_SIN_MAX + x_ofs;

    a.x1 = LV_MATH_MIN(p_mid.x, p_end.x) - needle_w;
    a.y1 = LV_MATH_MIN(p_mid.y, p_end.y) - needle_w;
    a.x2 = LV_MATH_MAX(p_mid.x, p_end.x) + needle_w;
    a.y2 = LV_MATH_MAX(p_mid.y, p_end.y) + needle_w;
    lv_obj_invalidate_area(gauge, &a);
}


/*=====================
 * Getter functions
 *====================*/

/**
 * Get the value of a needle
 * @param gauge pointer to gauge object
 * @param needle the id of the needle
 * @return the value of the needle [min,max]
 */
int32_t scifi_clock_get_value(const lv_obj_t * gauge, uint8_t needle)
{
    LV_ASSERT_OBJ(gauge, LV_OBJX_NAME);

    scifi_clock_ext_t * ext = lv_obj_get_ext_attr(gauge);

    if(needle >= 2) return 0;

    return ext->values[needle];
}


/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Handle the drawing related tasks of the gauges
 * @param gauge pointer to an object
 * @param clip_area the object will be drawn only in this area
 * @param mode LV_DESIGN_COVER_CHK: only check if the object fully covers the 'mask_p' area
 *                                  (return 'true' if yes)
 *             LV_DESIGN_DRAW: draw the object (always return 'true')
 *             LV_DESIGN_DRAW_POST: drawing after every children are drawn
 * @param return an element of `lv_design_res_t`
 */
static lv_design_res_t scifi_clock_design(lv_obj_t * gauge, const lv_area_t * clip_area, lv_design_mode_t mode)
{
    /*Return false if the object is not covers the mask_p area*/
    if(mode == LV_DESIGN_COVER_CHK) {
        return LV_DESIGN_RES_NOT_COVER;
    }
    /*Draw the object*/
    else if(mode == LV_DESIGN_DRAW_MAIN) {
        ancestor_design(gauge, clip_area, mode);

        scifi_clock_draw_needle(gauge, clip_area);
    }
    /*Post draw when the children are drawn*/
    else if(mode == LV_DESIGN_DRAW_POST) {
        ancestor_design(gauge, clip_area, mode);
    }

    return LV_DESIGN_RES_OK;
}

/**
 * Signal function of the gauge
 * @param gauge pointer to a gauge object
 * @param sign a signal type from lv_signal_t enum
 * @param param pointer to a signal specific variable
 * @return LV_RES_OK: the object is not deleted in the function; LV_RES_INV: the object is deleted
 */
static lv_res_t scifi_clock_signal(lv_obj_t * gauge, lv_signal_t sign, void * param)
{
    lv_res_t res;
    if(sign == LV_SIGNAL_GET_STYLE) {
        lv_get_style_info_t * info = param;
        info->result = scifi_clock_get_style(gauge, info->part);
        if(info->result != NULL) return LV_RES_OK;
        else return ancestor_signal(gauge, sign, param);
    }

    /* Include the ancient signal function */
    res = ancestor_signal(gauge, sign, param);
    if(res != LV_RES_OK) return res;
    if(sign == LV_SIGNAL_GET_TYPE) return lv_obj_handle_get_type_signal(param, LV_OBJX_NAME);

    scifi_clock_ext_t * ext = lv_obj_get_ext_attr(gauge);
    if(sign == LV_SIGNAL_CLEANUP) {
        lv_mem_free(ext->values);
        ext->values = NULL;
        lv_obj_clean_style_list(gauge, SCIFI_CLOCK_PART_THICK_NEEDLE);
        lv_obj_clean_style_list(gauge, SCIFI_CLOCK_PART_THIN_NEEDLE);
    }

    return res;
}
/**
 * Get the style descriptor of a part of the object
 * @param page pointer the object
 * @param part the part from `scifi_clock_part_t`. (SCIFI_CLOCK_PART_...)
 * @return pointer to the style descriptor of the specified part
 */
static lv_style_list_t * scifi_clock_get_style(lv_obj_t * gauge, uint8_t part)
{
    LV_ASSERT_OBJ(gauge, LV_OBJX_NAME);

    scifi_clock_ext_t * ext = lv_obj_get_ext_attr(gauge);
    lv_style_list_t * style_dsc_p;

    switch(part) {
        case SCIFI_CLOCK_PART_MAIN:
            style_dsc_p = &gauge->style_list;
            break;
        case SCIFI_CLOCK_PART_THICK_NEEDLE:
            style_dsc_p = &ext->style_thick_needle;
            break;
        case SCIFI_CLOCK_PART_THIN_NEEDLE:
            style_dsc_p = &ext->style_thin_needle;
        default:
            style_dsc_p = NULL;
    }

    return style_dsc_p;
}

/**
 * Draw the needles of a gauge
 * @param gauge pointer to gauge object
 * @param mask mask of drawing
 */
static void scifi_clock_draw_needle(lv_obj_t * gauge, const lv_area_t * clip_area)
{
    scifi_clock_ext_t * ext     = lv_obj_get_ext_attr(gauge);

    lv_coord_t width = lv_obj_get_width(gauge);
    lv_style_int_t left = lv_obj_get_style_pad_left(gauge, SCIFI_CLOCK_PART_MAIN);
    lv_style_int_t right = lv_obj_get_style_pad_right(gauge, SCIFI_CLOCK_PART_MAIN);
    lv_style_int_t top = lv_obj_get_style_pad_top(gauge, SCIFI_CLOCK_PART_MAIN);

    lv_style_int_t pad_thick_needle = lv_obj_get_style_pad_inner(gauge, SCIFI_CLOCK_PART_THICK_NEEDLE);
    lv_style_int_t pad_thin_needle = lv_obj_get_style_pad_inner(gauge, SCIFI_CLOCK_PART_THIN_NEEDLE);

    lv_coord_t r;
    lv_coord_t x_ofs;
    lv_coord_t y_ofs;
    lv_point_t p_mid;
    lv_point_t p_end;
    int16_t needle_angle;

    r = (width - left - right) / 2 - pad_thick_needle;
    x_ofs = gauge->coords.x1 + r + left + pad_thick_needle;
    y_ofs  = gauge->coords.y1 + r + top + pad_thick_needle;

    lv_draw_line_dsc_t line_dsc;
    lv_draw_line_dsc_init(&line_dsc);
    lv_obj_init_draw_line_dsc(gauge, SCIFI_CLOCK_PART_THICK_NEEDLE, &line_dsc);

    p_mid.x = x_ofs;
    p_mid.y = y_ofs;

    needle_angle = ext->values[0];

    p_end.y = (_lv_trigo_sin(needle_angle - 90) * r) / LV_TRIGO_SIN_MAX + y_ofs;
    p_end.x = (_lv_trigo_sin(needle_angle) * r) / LV_TRIGO_SIN_MAX + x_ofs;

    lv_draw_line(&p_mid, &p_end, clip_area, &line_dsc);

    //////////////////////////////////////////////////////////

    r = (width - left - right) / 2 - pad_thin_needle;
    x_ofs = gauge->coords.x1 + r + left + pad_thin_needle;
    y_ofs  = gauge->coords.y1 + r + top + pad_thin_needle;

    lv_obj_init_draw_line_dsc(gauge, SCIFI_CLOCK_PART_THIN_NEEDLE, &line_dsc);

    p_mid.x = x_ofs;
    p_mid.y = y_ofs;

    needle_angle = ext->values[1];

    p_end.y = (_lv_trigo_sin(needle_angle - 90) * r) / LV_TRIGO_SIN_MAX + y_ofs;
    p_end.x = (_lv_trigo_sin(needle_angle) * r) / LV_TRIGO_SIN_MAX + x_ofs;

    lv_draw_line(&p_mid, &p_end, clip_area, &line_dsc);
}
