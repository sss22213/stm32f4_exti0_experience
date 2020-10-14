#include "reg.h"
volatile gpio* gpio_device = (volatile gpio*)(GPIOD);
volatile gpio* gpio_input_device = (volatile gpio*)(GPIOA);
// exti
void exti0_handler()
{
    gpio_device->bsrr |= (1 << 15);
    for (int i = 0; i < 1000000; i++);
    gpio_device->bsrr |= (1 << 31);
    for (int i = 0; i < 100000; i++);
    // clear interrupt flag
    *__REG(EXTI_PR) |= (1 << 0);
}
void gpio_set()
{
    // GPIO input (PA0)
    *__REG(RCC_AHB1) |= (1 << 0);
    gpio_input_device->moder &= ~(0x03);
    gpio_input_device->pupdr |= (1 << 1);
    // EXTI0 (PA0)
    *__REG(EXTI_IMR) |= (1 << 0);
    *__REG(EXTI_FTSR) |= (1 << 0);
    *__REG(EXTI_PR) |= (1 << 0);
    // SYSCFG (PAX)
    *__REG(RCC_APB2ENR) |= (1 << 14);
    *__REG(SYSCFG_EXTICR1) &= ~(0x0F);
    // NVIC_ISER0
    *__REG(NVIC_ISER0) |= (1 << 6);
    // GPIO (LED)
    *__REG(RCC_AHB1) |= (1 << 3);
    //
    gpio_device->moder |= (1 << 30);
    gpio_device->ospeedr |= (1 << 31);
    gpio_device->ospeedr |= (1 << 30);
}

int main(void)
{
    gpio_set();
    // wait interrupt
    while(1);
    return 0;
}