#ifndef __HUY_GPIO_H
#define __HUY_GPIO_H
#include "stdint.h"
#include "stdarg.h"


#define GPIO_PORTA 2
#define GPIO_PORTB 3
#define GPIO_PORTC 4

//MODE
#define INPUT 0x00
#define OUTPUT_10MHZ 0x01
#define OUTPUT_2MHZ  0x02
#define OUTPUT_50MHZ  0x03

//INPUT MODE
#define IP_ANALOG 0x00
#define IP_FLOATING 0x01
#define IP_PULL_UP_DOWN 0x02

//OUTPUT MODE 
#define OP_GENERAL_PUSH_PULL 0x00
#define OP_GENERAL_OPEN_DRAIN 0x01
#define OP_ALTERNATE_PUSH_PULL 0x02
#define OP_ALTERNATE_OPEN_DRAIN 0x03

#define HIGH 1
#define LOW 0


void GPIO_MODE (uint8_t PORT, uint8_t PIN, uint8_t MODE, uint8_t CNF);
void GPIO_MODE_MULTI_PIN (uint8_t PORT, uint8_t MODE, uint8_t CNF,int numberpin,...);
uint8_t READ_GPIO_PIN(uint8_t PORT, uint8_t PIN);
uint16_t READ_GPIO_PORT(uint8_t PORT);
void WRITE_GPIO_PIN(uint8_t PORT, uint8_t PIN,uint8_t CMD);
void WRITE_GPIO_PORT(uint8_t PORT,uint16_t CMD);

#endif
