#ifndef __I2C_H
#define __I2C_H

#include "stdint.h"


#define I2C1_MODE 0x01
#define I2C2_MODE 0X02
#define Fast_MODE 0XF0
#define Standard_MODE 0XF1
#define HAVE_OPTION_CR1 0XF2
#define NO_OPTION_CR1 0xF3


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


#define address_7_bit 0x70
#define address_10_bit 0xA0

#define Transmit 0
#define receive 1

#define ADDRESS_MATCH  0XFF
#define NO_ADDRESS_MATCH  0XFE 


void I2C_init(uint8_t i2c, uint8_t freq_MHZ, uint8_t mode_clk,float SCL_CLOCK,int option ,...);
uint8_t Send_address(uint8_t i2c,uint8_t mode ,uint8_t number_bit_address, uint16_t address);
void I2C_transmit_data(uint8_t i2c,unsigned char data);
void I2C_stop(uint8_t i2c);
void I2C_transmit_string(uint8_t i2c, uint8_t number_bit_address, uint16_t address,unsigned char string[]);
void I2C_stop(uint8_t i2c);	
#endif

