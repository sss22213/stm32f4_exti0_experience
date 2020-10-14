#include <stdint.h>
#include "reg.h"
extern int main(void);

// system init (CLK 168MHZ)
void system_init()
{
    // turn on HSE
    *((volatile uint32_t*)RCC_CR) |= (1 << 16);
    while(!(*((volatile uint32_t*)RCC_CR) >> 17 & 0x01));
    // set PLL
    *((volatile uint32_t*)RCC_PLLCFGR) |= (1 << 22);
    // P (2 => 00)
    *((volatile uint32_t*)RCC_PLLCFGR) &= ~(1 << 16);
    *((volatile uint32_t*)RCC_PLLCFGR) &= ~(1 << 17);
    // N (168 => 10101000)
    *((volatile uint32_t*)RCC_PLLCFGR) |= (0xB8 << 6);
    // M (4 => 000100)
    *((volatile uint32_t*)RCC_PLLCFGR) |= (1 << 2);
    // turn on PLL
    *((volatile uint32_t*)RCC_CR) |= (1 << 24);
    while(!(*((volatile uint32_t*)RCC_CR) >> 25 & 0x01));
    // flash
    *((volatile uint32_t*)FLASH_ACR) |= (1 << 8);
    *((volatile uint32_t*)FLASH_ACR) |= 0x05;
    // set pull as system clock
    *((volatile uint32_t*)RCC_CFGR) |= (1 << 1);
    // wait set
    while(!(*((volatile uint32_t*)RCC_CFGR) >> 2 & 0x03));
}

// reset
void reset_handler(void)
{
    extern uint32_t _mydata_lma_start;
    extern uint32_t _mydata_vma_start;
    extern uint32_t _mydata_vma_end;
    extern uint32_t _mybss_vma_start;
    extern uint32_t _mybss_vma_end;
    // 
    uint32_t *_mydata_lstart_ptr = &_mydata_lma_start;
    uint32_t *_mydata_vstart_ptr = &_mydata_vma_start;
    uint32_t *_mydata_vend_ptr = &_mydata_vma_end;
    uint32_t *_mybss_vstart_ptr = &_mybss_vma_start;
    uint32_t *_mybss_vend_ptr = &_mybss_vma_end;
    // section data, lma to vma
    uint32_t *src, *dst;
    src = _mydata_lstart_ptr;
    dst = _mydata_vstart_ptr;
    while(dst < _mydata_vend_ptr)*dst++ = *src++;
    // section bss, clear
    src = _mybss_vstart_ptr;
    while(src < _mybss_vend_ptr)*src++ = 0;
    system_init();
    main();
}

void hardfault_handler(void)
{
	
}