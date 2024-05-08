
#include <math.h>
#include "Arm_Cortex_M3.h"
#include "STM32F103C8_IRQ.h"


void Disable_IRQ()
{
	//// Set bit PRIMASK
	__asm volatile ("MOV R0,#0x1"); 
	__asm volatile("MSR PRIMASK,R0");
}

void Enable_IRQ()
{
	//// Clear bit PRIMASK
	__asm volatile ("MOV R0,#0x0"); 
	__asm volatile ("MSR PRIMASK,R0");
}
	


void Systick_Timer_Init(uint32_t Milisecond,uint32_t System_Clock_Value)
{
    uint32_t *Pointer = (uint32_t *)0xE000E014;
    uint32_t *Pointer2 = (uint32_t *)0xE000E010;
    uint32_t Count_Value = Milisecond*(System_Clock_Value/1000);
    *Pointer = Count_Value;
    *Pointer2 |= 0x06;
    *Pointer2 |= 0x01;
}

void NVIC_Enable_IRQ(uint8_t IRQ_Number)
{
	
  NVIC->SetEnable_IRQ[IRQ_Number/32] |= (uint32_t)(1<<(IRQ_Number-(IRQ_Number/32)*32));
}

void NVIC_Disable_IRQ(uint8_t IRQ_Number)
{
    NVIC->ClearEnable_IRQ[IRQ_Number/32] |= (uint32_t)(1<<(IRQ_Number-(IRQ_Number/32)*32));
}

void NVIC_SetPending_IRQ(uint8_t IRQ_Number)
{
    NVIC->SetPending_IRQ[IRQ_Number/32] |= (uint32_t)(1<<(IRQ_Number-(IRQ_Number/32)*32));
}

void NVIC_Grouping_IRQ(uint8_t NumberBit_PreEmption)
{
	if(NumberBit_PreEmption <8)
	{
		uint32_t *Pointer = (uint32_t *)0xE000ED0C;
		uint32_t Data =*Pointer;
		Data &= ~(0xFFFF0700);
		Data |= (uint32_t)0x05FA0000|(uint32_t)((7-NumberBit_PreEmption)<<8) ;
		*Pointer = Data;
	}
}

void NVIC_SetPriority_IRQ(uint8_t IRQ_Number, uint8_t Priority_Value)
{
    uint32_t * Pointer = (uint32_t *)0xE000ED0C;
    uint8_t NumberBit_PreEmption = (uint8_t)(7 - (uint32_t)((*Pointer&0x0700)>>8));
    if (Priority_Value <= pow(2,NumberBit_PreEmption) && NumberBit_PreEmption < 8)
    {
        NVIC->IRQPriority[IRQ_Number] |= (uint8_t)(Priority_Value<<(7-NumberBit_PreEmption));
    }
}

void System_Pending_PENSV()
{
	uint32_t *Pointer = (uint32_t *)0xE000ED04;
	*Pointer |= (1<<28);
}




