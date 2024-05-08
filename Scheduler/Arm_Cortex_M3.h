#ifndef _ARM_CORTEX_M3_H
#define _ARM_CORTEX_M3_H
#include <stdint.h>

/// IRQ Number
#define WWDG            0U
#define PVD             1U
#define TAMPER          2U
#define RTC             3U
#define FLASH           4U
#define RCC             5U
#define EXTI0           6U
#define EXTI1           7U
#define EXTI2           8U
#define EXTI3           9U
#define EXTI4           10U
#define DMA1_Channel1   11U
#define DMA1_Channel2   12U
#define DMA1_Channel3   13U
#define DMA1_Channel4   14U
#define DMA1_Channel5   15U
#define DMA1_Channel6   16U
#define DMA1_Channel7   17U
#define ADC1_2          18U
#define CAN1_TX         19U
#define CAN1_RX0        20U
#define CAN1_RX1        21U
#define CAN1_SCE        22U
#define EXTI9_5         23U
#define TIM1_BRK        24U
#define TIM1_UP         25U
#define TIM1_TRG_COM    26U
#define TIM1_CC         27U
#define TIM2            28U
#define TIM3            29U
#define TIM4            30U
#define I2C1_EV         31U
#define I2C1_ER         32U
#define I2C2_EV         33U
#define I2C2_ER         34U
#define SP1             35U
#define SP2             36U
#define USART1          37U
#define USART2          38U
#define USART3          39U
#define EXTI15_10       40U
#define RTCAlarm        41U
#define OTG_FS_WKUP     42U




typedef struct 
{
    volatile uint32_t SetEnable_IRQ[8u];
    volatile uint32_t Reserved0[24u];
    volatile uint32_t ClearEnable_IRQ[8u];
		volatile uint32_t Reserved1[24u];
    volatile uint32_t SetPending_IRQ[8u];
    volatile uint32_t Reserved2[24u];
    volatile uint32_t ClearPending_IRQ[8u];
    volatile uint32_t Reserved3[24u];
    volatile uint32_t ActiveBit[8u];
    volatile uint32_t Reserved4[56u];
    volatile uint8_t  IRQPriority[240u];
}NVIC_Struct;

#define NVIC ((NVIC_Struct *)0xE000E100)


#endif

