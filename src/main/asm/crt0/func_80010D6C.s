/*
 * Not a function: two data words in .text between library objects
 * (0x0A5D, 0): a data word the linker placed before the entry point.
 */

dlabel func_80010D6C
    .word 0x00000A5D
    .word 0x00000000
enddlabel func_80010D6C
