nonmatching Stg20_BeetleShopMenuUpdate, 0x164

glabel Stg20_BeetleShopMenuUpdate
    /* 8B7C 8006BEDC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 8B80 8006BEE0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8B84 8006BEE4 21888000 */  addu       $s1, $a0, $zero
    /* 8B88 8006BEE8 01000224 */  addiu      $v0, $zero, 0x1
    /* 8B8C 8006BEEC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 8B90 8006BEF0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8B94 8006BEF4 1000268E */  lw         $a2, 0x10($s1)
    /* 8B98 8006BEF8 2C00308E */  lw         $s0, 0x2C($s1)
    /* 8B9C 8006BEFC 2200C210 */  beq        $a2, $v0, .L8006BF88
    /* 8BA0 8006BF00 0200C228 */   slti      $v0, $a2, 0x2
    /* 8BA4 8006BF04 49004010 */  beqz       $v0, .L8006C02C
    /* 8BA8 8006BF08 00000000 */   nop
    /* 8BAC 8006BF0C 4700C014 */  bnez       $a2, .L8006C02C
    /* 8BB0 8006BF10 21200002 */   addu      $a0, $s0, $zero
    /* 8BB4 8006BF14 2270000C */  jal        Mem_FillWordsNeg1
    /* 8BB8 8006BF18 02000524 */   addiu     $a1, $zero, 0x2
    /* 8BBC 8006BF1C 21200002 */  addu       $a0, $s0, $zero
    /* 8BC0 8006BF20 DD000524 */  addiu      $a1, $zero, 0xDD
    /* 8BC4 8006BF24 21300000 */  addu       $a2, $zero, $zero
    /* 8BC8 8006BF28 0680033C */  lui        $v1, %hi(D_80063594)
    /* 8BCC 8006BF2C 94356224 */  addiu      $v0, $v1, %lo(D_80063594)
    /* 8BD0 8006BF30 02004794 */  lhu        $a3, 0x2($v0)
    /* 8BD4 8006BF34 94356294 */  lhu        $v0, %lo(D_80063594)($v1)
    /* 8BD8 8006BF38 003C0700 */  sll        $a3, $a3, 16
    /* 8BDC 8006BF3C F26F000C */  jal        Text_OpenById
    /* 8BE0 8006BF40 25384700 */   or        $a3, $v0, $a3
    /* 8BE4 8006BF44 04000426 */  addiu      $a0, $s0, 0x4
    /* 8BE8 8006BF48 DE000524 */  addiu      $a1, $zero, 0xDE
    /* 8BEC 8006BF4C 21300000 */  addu       $a2, $zero, $zero
    /* 8BF0 8006BF50 0680033C */  lui        $v1, %hi(D_80063598)
    /* 8BF4 8006BF54 98356224 */  addiu      $v0, $v1, %lo(D_80063598)
    /* 8BF8 8006BF58 02004794 */  lhu        $a3, 0x2($v0)
    /* 8BFC 8006BF5C 98356294 */  lhu        $v0, %lo(D_80063598)($v1)
    /* 8C00 8006BF60 003C0700 */  sll        $a3, $a3, 16
    /* 8C04 8006BF64 F26F000C */  jal        Text_OpenById
    /* 8C08 8006BF68 25384700 */   or        $a3, $v0, $a3
    /* 8C0C 8006BF6C 5145000C */  jal        Task_NextState0
    /* 8C10 8006BF70 21202002 */   addu      $a0, $s1, $zero
    /* 8C14 8006BF74 0BB00108 */  j          .L8006C02C
    /* 8C18 8006BF78 00000000 */   nop
  .L8006BF7C:
    /* 8C1C 8006BF7C B8FFE6AC */  sw         $a2, -0x48($a3)
    /* 8C20 8006BF80 06B00108 */  j          .L8006C018
    /* 8C24 8006BF84 0B000424 */   addiu     $a0, $zero, 0xB
  .L8006BF88:
    /* 8C28 8006BF88 0780053C */  lui        $a1, %hi(D_80070A00)
    /* 8C2C 8006BF8C 000AA724 */  addiu      $a3, $a1, %lo(D_80070A00)
    /* 8C30 8006BF90 0680023C */  lui        $v0, %hi(Pad_State)
    /* 8C34 8006BF94 F0F6438C */  lw         $v1, %lo(Pad_State)($v0)
    /* 8C38 8006BF98 00000000 */  nop
    /* 8C3C 8006BF9C 07006018 */  blez       $v1, .L8006BFBC
    /* 8C40 8006BFA0 F0F64424 */   addiu     $a0, $v0, %lo(Pad_State)
    /* 8C44 8006BFA4 000AA28C */  lw         $v0, %lo(D_80070A00)($a1)
    /* 8C48 8006BFA8 00000000 */  nop
    /* 8C4C 8006BFAC 1F004014 */  bnez       $v0, .L8006C02C
    /* 8C50 8006BFB0 00000000 */   nop
    /* 8C54 8006BFB4 F8AF0108 */  j          .L8006BFE0
    /* 8C58 8006BFB8 000AA6AC */   sw        $a2, %lo(D_80070A00)($a1)
  .L8006BFBC:
    /* 8C5C 8006BFBC 0400828C */  lw         $v0, 0x4($a0)
    /* 8C60 8006BFC0 00000000 */  nop
    /* 8C64 8006BFC4 0B004018 */  blez       $v0, .L8006BFF4
    /* 8C68 8006BFC8 00000000 */   nop
    /* 8C6C 8006BFCC 000AA28C */  lw         $v0, %lo(D_80070A00)($a1)
    /* 8C70 8006BFD0 00000000 */  nop
    /* 8C74 8006BFD4 15004010 */  beqz       $v0, .L8006C02C
    /* 8C78 8006BFD8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 8C7C 8006BFDC 000AA2AC */  sw         $v0, %lo(D_80070A00)($a1)
  .L8006BFE0:
    /* 8C80 8006BFE0 0C000424 */  addiu      $a0, $zero, 0xC
    /* 8C84 8006BFE4 A369000C */  jal        Snd_PlayById
    /* 8C88 8006BFE8 21280000 */   addu      $a1, $zero, $zero
    /* 8C8C 8006BFEC 0BB00108 */  j          .L8006C02C
    /* 8C90 8006BFF0 00000000 */   nop
  .L8006BFF4:
    /* 8C94 8006BFF4 1C00828C */  lw         $v0, 0x1C($a0)
    /* 8C98 8006BFF8 00000000 */  nop
    /* 8C9C 8006BFFC DFFF401C */  bgtz       $v0, .L8006BF7C
    /* 8CA0 8006C000 00000000 */   nop
    /* 8CA4 8006C004 1400828C */  lw         $v0, 0x14($a0)
    /* 8CA8 8006C008 00000000 */  nop
    /* 8CAC 8006C00C 07004018 */  blez       $v0, .L8006C02C
    /* 8CB0 8006C010 0A000424 */   addiu     $a0, $zero, 0xA
    /* 8CB4 8006C014 B8FFE0AC */  sw         $zero, -0x48($a3)
  .L8006C018:
    /* 8CB8 8006C018 A369000C */  jal        Snd_PlayById
    /* 8CBC 8006C01C 21280000 */   addu      $a1, $zero, $zero
    /* 8CC0 8006C020 21202002 */  addu       $a0, $s1, $zero
    /* 8CC4 8006C024 7045000C */  jal        Task_SetState0
    /* 8CC8 8006C028 03000524 */   addiu     $a1, $zero, 0x3
  .L8006C02C:
    /* 8CCC 8006C02C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 8CD0 8006C030 1400B18F */  lw         $s1, 0x14($sp)
    /* 8CD4 8006C034 1000B08F */  lw         $s0, 0x10($sp)
    /* 8CD8 8006C038 0800E003 */  jr         $ra
    /* 8CDC 8006C03C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_BeetleShopMenuUpdate
