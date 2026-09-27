nonmatching func_800652C8, 0x8C

glabel func_800652C8
    /* 1F68 800652C8 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 1F6C 800652CC 4400B1AF */  sw         $s1, 0x44($sp)
    /* 1F70 800652D0 21888000 */  addu       $s1, $a0, $zero
    /* 1F74 800652D4 6000A28F */  lw         $v0, 0x60($sp)
    /* 1F78 800652D8 2120A000 */  addu       $a0, $a1, $zero
    /* 1F7C 800652DC 4000B0AF */  sw         $s0, 0x40($sp)
    /* 1F80 800652E0 2180C000 */  addu       $s0, $a2, $zero
    /* 1F84 800652E4 4800BFAF */  sw         $ra, 0x48($sp)
    /* 1F88 800652E8 05004014 */  bnez       $v0, .L80065300
    /* 1F8C 800652EC 5C00A7AF */   sw        $a3, 0x5C($sp)
    /* 1F90 800652F0 2178000C */  jal        Item_GetDescText
    /* 1F94 800652F4 00000000 */   nop
    /* 1F98 800652F8 C3940108 */  j          .L8006530C
    /* 1F9C 800652FC 2400A2AF */   sw        $v0, 0x24($sp)
  .L80065300:
    /* 1FA0 80065300 1278000C */  jal        Item_GetNameText
    /* 1FA4 80065304 00000000 */   nop
    /* 1FA8 80065308 2400A2AF */  sw         $v0, 0x24($sp)
  .L8006530C:
    /* 1FAC 8006530C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 1FB0 80065310 1400B0AF */  sw         $s0, 0x14($sp)
    /* 1FB4 80065314 5C00A297 */  lhu        $v0, 0x5C($sp)
    /* 1FB8 80065318 21202002 */  addu       $a0, $s1, $zero
    /* 1FBC 8006531C 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 1FC0 80065320 5E00A397 */  lhu        $v1, 0x5E($sp)
    /* 1FC4 80065324 6400A28F */  lw         $v0, 0x64($sp)
    /* 1FC8 80065328 1000A527 */  addiu      $a1, $sp, 0x10
    /* 1FCC 8006532C 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 1FD0 80065330 2000A0AF */  sw         $zero, 0x20($sp)
    /* 1FD4 80065334 2800A2AF */  sw         $v0, 0x28($sp)
    /* 1FD8 80065338 096F000C */  jal        Text_Open
    /* 1FDC 8006533C 1A00A3A7 */   sh        $v1, 0x1A($sp)
    /* 1FE0 80065340 4800BF8F */  lw         $ra, 0x48($sp)
    /* 1FE4 80065344 4400B18F */  lw         $s1, 0x44($sp)
    /* 1FE8 80065348 4000B08F */  lw         $s0, 0x40($sp)
    /* 1FEC 8006534C 0800E003 */  jr         $ra
    /* 1FF0 80065350 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_800652C8
