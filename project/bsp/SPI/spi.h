#ifndef __SPI_H__
#define __SPI_H__

#define READ        	0x03
#define FAST_READ   	0x0B
#define RDID        	0x9F
#define WREN 			0x06
#define WRDI 			0x04
#define SE 				0xD8
#define BE 				0xC7
#define PP 				0x02
#define RDSR 			0x05
#define WRSR 			0x01
#define DP 				0xB9
#define RES 			0xAB

void SPIM_Init(SPI_TypeDef* SPIx,unsigned short spi_baud_div);
//#define SPI_INT_MODE
//#define SPI_DMA
#endif
