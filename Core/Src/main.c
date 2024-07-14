#include "../Inc/main.h"
#include "../Inc/init.h"
#include "../Inc/demonstration.h"
#include "../Inc/interrupt.h"

uint8_t BtnNum;

int main(void){
    SysTick_Init();
    RCC_Init();
    GPIO_Init();
    ITR_init();

    while(1){
        // blinking_LED_and_turning_on_LED_with_button();
        // change_flicker_frequency_with_button_without_interrupt();
        change_flicker_frequency_with_button_interrupt();
        if(READ_BIT(GPIOF->IDR, GPIO_IDR_ID13) != 0){
            BtnNum = 0;
            MODIFY_REG(SYSCFG->EXTICR[3], SYSCFG_EXTICR4_EXTI13_Msk, SYSCFG_EXTICR4_EXTI13_PF);
        } 
        if(READ_BIT(GPIOC->IDR, GPIO_IDR_ID13) != 0){
            BtnNum = 1;
            MODIFY_REG(SYSCFG->EXTICR[3], SYSCFG_EXTICR4_EXTI13_Msk, SYSCFG_EXTICR4_EXTI13_PC);
        }
        

    }
}




