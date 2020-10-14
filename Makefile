CROSS-COMPILER = arm-none-eabi-

.PHONY: clean flash

all: clean blink.bin

blink.bin: blink.c
	${CROSS-COMPILER}gcc -Wall -g -std=c11 -mcpu=cortex-m4 -nostartfiles -T stm32f4.ld startup.c vector_table.s blink.c -o blink.elf
	${CROSS-COMPILER}objcopy -O binary blink.elf blink.bin

clean:
	rm -f *.o *.elf *.bin

flash:
	st-flash --reset write blink.bin 0x8000000

erase:
	st-flash --reset erase
