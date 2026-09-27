nonmatching func_8001BB88, 0x9C

glabel func_8001BB88
    /* C388 8001BB88 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C38C 8001BB8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* C390 8001BB90 21808000 */  addu       $s0, $a0, $zero
    /* C394 8001BB94 1800BFAF */  sw         $ra, 0x18($sp)
    /* C398 8001BB98 1400B1AF */  sw         $s1, 0x14($sp)
    /* C39C 8001BB9C 0000028E */  lw         $v0, 0x0($s0)
    /* C3A0 8001BBA0 FFFF1124 */  addiu      $s1, $zero, -0x1
    /* C3A4 8001BBA4 1A005110 */  beq        $v0, $s1, .L8001BC10
    /* C3A8 8001BBA8 09000424 */   addiu     $a0, $zero, 0x9
    /* C3AC 8001BBAC 21282002 */  addu       $a1, $s1, $zero
    /* C3B0 8001BBB0 4445000C */  jal        Task_FindFirst
    /* C3B4 8001BBB4 21302002 */   addu      $a2, $s1, $zero
    /* C3B8 8001BBB8 21204000 */  addu       $a0, $v0, $zero
    /* C3BC 8001BBBC 14008010 */  beqz       $a0, .L8001BC10
    /* C3C0 8001BBC0 00000000 */   nop
    /* C3C4 8001BBC4 0000058E */  lw         $a1, 0x0($s0)
    /* C3C8 8001BBC8 2C00838C */  lw         $v1, 0x2C($a0)
    /* C3CC 8001BBCC 3400848C */  lw         $a0, 0x34($a0)
    /* C3D0 8001BBD0 40100500 */  sll        $v0, $a1, 1
    /* C3D4 8001BBD4 21104500 */  addu       $v0, $v0, $a1
    /* C3D8 8001BBD8 80100200 */  sll        $v0, $v0, 2
    /* C3DC 8001BBDC 21104500 */  addu       $v0, $v0, $a1
    /* C3E0 8001BBE0 80100200 */  sll        $v0, $v0, 2
    /* C3E4 8001BBE4 21186200 */  addu       $v1, $v1, $v0
    /* C3E8 8001BBE8 80280500 */  sll        $a1, $a1, 2
    /* C3EC 8001BBEC 21208500 */  addu       $a0, $a0, $a1
    /* C3F0 8001BBF0 000060A0 */  sb         $zero, 0x0($v1)
    /* C3F4 8001BBF4 0400848C */  lw         $a0, 0x4($a0)
    /* C3F8 8001BBF8 00000000 */  nop
    /* C3FC 8001BBFC 03008010 */  beqz       $a0, .L8001BC0C
    /* C400 8001BC00 00000000 */   nop
    /* C404 8001BC04 7045000C */  jal        Task_SetState0
    /* C408 8001BC08 03000524 */   addiu     $a1, $zero, 0x3
  .L8001BC0C:
    /* C40C 8001BC0C 000011AE */  sw         $s1, 0x0($s0)
  .L8001BC10:
    /* C410 8001BC10 1800BF8F */  lw         $ra, 0x18($sp)
    /* C414 8001BC14 1400B18F */  lw         $s1, 0x14($sp)
    /* C418 8001BC18 1000B08F */  lw         $s0, 0x10($sp)
    /* C41C 8001BC1C 0800E003 */  jr         $ra
    /* C420 8001BC20 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001BB88
