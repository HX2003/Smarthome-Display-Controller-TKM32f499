#ifndef __SYS_H
#define __SYS_H	 
#include "tk499.h" 
#include "HAL_conf.h"
//λ������,ʵ��51���Ƶ�GPIO���ƹ���
//����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).M4ͬM3����,ֻ�ǼĴ�����ַ����.
//IO�ڲ����궨��
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 

void  RemapVtorTable(void);
void  AI_Responder_enable(void);
void  AI_Responder_disable(void);

void Sys_Soft_Reset(void);      							//ϵͳ��λ
void Sys_Standby(void);         							//����ģʽ 	

void TK499_NVIC_Init(u8 NVIC_PreemptionPriority,u8 NVIC_SubPriority,u8 NVIC_Channel,u8 NVIC_Group);	
void Ex_NVIC_Config(u8 GPIOx,u8 BITx,u8 TRIM);				//�ⲿ�ж����ú���(ֻ��GPIOA~I)

//����Ϊ��ຯ��
void WFI_SET(void);		//ִ��WFIָ��
void INTX_DISABLE(void);//�ر������ж�
void INTX_ENABLE(void);	//���������ж�

void TIM3_Config(u16 arr,u16 psc);
#endif











