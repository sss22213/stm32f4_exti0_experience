#ifndef __REG_H_
#define __REG_H_
#define __REG	(volatile uint32_t*)
#include <stdint.h>
typedef struct gpio gpio;
// RCC
#define RCC_BASE 0x40023800
#define RCC_CR (RCC_BASE)
#define RCC_PLLCFGR (RCC_BASE + 0x04)
#define RCC_CFGR (RCC_BASE + 0x08)
#define RCC_AHB1 (RCC_BASE + 0x30)
#define RCC_APB2ENR (RCC_BASE + 0x44)

// FLASH
#define FLASH_BASE 0x40023C00
#define FLASH_ACR (FLASH_BASE)

// GPIO
#define GPIO_BASE 0x40020000
#define GPIOA (GPIO_BASE + 0x000)
#define GPIOB (GPIO_BASE + 0x400)
#define GPIOC (GPIO_BASE + 0x800)
#define GPIOD (GPIO_BASE + 0xC00)

// EXTI
#define EXTI_BASE 0x40013C00
#define EXTI_IMR EXTI_BASE
#define EXTI_EMR (EXTI_BASE + 0x04)
#define EXTI_RTSR (EXTI_BASE + 0x08)
#define EXTI_FTSR (EXTI_BASE + 0x0C)
#define EXTI_SWIER (EXTI_BASE + 0x10)
#define EXTI_PR (EXTI_BASE + 0x14)

// SYSCFG
#define SYSCFG_BASE 0x40013800
#define SYSCFG_EXTICR1 (SYSCFG_BASE + 0x08)

// NVIC
#define NVIC_ISER0 0xE000E100

typedef struct gpio
{
	uint32_t moder;
	uint32_t otyper;
	uint32_t ospeedr;
	uint32_t pupdr;
	uint32_t idr;
	uint32_t odr;
	uint32_t bsrr;
}gpio;

#endif
