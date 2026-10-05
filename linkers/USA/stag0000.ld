SECTIONS
{
    HIDDEN(__romPos = 0);
    _gp = 0x800506F8;
    stag0000_ROM_START = __romPos;
    stag0000_VRAM = ADDR(.stag0000);
    .stag0000 0x80063360 : AT(stag0000_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        stag0000_RODATA_START = .;
        build/USA/asm/USA/stag0000/data/stag0000_rodata.rodata.s.o(.rodata);
        build/USA/src/stag0000/stag0000.c.o(.rodata);
        build/USA/src/stag0000/scrollview.c.o(.rodata);
        build/USA/src/stag0000/dungsel.c.o(.rodata);
        build/USA/src/stag0000/stag0000_1AE4.c.o(.rodata);
        build/USA/src/stag0000/stag0000_39F0.c.o(.rodata);
        build/USA/src/stag0000/stag0000_4668.c.o(.rodata);
        . = ALIGN(., 4);
        stag0000_RODATA_END = .;
        stag0000_RODATA_SIZE = ABSOLUTE(stag0000_RODATA_END - stag0000_RODATA_START);
        stag0000_TEXT_START = .;
        build/USA/src/stag0000/stag0000.c.o(.text);
        build/USA/src/stag0000/scrollview.c.o(.text);
        build/USA/src/stag0000/dungsel.c.o(.text);
        build/USA/src/stag0000/stag0000_1AE4.c.o(.text);
        build/USA/src/stag0000/stag0000_39F0.c.o(.text);
        build/USA/src/stag0000/stag0000_4668.c.o(.text);
        . = ALIGN(., 4);
        stag0000_TEXT_END = .;
        stag0000_TEXT_SIZE = ABSOLUTE(stag0000_TEXT_END - stag0000_TEXT_START);
        stag0000_DATA_START = .;
        build/USA/asm/USA/stag0000/data/stag0000_rodata.rodata.s.o(.data);
        build/USA/src/stag0000/stag0000.c.o(.data);
        build/USA/src/stag0000/scrollview.c.o(.data);
        build/USA/src/stag0000/dungsel.c.o(.data);
        build/USA/src/stag0000/stag0000_1AE4.c.o(.data);
        build/USA/src/stag0000/stag0000_39F0.c.o(.data);
        build/USA/src/stag0000/stag0000_4668.c.o(.data);
        . = ALIGN(., 4);
        stag0000_DATA_END = .;
        stag0000_DATA_SIZE = ABSOLUTE(stag0000_DATA_END - stag0000_DATA_START);
        stag0000_BSS_START = .;
        build/USA/asm/USA/stag0000/data/stag0000_rodata.rodata.s.o(.bss);
        build/USA/src/stag0000/stag0000.c.o(.bss);
        build/USA/src/stag0000/scrollview.c.o(.bss);
        build/USA/src/stag0000/dungsel.c.o(.bss);
        build/USA/src/stag0000/stag0000_1AE4.c.o(.bss);
        build/USA/src/stag0000/stag0000_39F0.c.o(.bss);
        build/USA/src/stag0000/stag0000_4668.c.o(.bss);
        . = ALIGN(., 4);
        stag0000_BSS_END = .;
        stag0000_BSS_SIZE = ABSOLUTE(stag0000_BSS_END - stag0000_BSS_START);
    }
    __romPos += SIZEOF(.stag0000);
    __romPos = ALIGN(__romPos, 4);
    . = ALIGN(., 4);
    stag0000_ROM_END = __romPos;
    stag0000_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
