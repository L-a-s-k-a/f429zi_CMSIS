#include "demonstration.h"

uint16_t GlobalTickCount;
uint8_t flag;
uint8_t BtnITCount, BtnCount, BtnITPressCheck;
uint16_t flicker_frequency;

void blinking_LED_and_turning_on_LED_with_button(void){
    if(GlobalTickCount >= 1000){
        flag = !flag;
        GlobalTickCount = 0;
    } 
    if(flag){
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS7);
    }
    if(!flag){
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR7);
    }


    if(READ_BIT(GPIOC->IDR, GPIO_IDR_ID13) != 0){
        GPIOB->BSRR = GPIO_BSRR_BS14;
    } 
    else{
        GPIOB->BSRR = GPIO_BSRR_BR14;
    }
}


void change_flicker_frequency_with_button_without_interrupt(void){
    if(READ_BIT(GPIOC->IDR, GPIO_IDR_ID13) != 0){
        GPIOB->BSRR = GPIO_BSRR_BS14;
        BtnCount++;
        if(BtnCount >= 5){
            BtnCount = 0;
        }
    } 
    else{
        GPIOB->BSRR = GPIO_BSRR_BR14;
    }

    switch(BtnCount){
        case 1:
            flicker_frequency = 200;
            break;
        case 2:
            flicker_frequency = 500;
            break;
        case 3:
            flicker_frequency = 1200;
            break;
        case 4:
            flicker_frequency = 1800;
            break;
        default:
            flicker_frequency = 1000;
            break;
    }
    if(GlobalTickCount >= flicker_frequency){
        flag = !flag;
        GlobalTickCount = 0;
    } 
    if(flag){
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS7);
    }
    if(!flag){
        SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR7);
    }
}
uint8_t DefState;
void change_flicker_frequency_with_button_interrupt(void){
    if(BtnITPressCheck) GPIOB->BSRR = GPIO_BSRR_BS14;
    else GPIOB->BSRR = GPIO_BSRR_BR14;
    
    switch(BtnITCount){
        case 1:
            flicker_frequency = 200;
            DefState = 0;
            break;
        case 2:
            flicker_frequency = 500;
            DefState = 0;
            break;
        case 3:
            flicker_frequency = 1200;
            DefState = 0;
            break;
        case 4:
            flicker_frequency = 1800;
            DefState = 0;
            break;
        default:
            flicker_frequency = 1000;
            DefState = 1;
            break;
    }

    if(GlobalTickCount >= flicker_frequency){
        flag = !flag;
        GlobalTickCount = 0;
    } 
    if(flag) SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS7);
    if(!flag) SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR7);

    if(DefState) SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS0);
    else SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR0);
}