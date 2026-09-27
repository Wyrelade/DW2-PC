nonmatching func_8001A958, 0x70

glabel func_8001A958
    /* B158 8001A958 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B15C 8001A95C 1000B0AF */  sw         $s0, 0x10($sp)
    /* B160 8001A960 21808000 */  addu       $s0, $a0, $zero
    /* B164 8001A964 1400BFAF */  sw         $ra, 0x14($sp)
    /* B168 8001A968 1000028E */  lw         $v0, 0x10($s0)
    /* B16C 8001A96C 00000000 */  nop
    /* B170 8001A970 11004014 */  bnez       $v0, .L8001A9B8
    /* B174 8001A974 00000000 */   nop
    /* B178 8001A978 E072000C */  jal        Gfx_FindOrLoadTexSlot
    /* B17C 8001A97C 3A01043C */   lui       $a0, (0x13A0000 >> 16)
    /* B180 8001A980 0680023C */  lui        $v0, %hi(D_8005F788)
    /* B184 8001A984 88F7428C */  lw         $v0, %lo(D_8005F788)($v0)
    /* B188 8001A988 00050324 */  addiu      $v1, $zero, 0x500
    /* B18C 8001A98C 000F4230 */  andi       $v0, $v0, 0xF00
    /* B190 8001A990 07004310 */  beq        $v0, $v1, .L8001A9B0
    /* B194 8001A994 00000000 */   nop
    /* B198 8001A998 E072000C */  jal        Gfx_FindOrLoadTexSlot
    /* B19C 8001A99C 1001043C */   lui       $a0, (0x1100000 >> 16)
    /* B1A0 8001A9A0 0A000424 */  addiu      $a0, $zero, 0xA
    /* B1A4 8001A9A4 3400058E */  lw         $a1, 0x34($s0)
    /* B1A8 8001A9A8 1F44000C */  jal        Task_Create
    /* B1AC 8001A9AC 21300000 */   addu      $a2, $zero, $zero
  .L8001A9B0:
    /* B1B0 8001A9B0 5145000C */  jal        Task_NextState0
    /* B1B4 8001A9B4 21200002 */   addu      $a0, $s0, $zero
  .L8001A9B8:
    /* B1B8 8001A9B8 1400BF8F */  lw         $ra, 0x14($sp)
    /* B1BC 8001A9BC 1000B08F */  lw         $s0, 0x10($sp)
    /* B1C0 8001A9C0 0800E003 */  jr         $ra
    /* B1C4 8001A9C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001A958
