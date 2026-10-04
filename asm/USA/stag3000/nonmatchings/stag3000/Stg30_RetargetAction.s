nonmatching Stg30_RetargetAction, 0x248

glabel Stg30_RetargetAction
    /* 6A88 80069DE8 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 6A8C 80069DEC 21200000 */  addu       $a0, $zero, $zero
    /* 6A90 80069DF0 4400BFAF */  sw         $ra, 0x44($sp)
    /* 6A94 80069DF4 4000B6AF */  sw         $s6, 0x40($sp)
    /* 6A98 80069DF8 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 6A9C 80069DFC 3800B4AF */  sw         $s4, 0x38($sp)
    /* 6AA0 80069E00 3400B3AF */  sw         $s3, 0x34($sp)
    /* 6AA4 80069E04 3000B2AF */  sw         $s2, 0x30($sp)
    /* 6AA8 80069E08 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 6AAC 80069E0C 9DB9010C */  jal        Stg30_TurnOrderGet
    /* 6AB0 80069E10 2800B0AF */   sw        $s0, 0x28($sp)
    /* 6AB4 80069E14 21A04000 */  addu       $s4, $v0, $zero
    /* 6AB8 80069E18 00111400 */  sll        $v0, $s4, 4
    /* 6ABC 80069E1C 0780033C */  lui        $v1, %hi(D_80073F6C)
    /* 6AC0 80069E20 6C3F6324 */  addiu      $v1, $v1, %lo(D_80073F6C)
    /* 6AC4 80069E24 21904300 */  addu       $s2, $v0, $v1
    /* 6AC8 80069E28 06004486 */  lh         $a0, 0x6($s2)
    /* 6ACC 80069E2C 117C000C */  jal        func_8001F044
    /* 6AD0 80069E30 00000000 */   nop
    /* 6AD4 80069E34 21A84000 */  addu       $s5, $v0, $zero
    /* 6AD8 80069E38 0200A232 */  andi       $v0, $s5, 0x2
    /* 6ADC 80069E3C 35004010 */  beqz       $v0, .L80069F14
    /* 6AE0 80069E40 02000224 */   addiu     $v0, $zero, 0x2
    /* 6AE4 80069E44 0000438E */  lw         $v1, 0x0($s2)
    /* 6AE8 80069E48 00000000 */  nop
    /* 6AEC 80069E4C 31006210 */  beq        $v1, $v0, .L80069F14
    /* 6AF0 80069E50 08000224 */   addiu     $v0, $zero, 0x8
    /* 6AF4 80069E54 21980000 */  addu       $s3, $zero, $zero
    /* 6AF8 80069E58 04004386 */  lh         $v1, 0x4($s2)
    /* 6AFC 80069E5C 00000000 */  nop
    /* 6B00 80069E60 0D006210 */  beq        $v1, $v0, .L80069E98
    /* 6B04 80069E64 03001124 */   addiu     $s1, $zero, 0x3
    /* 6B08 80069E68 09006228 */  slti       $v0, $v1, 0x9
    /* 6B0C 80069E6C 06004014 */  bnez       $v0, .L80069E88
    /* 6B10 80069E70 06006228 */   slti      $v0, $v1, 0x6
    /* 6B14 80069E74 09000224 */  addiu      $v0, $zero, 0x9
    /* 6B18 80069E78 09006210 */  beq        $v1, $v0, .L80069EA0
    /* 6B1C 80069E7C 21800000 */   addu      $s0, $zero, $zero
    /* 6B20 80069E80 ABA70108 */  j          .L80069EAC
    /* 6B24 80069E84 0780023C */   lui       $v0, %hi(Stg30_Battle)
  .L80069E88:
    /* 6B28 80069E88 06004010 */  beqz       $v0, .L80069EA4
    /* 6B2C 80069E8C 03006228 */   slti      $v0, $v1, 0x3
    /* 6B30 80069E90 05004014 */  bnez       $v0, .L80069EA8
    /* 6B34 80069E94 21800000 */   addu      $s0, $zero, $zero
  .L80069E98:
    /* 6B38 80069E98 A9A70108 */  j          .L80069EA4
    /* 6B3C 80069E9C 03001324 */   addiu     $s3, $zero, 0x3
  .L80069EA0:
    /* 6B40 80069EA0 06001124 */  addiu      $s1, $zero, 0x6
  .L80069EA4:
    /* 6B44 80069EA4 21800000 */  addu       $s0, $zero, $zero
  .L80069EA8:
    /* 6B48 80069EA8 0780023C */  lui        $v0, %hi(Stg30_Battle)
  .L80069EAC:
    /* 6B4C 80069EAC C03C5624 */  addiu      $s6, $v0, %lo(Stg30_Battle)
  .L80069EB0:
    /* 6B50 80069EB0 448E000C */  jal        Rand_Next
    /* 6B54 80069EB4 00000000 */   nop
    /* 6B58 80069EB8 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 6B5C 80069EBC 1A005100 */  div        $zero, $v0, $s1
    /* 6B60 80069EC0 10180000 */  mfhi       $v1
    /* 6B64 80069EC4 00000000 */  nop
    /* 6B68 80069EC8 21187300 */  addu       $v1, $v1, $s3
    /* 6B6C 80069ECC 40100300 */  sll        $v0, $v1, 1
    /* 6B70 80069ED0 21104300 */  addu       $v0, $v0, $v1
    /* 6B74 80069ED4 C0100200 */  sll        $v0, $v0, 3
    /* 6B78 80069ED8 23104300 */  subu       $v0, $v0, $v1
    /* 6B7C 80069EDC 80100200 */  sll        $v0, $v0, 2
    /* 6B80 80069EE0 21105600 */  addu       $v0, $v0, $s6
    /* 6B84 80069EE4 2E004284 */  lh         $v0, 0x2E($v0)
    /* 6B88 80069EE8 00000000 */  nop
    /* 6B8C 80069EEC 05004014 */  bnez       $v0, .L80069F04
    /* 6B90 80069EF0 64000224 */   addiu     $v0, $zero, 0x64
    /* 6B94 80069EF4 01001026 */  addiu      $s0, $s0, 0x1
    /* 6B98 80069EF8 6400022A */  slti       $v0, $s0, 0x64
    /* 6B9C 80069EFC ECFF4014 */  bnez       $v0, .L80069EB0
    /* 6BA0 80069F00 64000224 */   addiu     $v0, $zero, 0x64
  .L80069F04:
    /* 6BA4 80069F04 02000216 */  bne        $s0, $v0, .L80069F10
    /* 6BA8 80069F08 00000000 */   nop
    /* 6BAC 80069F0C 21188002 */  addu       $v1, $s4, $zero
  .L80069F10:
    /* 6BB0 80069F10 040043A6 */  sh         $v1, 0x4($s2)
  .L80069F14:
    /* 6BB4 80069F14 0400A232 */  andi       $v0, $s5, 0x4
    /* 6BB8 80069F18 0A004010 */  beqz       $v0, .L80069F44
    /* 6BBC 80069F1C 02000224 */   addiu     $v0, $zero, 0x2
    /* 6BC0 80069F20 0000438E */  lw         $v1, 0x0($s2)
    /* 6BC4 80069F24 00000000 */  nop
    /* 6BC8 80069F28 07006214 */  bne        $v1, $v0, .L80069F48
    /* 6BCC 80069F2C 0800A232 */   andi      $v0, $s5, 0x8
    /* 6BD0 80069F30 0300822A */  slti       $v0, $s4, 0x3
    /* 6BD4 80069F34 02004014 */  bnez       $v0, .L80069F40
    /* 6BD8 80069F38 08000224 */   addiu     $v0, $zero, 0x8
    /* 6BDC 80069F3C 07000224 */  addiu      $v0, $zero, 0x7
  .L80069F40:
    /* 6BE0 80069F40 040042A6 */  sh         $v0, 0x4($s2)
  .L80069F44:
    /* 6BE4 80069F44 0800A232 */  andi       $v0, $s5, 0x8
  .L80069F48:
    /* 6BE8 80069F48 2F004010 */  beqz       $v0, .L8006A008
    /* 6BEC 80069F4C 21488002 */   addu      $t1, $s4, $zero
    /* 6BF0 80069F50 21380000 */  addu       $a3, $zero, $zero
    /* 6BF4 80069F54 2128E000 */  addu       $a1, $a3, $zero
    /* 6BF8 80069F58 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 6BFC 80069F5C C03C4324 */  addiu      $v1, $v0, %lo(Stg30_Battle)
    /* 6C00 80069F60 1000A427 */  addiu      $a0, $sp, 0x10
  .L80069F64:
    /* 6C04 80069F64 19006290 */  lbu        $v0, 0x19($v1)
    /* 6C08 80069F68 00000000 */  nop
    /* 6C0C 80069F6C 08004010 */  beqz       $v0, .L80069F90
    /* 6C10 80069F70 00000000 */   nop
    /* 6C14 80069F74 2E006284 */  lh         $v0, 0x2E($v1)
    /* 6C18 80069F78 00000000 */  nop
    /* 6C1C 80069F7C 04004014 */  bnez       $v0, .L80069F90
    /* 6C20 80069F80 00000000 */   nop
    /* 6C24 80069F84 000085AC */  sw         $a1, 0x0($a0)
    /* 6C28 80069F88 04008424 */  addiu      $a0, $a0, 0x4
    /* 6C2C 80069F8C 0100E724 */  addiu      $a3, $a3, 0x1
  .L80069F90:
    /* 6C30 80069F90 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6C34 80069F94 0600A228 */  slti       $v0, $a1, 0x6
    /* 6C38 80069F98 F2FF4014 */  bnez       $v0, .L80069F64
    /* 6C3C 80069F9C 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 6C40 80069FA0 21400000 */  addu       $t0, $zero, $zero
    /* 6C44 80069FA4 1700E018 */  blez       $a3, .L8006A004
    /* 6C48 80069FA8 21280001 */   addu      $a1, $t0, $zero
    /* 6C4C 80069FAC 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 6C50 80069FB0 C03C4A24 */  addiu      $t2, $v0, %lo(Stg30_Battle)
    /* 6C54 80069FB4 1000A627 */  addiu      $a2, $sp, 0x10
  .L80069FB8:
    /* 6C58 80069FB8 0000C48C */  lw         $a0, 0x0($a2)
    /* 6C5C 80069FBC 00000000 */  nop
    /* 6C60 80069FC0 40100400 */  sll        $v0, $a0, 1
    /* 6C64 80069FC4 21104400 */  addu       $v0, $v0, $a0
    /* 6C68 80069FC8 C0100200 */  sll        $v0, $v0, 3
    /* 6C6C 80069FCC 23104400 */  subu       $v0, $v0, $a0
    /* 6C70 80069FD0 80100200 */  sll        $v0, $v0, 2
    /* 6C74 80069FD4 21104A00 */  addu       $v0, $v0, $t2
    /* 6C78 80069FD8 32004384 */  lh         $v1, 0x32($v0)
    /* 6C7C 80069FDC 00000000 */  nop
    /* 6C80 80069FE0 2A100301 */  slt        $v0, $t0, $v1
    /* 6C84 80069FE4 03004010 */  beqz       $v0, .L80069FF4
    /* 6C88 80069FE8 00000000 */   nop
    /* 6C8C 80069FEC 21406000 */  addu       $t0, $v1, $zero
    /* 6C90 80069FF0 21488000 */  addu       $t1, $a0, $zero
  .L80069FF4:
    /* 6C94 80069FF4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6C98 80069FF8 2A10A700 */  slt        $v0, $a1, $a3
    /* 6C9C 80069FFC EEFF4014 */  bnez       $v0, .L80069FB8
    /* 6CA0 8006A000 0400C624 */   addiu     $a2, $a2, 0x4
  .L8006A004:
    /* 6CA4 8006A004 040049A6 */  sh         $t1, 0x4($s2)
  .L8006A008:
    /* 6CA8 8006A008 4400BF8F */  lw         $ra, 0x44($sp)
    /* 6CAC 8006A00C 4000B68F */  lw         $s6, 0x40($sp)
    /* 6CB0 8006A010 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 6CB4 8006A014 3800B48F */  lw         $s4, 0x38($sp)
    /* 6CB8 8006A018 3400B38F */  lw         $s3, 0x34($sp)
    /* 6CBC 8006A01C 3000B28F */  lw         $s2, 0x30($sp)
    /* 6CC0 8006A020 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 6CC4 8006A024 2800B08F */  lw         $s0, 0x28($sp)
    /* 6CC8 8006A028 0800E003 */  jr         $ra
    /* 6CCC 8006A02C 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel Stg30_RetargetAction
