nonmatching func_80013AB0, 0x4C

glabel func_80013AB0
    /* 42B0 80013AB0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 42B4 80013AB4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 42B8 80013AB8 21888000 */  addu       $s1, $a0, $zero
    /* 42BC 80013ABC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 42C0 80013AC0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 42C4 80013AC4 688E000C */  jal        Cd_GetFileEntry
    /* 42C8 80013AC8 2180A000 */   addu      $s0, $a1, $zero
    /* 42CC 80013ACC 03241100 */  sra        $a0, $s1, 16
    /* 42D0 80013AD0 828E000C */  jal        Cd_GetFileOrNull
    /* 42D4 80013AD4 21884000 */   addu      $s1, $v0, $zero
    /* 42D8 80013AD8 80801000 */  sll        $s0, $s0, 2
    /* 42DC 80013ADC 21801102 */  addu       $s0, $s0, $s1
    /* 42E0 80013AE0 0000038E */  lw         $v1, 0x0($s0)
    /* 42E4 80013AE4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 42E8 80013AE8 1400B18F */  lw         $s1, 0x14($sp)
    /* 42EC 80013AEC 1000B08F */  lw         $s0, 0x10($sp)
    /* 42F0 80013AF0 21106200 */  addu       $v0, $v1, $v0
    /* 42F4 80013AF4 0800E003 */  jr         $ra
    /* 42F8 80013AF8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80013AB0
