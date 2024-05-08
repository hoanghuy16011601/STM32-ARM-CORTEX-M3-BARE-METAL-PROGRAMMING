#ifndef _STM32F103C8_IRQ_H_
#define _STM32F103C8_IRQ_H_
#include "stdint.h"

void Systick_Timer_Init(uint32_t Milisecond,uint32_t System_Clock_Value);
void Disable_IRQ(void);
void Enable_IRQ(void);
void NVIC_Enable_IRQ(uint8_t IRQ_Number);
void NVIC_Disable_IRQ(uint8_t IRQ_Number);
void NVIC_Disable_IRQ(uint8_t IRQ_Number);
void NVIC_SetPending_IRQ(uint8_t IRQ_Number);
void NVIC_Grouping_IRQ(uint8_t Number_Bit_PreEmption);
void NVIC_SetPriority_IRQ(uint8_t IRQ_Number, uint8_t Priority_Value);
void System_Pending_PENSV(void);



#endif

