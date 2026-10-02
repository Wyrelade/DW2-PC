nonmatching MemCardExist, 0x68

glabel MemCardExist
    /* 2E5B0 8003DDB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E5B4 8003DDB4 0680033C */  lui        $v1, %hi(D_80062F80)
    /* 2E5B8 8003DDB8 802F6324 */  addiu      $v1, $v1, %lo(D_80062F80)
    /* 2E5BC 8003DDBC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2E5C0 8003DDC0 0000628C */  lw         $v0, 0x0($v1)
    /* 2E5C4 8003DDC4 00000000 */  nop
    /* 2E5C8 8003DDC8 0B00401C */  bgtz       $v0, .L8003DDF8
    /* 2E5CC 8003DDCC 21288000 */   addu      $a1, $a0, $zero
    /* 2E5D0 8003DDD0 0480043C */  lui        $a0, %hi(Card_InfoTask)
    /* 2E5D4 8003DDD4 18DE8424 */  addiu      $a0, $a0, %lo(Card_InfoTask)
    /* 2E5D8 8003DDD8 01000224 */  addiu      $v0, $zero, 0x1
    /* 2E5DC 8003DDDC 000062AC */  sw         $v0, 0x0($v1)
    /* 2E5E0 8003DDE0 040060AC */  sw         $zero, 0x4($v1)
    /* 2E5E4 8003DDE4 080060AC */  sw         $zero, 0x8($v1)
    /* 2E5E8 8003DDE8 89FE000C */  jal        Card_PushTask
    /* 2E5EC 8003DDEC 100065AC */   sw        $a1, 0x10($v1)
    /* 2E5F0 8003DDF0 82F70008 */  j          .L8003DE08
    /* 2E5F4 8003DDF4 01000224 */   addiu     $v0, $zero, 0x1
  .L8003DDF8:
    /* 2E5F8 8003DDF8 0180043C */  lui        $a0, %hi(D_80010B74)
    /* 2E5FC 8003DDFC 05A8000C */  jal        printf
    /* 2E600 8003DE00 740B8424 */   addiu     $a0, $a0, %lo(D_80010B74)
    /* 2E604 8003DE04 21100000 */  addu       $v0, $zero, $zero
  .L8003DE08:
    /* 2E608 8003DE08 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2E60C 8003DE0C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2E610 8003DE10 0800E003 */  jr         $ra
    /* 2E614 8003DE14 00000000 */   nop
endlabel MemCardExist
