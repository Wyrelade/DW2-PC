nonmatching func_8001EC10, 0xD4

glabel func_8001EC10
    /* F410 8001EC10 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F414 8001EC14 1000B0AF */  sw         $s0, 0x10($sp)
    /* F418 8001EC18 21808000 */  addu       $s0, $a0, $zero
    /* F41C 8001EC1C 1400BFAF */  sw         $ra, 0x14($sp)
    /* F420 8001EC20 1000068E */  lw         $a2, 0x10($s0)
    /* F424 8001EC24 01000224 */  addiu      $v0, $zero, 0x1
    /* F428 8001EC28 1300C210 */  beq        $a2, $v0, .L8001EC78
    /* F42C 8001EC2C 0200C228 */   slti      $v0, $a2, 0x2
    /* F430 8001EC30 28004010 */  beqz       $v0, .L8001ECD4
    /* F434 8001EC34 00000000 */   nop
    /* F438 8001EC38 2600C014 */  bnez       $a2, .L8001ECD4
    /* F43C 8001EC3C 0480053C */   lui       $a1, %hi(D_80043704)
    /* F440 8001EC40 0437A524 */  addiu      $a1, $a1, %lo(D_80043704)
    /* F444 8001EC44 1083000C */  jal        Actor_InitTransform
    /* F448 8001EC48 21300000 */   addu      $a2, $zero, $zero
    /* F44C 8001EC4C 21200002 */  addu       $a0, $s0, $zero
    /* F450 8001EC50 6F7F000C */  jal        Gfx_AttachModel
    /* F454 8001EC54 5B000524 */   addiu     $a1, $zero, 0x5B
    /* F458 8001EC58 04000324 */  addiu      $v1, $zero, 0x4
    /* F45C 8001EC5C 3C0043AC */  sw         $v1, 0x3C($v0)
    /* F460 8001EC60 7A7D000C */  jal        Gfx_ResetModelBones
    /* F464 8001EC64 21200002 */   addu      $a0, $s0, $zero
    /* F468 8001EC68 5145000C */  jal        Task_NextState0
    /* F46C 8001EC6C 21200002 */   addu      $a0, $s0, $zero
    /* F470 8001EC70 357B0008 */  j          .L8001ECD4
    /* F474 8001EC74 00000000 */   nop
  .L8001EC78:
    /* F478 8001EC78 2C00058E */  lw         $a1, 0x2C($s0)
    /* F47C 8001EC7C 00000000 */  nop
    /* F480 8001EC80 0000A38C */  lw         $v1, 0x0($a1)
    /* F484 8001EC84 00000000 */  nop
    /* F488 8001EC88 12006010 */  beqz       $v1, .L8001ECD4
    /* F48C 8001EC8C 0400A0AC */   sw        $zero, 0x4($a1)
    /* F490 8001EC90 1000648C */  lw         $a0, 0x10($v1)
    /* F494 8001EC94 00000000 */  nop
    /* F498 8001EC98 0E008010 */  beqz       $a0, .L8001ECD4
    /* F49C 8001EC9C 03000224 */   addiu     $v0, $zero, 0x3
    /* F4A0 8001ECA0 0C008210 */  beq        $a0, $v0, .L8001ECD4
    /* F4A4 8001ECA4 00000000 */   nop
    /* F4A8 8001ECA8 3C00628C */  lw         $v0, 0x3C($v1)
    /* F4AC 8001ECAC 00000000 */  nop
    /* F4B0 8001ECB0 7800448C */  lw         $a0, 0x78($v0)
    /* F4B4 8001ECB4 3800038E */  lw         $v1, 0x38($s0)
    /* F4B8 8001ECB8 3400828C */  lw         $v0, 0x34($a0)
    /* F4BC 8001ECBC 340060AC */  sw         $zero, 0x34($v1)
    /* F4C0 8001ECC0 300062AC */  sw         $v0, 0x30($v1)
    /* F4C4 8001ECC4 3C00828C */  lw         $v0, 0x3C($a0)
    /* F4C8 8001ECC8 00000000 */  nop
    /* F4CC 8001ECCC 380062AC */  sw         $v0, 0x38($v1)
    /* F4D0 8001ECD0 0400A6AC */  sw         $a2, 0x4($a1)
  .L8001ECD4:
    /* F4D4 8001ECD4 1400BF8F */  lw         $ra, 0x14($sp)
    /* F4D8 8001ECD8 1000B08F */  lw         $s0, 0x10($sp)
    /* F4DC 8001ECDC 0800E003 */  jr         $ra
    /* F4E0 8001ECE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001EC10
