#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

#include "common_lib/utils.h"

#include "common_lib/spi.h"

#include "device_lib/max7219.h"

int main(void)
{
    LED_Init1();
    setup_delay_timer(TIM2);

    max7219_init();
    max7219_self_test();
    max7219_clear_display();

    max7219_set_led(1, 1);
    max7219_set_led(0, 1);
    max7219_set_led(1, 0);


    max7219_reset_led(1, 1);
    max7219_clear_display();

    uint8_t data[8] = {
        0b00000000,
        0b01100110,
        0b01100110,
        0b00000000,
        0b10000001,
        0b01000010,
        0b00111100,
        0b00000000
    };

    max7219_set_data(data);

    while(1) {
        delay_ms(TIM2, 10);
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
        delay_ms(TIM2, 100);
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);
    }
}
