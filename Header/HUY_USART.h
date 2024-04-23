#include "stdint.h"

#define UART1 0x10
#define UART2 0x20
#define UART3 0x30
#define Transmit 4
#define Receive 3
#define Yes 1
#define No 0
#define EXTI_H

void Configure_UART(uint8_t Select_USART,uint8_t Mode ,uint8_t word_length, unsigned int baudrate, int checking_parity,...);
void UART_Transmit_8word(uint8_t Select_USART,char data);
char UART_Receive_8Word(uint8_t Select_USART);
