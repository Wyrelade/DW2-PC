nonmatching _spu_FsetRXXa, 0xA4

glabel _spu_FsetRXXa
    /* 2B324 8003AB24 0580023C */  lui        $v0, %hi(D_8004FE4C)
    /* 2B328 8003AB28 4CFE428C */  lw         $v0, %lo(D_8004FE4C)($v0)
    /* 2B32C 8003AB2C 00000000 */  nop
    /* 2B330 8003AB30 10004010 */  beqz       $v0, .L8003AB74
    /* 2B334 8003AB34 21308000 */   addu      $a2, $a0, $zero
    /* 2B338 8003AB38 0580043C */  lui        $a0, %hi(D_8004FE54)
    /* 2B33C 8003AB3C 54FE848C */  lw         $a0, %lo(D_8004FE54)($a0)
    /* 2B340 8003AB40 00000000 */  nop
    /* 2B344 8003AB44 1B00A400 */  divu       $zero, $a1, $a0
    /* 2B348 8003AB48 02008014 */  bnez       $a0, .L8003AB54
    /* 2B34C 8003AB4C 00000000 */   nop
    /* 2B350 8003AB50 0D000700 */  break      7
  .L8003AB54:
    /* 2B354 8003AB54 10100000 */  mfhi       $v0
    /* 2B358 8003AB58 06004010 */  beqz       $v0, .L8003AB74
    /* 2B35C 8003AB5C 00000000 */   nop
    /* 2B360 8003AB60 0580023C */  lui        $v0, %hi(D_8004FE58)
    /* 2B364 8003AB64 58FE428C */  lw         $v0, %lo(D_8004FE58)($v0)
    /* 2B368 8003AB68 2128A400 */  addu       $a1, $a1, $a0
    /* 2B36C 8003AB6C 27100200 */  nor        $v0, $zero, $v0
    /* 2B370 8003AB70 2428A200 */  and        $a1, $a1, $v0
  .L8003AB74:
    /* 2B374 8003AB74 0580023C */  lui        $v0, %hi(D_8004FE50)
    /* 2B378 8003AB78 50FE428C */  lw         $v0, %lo(D_8004FE50)($v0)
    /* 2B37C 8003AB7C 00000000 */  nop
    /* 2B380 8003AB80 06384500 */  srlv       $a3, $a1, $v0
    /* 2B384 8003AB84 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 2B388 8003AB88 0600C210 */  beq        $a2, $v0, .L8003ABA4
    /* 2B38C 8003AB8C 2118E000 */   addu      $v1, $a3, $zero
    /* 2B390 8003AB90 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2B394 8003AB94 0500C214 */  bne        $a2, $v0, .L8003ABAC
    /* 2B398 8003AB98 2110A000 */   addu      $v0, $a1, $zero
    /* 2B39C 8003AB9C F0EA0008 */  j          .L8003ABC0
    /* 2B3A0 8003ABA0 FFFF6230 */   andi      $v0, $v1, 0xFFFF
  .L8003ABA4:
    /* 2B3A4 8003ABA4 F0EA0008 */  j          .L8003ABC0
    /* 2B3A8 8003ABA8 2110A000 */   addu      $v0, $a1, $zero
  .L8003ABAC:
    /* 2B3AC 8003ABAC 0580043C */  lui        $a0, %hi(D_8004FE28)
    /* 2B3B0 8003ABB0 28FE848C */  lw         $a0, %lo(D_8004FE28)($a0)
    /* 2B3B4 8003ABB4 40180600 */  sll        $v1, $a2, 1
    /* 2B3B8 8003ABB8 21186400 */  addu       $v1, $v1, $a0
    /* 2B3BC 8003ABBC 000067A4 */  sh         $a3, 0x0($v1)
  .L8003ABC0:
    /* 2B3C0 8003ABC0 0800E003 */  jr         $ra
    /* 2B3C4 8003ABC4 00000000 */   nop
endlabel _spu_FsetRXXa
