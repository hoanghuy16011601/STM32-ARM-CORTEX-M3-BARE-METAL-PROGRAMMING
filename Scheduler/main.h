/*
 * main.h
 *
 *  Created on: Apr 28, 2024
 *      Author: dell
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE  ((20U)*(1024U))
#define SRAM_END   (SRAM_START + SRAM_SIZE)

//// Stack of system
#define Idle_STACK_START SRAM_END
#define Task1_STACK_START (Idle_STACK_START - 256) ////Idle's Memory is 256Byte
#define Task2_STACK_START (Task1_STACK_START - 512) //// Tasks's memory are 512Byte
#define Task3_STACK_START (Task2_STACK_START - 512)
#define Task4_STACK_START (Task3_STACK_START - 512)
#define Scheduler_STACK_START (Task4_STACK_START - 512)

#define Ready_State 0x00
#define Blocked_State 0x99

void Task_Init(void);

__attribute__ ((naked)) void Init_Scheduler_Stack(void);
__attribute__((naked)) void Switch_SP_To_PSP(void);

void Save_PSP_Value(uint32_t Current_SP_Value);
uint32_t Get_PSP_Value(void);
uint32_t Get_Scheduler_Stack(void);

void Unblock_Task(void);
void Update_NextTask(void);

void SysTick_Handler(void);
__attribute__ ((naked)) void PendSV_Handler(void);

void Idle_Handler(void);
void Task1_Handler(void);
void Task2_Handler(void);
void Task3_Handler(void);
void Task4_Handler(void);

#endif /* MAIN_H_ */
