#include "HAL_device.h"
#include "HAL_conf.h"
#include "spi.h"
#include "stdio.h"

unsigned char tmpdata[256]__attribute__((at(0x00003400)));;

unsigned char rxtmpdata[256]__attribute__((at(0x00003500)));
volatile unsigned char spi0_rx_flag;
volatile unsigned char spi0_tx_flag;
extern void DataCompare(unsigned char *p1, unsigned char *p2,unsigned int count);
/********************************************************************************************************
**������Ϣ ��SPIM_CSLow()                      
**�������� :Ϊѡ����SPI ��������ڲ�NSS �ܽ� 
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_CSLow(SPI_TypeDef* SPIx)
{
	//Spi cs assign to this pin,select	
	SPI_CSInternalSelected(SPIx, SPI_CS_BIT0,ENABLE);
}

/********************************************************************************************************
**������Ϣ ��SPIM_CSHigh()                      
**�������� :Ϊѡ����SPI ��������ڲ�NSS �ܽ� 
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_CSHigh(SPI_TypeDef* SPIx)
{
	//Spi cs release
	SPI_CSInternalSelected(SPIx, SPI_CS_BIT0,DISABLE);
}

/********************************************************************************************************
**������Ϣ ��SPIM_TXEn()                     
**�������� :�ر� SPI ��˫��ģʽ�µ����ݴ��䷽�� 
**������� : ��
**������� ����
********************************************************************************************************/
void SPIM_TXEn(SPI_TypeDef* SPIx)
{
	//Transmit Enable bit TXEN
	SPI_BiDirectionalLineConfig(SPIx, SPI_Direction_Tx);
}

/********************************************************************************************************
**������Ϣ ��SPIM_TXDisable()                     
**�������� :�ر� SPI ��˫��ģʽ�µ����ݴ��䷽�� 
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_TXDisable(SPI_TypeDef* SPIx)
{
	//disable TXEN
	SPI_BiDirectionalLineConfig(SPIx, SPI_Disable_Tx);
}

/********************************************************************************************************
**������Ϣ ��SPIM_RXEn()                     
**�������� :�ر� SPI ��˫��ģʽ�µ����ݴ��䷽�� 
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_RXEn(SPI_TypeDef* SPIx)
{
	//enable RXEN
	SPI_BiDirectionalLineConfig(SPIx, SPI_Direction_Rx);
}

/********************************************************************************************************
**������Ϣ ��SPIM_RXDisable()                     
**�������� :�ر� SPI ��˫��ģʽ�µ����ݴ��䷽�� 
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_RXDisable(SPI_TypeDef* SPIx)
{
	//disable RXEN
	SPI_BiDirectionalLineConfig(SPIx, SPI_Disable_Rx);
}


/********************************************************************************************************
**������Ϣ ��SPIMReadWriteByte(unsigned char tx_data)                    
**�������� : ͨ������ SPIx �շ����� ,����ȫ˫��ģʽ(ͬʱ�շ�)
**������� ����
**������� ����
********************************************************************************************************/
unsigned int SPIMReadWriteByte(SPI_TypeDef* SPIx,unsigned char tx_data)
{
	SPI_SendData(SPIx, tx_data);	
	while (1)
	{
		if(SPI_GetFlagStatus(SPIx, SPI_FLAG_RXAVL))	
		{
			return SPI_ReceiveData(SPIx);
		}
	}
}

void SPI_RegRW()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);  //SPI1 clk enable
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);  //SPI1 clk enable 
	
		printf("SPI1->TXREG=0x%x\r\n",  SPI1->TXREG);  
		printf("SPI1->RXREG=0x%x\r\n",  SPI1->RXREG); 
		printf("SPI1->CSTAT=0x%x\r\n",  SPI1->CSTAT); 																	 
		printf("SPI1->INTSTAT=0x%x\r\n",SPI1->INTSTAT);																
		printf("SPI1->INTEN =0x%x\r\n", SPI1->INTEN );  																		 
		printf("SPI1->INTCLR=0x%x\r\n", SPI1->INTCLR);  																			
		printf("SPI1->GCTL  =0x%x\r\n", SPI1->GCTL  );  																 
		printf("SPI1->CCTL =0x%x\r\n",  SPI1->CCTL );   																	 
		printf("SPI1->SPBRG=0x%x\r\n",  SPI1->SPBRG);    																 
		printf("SPI1->RXDNR=0x%x\r\n",  SPI1->RXDNR);    																	 
		printf("SPI1->SCSR =0x%x\r\n",  SPI1->SCSR ); 
	
		printf("SPI2->TXREG=0x%x\r\n",  SPI2->TXREG);  
		printf("SPI2->RXREG=0x%x\r\n",  SPI2->RXREG); 
		printf("SPI2->CSTAT=0x%x\r\n",  SPI2->CSTAT); 																					
		printf("SPI2->INTSTAT=0x%x\r\n",SPI2->INTSTAT);																				
		printf("SPI2->INTEN =0x%x\r\n", SPI2->INTEN );  																				
		printf("SPI2->INTCLR=0x%x\r\n", SPI2->INTCLR);  																				
		printf("SPI2->GCTL  =0x%x\r\n", SPI2->GCTL  );  																				
		printf("SPI2->CCTL =0x%x\r\n",  SPI2->CCTL );   																				
		printf("SPI2->SPBRG=0x%x\r\n",  SPI2->SPBRG);    																				
		printf("SPI2->RXDNR=0x%x\r\n",  SPI2->RXDNR);    
																						
		printf("SPI2->SCSR =0x%x\r\n",  SPI2->SCSR );  
}

/********************************************************************************************************
**������Ϣ ��SPIM_Init(unsigned short spi_baud_div)            
**�������� :���޸Ĳ�����ʼ��SPI
**������� ��spi_baud_div
**������� ����
********************************************************************************************************/
void SPIM_Init(SPI_TypeDef* SPIx,unsigned short spi_baud_div)
{
	SPI_InitTypeDef SPI_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI2, ENABLE);  //SPI1 clk enable
		
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA ,ENABLE);
	
		                           //  LCD_BL       LCD=> RS or DCX
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2 | GPIO_Pin_3;   		 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	// ͨ���������
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;   		//spi1_cs  pa4
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	// ͨ���������
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		                            // SCK          MOSI
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5 | GPIO_Pin_7;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	// ���⸴�����
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;  		//spi1_miso  pa6
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		//��������   
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		
	GPIOA->AFRL &= 0;
	GPIOA->AFRL |= 0x555000ee;

	GPIOA->BSRR = 0x4;

	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_DataWidth = SPI_DataWidth_8b;

	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;    		
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;  
	
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = spi_baud_div;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_Init(SPIx, &SPI_InitStructure);

	SPI_Cmd(SPIx, ENABLE); 	//Enables the specified SPI peripheral SPIʹ�ܡ�����ģʽ 8λ����ģʽ SPI �Ĳ�����
	SPIM_TXEn(SPIx);
//	SPIM_RXEn(SPIx);	
}

/********************************************************************************************************
**������Ϣ ��SPIM_ReadID(SPI_TypeDef* SPIx)                   
**�������� :��ȡID 
**������� ��SPI_TypeDef* SPIx,��ѡ��SPI1,SPI2
**������� ����
********************************************************************************************************/
void SPIM_ReadID(SPI_TypeDef* SPIx)
{
	unsigned char temp;
	unsigned int i;
	
	SPIM_CSLow(SPIx);								//Spi cs assign to this pin,select
	SPIMReadWriteByte(SPIx,RDID);				

	for(i=0;i<3;i++)
	{
		temp = SPIMReadWriteByte(SPIx,0x01);
		printf("temp=0x%x\r\n",temp);		
	}
	SPIM_CSHigh(SPIx);   							//Spi cs release
}

/********************************************************************************************************
**������Ϣ ��SPIM_WriteEnable()                  
**�������� :д����ʹ��
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_WriteEnable(SPI_TypeDef* SPIx)
{
	SPIM_CSLow(SPIx); 								//Spi cs assign to this pin,select
	SPIMReadWriteByte(SPIx,WREN);	
	SPIM_CSHigh(SPIx); 								//Spi cs release
}

/********************************************************************************************************
**������Ϣ ��SSPIM_checkStatus()                 
**�������� :������ݷ����Ƿ���ȷ
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_checkStatus(SPI_TypeDef* SPIx)
{
	unsigned char temp;
	SPIM_CSLow(SPIx); 								//Spi cs assign to this pin,select
	SPIMReadWriteByte(SPIx,RDSR);	
	while(1)
	{
		temp = SPIMReadWriteByte(SPIx,0x00);	
	 	if((temp&0x01)==0x0)
	 	break;
	}
	SPIM_CSHigh(SPIx);  							//Spi cs release
}

/********************************************************************************************************
**������Ϣ ��SPIM_WriteEnable()                  
**�������� :д����ʧ��
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_WriteDisable(SPI_TypeDef* SPIx)
{	
	SPIM_CSLow(SPIx);
	SPIMReadWriteByte(SPIx,WRDI);
	SPIM_CSHigh(SPIx);
}

/********************************************************************************************************
**������Ϣ ��SPIM_PageRead(unsigned long address,unsigned char *p,unsigned int number)               
**�������� :��ȡ256ҳ����
**������� �� address  ;*p ;number
**������� ����
********************************************************************************************************/
void SPIM_PageRead(SPI_TypeDef* SPIx,unsigned long address,unsigned char *p,unsigned int number)  //page = 256 bytes
{
	unsigned char addr0,addr1,addr2;
	unsigned int i;
	address = address&0xffffff00; 					//page address
	addr0 = (unsigned char)(address>>16);
	addr1 = (unsigned char)(address>>8);
	addr2 = (unsigned char)address;
	
	SPIM_CSLow(SPIx); 								//Spi cs assign to this pin,select
	
	SPIMReadWriteByte(SPIx,READ);
	SPIMReadWriteByte(SPIx,addr0);
	SPIMReadWriteByte(SPIx,addr1);
	SPIMReadWriteByte(SPIx,addr2);

	for(i=0;i<256;i++)
	{
		rxtmpdata[i] = SPIMReadWriteByte(SPIx,0x00);
	}

	
	SPIM_CSHigh(SPIx);  							//Spi cs release
}

/********************************************************************************************************
**������Ϣ ��SPIM_PageProgram(unsigned long address,unsigned char *p,unsigned int number)              
**�������� :����256ҳ����
**������� �� address;*p;number
**������� ����
********************************************************************************************************/
void SPIM_PageProgram(SPI_TypeDef* SPIx,unsigned long address,unsigned char *p,unsigned int number)
{
	unsigned int j;
	unsigned char addr0,addr1,addr2;
	address = address&0xffffff00; 					//page address
	addr0 = (unsigned char)(address>>16);
	addr1 = (unsigned char)(address>>8);
	addr2 = (unsigned char)address;

	SPIM_WriteEnable(SPIx);
	SPIM_CSLow(SPIx);  								//Spi cs assign to this pin,select
	SPIMReadWriteByte(SPIx,PP);
	SPIMReadWriteByte(SPIx,addr0);
	SPIMReadWriteByte(SPIx,addr1);
	SPIMReadWriteByte(SPIx,addr2);
	for(j=0;j<number;j++)
	{
		SPIMReadWriteByte(SPIx,*(p++));
	}

	SPIM_CSHigh(SPIx);  							//Spi cs release

	SPIM_checkStatus(SPIx);
}

/********************************************************************************************************
**������Ϣ ��SPIM_SectorErase()             
**�������� :��������
**������� ��unsigned long address,ɾ��ָ��sector�ĵ�ַ each sector = 64Kbytes
**������� ����
********************************************************************************************************/
void SPIM_SectorErase(SPI_TypeDef* SPIx,unsigned long address)
{
	unsigned char addr0,addr1,addr2;
	address = address & 0xffff0000;
	addr0 = ((unsigned char)(address>>16))&0xff;
	addr1 = ((unsigned char)(address>>8))&0xff;
	addr2 = ((unsigned char)address)&0xff;
	
	SPIM_WriteEnable(SPIx);
	
	SPIM_CSLow(SPIx);  								//Spi cs assign to this pin,select

	SPIMReadWriteByte(SPIx,SE);
	SPIMReadWriteByte(SPIx,addr0);
	SPIMReadWriteByte(SPIx,addr1);
	SPIMReadWriteByte(SPIx,addr2);
	SPIM_CSHigh(SPIx);  							//Spi cs release
	
	SPIM_checkStatus(SPIx);
}

/********************************************************************************************************
**������Ϣ ��SPIM_BlockErase()             
**�������� :��������
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_BlockErase(SPI_TypeDef* SPIx)
{
	SPIM_WriteEnable(SPIx);
	
	SPIM_CSLow(SPIx);  								//Spi cs assign to this pin,select

	SPIMReadWriteByte(SPIx,BE);	
	
	SPIM_CSHigh(SPIx);  							//Spi cs release
	
	SPIM_checkStatus(SPIx);
}
/********************************************************************************************************
**������Ϣ ��SPIM_Close()             
**�������� : CS�ź����ߣ�ֹͣͨ��
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_Close(SPI_TypeDef* SPIx)
{
	SPIM_CSHigh(SPIx);  							//Spi cs release
	SPIMReadWriteByte(SPIx,0x01);
}

/********************************************************************************************************
**������Ϣ ��SPIM_Test()          
**�������� :���Գ���ʹ�ô��ڴ�ӡ256ҳ����
**������� ����
**������� ����
********************************************************************************************************/
void SPIM_Test(SPI_TypeDef* SPIx)
{
	unsigned int i;
	for(i=0;i<256;i++)
	{
		tmpdata[i] = i;
//		tmpdata[i] = 0xaa;
	}

		printf("spi1 test\r\n");
		SPIM_Init(SPIx,0x8);//36MHz

		SPIM_ReadID(SPIx);
		
		SPIM_SectorErase(SPIx,0);
//	  SPIM_BlockErase(SPIx);
		
		SPIM_PageProgram(SPIx,0,tmpdata,256);
		
		for(i=0;i<256;i++)
		{
			rxtmpdata[i] = 0x0;
		}
		SPIM_PageRead(SPIx,0,rxtmpdata,256); 		//��д��ȥ��һҳ256�ֽڶ�����
		
		for(i=0;i<256;i++)
		{
				printf("rx[%d]=0x%x\r\n",i,rxtmpdata[i]);
		}
		
			printf("spi1 test over\r\n");
	
	
	
}


/*------------------------------------SPI loop------------------------------
-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
*/

void SPIMSendByte(SPI_TypeDef* SPIx,unsigned char tx_data)
{
	//SPI mode0 and clk is fclk/32 and enable spi
	SPI_SendData(SPIx,tx_data);

	while (1)
	{
		
		if(SPI_GetFlagStatus(SPIx, SPI_FLAG_TXEPT))	
		{
			break;
		}
	}

}

unsigned char SPIM_Readbyte(SPI_TypeDef* SPIx)
{
	unsigned char temp;
	 
	while(1)
	{
		if(SPI_GetFlagStatus(SPIx, SPI_FLAG_RXAVL)) 
		{
			break;
		}
		
	}

	temp = (unsigned char)SPI_ReceiveData(SPIx);
	 
	return temp;
}	


void SPI_master_loop(SPI_TypeDef* SPIx)
{
	unsigned int i;
	unsigned char temp[20] = {0x55,0xaa,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x56,0x23,0xff,0xaa,0x87,0x89,0x88,0x20,0x34,0x38,0xcd};
	unsigned char rxdata[20];
	for(i=0;i<20;i++)
	{
		rxdata[i] = 0x0;
	}
	
	SPIM_Init(SPIx,0x3);
	SPIM_TXDisable(SPIx);       ////disable TXEN	clear fifo
	SPIM_RXDisable(SPIx); 			 //disable RXEN	clear fifo
	SPI_RxBytes(SPIx, 0x01); //SPI1_RXDNR = 0x01;
	SPIM_CSLow(SPIx);  				//Spi cs assign to this pin,select
	SPIM_TXEn(SPIx); 				  //Transmit Enable bit TXEN
	SPIM_RXEn(SPIx);
	
	for(i=0;i<20;i++)
	{
		SPIMSendByte(SPIx,temp[i]); 			//SPDAT = PP;CheckStatus();
		rxdata[i] = SPIM_Readbyte(SPIx);
		printf("rxdata[%d]=0x%x\r\n",i,rxdata[i]);
	}
	for(i=0;i<20;i++)
	{
		if(rxdata[i]!=temp[i])	
			printf("err\r\n");
		if(i==19)
		printf("OK\r\n");	
	}
	
	SPIM_TXDisable(SPIx);
	SPIM_RXDisable(SPIx); 			 //disable RXEN	
	
}

