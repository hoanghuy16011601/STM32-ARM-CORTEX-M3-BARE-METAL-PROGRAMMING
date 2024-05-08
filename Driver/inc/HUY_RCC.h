#ifndef __HUY_RCC_H
#define __HUY_RCC_H
#include "stdint.h"
#include "HUY_RCC_Bitfields.h"


#define READ_PLL_Clock_Output 0xF0
#define READ_System_Clock_Output 0xF1
#define READ_AHP_Clock_Output 0xF2
#define READ_APB1_Clock_Output 0xF3
#define READ_APB2_Clock_Output 0xF4
#define READ_ADC_Clock_Output 0xF5
#define READ_USB_Clock_Output 0xF6
#define READ_MCO_Clock_Output 0xF7
#define READ_TIMER1_Clock_INPUT 0xF8
#define READ_TIMER234_Clock_INPUT 0xF9

void Configure_HSE_Clock(uint8_t HSE_Divided);
void Configure_PLL_Clock(uint8_t PLLCLK_Select_InputClock, uint8_t PLL_Multiple);
void Configure_System_Clock(uint8_t SYSCLK_Select_InputClock, uint8_t AHB_Prescaler,uint8_t APB1_Prescaler, uint8_t APB2_Prescaler, uint8_t ADC_Prescaler);
void Configure_Microcontroler_ClockOuput(uint8_t MCO_Select_InputClock);
uint32_t Read_Clock(uint8_t Clock);

#endif
