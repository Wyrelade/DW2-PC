nonmatching Enemy_GetSetSummary, 0xBC

glabel Enemy_GetSetSummary
    /* E368 8001DB68 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E36C 8001DB6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* E370 8001DB70 1400BFAF */  sw         $ra, 0x14($sp)
    /* E374 8001DB74 C676000C */  jal        Enemy_FindSetById
    /* E378 8001DB78 2180A000 */   addu      $s0, $a1, $zero
    /* E37C 8001DB7C 02004384 */  lh         $v1, 0x2($v0)
    /* E380 8001DB80 00000000 */  nop
    /* E384 8001DB84 000003AE */  sw         $v1, 0x0($s0)
    /* E388 8001DB88 0000438C */  lw         $v1, 0x0($v0)
    /* E38C 8001DB8C 00000000 */  nop
    /* E390 8001DB90 001D0300 */  sll        $v1, $v1, 20
    /* E394 8001DB94 031F0300 */  sra        $v1, $v1, 28
    /* E398 8001DB98 040003AE */  sw         $v1, 0x4($s0)
    /* E39C 8001DB9C 0000438C */  lw         $v1, 0x0($v0)
    /* E3A0 8001DBA0 00000000 */  nop
    /* E3A4 8001DBA4 001C0300 */  sll        $v1, $v1, 16
    /* E3A8 8001DBA8 031F0300 */  sra        $v1, $v1, 28
    /* E3AC 8001DBAC 080003AE */  sw         $v1, 0x8($s0)
    /* E3B0 8001DBB0 04004390 */  lbu        $v1, 0x4($v0)
    /* E3B4 8001DBB4 00000000 */  nop
    /* E3B8 8001DBB8 0C0003AE */  sw         $v1, 0xC($s0)
    /* E3BC 8001DBBC 0400438C */  lw         $v1, 0x4($v0)
    /* E3C0 8001DBC0 00000000 */  nop
    /* E3C4 8001DBC4 021A0300 */  srl        $v1, $v1, 8
    /* E3C8 8001DBC8 0F006330 */  andi       $v1, $v1, 0xF
    /* E3CC 8001DBCC 100003AE */  sw         $v1, 0x10($s0)
    /* E3D0 8001DBD0 0400438C */  lw         $v1, 0x4($v0)
    /* E3D4 8001DBD4 21204000 */  addu       $a0, $v0, $zero
    /* E3D8 8001DBD8 021B0300 */  srl        $v1, $v1, 12
    /* E3DC 8001DBDC 0F006330 */  andi       $v1, $v1, 0xF
    /* E3E0 8001DBE0 140003AE */  sw         $v1, 0x14($s0)
    /* E3E4 8001DBE4 06008284 */  lh         $v0, 0x6($a0)
    /* E3E8 8001DBE8 21280000 */  addu       $a1, $zero, $zero
    /* E3EC 8001DBEC 180002AE */  sw         $v0, 0x18($s0)
  .L8001DBF0:
    /* E3F0 8001DBF0 08008294 */  lhu        $v0, 0x8($a0)
    /* E3F4 8001DBF4 0100A524 */  addiu      $a1, $a1, 0x1
    /* E3F8 8001DBF8 1C0002A6 */  sh         $v0, 0x1C($s0)
    /* E3FC 8001DBFC 12008290 */  lbu        $v0, 0x12($a0)
    /* E400 8001DC00 1E008424 */  addiu      $a0, $a0, 0x1E
    /* E404 8001DC04 220002A6 */  sh         $v0, 0x22($s0)
    /* E408 8001DC08 0300A228 */  slti       $v0, $a1, 0x3
    /* E40C 8001DC0C F8FF4014 */  bnez       $v0, .L8001DBF0
    /* E410 8001DC10 02001026 */   addiu     $s0, $s0, 0x2
    /* E414 8001DC14 1400BF8F */  lw         $ra, 0x14($sp)
    /* E418 8001DC18 1000B08F */  lw         $s0, 0x10($sp)
    /* E41C 8001DC1C 0800E003 */  jr         $ra
    /* E420 8001DC20 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Enemy_GetSetSummary
