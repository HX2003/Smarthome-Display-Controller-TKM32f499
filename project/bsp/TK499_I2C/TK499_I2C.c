#include "HAL_conf.h"
#include "touch_CTP.h"
#include "TK499_I2C.h"
volatile unsigned char rx_flag = 0;
volatile unsigned char tx_flag = 0;
extern uint16_t I2C_DMA_DIR;
unsigned char tx_buffer0[16] = {0x55,1,2,3,4,5,6,7,8,9,0xa,0xb,0xc,0xd,0xe,0xf};
unsigned char rx_buffer0[16] ;

volatile unsigned short txData_Number = 0;
volatile unsigned short txData_count = 0;
#define MXT224_ADDR		0x94		//��ַΪ 0x4a<<1, Ҫ��һλ
#define FLASH_DEVICE_ADDR 0xa8
//#define FLASH_DEVICE_ADDR 0xa0
/********************************************************************************************************
**������Ϣ ��I2CInitMasterMode(I2C_TypeDef *I2Cx,unsigned long apb_mhz,unsigned long i2c_baud_rate) //unit is Khz                    
**�������� ����ʼ��I2C
**������� ��I2C_TypeDef *I2Cx��ѡ��I2C1,I2C2
**������� ����
********************************************************************************************************/
void I2CInitMasterMode(I2C_TypeDef *I2Cx) 
{
	I2C_InitTypeDef I2C_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);  //i2c1 clk enable
		
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	
	GPIO_PinAFConfig(GPIOB, GPIO_Pin_0 | GPIO_Pin_2, GPIO_AF_I2C); //PB0��PB2����ΪIIC
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_2 ;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD; // ���ÿ�©���
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//========== PD7 ��ʼ��Ϊ��������
	GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
  I2C_InitStructure.I2C_Mode = I2C_Mode_MASTER;//��ģʽ
  I2C_InitStructure.I2C_OwnAddress = FT6206_ADDR;
  I2C_InitStructure.I2C_Speed = I2C_Speed_STANDARD;
  I2C_InitStructure.I2C_ClockSpeed = 1000000;   //�ٶ�����Ϊ400K
	I2C_Init(I2C1, &I2C_InitStructure);
	
	I2C_Send7bitAddress(I2C1, FT6206_ADDR, 0);
	I2C_Cmd(I2C1, ENABLE);
}
/********************************************************************************************************
**������Ϣ ��I2CTXEmptyCheck(I2C_TypeDef *I2Cx)                 
**�������� ����鷢���жϱ�־λ
**������� ��I2C_TypeDef *I2Cx��ѡ��I2C1,I2C2
**������� ����
********************************************************************************************************/
void I2CTXEmptyCheck(I2C_TypeDef *I2Cx)
{
	while(1)
	{
		if(I2C_GetFlagStatus(I2Cx, I2C_FLAG_TX_EMPTY))
		{
			break;
		}
	}
}
/********************************************************************************************************
**������Ϣ ��I2CTXEmptyCheck(I2C_TypeDef *I2Cx)                 
**�������� ���������жϱ�־λ
**������� ��I2C_TypeDef *I2Cx��ѡ��I2C1,I2C2
**������� ����
********************************************************************************************************/
void I2CRXFullCheck(I2C_TypeDef *I2Cx)
{
	int i=0;
	while(1)
	{
		if(I2C_GetFlagStatus(I2Cx, I2C_FLAG_RX_FULL))
		{

			break;
		}	
		i++;
			if(i>400)//��ʱ�˳�
			break;
	}
}
/********************************************************************************************************
**������Ϣ ��I2CTXByte(I2C_TypeDef *I2Cx,unsigned short cmd,unsigned char temp)              
**�������� ��I2C��������
**������� ��I2C_TypeDef *I2Cx��ѡ��I2C1,I2C2��cmd��temp
**������� ����
********************************************************************************************************/
void I2CTXByte(I2C_TypeDef *I2Cx,unsigned short cmd,unsigned char temp)
{
	I2C_SendData(I2Cx, temp);
	I2CTXEmptyCheck(I2Cx);

}
/********************************************************************************************************
**������Ϣ ��I2CRXByte(I2C_TypeDef *I2Cx)             
**�������� ��I2C��������
**������� ��I2C_TypeDef *I2Cx��ѡ��I2C1,I2C2
**������� ��temp
********************************************************************************************************/
unsigned char I2CRXByte(I2C_TypeDef *I2Cx)
{
	unsigned char temp;

	I2CRXFullCheck(I2Cx);
	
	temp = I2C_ReceiveData(I2Cx);
	return (unsigned char)temp;
}

/********************************************************************************************************
**������Ϣ ��I2CMasterWrite(I2C_TypeDef *I2Cx,unsigned char device_id, unsigned short mem_byte_addr, unsigned short tx_count, unsigned char *tx_data )             
**�������� ��I2C��������
**������� ��I2C_TypeDef *I2Cx��ѡ��I2C1,I2C2��cmd��temp
**������� ����
********************************************************************************************************/
void I2CMasterWrite(I2C_TypeDef *I2Cx,unsigned char device_id, unsigned short mem_byte_addr, unsigned short tx_count, unsigned char *tx_data )
{
	unsigned short temp;
	unsigned short i;
	unsigned char *p;
	uint32_t j;
	p = tx_data;
	
//	txData_count = tx_count;
	I2C_Cmd(I2Cx, DISABLE);
	I2C_Send7bitAddress(I2Cx, FLASH_DEVICE_ADDR, I2C_Direction_Transmitter);
	I2C_Cmd(I2Cx, ENABLE);
	temp = ((mem_byte_addr) & 0xff);
	I2CTXByte(I2Cx,CMD_WRITE,temp);  //tx memory addr

	for(i=0;i<tx_count;i++)
	{
		temp = *p;
		p++;
//		txData_Number ++;
		if(i==(tx_count-1))
			I2Cx->IC_DATA_CMD =temp| 0x200; // //muaul set stop flag
		else
		I2CTXByte(I2Cx,CMD_WRITE,temp); //tx data
		
		
	}	

for(j=0;j<0x5000;j++); 

}

/********************************************************************************************************
**������Ϣ ��I2CMasterRead(I2C_TypeDef *I2Cx,unsigned char device_id, unsigned short mem_byte_addr, unsigned short rx_count, unsigned char *rx_data )           
**�������� ��I2C��������
**������� ��I2C_TypeDef *I2Cx��ѡ��I2C1,I2C2��device_id��mem_byte_addr��rx_count��rx_data
**������� ����
********************************************************************************************************/
void I2CMasterRead(I2C_TypeDef *I2Cx,unsigned char device_id, unsigned short mem_byte_addr, unsigned short rx_count, unsigned char *rx_data )
{
	unsigned char temp=0;
	unsigned short i;

	I2C_Send7bitAddress(I2Cx, FLASH_DEVICE_ADDR, I2C_Direction_Transmitter);
	
	I2C_Cmd(I2Cx, ENABLE);
	
	temp = ((mem_byte_addr) & 0xff);
	
	I2CTXByte(I2Cx,CMD_WRITE,temp);  //tx memory addr
	
	for(i=0;i<rx_count;i++)
	{
		rx_data[i] = I2CRXByte(I2Cx);
		printf("RX data%d is  : %x \r\n",i,rx_data[i]);
	}
}

/********************************************************************************************************
**������Ϣ ��I2CMasterTest(I2C_TypeDef *I2Cx)          
**�������� ��I2C���շ������ݲ��Գ���
**������� ��I2C_TypeDef *I2Cx��ѡ��I2C1,I2C2
**������� ����
********************************************************************************************************/
unsigned char rxBuffer[16] = {0};

void I2CMasterTest(I2C_TypeDef *I2Cx)
{
	unsigned char i;
//	I2CInitMasterMode(I2C1);
	
	I2CMasterWrite(I2C1,FLASH_DEVICE_ADDR, 16*1, 16, tx_buffer0 );
	

	for(i = 0; i < 16 ;i ++)
	{
		printf("TX data is: %x \r\n", tx_buffer0[i]);
	}

	I2CMasterRead(I2C1,FLASH_DEVICE_ADDR, 16*1, 16, rx_buffer0 );

}


