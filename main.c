#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

#include "common_lib/utils.h"

int main(void)
{
    LED_Init1();
    unsigned j = 0;

    while(1) {
        for (j = 0; j < 200000; ++j) {}
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
        for (j = 0; j < 200000; ++j) {}
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
    }
}
