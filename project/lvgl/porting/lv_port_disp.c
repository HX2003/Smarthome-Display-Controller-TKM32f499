/**
 * @file lv_port_disp_templ.c
 *
 */

 /*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1  ///

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp.h"
#include "LCD.h"                    ///   
#include "tk499.h" 
#include <stdint.h> 
#include "UART.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);

static void disp_flush(lv_disp_drv_t * disp_drv_f, const lv_area_t * area, lv_color_t * color_p);
#if LV_USE_GPU
static void gpu_blend(lv_disp_drv_t * disp_drv, lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa);
static void gpu_fill(lv_disp_drv_t * disp_drv, lv_color_t * dest_buf, lv_coord_t dest_width,
        const lv_area_t * fill_area, lv_color_t color);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*-----------------------------
     * Create a buffer for drawing
     *----------------------------*/

    /* LittlevGL requires a buffer where it draws the objects. The buffer's has to be greater than 1 display row
     *
     * There are three buffering configurations:
     * 1. Create ONE buffer with some rows: 
     *      LittlevGL will draw the display's content here and writes it to your display
     * 
     * 2. Create TWO buffer with some rows: 
     *      LittlevGL will draw the display's content to a buffer and writes it your display.
     *      You should use DMA to write the buffer's content to the display.
     *      It will enable LittlevGL to draw the next part of the screen to the other buffer while
     *      the data is being sent form the first buffer. It makes rendering and flushing parallel.
     * 
     * 3. Create TWO screen-sized buffer: 
     *      Similar to 2) but the buffer have to be screen sized. When LittlevGL is ready it will give the
     *      whole frame to display. This way you only need to change the frame buffer's address instead of
     *      copying the pixels.
     * */

    /* Example for 1) */
//       static lv_disp_buf_t disp_buf_1;
//       static lv_color_t buf1_1[LV_HOR_RES_MAX * LV_VER_RES_MAX];                      /*A buffer for 10 rows*/
//       lv_disp_buf_init(&disp_buf_1, buf1_1, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX);   /*Initialize the display buffer*/

//    /* Example for 2) */
//       static lv_disp_buf_t disp_buf_2;
//       static lv_color_t buf2_1[LV_HOR_RES_MAX * LV_VER_RES_MAX];                        /*A buffer for 10 rows*/
//       static lv_color_t buf2_2[LV_HOR_RES_MAX * LV_VER_RES_MAX];                        /*An other buffer for 10 rows*/
//       lv_disp_buf_init(&disp_buf_2, buf2_1, buf2_2, LV_HOR_RES_MAX * LV_VER_RES_MAX);   /*Initialize the display buffer*/

//    /* Example for 3) */
//    static lv_disp_buf_t disp_buf_3;
//		extern __align(256) u32 LTDC_Buf[XSIZE_PHYS*YSIZE_PHYS*2];//XSIZE_PHYS*YSIZE_PHYS*2
//		#define buf3_1 (uint8_t*)LTDC_Buf
//    #define buf3_2 (uint8_t*)(LTDC_Buf+XSIZE_PHYS*YSIZE_PHYS)
//    ///static lv_color_t buf3_1[LV_HOR_RES_MAX * LV_VER_RES_MAX];            /*A screen sized buffer*/
//    ///static lv_color_t buf3_2[LV_HOR_RES_MAX * LV_VER_RES_MAX];            /*An other screen sized buffer*/
//    lv_disp_buf_init(&disp_buf_3, buf3_1, buf3_2, LV_HOR_RES_MAX * LV_VER_RES_MAX);   /*Initialize the display buffer*/

  static lv_disp_buf_t disp_buf_3;
  static lv_color_t buf3_1[LV_HOR_RES_MAX * LV_VER_RES_MAX + 1];            /*A screen sized buffer*/
  static lv_color_t buf3_2[LV_HOR_RES_MAX * LV_VER_RES_MAX + 1];            /*An other screen sized buffer*/
 lv_disp_buf_init(&disp_buf_3, buf3_1, buf3_2, LV_HOR_RES_MAX * LV_VER_RES_MAX + 1);   /*Initialize the display buffer*/

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = XSIZE_PHYS;
    disp_drv.ver_res = YSIZE_PHYS;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.buffer = &disp_buf_3;

#if LV_USE_GPU
    /*Optionally add functions to access the GPU. (Only in buffered mode, LV_VDB_SIZE != 0)*/

    /*Blend two color array using opacity*/
    disp_drv.gpu_blend_cb = gpu_blend;

    /*Fill a memory array with a color*/
    disp_drv.gpu_fill_cb = gpu_fill;
#endif

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Initialize your display and the required peripherals. */
static void disp_init(void)
{
    /*You code here*/
		//	LCD_Initial();               ///LCD初始化函数
}
/********************************************************************************************************
**函数信息 ：DMA1_Channel2_IRQHandler()     
**功能描述 : DMA1通道2的中断函数
**输入参数 ：无
**输出参数 ：无
********************************************************************************************************/

void DMA2_Channel2_IRQHandler()
{ 
	if(DMA_GetITStatus(DMA2_IT_TC2))
		{
//			printf(" A");
			DMA_ClearITPendingBit(DMA2_IT_TC2);

			lv_disp_flush_ready(&disp_drv);
		}
		
}
/* Flush the content of the internal buffer the specific area on the display
 * You can use DMA or any hardware acceleration to do this operation in the background but
 * 'lv_disp_flush_ready()' has to be called when finished. */
//#pragma arm section code ="RAMCODE"
//#pragma arm section
static void disp_flush(lv_disp_drv_t * disp_drv_f, const lv_area_t * area, lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

//   int32_t x;
//   int32_t y;
	
//	LCD_Fill_Pic(area->x1,area->x2,area->y1, area->y2, (u32*)color_p);
	
	BlockWrite(area->x1,area->x2,area->y1,area->y2);
	TK80_DMA_Init((u32)color_p,(area->x2-area->x1+1)*(area->y2-area->y1+1));//DMA初始化
	while((DMA2->ISR & 0x20)==0);
	DMA2->IFCR |=1<<5;

  /* Inform the graphics library that you are ready with the flushing*/
  lv_disp_flush_ready(&disp_drv);
}


/*OPTIONAL: GPU INTERFACE*/
#if LV_USE_GPU

/* If your MCU has hardware accelerator (GPU) then you can use it to blend to memories using opacity
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/
static void gpu_blend(lv_disp_drv_t * disp_drv, lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa)
{
    /*It's an example code which should be done by your GPU*/
    uint32_t i;
    for(i = 0; i < length; i++) {
        dest[i] = lv_color_mix(dest[i], src[i], opa);
    }
}

/* If your MCU has hardware accelerator (GPU) then you can use it to fill a memory with a color
 * It can be used only in buffered mode (LV_VDB_SIZE != 0 in lv_conf.h)*/
static void gpu_fill(lv_disp_drv_t * disp_drv, lv_color_t * dest_buf, lv_coord_t dest_width,
                    const lv_area_t * fill_area, lv_color_t color)
{
    /*It's an example code which should be done by your GPU*/
    int32_t x, y;
    dest_buf += dest_width * fill_area->y1; /*Go to the first line*/

    for(y = fill_area->y1; y < fill_area->y2; y++) {
        for(x = fill_area->x1; x < fill_area->x2; x++) {
            dest_buf[x] = color;
        }
        dest_buf+=dest_width;    /*Go to the next line*/
    }
}

#endif  /*LV_USE_GPU*/

#else /* Enable this file at the top */

/* This dummy typedef exists purely to silence -Wpedantic. */
typedef int keep_pedantic_happy;
#endif
