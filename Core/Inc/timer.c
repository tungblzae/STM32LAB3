#include "main.h"
#include "input_reading.h"

void TIM2_IRQHandler(void) {
    if (__HAL_TIM_GET_ITSTATUS(&htim2, TIM_IT_UPDATE) != RESET) {
        button_reading(); // Call the button reading function
        __HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE); // Clear the timer interrupt flag
    }
}
