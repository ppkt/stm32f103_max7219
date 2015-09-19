#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

#include "common_lib/utils.h"

#include "common_lib/spi.h"

int main(void)
{
    LED_Init1();
    spi_init(SPI1, true);
    unsigned j = 0;

    u8 tx[2], rx[2];

//    tx[0] = 0x09;
//    tx[1] = 0xFF;
//    spi_send(SPI1, tx, rx, 2);

    tx[0] = 0x09;
    tx[1] = 0x01;
    GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);
    spi_send(SPI1, tx, rx, 2);
    GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);

    tx[0] = 0x0A;
    tx[1] = 0x00;
    GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);
    spi_send(SPI1, tx, rx, 2);
    GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);



    while(1) {
        GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);

//        tx[0] = 0x09;
//        tx[1] = 0xFF;
//        spi_send(SPI1, tx, rx, 2);
        GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);

        for (j = 0; j < 200000; ++j) {}
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
        for (j = 0; j < 200000; ++j) {}
        GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_RESET);

    }
}
