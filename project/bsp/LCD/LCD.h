#include "HAL_conf.h"

#define XSIZE_PHYS 854
#define YSIZE_PHYS 480
//extern __align(256) u32 LTDC_Buf[XSIZE_PHYS*YSIZE_PHYS];//XSIZE_PHYS*YSIZE_PHYS*2
#define LCD_SPI_CS(a)	\
						if (a)	\
						GPIOB->BSRR = GPIO_Pin_11;	\
						else		\
						GPIOB->BRR  = GPIO_Pin_11;					
#define SPI_DCLK(a)	\
						if (a)	\
						GPIOB->BSRR = GPIO_Pin_9;	\
						else		\
						GPIOB->BRR  = GPIO_Pin_9;	
#define SPI_SDA(a)	\
						if (a)	\
						GPIOE->BSRR = GPIO_Pin_0;	\
						else		\
						GPIOE->BRR  = GPIO_Pin_0;

#define LCD_RST(a)	\
						if (a)	\
						GPIOD->BSRR = GPIO_Pin_6;	\
						else		\
						GPIOD->BRR  = GPIO_Pin_6;

#define Lcd_Light_ON   GPIOD->BSRR = GPIO_Pin_8  //PD8为高电平 背光打开
#define Lcd_Light_OFF  GPIOD->BRR  = GPIO_Pin_8  //PD8为低电平 背光关闭

//*************  24位色（1600万色）定义 *************//
#define White          0xFFFFFF
#define Black          0x000000
#define Blue           0x0000FF
#define Blue2          0xFF3F3F
#define Red            0xFF0000
#define Magenta        0xFF00FF
#define Green          0x00FF00
#define Cyan           0x00FFFF
#define Yellow         0xFFFF00						

//*************  16位色定义 *************//
//#define White          0xFFFF
//#define Black          0x0000
//#define Blue           0x001F
//#define Blue2          0x051F
//#define Red            0xF800
//#define Magenta        0xF81F
//#define Green          0x07E0
//#define Cyan           0x7FFF
//#define Yellow         0xFFE0
						
						
void TK80_DMA_Init(u32 srcAdd ,u32 len);
void LCD_Initial(void); //LCD初始化函数
void LCD_delay(int time);
void WriteComm(unsigned char CMD);
void WriteData(u32 dat);
void LCD_WR_REG(u16 Index,u16 CongfigTemp);
void BlockWrite(unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend);
void Lcd_ColorBox(u16 xStart,u16 yStart,u16 xLong,u16 yLong,u32 Color);
//void SPILCD_DrawLine(unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2,unsigned short color);
//void SPILCD_ShowChar(unsigned short x,unsigned short y,unsigned char num, unsigned int fColor, unsigned int bColor,unsigned char flag) ;
void LCD_PutString(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor,unsigned char flag);
void LCD_Fill_Pic(u16 x, u16 y,u16 pic_H, u16 pic_V, u32* pic);

