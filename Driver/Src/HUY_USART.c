#include "stdint.h"
#include "stdarg.h"
#include "HUY_STM32F103.h"
#include "HUY_GPIO.h"
#include "HUY_USART.h"


void Configure_UART(uint8_t Select_USART,uint8_t Mode ,uint8_t word_length, unsigned int baudrate, int checking_parity,...)
{
	HUY_USART_Struct * USART_SELECTED;
	HUY_RCC->APB2ENR.bit.AFIOEN = 1;
	switch (Select_USART)
	{
		default : USART_SELECTED = HUY_USART1;
							GPIO_MODE(GPIO_PORTA,9, OUTPUT_10MHZ, OP_ALTERNATE_PUSH_PULL);
							GPIO_MODE(GPIO_PORTA,10,INPUT, IP_PULL_UP_DOWN);
							break;
		case UART2 : USART_SELECTED = HUY_USART2; 
								 GPIO_MODE(GPIO_PORTA,2, OUTPUT_10MHZ, OP_ALTERNATE_PUSH_PULL);
								 GPIO_MODE(GPIO_PORTA,3,INPUT, IP_PULL_UP_DOWN);
								 break;
		case UART3 : USART_SELECTED = HUY_USART3; 
								 GPIO_MODE(GPIO_PORTB,10, OUTPUT_10MHZ, OP_ALTERNATE_PUSH_PULL);
								 GPIO_MODE(GPIO_PORTB,11,INPUT, IP_PULL_UP_DOWN);
								 break;
	}
	HUY_RCC->APB2ENR.bit.USART1EN =1;
	USART_SELECTED->CR1.reg |= (uint32_t)((1<<13)|(word_length/9<<12)|(Mode/4<<3)|(Mode%2<<2));
	if(checking_parity==Yes)
	{
		va_list data;
		va_start (data,checking_parity);
		USART_SELECTED->CR1.bit.PS = (uint32_t)va_arg(data,int);
		va_end(data);
	}
	double USARTDIV = (double)(72000000)/(baudrate*16);
	uint16_t DIV_Mantissa =(uint16_t) USARTDIV;
	float Frac =  (float) ((USARTDIV - DIV_Mantissa)*16);
	uint8_t DIV_Fraction = (uint8_t) Frac;
	if((float)Frac-DIV_Fraction >= (float)0.5)
	{
		DIV_Fraction +=1;
	}
	if (DIV_Fraction ==16)
	{
		DIV_Fraction =0;
		DIV_Mantissa +=1;
	}
	USART_SELECTED->BRR.bit.DIV_Mantissa = DIV_Mantissa;
	USART_SELECTED->BRR.bit.DIV_Fraction = DIV_Fraction;
	////
}



/////////////
void UART_Transmit_8word(uint8_t Select_USART,char data)
{
	HUY_USART_Struct * USART_SELECTED;
	switch(Select_USART)
	{
		default : USART_SELECTED = HUY_USART1; break;
		case UART2: USART_SELECTED = HUY_USART2; break;
		case UART3: USART_SELECTED = HUY_USART3; break;
	}
	USART_SELECTED->DR.bit.DR = data;
	while(USART_SELECTED->SR.bit.TXE ==0);
}



//////////////
char UART_Receive_8Word(uint8_t Select_USART)
{
	HUY_USART_Struct * USART_SELECTED;
	switch(Select_USART)
	{
		default : USART_SELECTED = HUY_USART1; break;
		case UART2: USART_SELECTED = HUY_USART2; break;
		case UART3: USART_SELECTED = HUY_USART3; break;
	}
	while(USART_SELECTED->SR.bit.RXNE ==0);
	return (char) USART_SELECTED->DR.bit.DR;

}
	
