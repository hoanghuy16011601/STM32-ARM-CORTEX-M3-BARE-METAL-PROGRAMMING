#ifndef __HUY_Delay_Function_h
#define __HUY_Delay_Function_h
#include "stdint.h"

void delay_ms(uint32_t t, uint32_t HCLK_Freq);
void delay_us(uint32_t time, uint32_t HCLK_Freq);

#endif
