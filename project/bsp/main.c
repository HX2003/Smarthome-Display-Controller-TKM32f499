#include "main.h"
#include "lvgl.h"
#include "LCD.h"
#include "lv_conf.h"
#include "lv_port_disp.h"  ///
#include "lv_port_indev.h" ///
#include "reflow_oven_ui.h"

//分配启动任务优先级、堆栈大小、任务堆栈
#define START_TASK_PRIO		(configMAX_PRIORITIES-1)        //任务优先级
#define START_TASK_STK_SIZE 256      //任务堆栈大小	
//启动任务函数
void Start_Task(void *pvParameters);

//分配LED任务优先级、堆栈大小、任务堆栈
#define GUI_TASK_PRIO		1     //任务优先级
#define GUI_TASK_STK_SIZE   25600   //任务堆栈大小
//led任务函数
void GUI_Task(void *pvParameters);

//分配LED任务优先级、堆栈大小、任务堆栈
#define UART_TASK_PRIO		2     //任务优先级
#define UART_TASK_STK_SIZE   1024   //任务堆栈大小
//led任务函数
void UART_Task(void *pvParameters);

//UART任务
void UART_Task(void *pvParameters)
{
  while(1)
	{
		//for(int i=0; i<5; i++){
		vTaskDelay(5000);        //延时
		//printf("{ \"ip\": \"192.168.1.133\", \"id\": 1, \"g\": 1, \"req\": { \"state\": \"On\", \"hue\": 0, \"saturation\": 0, \"brightness\": %i, \"bulb_mode\" : \"white\" }} \n", i*50);
		//}
	}
}
//LED任务
void LED_Task(void *pvParameters)
{
	while(1)
	{
		//GPIOD->ODR ^= GPIO_Pin_8;//取反PD8，令LED灯闪动
		lv_task_handler();
		vTaskDelay(5);        //延时1s
	}
}
//启动任务
void Start_Task(void *pvParameters)
{	
	//创建用户任务
	xTaskCreate(LED_Task,                    //任务函数
	            (const char *)"gui task",    //任务名
	            GUI_TASK_STK_SIZE,    //栈大小
	            NULL,                        //任务参数
	            GUI_TASK_PRIO,      //优先级,启动任务优先级分配为最大
	            NULL);  
  xTaskCreate(UART_Task,                    //任务函数
	            (const char *)"uart task",    //任务名
	            UART_TASK_STK_SIZE,    //栈大小
	            NULL,                        //任务参数
	            UART_TASK_PRIO,      //优先级,启动任务优先级分配为最大
	            NULL); 							//任务句柄
				
	//删除启动任务
	vTaskDelete(NULL);  //NULL表示删除自己
}


int main(void)
{
RemapVtorTable();
	SystemClk_HSEInit(RCC_PLLMul_25);//启动PLL时钟，12MHz*20=240MHz，25超频慎用
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//2：2，全局性函数，仅需设置一次
	UartInit(UART2, 115200);      //配置串口1，波特率为460800
	printf("Hello \n");
		
	TIM8_Config(240,1000);        //配置定时器8，在定时器中断里打印
	TIM3_Config(1000,240);//1mS
	LCD_Initial();               //LCD初始化函数
	Times_Pwm_Config(200,499,200); //Backlight PWM
  I2CInitMasterMode(I2C1);
	Lcd_ColorBox(0,0,XSIZE_PHYS,YSIZE_PHYS,Blue);
	//EXIT_KEY_Init();	//外部模拟LCD中断按键初始化
	/************/
	//EXIT_KEY_Init();	//外部模拟LCD中断按键初始化
	/************/
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	reflow_oven_ui();
//创建启动任务,优先级设为最大,优先级值越大,优先级越大
	xTaskCreate(Start_Task,                    //任务函数
	            (const char *)"start task",    //任务名
	            START_TASK_STK_SIZE,    //栈大小
	            NULL,                        //任务参数
	            START_TASK_PRIO,      //优先级,启动任务优先级分配为最大
	            NULL);                       //任务句柄
				
	//启动调度器
	vTaskStartScheduler();
	
	while(1)
	{
	
	}
}





