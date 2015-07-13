#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

void LED_Init1() {
    //Smaller board

    /* Enable GPIO clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // Use PC8 and PC9 // Discovery LEDs
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void LED_Init2() {
    //Bigger board

    /* Enable GPIO clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // Use PC8 and PC9 // Discovery LEDs
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}


int main(void)
{

    LED_Init1();
    unsigned int j = 0;

    while(1) {
        for (j = 0; j < 2000000; ++j) {}
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
        for (j = 0; j < 2000000; ++j) {}
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
    }
}
