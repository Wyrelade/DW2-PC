nonmatching Gpu_ClearOt, 0x40

glabel Gpu_ClearOt
    /* D018 8001C818 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D01C 8001C81C 00120400 */  sll        $v0, $a0, 8
    /* D020 8001C820 21104400 */  addu       $v0, $v0, $a0
    /* D024 8001C824 80100200 */  sll        $v0, $v0, 2
    /* D028 8001C828 23104400 */  subu       $v0, $v0, $a0
    /* D02C 8001C82C 00110200 */  sll        $v0, $v0, 4
    /* D030 8001C830 0580043C */  lui        $a0, %hi(Gpu_OtBufs)
    /* D034 8001C834 F84C8424 */  addiu      $a0, $a0, %lo(Gpu_OtBufs)
    /* D038 8001C838 21204400 */  addu       $a0, $v0, $a0
    /* D03C 8001C83C 1000BFAF */  sw         $ra, 0x10($sp)
    /* D040 8001C840 5B9E000C */  jal        ClearOTagR
    /* D044 8001C844 0C100524 */   addiu     $a1, $zero, 0x100C
    /* D048 8001C848 1000BF8F */  lw         $ra, 0x10($sp)
    /* D04C 8001C84C 00000000 */  nop
    /* D050 8001C850 0800E003 */  jr         $ra
    /* D054 8001C854 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Gpu_ClearOt
