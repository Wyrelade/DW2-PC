SECTIONS
{
    HIDDEN(__romPos = 0);
    _gp = 0x800506F8;
    stag3500_ROM_START = __romPos;
    stag3500_VRAM = ADDR(.stag3500);
    .stag3500 0x80063360 : AT(stag3500_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        stag3500_RODATA_START = .;
        build/USA/asm/USA/stag3500/data/stag3500_rodata.rodata.s.o(.rodata);
        build/USA/src/stag3500/stag3500.c.o(.rodata);
        build/USA/src/stag3500/stag3500_2334.c.o(.rodata);
        build/USA/src/stag3500/stag3500_5F0C.c.o(.rodata);
        . = ALIGN(., 4);
        stag3500_RODATA_END = .;
        stag3500_RODATA_SIZE = ABSOLUTE(stag3500_RODATA_END - stag3500_RODATA_START);
        stag3500_TEXT_START = .;
        build/USA/src/stag3500/stag3500.c.o(.text);
        build/USA/src/stag3500/stag3500_2334.c.o(.text);
        build/USA/src/stag3500/stag3500_5F0C.c.o(.text);
        . = ALIGN(., 4);
        stag3500_TEXT_END = .;
        stag3500_TEXT_SIZE = ABSOLUTE(stag3500_TEXT_END - stag3500_TEXT_START);
        stag3500_DATA_START = .;
        build/USA/asm/USA/stag3500/data/stag3500_rodata.rodata.s.o(.data);
        build/USA/src/stag3500/stag3500.c.o(.data);
        build/USA/src/stag3500/stag3500_2334.c.o(.data);
        build/USA/src/stag3500/stag3500_5F0C.c.o(.data);
        build/USA/asm/USA/stag3500/data/stag3500_data.data.s.o(.data);
        . = ALIGN(., 4);
        stag3500_DATA_END = .;
        stag3500_DATA_SIZE = ABSOLUTE(stag3500_DATA_END - stag3500_DATA_START);
    }
    stag3500_bss_VRAM = ADDR(.stag3500_bss);
    .stag3500_bss (NOLOAD) : SUBALIGN(4)
    {
        FILL(0x00000000);
        stag3500_BSS_START = .;
        build/USA/asm/USA/stag3500/data/stag3500_rodata.rodata.s.o(.bss);
        build/USA/src/stag3500/stag3500.c.o(.bss);
        build/USA/src/stag3500/stag3500_2334.c.o(.bss);
        build/USA/src/stag3500/stag3500_5F0C.c.o(.bss);
        . = ALIGN(., 4);
        stag3500_BSS_END = .;
        stag3500_BSS_SIZE = ABSOLUTE(stag3500_BSS_END - stag3500_BSS_START);
    }
    __romPos += SIZEOF(.stag3500);
    __romPos = ALIGN(__romPos, 4);
    . = ALIGN(., 4);
    stag3500_ROM_END = __romPos;
    stag3500_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
