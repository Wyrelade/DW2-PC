build/USA/main.elf: \
    build/USA/asm/USA/main/header.s.o \
    build/USA/asm/USA/main/data/800.rodata.s.o \
    build/USA/src/main/156C.c.o \
    build/USA/src/main/psyq.c.o \
    build/USA/asm/USA/main/data/31570.data.s.o
build/USA/asm/USA/main/header.s.o:
build/USA/asm/USA/main/data/800.rodata.s.o:
build/USA/src/main/156C.c.o:
build/USA/src/main/psyq.c.o:
build/USA/asm/USA/main/data/31570.data.s.o:
-include build/USA/asm/USA/main/header.s.d build/USA/asm/USA/main/data/800.rodata.s.d build/USA/src/main/156C.c.d build/USA/src/main/psyq.c.d build/USA/asm/USA/main/data/31570.data.s.d
