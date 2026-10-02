SECTIONS
{
    HIDDEN(__romPos = 0);
    _gp = 0x800506F8;
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header : AT(header_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        header_DATA_START = .;
        build/USA/asm/USA/main/header.s.o(.data);
        header_DATA_END = .;
        header_DATA_SIZE = ABSOLUTE(header_DATA_END - header_DATA_START);
    }
    __romPos += SIZEOF(.header);
    header_ROM_END = __romPos;
    header_VRAM_END = .;

    main_ROM_START = __romPos;
    main_VRAM = ADDR(.main);
    .main 0x80010000 : AT(main_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        main_RODATA_START = .;
        build/USA/asm/USA/main/data/800.rodata.s.o(.rodata);
        build/USA/src/main/156C.c.o(.rodata);
        build/USA/src/main/187C.c.o(.rodata);
        build/USA/src/main/307C.c.o(.rodata);
        build/USA/src/main/4BCC.c.o(.rodata);
        build/USA/src/main/6530.c.o(.rodata);
        build/USA/src/main/77DC.c.o(.rodata);
        build/USA/src/main/E280.c.o(.rodata);
        build/USA/src/main/12550.c.o(.rodata);
        build/USA/src/main/12654.c.o(.rodata);
        build/USA/src/main/13584.c.o(.rodata);
        build/USA/src/main/psyq.c.o(.rodata);
        . = ALIGN(., 4);
        main_RODATA_END = .;
        main_RODATA_SIZE = ABSOLUTE(main_RODATA_END - main_RODATA_START);
        main_TEXT_START = .;
        build/USA/src/main/156C.c.o(.text);
        build/USA/src/main/187C.c.o(.text);
        build/USA/src/main/307C.c.o(.text);
        build/USA/src/main/4BCC.c.o(.text);
        build/USA/src/main/6530.c.o(.text);
        build/USA/src/main/77DC.c.o(.text);
        build/USA/src/main/E280.c.o(.text);
        build/USA/src/main/12550.c.o(.text);
        build/USA/src/main/12654.c.o(.text);
        build/USA/src/main/13584.c.o(.text);
        build/USA/src/main/psyq.c.o(.text);
        . = ALIGN(., 4);
        main_TEXT_END = .;
        main_TEXT_SIZE = ABSOLUTE(main_TEXT_END - main_TEXT_START);
        main_DATA_START = .;
        build/USA/asm/USA/main/data/800.rodata.s.o(.data);
        build/USA/src/main/156C.c.o(.data);
        build/USA/src/main/187C.c.o(.data);
        build/USA/src/main/307C.c.o(.data);
        build/USA/src/main/4BCC.c.o(.data);
        build/USA/src/main/6530.c.o(.data);
        build/USA/src/main/77DC.c.o(.data);
        build/USA/src/main/E280.c.o(.data);
        build/USA/src/main/12550.c.o(.data);
        build/USA/src/main/12654.c.o(.data);
        build/USA/src/main/13584.c.o(.data);
        build/USA/src/main/psyq.c.o(.data);
        build/USA/asm/USA/main/data/31570.data.s.o(.data);
        . = ALIGN(., 4);
        main_DATA_END = .;
        main_DATA_SIZE = ABSOLUTE(main_DATA_END - main_DATA_START);
    }
    main_bss_VRAM = ADDR(.main_bss);
    .main_bss (NOLOAD) : SUBALIGN(4)
    {
        FILL(0x00000000);
        main_BSS_START = .;
        build/USA/asm/USA/main/data/800.rodata.s.o(.bss);
        build/USA/src/main/156C.c.o(.bss);
        build/USA/src/main/187C.c.o(.bss);
        build/USA/src/main/307C.c.o(.bss);
        build/USA/src/main/4BCC.c.o(.bss);
        build/USA/src/main/6530.c.o(.bss);
        build/USA/src/main/77DC.c.o(.bss);
        build/USA/src/main/E280.c.o(.bss);
        build/USA/src/main/12550.c.o(.bss);
        build/USA/src/main/12654.c.o(.bss);
        build/USA/src/main/13584.c.o(.bss);
        build/USA/src/main/psyq.c.o(.bss);
        . = ALIGN(., 4);
        main_BSS_END = .;
        main_BSS_SIZE = ABSOLUTE(main_BSS_END - main_BSS_START);
    }
    __romPos += SIZEOF(.main);
    __romPos = ALIGN(__romPos, 4);
    . = ALIGN(., 4);
    main_ROM_END = __romPos;
    main_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
