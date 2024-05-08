#ifndef __HUY_I2C_H
#define __HUY_I2C_H

#include "stdint.h"


#define I2C1_MODE 21
#define I2C2_MODE 22
#define I2C_Fast_MODE 0XF0
#define I2C_Standard_MODE 0XF1
#define I2C_HAVE_OPTION_CR1 0XF2
#define I2C_NO_OPTION_CR1 0xF3


#define I2C_ALERT 13
#define I2C_PEC 12
#define I2C_POS 11
#define I2C_ACK 10
#define I2C_NOSTRETH 7
#define I2C_ENGC 6
#define I2C_ENPEC 5
#define I2C_ENARP 4
#define I2C_SMBTYPE 3
#define I2C_SMBUS 1


#define I2C_Address_7_Bit 0x70
#define I2C_Address_10_Bit 0xA0

#define I2C_Transmit 0
#define I2C_receive 1

#define I2C_ADDRESS_MATCH  0XFF
#define I2C_NO_ADDRESS_MATCH  0XFE 


void I2C_init(uint8_t Select_I2C, uint8_t freq_MHZ, uint8_t mode_clk,float SCL_CLOCK,int option ,...);
uint8_t I2C_Start(uint8_t Select_I2C,uint8_t I2C_Direction ,uint8_t Number_Bit_Address, uint16_t Address);
void I2C_Transmit_Data(uint8_t Select_I2C,unsigned char Data);
void I2C_Stop(uint8_t Select_I2C);

#endif
