nonmatching Card_ReadFileTask, 0x108

glabel Card_ReadFileTask
    /* 2F3F4 8003EBF4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2F3F8 8003EBF8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2F3FC 8003EBFC 21888000 */  addu       $s1, $a0, $zero
    /* 2F400 8003EC00 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2F404 8003EC04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2F408 8003EC08 0000238E */  lw         $v1, 0x0($s1)
    /* 2F40C 8003EC0C 0A001024 */  addiu      $s0, $zero, 0xA
    /* 2F410 8003EC10 14007010 */  beq        $v1, $s0, .L8003EC64
    /* 2F414 8003EC14 0B006228 */   slti      $v0, $v1, 0xB
    /* 2F418 8003EC18 05004010 */  beqz       $v0, .L8003EC30
    /* 2F41C 8003EC1C 0B000224 */   addiu     $v0, $zero, 0xB
    /* 2F420 8003EC20 09006010 */  beqz       $v1, .L8003EC48
    /* 2F424 8003EC24 21100000 */   addu      $v0, $zero, $zero
    /* 2F428 8003EC28 3AFB0008 */  j          .L8003ECE8
    /* 2F42C 8003EC2C 00000000 */   nop
  .L8003EC30:
    /* 2F430 8003EC30 1C006210 */  beq        $v1, $v0, .L8003ECA4
    /* 2F434 8003EC34 14000224 */   addiu     $v0, $zero, 0x14
    /* 2F438 8003EC38 21006210 */  beq        $v1, $v0, .L8003ECC0
    /* 2F43C 8003EC3C 21100000 */   addu      $v0, $zero, $zero
    /* 2F440 8003EC40 3AFB0008 */  j          .L8003ECE8
    /* 2F444 8003EC44 00000000 */   nop
  .L8003EC48:
    /* 2F448 8003EC48 0480043C */  lui        $a0, %hi(Card_InfoTask)
    /* 2F44C 8003EC4C 18DE8424 */  addiu      $a0, $a0, %lo(Card_InfoTask)
    /* 2F450 8003EC50 0580013C */  lui        $at, %hi(D_800506D8)
    /* 2F454 8003EC54 89FE000C */  jal        Card_PushTask
    /* 2F458 8003EC58 D80620AC */   sw        $zero, %lo(D_800506D8)($at)
    /* 2F45C 8003EC5C 39FB0008 */  j          .L8003ECE4
    /* 2F460 8003EC60 000030AE */   sw        $s0, 0x0($s1)
  .L8003EC64:
    /* 2F464 8003EC64 0680103C */  lui        $s0, %hi(D_80062F84)
    /* 2F468 8003EC68 842F1026 */  addiu      $s0, $s0, %lo(D_80062F84)
    /* 2F46C 8003EC6C 0000028E */  lw         $v0, 0x0($s0)
    /* 2F470 8003EC70 00000000 */  nop
    /* 2F474 8003EC74 1C004014 */  bnez       $v0, .L8003ECE8
    /* 2F478 8003EC78 01000224 */   addiu     $v0, $zero, 0x1
    /* 2F47C 8003EC7C 20000426 */  addiu      $a0, $s0, 0x20
    /* 2F480 8003EC80 5DFD000C */  jal        open
    /* 2F484 8003EC84 01800534 */   ori       $a1, $zero, 0x8001
    /* 2F488 8003EC88 06004104 */  bgez       $v0, .L8003ECA4
    /* 2F48C 8003EC8C 100002AE */   sw        $v0, 0x10($s0)
    /* 2F490 8003EC90 FCFF0326 */  addiu      $v1, $s0, -0x4
    /* 2F494 8003EC94 05000224 */  addiu      $v0, $zero, 0x5
    /* 2F498 8003EC98 040062AC */  sw         $v0, 0x4($v1)
    /* 2F49C 8003EC9C 3AFB0008 */  j          .L8003ECE8
    /* 2F4A0 8003ECA0 01000224 */   addiu     $v0, $zero, 0x1
  .L8003ECA4:
    /* 2F4A4 8003ECA4 14000224 */  addiu      $v0, $zero, 0x14
    /* 2F4A8 8003ECA8 0480043C */  lui        $a0, %hi(Card_ReadDataTask)
    /* 2F4AC 8003ECAC C8E68424 */  addiu      $a0, $a0, %lo(Card_ReadDataTask)
    /* 2F4B0 8003ECB0 89FE000C */  jal        Card_PushTask
    /* 2F4B4 8003ECB4 000022AE */   sw        $v0, 0x0($s1)
    /* 2F4B8 8003ECB8 3AFB0008 */  j          .L8003ECE8
    /* 2F4BC 8003ECBC 21100000 */   addu      $v0, $zero, $zero
  .L8003ECC0:
    /* 2F4C0 8003ECC0 0680103C */  lui        $s0, %hi(D_80062F94)
    /* 2F4C4 8003ECC4 942F1026 */  addiu      $s0, $s0, %lo(D_80062F94)
    /* 2F4C8 8003ECC8 0000048E */  lw         $a0, 0x0($s0)
    /* 2F4CC 8003ECCC 69FD000C */  jal        close
    /* 2F4D0 8003ECD0 00000000 */   nop
    /* 2F4D4 8003ECD4 01000224 */  addiu      $v0, $zero, 0x1
    /* 2F4D8 8003ECD8 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 2F4DC 8003ECDC 3AFB0008 */  j          .L8003ECE8
    /* 2F4E0 8003ECE0 000003AE */   sw        $v1, 0x0($s0)
  .L8003ECE4:
    /* 2F4E4 8003ECE4 21100000 */  addu       $v0, $zero, $zero
  .L8003ECE8:
    /* 2F4E8 8003ECE8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2F4EC 8003ECEC 1400B18F */  lw         $s1, 0x14($sp)
    /* 2F4F0 8003ECF0 1000B08F */  lw         $s0, 0x10($sp)
    /* 2F4F4 8003ECF4 0800E003 */  jr         $ra
    /* 2F4F8 8003ECF8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Card_ReadFileTask
