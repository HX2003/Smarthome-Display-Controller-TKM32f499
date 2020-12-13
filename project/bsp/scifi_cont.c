/**
 * @file scifi_cont.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "scifi_cont.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void draw_vertical_lines(lv_obj_t * parent, lv_coord_t x, scifi_cont_vert_line_t type);

lv_obj_t * scifi_cont_create(lv_obj_t * parent)
{
    lv_obj_t * win = lv_obj_create(parent, NULL);
    lv_coord_t w = lv_obj_get_width(parent);
    lv_coord_t h = lv_obj_get_height(parent);

    lv_obj_set_size(win, w, h);

    draw_vertical_lines(win, 5, SCIFI_CONT_VERT_LINE_FULL);
    draw_vertical_lines(win, w*(4)/100, SCIFI_CONT_VERT_LINE_PARTIAL);
    draw_vertical_lines(win, w - 5 - 3, SCIFI_CONT_VERT_LINE_FULL);
    draw_vertical_lines(win, w - 3 - w*(4)/100, SCIFI_CONT_VERT_LINE_PARTIAL);
    /*lv_obj_set_flex_cont(win, LV_FLEX_DIR_COLUMN, LV_FLEX_START);
    lv_obj_reset_style_list(win, LV_OBJ_PART_MAIN);

    lv_obj_t * header = lv_obj_create(win, NULL);
    lv_obj_set_flex_item(header, LV_FLEX_START);
    lv_obj_set_size(header, LV_COORD_PCT(100), header_height);
    lv_obj_set_flex_cont(header, LV_FLEX_DIR_ROW, LV_FLEX_CENTER);
    lv_obj_set_flex_gap(header, LV_DPX(2));
    lv_obj_add_style(header, LV_OBJ_PART_MAIN, &style_plain);

    lv_obj_t * cont = lv_obj_create(win, NULL);
    lv_obj_set_flex_item(cont, LV_FLEX_START);
    lv_obj_set_size(cont, LV_COORD_PCT(100), LV_FLEX_GROW(1));
    lv_obj_add_style(cont, LV_OBJ_PART_MAIN, &style_plain);*/

    return win;
}

void draw_vertical_lines(lv_obj_t * parent, lv_coord_t x, scifi_cont_vert_line_t type){
    lv_coord_t h = lv_obj_get_height(parent);

    static lv_style_t style_line_mid;
    lv_style_init(&style_line_mid);
    lv_style_set_line_width(&style_line_mid, LV_STATE_DEFAULT, 3);
    lv_style_set_line_color(&style_line_mid, LV_STATE_DEFAULT, lv_color_hex(0x5f697d));
    lv_style_set_line_rounded(&style_line_mid, LV_STATE_DEFAULT, true);

    static lv_style_t style_line_thick;
    lv_style_init(&style_line_thick);
    lv_style_set_line_width(&style_line_thick, LV_STATE_DEFAULT, 5);
    lv_style_set_line_color(&style_line_thick, LV_STATE_DEFAULT, lv_color_hex(0x5f697d));
    lv_style_set_line_rounded(&style_line_thick, LV_STATE_DEFAULT, true);

    /*Create a line and apply the new style*/
    lv_obj_t * line;

    static lv_point_t line_points_short[] = {{0,0},{0,0}};
    line_points_short[1].y = h*(2)/100;
    static lv_point_t line_points_mid[] = {{0,0},{0,0}};
    line_points_mid[1].y = h*(3)/100;
    static lv_point_t line_points_long[] = {{0,0},{0,0}};
    line_points_long[1].y = h*(100 - 18)/100;

    if(type == SCIFI_CONT_VERT_LINE_FULL){
        line = lv_line_create(parent, NULL);
        lv_line_set_points(line, line_points_mid, 2);     /*Set the points*/
        lv_obj_add_style(line, LV_LINE_PART_MAIN, &style_line_mid);     /*Set the points*/
        lv_obj_set_pos(line, x, 5+2+h*(3)/100);

        line = lv_line_create(parent, NULL);
        lv_line_set_points(line, line_points_long, 2);     /*Set the points*/
        lv_obj_add_style(line, LV_LINE_PART_MAIN, &style_line_mid);     /*Set the points*/
        lv_obj_set_pos(line, x, h*(9)/100);

        line = lv_line_create(parent, NULL);
        lv_line_set_points(line, line_points_mid, 2);     /*Set the points*/
        lv_obj_add_style(line, LV_LINE_PART_MAIN, &style_line_mid);     /*Set the points*/
        lv_obj_set_pos(line, x, 4 + h*(100 - 9)/100);
    }

    line = lv_line_create(parent, NULL);
    lv_line_set_points(line, line_points_short, 2);     /*Set the points*/
    lv_obj_add_style(line, LV_LINE_PART_MAIN, &style_line_thick);     /*Set the points*/
    lv_obj_set_pos(line, x, 5);

    line = lv_line_create(parent, NULL);
    lv_line_set_points(line, line_points_short, 2);     /*Set the points*/
    lv_obj_add_style(line, LV_LINE_PART_MAIN, &style_line_thick);     /*Set the points*/
    lv_obj_set_pos(line, x, 5 + 5 + h*(100 - 9 + 3)/100);
}

lv_obj_t * scifi_cont_get_content(lv_obj_t * win)
{
    return lv_obj_get_child(win, NULL);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
