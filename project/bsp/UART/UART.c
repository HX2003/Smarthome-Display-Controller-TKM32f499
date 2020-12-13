#include "UART.h"

void UartInit(UART_TypeDef* UARTx,int BaudRate)
{
	UART_InitTypeDef       UART_InitStructure;  
	GPIO_InitTypeDef  GPIO_InitStructure;   
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;   //uart1_tx  PA9, uart2_tx  PA2
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // 推免复用输出
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;  //uart1_rx  PA10, uart2_tx  PA3
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // 推免复用输出////   

  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//GPIO_PinAFConfig(GPIOA, GPIO_Pin_9 | GPIO_Pin_10, GPIO_AF_UART_1); //PA9、PA10复用为串口1
	GPIO_PinAFConfig(GPIOA, GPIO_Pin_2 | GPIO_Pin_3, GPIO_AF_UART_2345);
	
	
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_UART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_UART2, ENABLE);
	UART_InitStructure.UART_BaudRate = BaudRate; //波特率
  UART_InitStructure.UART_WordLength = UART_WordLength_8b;//数据位
  UART_InitStructure.UART_StopBits = UART_StopBits_1;//停止位
  UART_InitStructure.UART_Parity = UART_Parity_No ;
  UART_InitStructure.UART_Mode = UART_Mode_Rx | UART_Mode_Tx;//输入输出模式
  UART_InitStructure.UART_HardwareFlowControl = UART_HardwareFlowControl_None; 	
	UART_Init(UARTx, &UART_InitStructure);
	UART_Cmd(UARTx, ENABLE);  //UART 模块使能
	
  UART_ClearITPendingBit(UARTx, 0xff); 

}
u8 Uart1_Receive(void)
{
	//判断数据是否到来
  while((UART1->CSR & (1<<1)) ==0);
	return UART1->RDR;

}

void send_data(u8 data)
{
	while((UART2->CSR &0x1) == 0);
	UART2->TDR = data; 
}
void send_group(u8*data,u16 len)
{
	while(len--)
	send_data(*data++);
}
void send_str(char *p)
{
		while(*p != '\0')
		{
			send_data(*p);
			p++;
		}
}

//加入下列代码，不用勾选USE microlib,使用printf

#pragma import(__use_no_semihosting)                          
struct __FILE 
{ 
	int handle; 
}; 
FILE __stdout; 

void _sys_exit(int x) 
{ 
	x = x; 
} 

int fputc(int ch, FILE *f)
{      
	//while((UART1->CSR &0x1) == 0){}
	//	UART1->TDR = (u8) ch;      
	while((UART2->CSR &0x1) == 0){}
		UART2->TDR = (u8) ch;      
	return ch;
}




