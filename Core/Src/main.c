#include "../Inc/main.h"
#include "../Inc/init.h"
#include "../Inc/demonstration.h"
#include "../Inc/interrupt.h"

int main(void){
    SysTick_Init();
    RCC_Init();
    GPIO_Init();
    ITR_init();

    while(1){
        // blinking_LED_and_turning_on_LED_with_button();
        // change_flicker_frequency_with_button_without_interrupt();
        change_flicker_frequency_with_button_interrupt();

    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS7);
    // delay(1000);
    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR7);
    // delay(1000);
    }
}




