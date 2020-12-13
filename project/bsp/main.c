#include "main.h"
#include "lvgl.h"
#include "LCD.h"
#include "lv_conf.h"
#include "lv_port_disp.h"  ///
#include "lv_port_indev.h" ///
#include "reflow_oven_ui.h"

//���������������ȼ�����ջ��С�������ջ
#define START_TASK_PRIO		(configMAX_PRIORITIES-1)        //�������ȼ�
#define START_TASK_STK_SIZE 256      //�����ջ��С	
//����������
void Start_Task(void *pvParameters);

//����LED�������ȼ�����ջ��С�������ջ
#define GUI_TASK_PRIO		1     //�������ȼ�
#define GUI_TASK_STK_SIZE   25600   //�����ջ��С
//led������
void GUI_Task(void *pvParameters);

//����LED�������ȼ�����ջ��С�������ջ
#define UART_TASK_PRIO		2     //�������ȼ�
#define UART_TASK_STK_SIZE   1024   //�����ջ��С
//led������
void UART_Task(void *pvParameters);

//UART����
void UART_Task(void *pvParameters)
{
  while(1)
	{
		//for(int i=0; i<5; i++){
		vTaskDelay(5000);        //��ʱ
		//printf("{ \"ip\": \"192.168.1.133\", \"id\": 1, \"g\": 1, \"req\": { \"state\": \"On\", \"hue\": 0, \"saturation\": 0, \"brightness\": %i, \"bulb_mode\" : \"white\" }} \n", i*50);
		//}
	}
}
//LED����
void LED_Task(void *pvParameters)
{
	while(1)
	{
		//GPIOD->ODR ^= GPIO_Pin_8;//ȡ��PD8����LED������
		lv_task_handler();
		vTaskDelay(5);        //��ʱ1s
	}
}
//��������
void Start_Task(void *pvParameters)
{	
	//�����û�����
	xTaskCreate(LED_Task,                    //������
	            (const char *)"gui task",    //������
	            GUI_TASK_STK_SIZE,    //ջ��С
	            NULL,                        //�������
	            GUI_TASK_PRIO,      //���ȼ�,�����������ȼ�����Ϊ���
	            NULL);  
  xTaskCreate(UART_Task,                    //������
	            (const char *)"uart task",    //������
	            UART_TASK_STK_SIZE,    //ջ��С
	            NULL,                        //�������
	            UART_TASK_PRIO,      //���ȼ�,�����������ȼ�����Ϊ���
	            NULL); 							//������
				
	//ɾ����������
	vTaskDelete(NULL);  //NULL��ʾɾ���Լ�
}


int main(void)
{
RemapVtorTable();
	SystemClk_HSEInit(RCC_PLLMul_25);//����PLLʱ�ӣ�12MHz*20=240MHz��25��Ƶ����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//2��2��ȫ���Ժ�������������һ��
	UartInit(UART2, 115200);      //���ô���1��������Ϊ460800
	printf("Hello \n");
		
	TIM8_Config(240,1000);        //���ö�ʱ��8���ڶ�ʱ���ж����ӡ
	TIM3_Config(1000,240);//1mS
	LCD_Initial();               //LCD��ʼ������
	Times_Pwm_Config(200,499,200); //Backlight PWM
  I2CInitMasterMode(I2C1);
	Lcd_ColorBox(0,0,XSIZE_PHYS,YSIZE_PHYS,Blue);
	//EXIT_KEY_Init();	//�ⲿģ��LCD�жϰ�����ʼ��
	/************/
	//EXIT_KEY_Init();	//�ⲿģ��LCD�жϰ�����ʼ��
	/************/
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	reflow_oven_ui();
//������������,���ȼ���Ϊ���,���ȼ�ֵԽ��,���ȼ�Խ��
	xTaskCreate(Start_Task,                    //������
	            (const char *)"start task",    //������
	            START_TASK_STK_SIZE,    //ջ��С
	            NULL,                        //�������
	            START_TASK_PRIO,      //���ȼ�,�����������ȼ�����Ϊ���
	            NULL);                       //������
				
	//����������
	vTaskStartScheduler();
	
	while(1)
	{
	
	}
}





