#include "interrupt.h"

extern uint16_t GlobalTickCount; //extern - обозначает, что переменная будет объявленна в другом месте (в файле demonstration.c)
extern uint8_t BtnITCount, BtnITPressCheck;
uint16_t TickDelayCount;

void SysTick_Handler(void){
    TickDelayCount++;
    GlobalTickCount++;
}

void EXTI15_10_IRQHandler(void){
    if(TickDelayCount > 100){
        BtnITCount++;
        BtnITPressCheck = !BtnITPressCheck;
        TickDelayCount = 0;
    }
    if(BtnITCount >= 5){
         BtnITCount = 0;
    }
    SET_BIT(EXTI->PR, EXTI_PR_PR13);
} 

void delay(uint16_t del){
    while(TickDelayCount < del){

    }
    if(TickDelayCount >= del) TickDelayCount = 0;
}