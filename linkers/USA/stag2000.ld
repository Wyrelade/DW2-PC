SECTIONS
{
    HIDDEN(__romPos = 0);
    _gp = 0x800506F8;
    stag2000_ROM_START = __romPos;
    stag2000_VRAM = ADDR(.stag2000);
    .stag2000 0x80063360 : AT(stag2000_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        stag2000_RODATA_START = .;
        build/USA/asm/USA/stag2000/data/stag2000_rodata.rodata.s.o(.rodata);
        build/USA/src/stag2000/stag2000.c.o(.rodata);
        . = ALIGN(., 4);
        stag2000_RODATA_END = .;
        stag2000_RODATA_SIZE = ABSOLUTE(stag2000_RODATA_END - stag2000_RODATA_START);
        stag2000_TEXT_START = .;
        build/USA/src/stag2000/stag2000.c.o(.text);
        . = ALIGN(., 4);
        stag2000_TEXT_END = .;
        stag2000_TEXT_SIZE = ABSOLUTE(stag2000_TEXT_END - stag2000_TEXT_START);
        stag2000_DATA_START = .;
        build/USA/asm/USA/stag2000/data/stag2000_rodata.rodata.s.o(.data);
        build/USA/src/stag2000/stag2000.c.o(.data);
        build/USA/asm/USA/stag2000/data/stag2000_data.data.s.o(.data);
        . = ALIGN(., 4);
        stag2000_DATA_END = .;
        stag2000_DATA_SIZE = ABSOLUTE(stag2000_DATA_END - stag2000_DATA_START);
    }
    stag2000_bss_VRAM = ADDR(.stag2000_bss);
    .stag2000_bss (NOLOAD) : SUBALIGN(4)
    {
        FILL(0x00000000);
        stag2000_BSS_START = .;
        build/USA/asm/USA/stag2000/data/stag2000_rodata.rodata.s.o(.bss);
        build/USA/src/stag2000/stag2000.c.o(.bss);
        . = ALIGN(., 4);
        stag2000_BSS_END = .;
        stag2000_BSS_SIZE = ABSOLUTE(stag2000_BSS_END - stag2000_BSS_START);
    }
    __romPos += SIZEOF(.stag2000);
    __romPos = ALIGN(__romPos, 4);
    . = ALIGN(., 4);
    stag2000_ROM_END = __romPos;
    stag2000_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
