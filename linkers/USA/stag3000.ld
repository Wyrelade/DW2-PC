SECTIONS
{
    HIDDEN(__romPos = 0);
    _gp = 0x800506F8;
    stag3000_ROM_START = __romPos;
    stag3000_VRAM = ADDR(.stag3000);
    .stag3000 0x80063360 : AT(stag3000_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        stag3000_RODATA_START = .;
        build/USA/asm/USA/stag3000/data/stag3000_rodata.rodata.s.o(.rodata);
        build/USA/src/stag3000/stag3000.c.o(.rodata);
        build/USA/src/stag3000/stag3000_100C.c.o(.rodata);
        build/USA/src/stag3000/stag3000_41D0.c.o(.rodata);
        build/USA/src/stag3000/stag3000_5980.c.o(.rodata);
        build/USA/src/stag3000/stag3000_6A88.c.o(.rodata);
        build/USA/src/stag3000/stag3000_96DC.c.o(.rodata);
        build/USA/src/stag3000/stag3000_9F8C.c.o(.rodata);
        build/USA/src/stag3000/stag3000_AF5C.c.o(.rodata);
        build/USA/src/stag3000/stag3000_C918.c.o(.rodata);
        build/USA/src/stag3000/stag3000_CC70.c.o(.rodata);
        . = ALIGN(., 4);
        stag3000_RODATA_END = .;
        stag3000_RODATA_SIZE = ABSOLUTE(stag3000_RODATA_END - stag3000_RODATA_START);
        stag3000_TEXT_START = .;
        build/USA/src/stag3000/stag3000.c.o(.text);
        build/USA/src/stag3000/stag3000_100C.c.o(.text);
        build/USA/src/stag3000/stag3000_41D0.c.o(.text);
        build/USA/src/stag3000/stag3000_5980.c.o(.text);
        build/USA/src/stag3000/stag3000_6A88.c.o(.text);
        build/USA/src/stag3000/stag3000_96DC.c.o(.text);
        build/USA/src/stag3000/stag3000_9F8C.c.o(.text);
        build/USA/src/stag3000/stag3000_AF5C.c.o(.text);
        build/USA/src/stag3000/stag3000_C918.c.o(.text);
        build/USA/src/stag3000/stag3000_CC70.c.o(.text);
        . = ALIGN(., 4);
        stag3000_TEXT_END = .;
        stag3000_TEXT_SIZE = ABSOLUTE(stag3000_TEXT_END - stag3000_TEXT_START);
        stag3000_DATA_START = .;
        build/USA/asm/USA/stag3000/data/stag3000_rodata.rodata.s.o(.data);
        build/USA/src/stag3000/stag3000.c.o(.data);
        build/USA/src/stag3000/stag3000_100C.c.o(.data);
        build/USA/src/stag3000/stag3000_41D0.c.o(.data);
        build/USA/src/stag3000/stag3000_5980.c.o(.data);
        build/USA/src/stag3000/stag3000_6A88.c.o(.data);
        build/USA/src/stag3000/stag3000_96DC.c.o(.data);
        build/USA/src/stag3000/stag3000_9F8C.c.o(.data);
        build/USA/src/stag3000/stag3000_AF5C.c.o(.data);
        build/USA/src/stag3000/stag3000_C918.c.o(.data);
        build/USA/src/stag3000/stag3000_CC70.c.o(.data);
        build/USA/asm/USA/stag3000/data/stag3000_data.data.s.o(.data);
        . = ALIGN(., 4);
        stag3000_DATA_END = .;
        stag3000_DATA_SIZE = ABSOLUTE(stag3000_DATA_END - stag3000_DATA_START);
    }
    stag3000_bss_VRAM = ADDR(.stag3000_bss);
    .stag3000_bss (NOLOAD) : SUBALIGN(4)
    {
        FILL(0x00000000);
        stag3000_BSS_START = .;
        build/USA/asm/USA/stag3000/data/stag3000_rodata.rodata.s.o(.bss);
        build/USA/src/stag3000/stag3000.c.o(.bss);
        build/USA/src/stag3000/stag3000_100C.c.o(.bss);
        build/USA/src/stag3000/stag3000_41D0.c.o(.bss);
        build/USA/src/stag3000/stag3000_5980.c.o(.bss);
        build/USA/src/stag3000/stag3000_6A88.c.o(.bss);
        build/USA/src/stag3000/stag3000_96DC.c.o(.bss);
        build/USA/src/stag3000/stag3000_9F8C.c.o(.bss);
        build/USA/src/stag3000/stag3000_AF5C.c.o(.bss);
        build/USA/src/stag3000/stag3000_C918.c.o(.bss);
        build/USA/src/stag3000/stag3000_CC70.c.o(.bss);
        . = ALIGN(., 4);
        stag3000_BSS_END = .;
        stag3000_BSS_SIZE = ABSOLUTE(stag3000_BSS_END - stag3000_BSS_START);
    }
    __romPos += SIZEOF(.stag3000);
    __romPos = ALIGN(__romPos, 4);
    . = ALIGN(., 4);
    stag3000_ROM_END = __romPos;
    stag3000_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
