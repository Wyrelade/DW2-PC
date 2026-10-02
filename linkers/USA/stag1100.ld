SECTIONS
{
    HIDDEN(__romPos = 0);
    _gp = 0x800506F8;
    stag1100_ROM_START = __romPos;
    stag1100_VRAM = ADDR(.stag1100);
    .stag1100 0x80063360 : AT(stag1100_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        stag1100_RODATA_START = .;
        build/USA/asm/USA/stag1100/data/stag1100_rodata.rodata.s.o(.rodata);
        build/USA/src/stag1100/stag1100.c.o(.rodata);
        build/USA/src/stag1100/stag1100_301C.c.o(.rodata);
        . = ALIGN(., 4);
        stag1100_RODATA_END = .;
        stag1100_RODATA_SIZE = ABSOLUTE(stag1100_RODATA_END - stag1100_RODATA_START);
        stag1100_TEXT_START = .;
        build/USA/src/stag1100/stag1100.c.o(.text);
        build/USA/src/stag1100/stag1100_301C.c.o(.text);
        . = ALIGN(., 4);
        stag1100_TEXT_END = .;
        stag1100_TEXT_SIZE = ABSOLUTE(stag1100_TEXT_END - stag1100_TEXT_START);
        stag1100_DATA_START = .;
        build/USA/asm/USA/stag1100/data/stag1100_rodata.rodata.s.o(.data);
        build/USA/src/stag1100/stag1100.c.o(.data);
        build/USA/src/stag1100/stag1100_301C.c.o(.data);
        build/USA/asm/USA/stag1100/data/stag1100_data.data.s.o(.data);
        . = ALIGN(., 4);
        stag1100_DATA_END = .;
        stag1100_DATA_SIZE = ABSOLUTE(stag1100_DATA_END - stag1100_DATA_START);
    }
    stag1100_bss_VRAM = ADDR(.stag1100_bss);
    .stag1100_bss (NOLOAD) : SUBALIGN(4)
    {
        FILL(0x00000000);
        stag1100_BSS_START = .;
        build/USA/asm/USA/stag1100/data/stag1100_rodata.rodata.s.o(.bss);
        build/USA/src/stag1100/stag1100.c.o(.bss);
        build/USA/src/stag1100/stag1100_301C.c.o(.bss);
        . = ALIGN(., 4);
        stag1100_BSS_END = .;
        stag1100_BSS_SIZE = ABSOLUTE(stag1100_BSS_END - stag1100_BSS_START);
    }
    __romPos += SIZEOF(.stag1100);
    __romPos = ALIGN(__romPos, 4);
    . = ALIGN(., 4);
    stag1100_ROM_END = __romPos;
    stag1100_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
