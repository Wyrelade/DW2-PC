nonmatching Stg40_PlayerOpenChest, 0xD8

glabel Stg40_PlayerOpenChest
    /* 72B4 8006A614 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 72B8 8006A618 602B458C */  lw         $a1, %lo(Stg40_RootState)($v0)
    /* 72BC 8006A61C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 72C0 8006A620 1000B0AF */  sw         $s0, 0x10($sp)
    /* 72C4 8006A624 21808000 */  addu       $s0, $a0, $zero
    /* 72C8 8006A628 1400B1AF */  sw         $s1, 0x14($sp)
    /* 72CC 8006A62C 01001124 */  addiu      $s1, $zero, 0x1
    /* 72D0 8006A630 1800BFAF */  sw         $ra, 0x18($sp)
    /* 72D4 8006A634 1800038E */  lw         $v1, 0x18($s0)
    /* 72D8 8006A638 4000A28C */  lw         $v0, 0x40($a1)
    /* 72DC 8006A63C 3C00A48C */  lw         $a0, 0x3C($a1)
    /* 72E0 8006A640 1000468C */  lw         $a2, 0x10($v0)
    /* 72E4 8006A644 09007110 */  beq        $v1, $s1, .L8006A66C
    /* 72E8 8006A648 02006228 */   slti      $v0, $v1, 0x2
    /* 72EC 8006A64C 03004014 */  bnez       $v0, .L8006A65C
    /* 72F0 8006A650 02000224 */   addiu     $v0, $zero, 0x2
    /* 72F4 8006A654 0D006210 */  beq        $v1, $v0, .L8006A68C
    /* 72F8 8006A658 00000000 */   nop
  .L8006A65C:
    /* 72FC 8006A65C 7745000C */  jal        Task_SetState1
    /* 7300 8006A660 04000524 */   addiu     $a1, $zero, 0x4
    /* 7304 8006A664 9FA90108 */  j          .L8006A67C
    /* 7308 8006A668 00000000 */   nop
  .L8006A66C:
    /* 730C 8006A66C 1400838C */  lw         $v1, 0x14($a0)
    /* 7310 8006A670 03000224 */  addiu      $v0, $zero, 0x3
    /* 7314 8006A674 18006214 */  bne        $v1, $v0, .L8006A6D8
    /* 7318 8006A678 00000000 */   nop
  .L8006A67C:
    /* 731C 8006A67C 6045000C */  jal        Task_NextState2
    /* 7320 8006A680 21200002 */   addu      $a0, $s0, $zero
    /* 7324 8006A684 B6A90108 */  j          .L8006A6D8
    /* 7328 8006A688 00000000 */   nop
  .L8006A68C:
    /* 732C 8006A68C 0100C390 */  lbu        $v1, 0x1($a2)
    /* 7330 8006A690 00000000 */  nop
    /* 7334 8006A694 03006010 */  beqz       $v1, .L8006A6A4
    /* 7338 8006A698 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 733C 8006A69C 04006214 */  bne        $v1, $v0, .L8006A6B0
    /* 7340 8006A6A0 00000000 */   nop
  .L8006A6A4:
    /* 7344 8006A6A4 21200002 */  addu       $a0, $s0, $zero
    /* 7348 8006A6A8 B4A90108 */  j          .L8006A6D0
    /* 734C 8006A6AC 15000524 */   addiu     $a1, $zero, 0x15
  .L8006A6B0:
    /* 7350 8006A6B0 5000A48C */  lw         $a0, 0x50($a1)
    /* 7354 8006A6B4 96C4010C */  jal        Stg40_RollTrapDisarm
    /* 7358 8006A6B8 00000000 */   nop
    /* 735C 8006A6BC 03005114 */  bne        $v0, $s1, .L8006A6CC
    /* 7360 8006A6C0 21200002 */   addu      $a0, $s0, $zero
    /* 7364 8006A6C4 B4A90108 */  j          .L8006A6D0
    /* 7368 8006A6C8 15000524 */   addiu     $a1, $zero, 0x15
  .L8006A6CC:
    /* 736C 8006A6CC 16000524 */  addiu      $a1, $zero, 0x16
  .L8006A6D0:
    /* 7370 8006A6D0 7745000C */  jal        Task_SetState1
    /* 7374 8006A6D4 00000000 */   nop
  .L8006A6D8:
    /* 7378 8006A6D8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 737C 8006A6DC 1400B18F */  lw         $s1, 0x14($sp)
    /* 7380 8006A6E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 7384 8006A6E4 0800E003 */  jr         $ra
    /* 7388 8006A6E8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_PlayerOpenChest
