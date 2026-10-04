SECTIONS
{
    HIDDEN(__romPos = 0);
    _gp = 0x800506F8;
    stag1000_ROM_START = __romPos;
    stag1000_VRAM = ADDR(.stag1000);
    .stag1000 0x80063360 : AT(stag1000_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        stag1000_RODATA_START = .;
        build/USA/asm/USA/stag1000/data/stag1000_rodata.rodata.s.o(.rodata);
        build/USA/src/stag1000/stag1000.c.o(.rodata);
        build/USA/src/stag1000/stag1000_libpress.c.o(.rodata);
        build/USA/src/stag1000/stag1000_tail.c.o(.rodata);
        . = ALIGN(., 4);
        stag1000_RODATA_END = .;
        stag1000_RODATA_SIZE = ABSOLUTE(stag1000_RODATA_END - stag1000_RODATA_START);
        stag1000_TEXT_START = .;
        build/USA/src/stag1000/stag1000.c.o(.text);
        build/USA/src/stag1000/stag1000_libpress.c.o(.text);
        build/USA/src/stag1000/stag1000_tail.c.o(.text);
        . = ALIGN(., 4);
        stag1000_TEXT_END = .;
        stag1000_TEXT_SIZE = ABSOLUTE(stag1000_TEXT_END - stag1000_TEXT_START);
        stag1000_DATA_START = .;
        build/USA/asm/USA/stag1000/data/stag1000_rodata.rodata.s.o(.data);
        build/USA/src/stag1000/stag1000.c.o(.data);
        build/USA/asm/USA/stag1000/data/stag1000_libpress.data.s.o(.data);
        build/USA/src/stag1000/stag1000_tail.c.o(.data);
        . = ALIGN(., 4);
        stag1000_DATA_END = .;
        stag1000_DATA_SIZE = ABSOLUTE(stag1000_DATA_END - stag1000_DATA_START);
        stag1000_BSS_START = .;
        build/USA/asm/USA/stag1000/data/stag1000_rodata.rodata.s.o(.bss);
        build/USA/src/stag1000/stag1000.c.o(.bss);
        build/USA/src/stag1000/stag1000_libpress.c.o(.bss);
        build/USA/src/stag1000/stag1000_tail.c.o(.bss);
        . = ALIGN(., 4);
        stag1000_BSS_END = .;
        stag1000_BSS_SIZE = ABSOLUTE(stag1000_BSS_END - stag1000_BSS_START);
    }
    __romPos += SIZEOF(.stag1000);
    __romPos = ALIGN(__romPos, 4);
    . = ALIGN(., 4);
    stag1000_ROM_END = __romPos;
    stag1000_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
