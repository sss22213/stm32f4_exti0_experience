MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 1M
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 128k
}

SECTIONS
{
    .mytext : 
    {
        KEEP(*(.vector_table))
        *(.text)
        *(.rodata)
        _mydata_lma_start = .;
    } > FLASH

    .mydata : AT(_mydata_lma_start)
    {
        _mydata_vma_start = .;
        *(.data)
        _mydata_vma_end = .;
    } > SRAM

    .mybss : 
    {
        _mybss_vma_start = .;
        *(.bss)
        *(.COMMON)
        _mybss_vma_end = .;
    } > SRAM

    _msp_init = ORIGIN(SRAM) + LENGTH(SRAM);
}