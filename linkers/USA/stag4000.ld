SECTIONS
{
    HIDDEN(__romPos = 0);
    _gp = 0x800506F8;
    stag4000_ROM_START = __romPos;
    stag4000_VRAM = ADDR(.stag4000);
    .stag4000 0x80063360 : AT(stag4000_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        stag4000_RODATA_START = .;
        build/USA/asm/USA/stag4000/data/stag4000_rodata.rodata.s.o(.rodata);
        build/USA/src/stag4000/stag4000.c.o(.rodata);
        build/USA/src/stag4000/linkedmodel.c.o(.rodata);
        build/USA/src/stag4000/floor.c.o(.rodata);
        build/USA/src/stag4000/hud.c.o(.rodata);
        build/USA/src/stag4000/bitswin.c.o(.rodata);
        build/USA/src/stag4000/itemmenu.c.o(.rodata);
        build/USA/src/stag4000/enemyinfo.c.o(.rodata);
        build/USA/src/stag4000/msgwin.c.o(.rodata);
        build/USA/src/stag4000/obj.c.o(.rodata);
        build/USA/src/stag4000/player.c.o(.rodata);
        build/USA/src/stag4000/stag4000_8338.c.o(.rodata);
        build/USA/src/stag4000/stag4000_9364.c.o(.rodata);
        build/USA/src/stag4000/stag4000_A180.c.o(.rodata);
        build/USA/src/stag4000/stag4000_C2CC.c.o(.rodata);
        . = ALIGN(., 4);
        stag4000_RODATA_END = .;
        stag4000_RODATA_SIZE = ABSOLUTE(stag4000_RODATA_END - stag4000_RODATA_START);
        stag4000_TEXT_START = .;
        build/USA/src/stag4000/stag4000.c.o(.text);
        build/USA/src/stag4000/linkedmodel.c.o(.text);
        build/USA/src/stag4000/floor.c.o(.text);
        build/USA/src/stag4000/hud.c.o(.text);
        build/USA/src/stag4000/bitswin.c.o(.text);
        build/USA/src/stag4000/itemmenu.c.o(.text);
        build/USA/src/stag4000/enemyinfo.c.o(.text);
        build/USA/src/stag4000/msgwin.c.o(.text);
        build/USA/src/stag4000/obj.c.o(.text);
        build/USA/src/stag4000/player.c.o(.text);
        build/USA/src/stag4000/stag4000_8338.c.o(.text);
        build/USA/src/stag4000/stag4000_9364.c.o(.text);
        build/USA/src/stag4000/stag4000_A180.c.o(.text);
        build/USA/src/stag4000/stag4000_C2CC.c.o(.text);
        . = ALIGN(., 4);
        stag4000_TEXT_END = .;
        stag4000_TEXT_SIZE = ABSOLUTE(stag4000_TEXT_END - stag4000_TEXT_START);
        stag4000_DATA_START = .;
        build/USA/asm/USA/stag4000/data/stag4000_rodata.rodata.s.o(.data);
        build/USA/src/stag4000/stag4000.c.o(.data);
        build/USA/src/stag4000/linkedmodel.c.o(.data);
        build/USA/src/stag4000/floor.c.o(.data);
        build/USA/src/stag4000/hud.c.o(.data);
        build/USA/src/stag4000/bitswin.c.o(.data);
        build/USA/src/stag4000/itemmenu.c.o(.data);
        build/USA/src/stag4000/enemyinfo.c.o(.data);
        build/USA/src/stag4000/msgwin.c.o(.data);
        build/USA/src/stag4000/obj.c.o(.data);
        build/USA/src/stag4000/player.c.o(.data);
        build/USA/src/stag4000/stag4000_8338.c.o(.data);
        build/USA/src/stag4000/stag4000_9364.c.o(.data);
        build/USA/src/stag4000/stag4000_A180.c.o(.data);
        build/USA/src/stag4000/stag4000_C2CC.c.o(.data);
        . = ALIGN(., 4);
        stag4000_DATA_END = .;
        stag4000_DATA_SIZE = ABSOLUTE(stag4000_DATA_END - stag4000_DATA_START);
        stag4000_BSS_START = .;
        build/USA/asm/USA/stag4000/data/stag4000_rodata.rodata.s.o(.bss);
        build/USA/src/stag4000/stag4000.c.o(.bss);
        build/USA/src/stag4000/linkedmodel.c.o(.bss);
        build/USA/src/stag4000/floor.c.o(.bss);
        build/USA/src/stag4000/hud.c.o(.bss);
        build/USA/src/stag4000/bitswin.c.o(.bss);
        build/USA/src/stag4000/itemmenu.c.o(.bss);
        build/USA/src/stag4000/enemyinfo.c.o(.bss);
        build/USA/src/stag4000/msgwin.c.o(.bss);
        build/USA/src/stag4000/obj.c.o(.bss);
        build/USA/src/stag4000/player.c.o(.bss);
        build/USA/src/stag4000/stag4000_8338.c.o(.bss);
        build/USA/src/stag4000/stag4000_9364.c.o(.bss);
        build/USA/src/stag4000/stag4000_A180.c.o(.bss);
        build/USA/src/stag4000/stag4000_C2CC.c.o(.bss);
        . = ALIGN(., 4);
        stag4000_BSS_END = .;
        stag4000_BSS_SIZE = ABSOLUTE(stag4000_BSS_END - stag4000_BSS_START);
    }
    __romPos += SIZEOF(.stag4000);
    __romPos = ALIGN(__romPos, 4);
    . = ALIGN(., 4);
    stag4000_ROM_END = __romPos;
    stag4000_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
