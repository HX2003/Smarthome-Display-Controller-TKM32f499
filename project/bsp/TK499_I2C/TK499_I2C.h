#include "HAL_conf.h"
void I2CInitMasterMode(I2C_TypeDef *I2Cx);
void I2CTXEmptyCheck(I2C_TypeDef *I2Cx);
void I2CRXFullCheck(I2C_TypeDef *I2Cx);
void I2CTXByte(I2C_TypeDef *I2Cx,unsigned short cmd,unsigned char temp);
unsigned char I2CRXByte(I2C_TypeDef *I2Cx);
void I2CMasterWrite(I2C_TypeDef *I2Cx,unsigned char device_id, unsigned short mem_byte_addr, unsigned short tx_count, unsigned char *tx_data );
void I2CMasterRead(I2C_TypeDef *I2Cx,unsigned char device_id, unsigned short mem_byte_addr, unsigned short rx_count, unsigned char *rx_data );
void I2CMasterTest(I2C_TypeDef *I2Cx);

