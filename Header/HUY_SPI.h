#include "stdint.h"





#define SPI1_MODE 0X10
#define SPI2_MODE 0X20
#define SPI3_MODE 0x30

#define BIDIMODE 15;
#define BIDEOE 14;  
#define CRCEN 13;
#define CRCNEXT 12; 
#define DFF 11; 
#define RXONLY 10;
#define SSM 9;
#define SSI 8;
#define LSBFIRST 7;


void SPI_init_master(uint8_t type,int baudrate,...);
uint16_t SPI_full_duxplex_16bit(uint8_t type,uint16_t data);
uint8_t SPI_full_duxplex_8bit(uint8_t type,uint8_t data);
