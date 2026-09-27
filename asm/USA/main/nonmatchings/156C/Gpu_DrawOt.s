nonmatching Gpu_DrawOt, 0x40

glabel Gpu_DrawOt
    /* D058 8001C858 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D05C 8001C85C 00120400 */  sll        $v0, $a0, 8
    /* D060 8001C860 21104400 */  addu       $v0, $v0, $a0
    /* D064 8001C864 80100200 */  sll        $v0, $v0, 2
    /* D068 8001C868 23104400 */  subu       $v0, $v0, $a0
    /* D06C 8001C86C 00110200 */  sll        $v0, $v0, 4
    /* D070 8001C870 0680033C */  lui        $v1, %hi(D_80058D28)
    /* D074 8001C874 288D6324 */  addiu      $v1, $v1, %lo(D_80058D28)
    /* D078 8001C878 21104300 */  addu       $v0, $v0, $v1
    /* D07C 8001C87C 1000BFAF */  sw         $ra, 0x10($sp)
    /* D080 8001C880 9D9E000C */  jal        DrawOTag
    /* D084 8001C884 FCFF4424 */   addiu     $a0, $v0, -0x4
    /* D088 8001C888 1000BF8F */  lw         $ra, 0x10($sp)
    /* D08C 8001C88C 00000000 */  nop
    /* D090 8001C890 0800E003 */  jr         $ra
    /* D094 8001C894 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Gpu_DrawOt
