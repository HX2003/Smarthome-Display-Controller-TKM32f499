/**
 * @file reflow_oven_ui.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "reflow_oven_ui.h"
#include "reflow_oven_theme.h"
#include "scifi_clock.h"
#include "scifi_cont.h"
/*********************
 *      DEFINES
 *********************/
//NOTE: A MODIFICATION WAS MADE TO LVGL COLOR PICKER WIDGET
/*Animations*/
#define REFLOW_OVEN_ANIM_Y (LV_VER_RES / 20)
#define REFLOW_OVEN_ANIM_DELAY (40)
#define REFLOW_OVEN_ANIM_TIME  (150)
#define REFLOW_OVEN_ANIM_TIME_BG  (300)

/**********************
 *      TYPEDEFS
 **********************/
typedef enum light_mode{
	LIGHT_MODE_OFF,
	LIGHT_MODE_TEMP,
	LIGHT_MODE_COLOR
} light_mode_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_obj_t * add_loader(void (*end_cb)(lv_anim_t *));
static void loader_anim_cb(void * arc, lv_anim_value_t v);
LV_IMG_DECLARE(light_active_64px);
LV_IMG_DECLARE(light_inactive_64px);
LV_IMG_DECLARE(light_switch_36px);
LV_IMG_DECLARE(switch_36px);
LV_IMG_DECLARE(up_96px);
LV_IMG_DECLARE(down_96px);
LV_IMG_DECLARE(color_wheel_64px);
LV_IMG_DECLARE(color_wheel_temp_64px);
LV_IMG_DECLARE(color_wheel_off_64px);
LV_EVENT_CB_DECLARE(light_event_cb);
LV_EVENT_CB_DECLARE(light_color_event_cb);
LV_EVENT_CB_DECLARE(light_mode_off_event_cb);
LV_EVENT_CB_DECLARE(light_mode_color_event_cb);
LV_EVENT_CB_DECLARE(light_mode_temp_event_cb);
LV_EVENT_CB_DECLARE(light_temp_temperature_event_cb);
LV_EVENT_CB_DECLARE(light_temp_brightness_event_cb);
static void reflow_oven_anim_bg(uint32_t delay, lv_color_t color, int32_t y_new);
static void reflow_oven_anim_out(lv_obj_t * obj, uint32_t delay);
static void reflow_oven_anim_out_all(lv_obj_t * obj, uint32_t delay);
static void reflow_oven_anim_in(lv_obj_t * obj, uint32_t delay);
static void lights_on();
static void lights_off();
/**********************
 *  STATIC VARIABLES
 **********************/
static bool error_state = false;
static light_mode_t light_mode_var = LIGHT_MODE_OFF;
static lv_color_t lights_main_color;
static lv_cpicker_color_mode_t cpicker_color_mode = LV_CPICKER_COLOR_MODE_HUE;
static lv_group_t * g;

static lv_obj_t * lights[6];
static lv_obj_t * cpicker_mode_label;
static lv_obj_t * light_mode_off_tab;
static lv_obj_t * light_mode_temp_tab;
static lv_obj_t * light_mode_color_tab;

static uint16_t light_hue = 0;
static uint8_t light_sat = 0;
static uint8_t light_brightness = 0;
static uint8_t light_temperature = 0;
	
static char * cpicker_mode_txt[] = {
    "HUE",
    "SAT",
    "VAL"
};
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void reflow_oven_ui(void)
{
    lv_theme_t * th = reflow_oven_theme_init(LV_COLOR_BLACK, LV_COLOR_BLACK,
            0, &lv_font_eurostyle_normal_12, &lv_font_eurostyle_14,
            &lv_font_eurostyle_16, &lv_font_eurostyle_normal_18);
    lv_theme_set_act(th);

    lv_obj_t * scr = lv_obj_create(NULL, NULL);
    lv_obj_set_style_local_bg_color(scr, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_scr_load(scr);

    lights_main_color = LV_COLOR_WHITE;

    static lv_style_t style_font_title;
    lv_style_init(&style_font_title);
    lv_style_set_text_font(&style_font_title, LV_STATE_DEFAULT, &lv_font_eurostyle_bold_extended_30);
    lv_style_set_text_color(&style_font_title, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    lv_obj_t * title = lv_label_create(lv_scr_act(), NULL);
    lv_obj_align(title, NULL, LV_ALIGN_IN_TOP_LEFT, 8, 8);
    lv_obj_add_style(title, LV_LABEL_PART_MAIN, &style_font_title);
    lv_label_set_align(title, LV_LABEL_ALIGN_CENTER);
    lv_label_set_text(title, "SECTOR CONTROL");


    /*Create a scifi_clock*/
    lv_obj_t * gauge1 = scifi_clock_create(lv_scr_act(), NULL);
    lv_obj_set_size(gauge1, 24, 24);
    lv_obj_align(gauge1, NULL, LV_ALIGN_IN_TOP_LEFT, 620, 8);

    /*Set the values*/
    scifi_clock_set_value(gauge1, 0, 10);
    scifi_clock_set_value(gauge1, 1, 80);

    static lv_point_t line_points[] = {{0, 0}, {0, 32}};

    /*Create style*/
    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, LV_STATE_DEFAULT, 1);
    lv_style_set_line_color(&style_line, LV_STATE_DEFAULT, lv_color_hex(0x5f697d));
    lv_style_set_line_rounded(&style_line, LV_STATE_DEFAULT, false);

    /*Create a line and apply the new style*/
    lv_obj_t * line1;
    line1 = lv_line_create(lv_scr_act(), NULL);
    lv_line_set_points(line1, line_points, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 650, 4);

    line1 = lv_line_create(lv_scr_act(), NULL);
    lv_line_set_points(line1, line_points, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 765, 4);

    static lv_point_t line_points_2[] = {{0, 0}, {842, 0}};
    static lv_point_t line_points_3[] = {{0, 0}, {45, 45}};
    line1 = lv_line_create(lv_scr_act(), NULL);
    lv_line_set_points(line1, line_points_2, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 4, 40);

    ///////////
    static lv_style_t style_font_0;
    lv_style_init(&style_font_0);
    lv_style_set_text_font(&style_font_0, LV_STATE_DEFAULT, &lv_font_eurostyle_bold_18);
    lv_style_set_text_color(&style_font_0, LV_STATE_DEFAULT, lv_color_hex(0xd9e6ff));

    static lv_style_t style_font_1;
    lv_style_init(&style_font_1);
    lv_style_set_text_font(&style_font_1, LV_STATE_DEFAULT, &lv_font_eurostyle_bold_26);
    lv_style_set_text_color(&style_font_1, LV_STATE_DEFAULT, lv_color_hex(0xd9e6ff));

    lv_obj_t * label1 = lv_label_create(lv_scr_act(), NULL);
    lv_obj_align(label1, NULL, LV_ALIGN_IN_TOP_LEFT, 655, 4);
    lv_label_set_long_mode(label1, LV_LABEL_LONG_SROLL_CIRC);
    lv_obj_set_size(label1, 64, 20);
    lv_obj_add_style(label1, LV_LABEL_PART_MAIN, &style_font_0);
    lv_label_set_align(label1, LV_LABEL_ALIGN_CENTER);
    lv_label_set_text(label1, "12:43");
    ///////////
    static lv_style_t style_font_2;
    lv_style_init(&style_font_2);
    lv_style_set_text_font(&style_font_2, LV_STATE_DEFAULT, &lv_font_eurostyle_normal_18);
    lv_style_set_text_color(&style_font_2, LV_STATE_DEFAULT, lv_color_hex(0x5f697d));

    lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SROLL_CIRC);
    lv_obj_set_size(label2, 64, 20);
    lv_obj_add_style(label2, LV_LABEL_PART_MAIN, &style_font_2);
    lv_label_set_text(label2, "SUNDAY 14/11/2020");
    lv_label_set_align(label2, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(label2, NULL, LV_ALIGN_IN_TOP_LEFT, 655, 24);

    LV_IMG_DECLARE(icon_wifi);

    lv_obj_t * img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, &icon_wifi);
    lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 730, 4);

    static lv_style_t style_font_3;
    lv_style_init(&style_font_3);
    lv_style_set_text_font(&style_font_3, LV_STATE_DEFAULT, &lv_font_eurostyle_bold_18);
    lv_style_set_text_color(&style_font_3, LV_STATE_DEFAULT, lv_color_hex(0x00d620));

    lv_obj_t * label3 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(label3, LV_LABEL_LONG_SROLL_CIRC);
    lv_obj_set_size(label3, 64, 20);
    lv_obj_add_style(label3, LV_LABEL_PART_MAIN, &style_font_3);
    lv_label_set_text(label3, "ONLINE");
    lv_label_set_align(label3, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(label3, NULL, LV_ALIGN_IN_TOP_LEFT, 770, 12);

    static lv_style_t style_tabview_indicator;
    lv_style_init(&style_tabview_indicator);
    lv_style_set_bg_opa(&style_tabview_indicator, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_bg_color(&style_tabview_indicator, LV_STATE_DEFAULT, lv_color_hex(0xf00000));
    lv_style_set_pad_top(&style_tabview_indicator, LV_STATE_DEFAULT, 10);

    static lv_style_t style_tabview_btn;
    lv_style_init(&style_tabview_btn);
    lv_style_set_pad_bottom(&style_tabview_btn, LV_STATE_DEFAULT, 15);

    lv_obj_t *tabview;
    tabview = lv_tabview_create(lv_scr_act(), NULL);
    lv_tabview_set_anim_time(tabview, 0);
    lv_obj_set_height(tabview, lv_obj_get_height(lv_scr_act()) - 40);
    lv_obj_align(tabview, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 40);
    lv_obj_set_style_local_pad_right(tabview, LV_TABVIEW_PART_TAB_BG, LV_STATE_DEFAULT, 550);
    lv_obj_set_style_local_pad_left(tabview, LV_TABVIEW_PART_TAB_BG, LV_STATE_DEFAULT, 5);
    lv_obj_add_style(tabview, LV_TABVIEW_PART_TAB_BTN, &style_font_1);
    lv_obj_add_style(tabview, LV_TABVIEW_PART_INDIC, &style_tabview_indicator);
    lv_obj_add_style(tabview, LV_TABVIEW_PART_TAB_BTN, &style_tabview_btn);
    /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
    lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "LIGHTING");
    lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "CLIMATE");

   /*Create a window*/
    lv_obj_t * win = scifi_cont_create(tab1);

    lv_obj_t * mode_img_btn = lv_img_create(win, NULL);
    lv_img_set_src(mode_img_btn, &color_wheel_off_64px);
    lv_obj_align(mode_img_btn, NULL, LV_ALIGN_IN_TOP_LEFT, 590, 30);
    lv_obj_set_click(mode_img_btn, true);
    lv_obj_set_event_cb(mode_img_btn, light_mode_off_event_cb);

    mode_img_btn = lv_img_create(win, NULL);
    lv_img_set_src(mode_img_btn, &color_wheel_temp_64px);
    lv_obj_align(mode_img_btn, NULL, LV_ALIGN_IN_TOP_LEFT, 670, 30);
    lv_obj_set_click(mode_img_btn, true);
    lv_obj_set_event_cb(mode_img_btn, light_mode_temp_event_cb);

    mode_img_btn = lv_img_create(win, NULL);
    lv_img_set_src(mode_img_btn, &color_wheel_64px);
    lv_obj_align(mode_img_btn, NULL, LV_ALIGN_IN_TOP_LEFT, 750, 30);
    lv_obj_set_click(mode_img_btn, true);
    lv_obj_set_event_cb(mode_img_btn, light_mode_color_event_cb);

    const lv_point_t lights_pts[] = {{50, 90}, {250, 90},  {450, 90},
                                {50, 240}, {250, 240}, {450, 240}};
    for(int i=0; i<6; i++){
        lights[i] = lv_img_create(win, NULL);
        lv_img_set_src(lights[i], &light_inactive_64px);
        lv_obj_set_style_local_image_recolor_opa(lights[i], LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
        lv_obj_set_style_local_image_recolor(lights[i], LV_IMG_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x5f697d));
        lv_obj_align(lights[i], NULL, LV_ALIGN_IN_TOP_LEFT, lights_pts[i].x, lights_pts[i].y);
    }

    static lv_point_t line_points_4[] = {{0, 0}, {0, 320}};
    line1 = lv_line_create(win, NULL);
    lv_line_set_points(line1, line_points_4, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 550, 40);

    static lv_point_t line_points_5[] = {{0, 0}, {0, 20}, {405, 20}, {445, 60}};
    static lv_point_t line_points_6[] = {{0, 60}, {0, 40}, {405, 40}, {445, 0}};


    static lv_point_t line_points_angle_45[] = {{0, 45}, {45, 0}};
    static lv_point_t line_points_angle_75[] = {{0, 0}, {45, 45}};

    line1 = lv_line_create(win, NULL);
    lv_line_set_points(line1, line_points_5, 4);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 37, 20);

    line1 = lv_line_create(win, NULL);
    lv_line_set_points(line1, line_points_angle_75, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 237, 40);

    line1 = lv_line_create(win, NULL);
    lv_line_set_points(line1, line_points_angle_75, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 37, 40);


    lv_obj_t * light_group_1 = lv_label_create(win, NULL);
    lv_obj_add_style(light_group_1, LV_LABEL_PART_MAIN, &style_font_2);
    lv_label_set_text(light_group_1, "Front Group");
    lv_label_set_align(light_group_1, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(light_group_1, NULL, LV_ALIGN_IN_TOP_LEFT, 42, 23);

    line1 = lv_line_create(win, NULL);
    lv_line_set_points(line1, line_points_6, 4);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 37, 315);

    line1 = lv_line_create(win, NULL);
    lv_line_set_points(line1, line_points_angle_45, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 237, 310);

    line1 = lv_line_create(win, NULL);
    lv_line_set_points(line1, line_points_angle_45, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 37, 310);

    lv_obj_t * light_group_2 = lv_label_create(win, NULL);
    lv_obj_add_style(light_group_2, LV_LABEL_PART_MAIN, &style_font_2);
    lv_label_set_text(light_group_2, "Back Group");
    lv_label_set_align(light_group_2, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(light_group_2, NULL, LV_ALIGN_IN_TOP_LEFT, 42, 360);

    static const char * btnm_map[] = {"OFF", "ON", ""};

    lv_obj_t * txt = lv_label_create(win, NULL);
    lv_obj_add_style(txt, LV_LABEL_PART_MAIN, &style_font_2);
    lv_obj_align(txt, NULL, LV_ALIGN_IN_TOP_LEFT, 600, 0);
    lv_label_set_text(txt, "All light groups");


    light_mode_off_tab = lv_obj_create(win, NULL);
    lv_obj_align(light_mode_off_tab, NULL, LV_ALIGN_IN_TOP_LEFT, 600, 150);
    lv_obj_set_size(light_mode_off_tab, 200, 200);
    lv_obj_set_hidden(light_mode_off_tab, false);

    light_mode_temp_tab = lv_obj_create(win, NULL);
    lv_obj_align(light_mode_temp_tab, NULL, LV_ALIGN_IN_TOP_LEFT, 590, 100);
    lv_obj_set_size(light_mode_temp_tab, 220, 200);
    lv_obj_set_hidden(light_mode_temp_tab, true);

    txt = lv_label_create(light_mode_temp_tab, NULL);
    lv_obj_add_style(txt, LV_LABEL_PART_MAIN, &style_font_2);
    lv_obj_align(txt, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 50);
    lv_label_set_text(txt, "Color Temperature");

    lv_obj_t * slider = lv_slider_create(light_mode_temp_tab, NULL);
    lv_obj_set_size(slider, 190, 15);
    lv_obj_align(slider, NULL, LV_ALIGN_IN_TOP_LEFT, 15, 80);
    lv_obj_set_event_cb(slider, light_temp_temperature_event_cb);
    lv_slider_set_range(slider, 0, 255);

    txt = lv_label_create(light_mode_temp_tab, NULL);
    lv_obj_add_style(txt, LV_LABEL_PART_MAIN, &style_font_2);
    lv_obj_align(txt, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 150);
    lv_label_set_text(txt, "Brightness");

    slider = lv_slider_create(light_mode_temp_tab, NULL);
    lv_obj_set_size(slider, 190, 15);
    lv_obj_align(slider, NULL, LV_ALIGN_IN_TOP_LEFT, 15, 180);
    lv_slider_set_range(slider, 0, 255);
    lv_obj_set_event_cb(slider, light_temp_brightness_event_cb);
		
		light_mode_color_tab = lv_obj_create(win, NULL);	
    lv_obj_align(light_mode_color_tab, NULL, LV_ALIGN_IN_TOP_LEFT, 600, 150);	
    lv_obj_set_size(light_mode_color_tab, 200, 200);	
    lv_obj_set_hidden(light_mode_color_tab, true);	
		
    lv_obj_t * cpicker_color = lv_cpicker_create(light_mode_color_tab, NULL);	
    lv_obj_set_size(cpicker_color, 200, 200);	
    lv_obj_align(cpicker_color, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);	
    lv_obj_set_event_cb(cpicker_color, light_color_event_cb);	

    lv_obj_t * img2 = lv_img_create(light_mode_color_tab, NULL);
    lv_img_set_src(img2, &switch_36px);
    lv_obj_align(img2, NULL, LV_ALIGN_IN_TOP_LEFT, 82, 82);
		
    cpicker_mode_label = lv_label_create(light_mode_color_tab, NULL);
    lv_obj_add_style(cpicker_mode_label, LV_LABEL_PART_MAIN, &style_font_2);
    lv_obj_align(cpicker_mode_label, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
    lv_label_set_text(cpicker_mode_label, cpicker_mode_txt[(uint8_t )cpicker_color_mode]);



    /////////////////////////////////
    lv_obj_t * win_climate = scifi_cont_create(tab2);
    lv_obj_t *label = lv_label_create(win_climate, NULL);

    static lv_style_t style_font_temp;
    lv_style_init(&style_font_temp);
    //lv_style_set_bg_opa(&style_font_temp, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_text_font(&style_font_temp, LV_STATE_DEFAULT, &lv_font_eurostyle_bold_100);
    lv_style_set_text_color(&style_font_temp, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style_font_temp);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SROLL_CIRC);
    lv_obj_set_size(label, 200, 120);
    lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_LEFT, 30, 150);

    lv_label_set_text(label, "24°C");

    line1 = lv_line_create(win_climate, NULL);
    lv_line_set_points(line1, line_points_4, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 255, 40);

    line1 = lv_line_create(win_climate, NULL);
    lv_line_set_points(line1, line_points_4, 2);     /*Set the points*/
    lv_obj_add_style(line1, LV_LINE_PART_MAIN, &style_line);     /*Set the points*/
    lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 550, 40);

    lv_obj_t * ac = lv_label_create(win_climate, NULL);
    lv_obj_add_style(ac, LV_LABEL_PART_MAIN, &style_font_2);
    lv_label_set_text(ac, "AC");
    lv_label_set_align(ac, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(ac, NULL, LV_ALIGN_IN_TOP_LEFT, 390, 0);


    lv_obj_t * fan = lv_label_create(win_climate, NULL);
    lv_obj_add_style(fan, LV_LABEL_PART_MAIN, &style_font_2);
    lv_label_set_text(fan, "FAN");
    lv_label_set_align(fan, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(fan, NULL, LV_ALIGN_IN_TOP_LEFT, 690, 0);

    lv_obj_t * btnm1 = lv_btnmatrix_create(win_climate, NULL);
    lv_obj_set_size(btnm1, 200, 30);
    lv_btnmatrix_set_map(btnm1, btnm_map);
    lv_btnmatrix_set_one_check(btnm1, true);
    lv_btnmatrix_set_btn_ctrl(btnm1, 0, LV_BTNMATRIX_CTRL_CHECKABLE|LV_BTNMATRIX_CTRL_CHECK_STATE|LV_BTNMATRIX_CTRL_CLICK_TRIG|LV_BTNMATRIX_CTRL_NO_REPEAT);
    lv_btnmatrix_set_btn_ctrl(btnm1, 1, LV_BTNMATRIX_CTRL_CHECKABLE|LV_BTNMATRIX_CTRL_CLICK_TRIG|LV_BTNMATRIX_CTRL_NO_REPEAT);
    lv_obj_align(btnm1, NULL, LV_ALIGN_IN_TOP_LEFT, 300, 20);
    lv_obj_set_event_cb(btnm1, light_event_cb);

    btnm1 = lv_btnmatrix_create(win_climate, NULL);
    lv_obj_set_size(btnm1, 200, 30);
    lv_btnmatrix_set_map(btnm1, btnm_map);
    lv_btnmatrix_set_one_check(btnm1, true);
    lv_btnmatrix_set_btn_ctrl(btnm1, 0, LV_BTNMATRIX_CTRL_CHECKABLE|LV_BTNMATRIX_CTRL_CHECK_STATE|LV_BTNMATRIX_CTRL_CLICK_TRIG|LV_BTNMATRIX_CTRL_NO_REPEAT);
    lv_btnmatrix_set_btn_ctrl(btnm1, 1, LV_BTNMATRIX_CTRL_CHECKABLE|LV_BTNMATRIX_CTRL_CLICK_TRIG|LV_BTNMATRIX_CTRL_NO_REPEAT);
    lv_obj_align(btnm1, NULL, LV_ALIGN_IN_TOP_LEFT, 600, 20);

    lv_obj_t * ac_up = lv_img_create(win_climate, NULL);
    lv_img_set_src(ac_up, &up_96px);
    lv_obj_align(ac_up, NULL, LV_ALIGN_IN_TOP_LEFT, 407, 290);
    lv_obj_set_style_local_image_recolor_opa(ac_up, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_obj_set_style_local_image_recolor(ac_up, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x5c8cf4));
    lv_obj_set_style_local_image_recolor(ac_up, LV_IMG_PART_MAIN, LV_STATE_PRESSED, lv_color_darken(lv_color_hex(0x5c8cf4), 30));
    lv_obj_set_click(ac_up, true);

    lv_obj_t * ac_down = lv_img_create(win_climate, NULL);
    lv_img_set_src(ac_down, &down_96px);
    lv_obj_set_style_local_image_recolor_opa(ac_down, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_obj_set_style_local_image_recolor(ac_down, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x5c8cf4));
    lv_obj_align(ac_down, NULL, LV_ALIGN_IN_TOP_LEFT, 297, 290);
    lv_obj_set_style_local_image_recolor(ac_down, LV_IMG_PART_MAIN, LV_STATE_PRESSED, lv_color_darken(lv_color_hex(0x5c8cf4), 30));
    lv_obj_set_click(ac_down, true);

    static lv_style_t style_font_temp_setpoint;
    lv_style_init(&style_font_temp_setpoint);
    //lv_style_set_bg_opa(&style_font_temp_setpoint, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_style_set_text_font(&style_font_temp_setpoint, LV_STATE_DEFAULT, &lv_font_eurostyle_bold_50);
    lv_style_set_text_color(&style_font_temp_setpoint, LV_STATE_DEFAULT, LV_COLOR_WHITE);

    label = lv_label_create(win_climate, NULL);
    lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style_font_temp_setpoint);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SROLL_CIRC);
    lv_obj_set_size(label, 200, 120);
    lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_LEFT, 300, 150);

    lv_label_set_text(label, "SET: 23°C");

    label = lv_label_create(win_climate, NULL);
    lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style_font_temp_setpoint);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SROLL_CIRC);
    lv_obj_set_size(label, 200, 120);
    lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_LEFT, 600, 150);

    lv_label_set_text(label, "SET: L3");

    lv_obj_t * fan_up = lv_img_create(win_climate, NULL);
    lv_img_set_src(fan_up, &up_96px);
    lv_obj_align(fan_up, NULL, LV_ALIGN_IN_TOP_LEFT, 707, 290);
    lv_obj_set_style_local_image_recolor_opa(fan_up, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_obj_set_style_local_image_recolor(fan_up, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x5c8cf4));
    lv_obj_set_style_local_image_recolor(fan_up, LV_IMG_PART_MAIN, LV_STATE_PRESSED, lv_color_darken(lv_color_hex(0x5c8cf4), 30));
    lv_obj_set_click(fan_up, true);

    lv_obj_t * fan_down = lv_img_create(win_climate, NULL);
    lv_img_set_src(fan_down, &down_96px);
    lv_obj_set_style_local_image_recolor_opa(fan_down, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
    lv_obj_set_style_local_image_recolor(fan_down, LV_IMG_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x5c8cf4));
    lv_obj_align(fan_down, NULL, LV_ALIGN_IN_TOP_LEFT, 597, 290);
    lv_obj_set_style_local_image_recolor(fan_down, LV_IMG_PART_MAIN, LV_STATE_PRESSED, lv_color_darken(lv_color_hex(0x5c8cf4), 30));
    lv_obj_set_click(fan_down, true);
}

static void light_temp_temperature_event_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        light_temperature = lv_slider_get_value(obj);
        lights_on();
    }
}

static void light_temp_brightness_event_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        light_brightness = lv_slider_get_value(obj);
        lights_on();
    }
}

static void light_event_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        uint16_t btn_id = lv_btnmatrix_get_active_btn(obj);

        if(btn_id == 0){
            lv_obj_set_style_local_bg_color(obj, LV_BTNMATRIX_PART_BTN, LV_STATE_CHECKED, lv_color_hex(0xf00000));
            lv_obj_set_style_local_bg_color(obj, LV_BTNMATRIX_PART_BTN, LV_STATE_PRESSED|LV_STATE_CHECKED, lv_color_hex(0xf00000));
        }else{
            lv_obj_set_style_local_bg_color(obj, LV_BTNMATRIX_PART_BTN, LV_STATE_CHECKED, lv_color_hex(0x00d620));
            lv_obj_set_style_local_bg_color(obj, LV_BTNMATRIX_PART_BTN, LV_STATE_PRESSED|LV_STATE_CHECKED, lv_color_hex(0x00d620));
        }
    }
}

static void lights_on(){
    lv_color_t light_color;

    if(light_mode_var==LIGHT_MODE_TEMP){
        lv_color_t mixed_color = lv_color_mix(lv_color_hex(0xFF7A08), lv_color_hex(0xFFFFFF), light_temperature);
        light_color = lv_color_darken(mixed_color, (255 - light_brightness)*0.8);
			  printf("{\"ip\": \"192.168.1.17\", \"id\": 1, \"g\": 1, \"req\": { \"state\": \"On\", \"kelvin\": %i, \"brightness\": %i, \"bulb_mode\" : \"white\" }}\n", (int)(light_temperature/2.55), light_brightness);
    }else if(light_mode_var==LIGHT_MODE_COLOR){
        light_color = lights_main_color;
				printf("{\"ip\": \"192.168.1.17\", \"id\": 1, \"g\": 1, \"req\": { \"state\": \"On\", \"hue\": %i, \"saturation\": %i, \"brightness\": %i, \"bulb_mode\" : \"color\" }}\n", light_hue, light_sat, light_brightness);	
    }

    for(int i=0; i<6; i++){
        lv_img_set_src(lights[i], &light_active_64px);
        lv_obj_set_style_local_image_recolor(lights[i], LV_IMG_PART_MAIN, LV_STATE_DEFAULT, light_color);
    };
}

static void lights_off(){
    for(int i=0; i<6; i++){
        lv_img_set_src(lights[i], &light_inactive_64px);
        lv_obj_set_style_local_image_recolor(lights[i], LV_IMG_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x5f697d));
    }
}


static void light_color_event_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        lights_main_color = lv_cpicker_get_color(obj);
				light_hue = lv_cpicker_get_hue(obj);
        light_sat = lv_cpicker_get_saturation(obj);
        light_brightness = lv_cpicker_get_value(obj);
        if(light_mode_var!=LIGHT_MODE_OFF){
						lights_on();
        }
        cpicker_color_mode = lv_cpicker_get_color_mode(obj);
        lv_label_set_text(cpicker_mode_label, cpicker_mode_txt[(uint8_t )cpicker_color_mode]);
    }
}

static void light_mode_off_event_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        if(light_mode_var!=LIGHT_MODE_OFF){
            light_mode_var = LIGHT_MODE_OFF;
            lv_obj_set_hidden(light_mode_off_tab, false);
            lv_obj_set_hidden(light_mode_temp_tab, true);
            lv_obj_set_hidden(light_mode_color_tab, true);
            lights_off();
        }
				printf("{ \"ip\": \"192.168.1.17\", \"id\": 1, \"g\": 1, \"req\": {\"brightness\": 0, \"bulb_mode\" : \"white\", \"state\": \"Off\"}}\n");
    }
}

static void light_mode_temp_event_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        if(light_mode_var!=LIGHT_MODE_TEMP){
            light_mode_var = LIGHT_MODE_TEMP;
            lv_obj_set_hidden(light_mode_off_tab, true);
            lv_obj_set_hidden(light_mode_temp_tab, false);
            lv_obj_set_hidden(light_mode_color_tab, true);
            //lights_on();
        }
				lights_on();
    }
}

static void light_mode_color_event_cb(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        if(light_mode_var!=LIGHT_MODE_COLOR){
            light_mode_var = LIGHT_MODE_COLOR;
            lv_obj_set_hidden(light_mode_off_tab, true);
            lv_obj_set_hidden(light_mode_temp_tab, true);
            lv_obj_set_hidden(light_mode_color_tab, false);
            //lights_on();
        }
				lights_on();
    }
}
static lv_obj_t * add_loader(void (*end_cb)(lv_anim_t *))
{
    lv_obj_t * arc = lv_arc_create(lv_scr_act(), NULL);
    lv_arc_set_bg_angles(arc, 0, 0);
    lv_arc_set_start_angle(arc, 270);
    lv_obj_set_size(arc, 180, 180);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, loader_anim_cb);
    lv_anim_set_ready_cb(&a, end_cb);
    lv_anim_set_values(&a, 0, 110);
    lv_anim_set_time(&a, 2000);
    lv_anim_set_var(&a, arc);
    lv_anim_start(&a);

    return arc;
}

static void loader_anim_cb(void * arc, lv_anim_value_t v)
{
    if(v > 100) v = 100;
    lv_arc_set_end_angle(arc, v * 360 / 100 + 270);

    static char buf[32];
    lv_snprintf(buf, sizeof(buf), "%d %%", v);
    lv_obj_set_style_local_value_str(arc, LV_ARC_PART_BG, LV_STATE_DEFAULT, buf);
}

LV_EVENT_CB_DECLARE(icon_generic_event_cb)
{
    if (e == LV_EVENT_FOCUSED) {
        lv_obj_t * cont = lv_obj_get_parent(obj);
        lv_obj_t * label = lv_obj_get_child(cont, NULL);
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_time(&a, 100);
        lv_anim_set_var(&a, label);
        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
        lv_coord_t initial_y = (lv_coord_t)lv_obj_get_user_data(label);
        lv_anim_set_values(&a, initial_y, initial_y-5);
        lv_anim_start(&a);
        lv_anim_t a1;
        lv_anim_init(&a1);
        lv_anim_set_time(&a1, 100);
        lv_anim_set_var(&a1, label);
        lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t)lv_img_set_zoom);
        lv_anim_set_values(&a1, lv_img_get_zoom(label), 225);
        lv_anim_start(&a1);
    }
    else if(e == LV_EVENT_DEFOCUSED) {
        lv_obj_t * cont = lv_obj_get_parent(obj);
        lv_obj_t * label = lv_obj_get_child(cont, NULL);
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_delay(&a, 50);
        lv_anim_set_time(&a, 100);
        lv_anim_set_var(&a, label);
        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
        lv_coord_t initial_y = (lv_coord_t)lv_obj_get_user_data(label);
        lv_anim_set_values(&a, initial_y-5, initial_y);
        lv_anim_start(&a);
        lv_anim_t a1;
        lv_anim_init(&a1);
        lv_anim_set_time(&a1, 100);
        lv_anim_set_var(&a1, label);
        lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t)lv_img_set_zoom);
        lv_anim_set_values(&a1, lv_img_get_zoom(label), 256);
        lv_anim_start(&a1);
    }
}

static void reflow_oven_anim_out(lv_obj_t * obj, uint32_t delay) {
    lv_obj_t * child = lv_obj_get_child_back(obj, NULL);
    while(child) {
        if(child != lv_scr_act()) {
            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, child);
            lv_anim_set_time(&a, REFLOW_OVEN_ANIM_TIME);
            lv_anim_set_delay(&a, delay);
            lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb);
            lv_anim_start(&a);

            lv_obj_fade_out(child, REFLOW_OVEN_ANIM_TIME - 70, delay + 70);
        }
        child = lv_obj_get_child_back(obj, child);
    }

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_time(&a, REFLOW_OVEN_ANIM_TIME);
    lv_anim_set_delay(&a, delay);
    lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb);
    lv_anim_start(&a);
    lv_obj_fade_out(obj, REFLOW_OVEN_ANIM_TIME - 70, delay + 70);
}

static void reflow_oven_anim_out_all(lv_obj_t * obj, uint32_t delay) {
    lv_obj_t * child = lv_obj_get_child_back(obj, NULL);
    while(child) {
        if(child != lv_scr_act()) {
            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, child);
            lv_anim_set_time(&a, REFLOW_OVEN_ANIM_TIME);
            lv_anim_set_delay(&a, delay);

            lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb);
            lv_anim_start(&a);

            lv_obj_fade_out(child, REFLOW_OVEN_ANIM_TIME - 70, delay + 70);
        }
        child = lv_obj_get_child_back(obj, child);
    }
}

static void reflow_oven_anim_in(lv_obj_t * obj, uint32_t delay)
{
    if (obj != lv_scr_act()) {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, obj);
        lv_anim_set_time(&a, REFLOW_OVEN_ANIM_TIME);
        lv_anim_set_delay(&a, delay);
        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);
        lv_anim_set_values(&a, lv_obj_get_y(obj) - REFLOW_OVEN_ANIM_Y,
                lv_obj_get_y(obj));
        lv_anim_start(&a);

        lv_obj_fade_in(obj, REFLOW_OVEN_ANIM_TIME - 50, delay);
    }
}
