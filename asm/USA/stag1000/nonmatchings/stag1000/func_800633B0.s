nonmatching func_800633B0, 0x1EC

glabel func_800633B0
    /* 50 800633B0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 54 800633B4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 58 800633B8 21908000 */  addu       $s2, $a0, $zero
    /* 5C 800633BC 2400BFAF */  sw         $ra, 0x24($sp)
    /* 60 800633C0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 64 800633C4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 68 800633C8 1000428E */  lw         $v0, 0x10($s2)
    /* 6C 800633CC 3400518E */  lw         $s1, 0x34($s2)
    /* 70 800633D0 6C004014 */  bnez       $v0, .L80063584
    /* 74 800633D4 0680023C */   lui       $v0, %hi(D_8005F770)
    /* 78 800633D8 70F75024 */  addiu      $s0, $v0, %lo(D_8005F770)
    /* 7C 800633DC 1800038E */  lw         $v1, 0x18($s0)
    /* 80 800633E0 00000000 */  nop
    /* 84 800633E4 08046228 */  slti       $v0, $v1, 0x408
    /* 88 800633E8 05004010 */  beqz       $v0, .L80063400
    /* 8C 800633EC 02046228 */   slti      $v0, $v1, 0x402
    /* 90 800633F0 36004010 */  beqz       $v0, .L800634CC
    /* 94 800633F4 00000000 */   nop
    /* 98 800633F8 038D0108 */  j          .L8006340C
    /* 9C 800633FC 0200043C */   lui       $a0, (0x25800 >> 16)
  .L80063400:
    /* A0 80063400 08040224 */  addiu      $v0, $zero, 0x408
    /* A4 80063404 1C006210 */  beq        $v1, $v0, .L80063478
    /* A8 80063408 0200043C */   lui       $a0, (0x25800 >> 16)
  .L8006340C:
    /* AC 8006340C 6C72000C */  jal        Gpu_AllocPacketBufs
    /* B0 80063410 00588434 */   ori       $a0, $a0, (0x25800 & 0xFFFF)
    /* B4 80063414 5C8E000C */  jal        Sys_SetFrameRate30
    /* B8 80063418 00000000 */   nop
    /* BC 8006341C 8F72000C */  jal        Gfx_InitTexSlots
    /* C0 80063420 00000000 */   nop
    /* C4 80063424 40010424 */  addiu      $a0, $zero, 0x140
    /* C8 80063428 E0010524 */  addiu      $a1, $zero, 0x1E0
    /* CC 8006342C 02000624 */  addiu      $a2, $zero, 0x2
    /* D0 80063430 7870000C */  jal        Gpu_InitDoubleBuffer
    /* D4 80063434 21380000 */   addu      $a3, $zero, $zero
    /* D8 80063438 21200000 */  addu       $a0, $zero, $zero
    /* DC 8006343C 21288000 */  addu       $a1, $a0, $zero
    /* E0 80063440 6570000C */  jal        Gpu_SetBgClearColor
    /* E4 80063444 21308000 */   addu      $a2, $a0, $zero
    /* E8 80063448 4170000C */  jal        Gpu_ClearScreens
    /* EC 8006344C 00000000 */   nop
    /* F0 80063450 3271000C */  jal        Gfx_FadeInFromBlack
    /* F4 80063454 20000424 */   addiu     $a0, $zero, 0x20
    /* F8 80063458 01040424 */  addiu      $a0, $zero, 0x401
    /* FC 8006345C 04002526 */  addiu      $a1, $s1, 0x4
    /* 100 80063460 1F44000C */  jal        Task_Create
    /* 104 80063464 21300000 */   addu      $a2, $zero, $zero
    /* 108 80063468 D068000C */  jal        Snd_StopAll
    /* 10C 8006346C 00000000 */   nop
    /* 110 80063470 5F8D0108 */  j          .L8006357C
    /* 114 80063474 00000000 */   nop
  .L80063478:
    /* 118 80063478 6C72000C */  jal        Gpu_AllocPacketBufs
    /* 11C 8006347C 00588434 */   ori       $a0, $a0, (0x25800 & 0xFFFF)
    /* 120 80063480 5C8E000C */  jal        Sys_SetFrameRate30
    /* 124 80063484 00000000 */   nop
    /* 128 80063488 40010424 */  addiu      $a0, $zero, 0x140
    /* 12C 8006348C E0010524 */  addiu      $a1, $zero, 0x1E0
    /* 130 80063490 02000624 */  addiu      $a2, $zero, 0x2
    /* 134 80063494 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 138 80063498 21380000 */   addu      $a3, $zero, $zero
    /* 13C 8006349C 21200000 */  addu       $a0, $zero, $zero
    /* 140 800634A0 21288000 */  addu       $a1, $a0, $zero
    /* 144 800634A4 6570000C */  jal        Gpu_SetBgClearColor
    /* 148 800634A8 21308000 */   addu      $a2, $a0, $zero
    /* 14C 800634AC 4170000C */  jal        Gpu_ClearScreens
    /* 150 800634B0 00000000 */   nop
    /* 154 800634B4 5671000C */  jal        Gfx_FadeClear
    /* 158 800634B8 00000000 */   nop
    /* 15C 800634BC 03040424 */  addiu      $a0, $zero, 0x403
    /* 160 800634C0 04002526 */  addiu      $a1, $s1, 0x4
    /* 164 800634C4 5D8D0108 */  j          .L80063574
    /* 168 800634C8 21300000 */   addu      $a2, $zero, $zero
  .L800634CC:
    /* 16C 800634CC 6C72000C */  jal        Gpu_AllocPacketBufs
    /* 170 800634D0 00040424 */   addiu     $a0, $zero, 0x400
    /* 174 800634D4 598E000C */  jal        Sys_SetFrameRate60
    /* 178 800634D8 00000000 */   nop
    /* 17C 800634DC 40010424 */  addiu      $a0, $zero, 0x140
    /* 180 800634E0 E0010524 */  addiu      $a1, $zero, 0x1E0
    /* 184 800634E4 02000624 */  addiu      $a2, $zero, 0x2
    /* 188 800634E8 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 18C 800634EC 01000724 */   addiu     $a3, $zero, 0x1
    /* 190 800634F0 419C000C */  jal        ResetGraph
    /* 194 800634F4 01000424 */   addiu     $a0, $zero, 0x1
    /* 198 800634F8 0680043C */  lui        $a0, %hi(D_800651C0)
    /* 19C 800634FC C0518424 */  addiu      $a0, $a0, %lo(D_800651C0)
    /* 1A0 80063500 21280000 */  addu       $a1, $zero, $zero
    /* 1A4 80063504 2130A000 */  addu       $a2, $a1, $zero
    /* 1A8 80063508 A59D000C */  jal        ClearImage2
    /* 1AC 8006350C 2138A000 */   addu      $a3, $a1, $zero
    /* 1B0 80063510 209D000C */  jal        DrawSync
    /* 1B4 80063514 21200000 */   addu      $a0, $zero, $zero
    /* 1B8 80063518 D068000C */  jal        Snd_StopAll
    /* 1BC 8006351C 280000AE */   sw        $zero, 0x28($s0)
    /* 1C0 80063520 0680033C */  lui        $v1, %hi(D_800651C8)
    /* 1C4 80063524 1800028E */  lw         $v0, 0x18($s0)
    /* 1C8 80063528 C8516324 */  addiu      $v1, $v1, %lo(D_800651C8)
    /* 1CC 8006352C FEFB4224 */  addiu      $v0, $v0, -0x402
    /* 1D0 80063530 40100200 */  sll        $v0, $v0, 1
    /* 1D4 80063534 21104300 */  addu       $v0, $v0, $v1
    /* 1D8 80063538 00004484 */  lh         $a0, 0x0($v0)
    /* 1DC 8006353C E48F000C */  jal        Cd_GetFileSectors
    /* 1E0 80063540 1000A4AF */   sw        $a0, 0x10($sp)
    /* 1E4 80063544 6666033C */  lui        $v1, (0x66666667 >> 16)
    /* 1E8 80063548 67666334 */  ori        $v1, $v1, (0x66666667 & 0xFFFF)
    /* 1EC 8006354C 18004300 */  mult       $v0, $v1
    /* 1F0 80063550 02040424 */  addiu      $a0, $zero, 0x402
    /* 1F4 80063554 08002526 */  addiu      $a1, $s1, 0x8
    /* 1F8 80063558 1000A627 */  addiu      $a2, $sp, 0x10
    /* 1FC 8006355C C3170200 */  sra        $v0, $v0, 31
    /* 200 80063560 10400000 */  mfhi       $t0
    /* 204 80063564 83180800 */  sra        $v1, $t0, 2
    /* 208 80063568 23186200 */  subu       $v1, $v1, $v0
    /* 20C 8006356C F6FF6324 */  addiu      $v1, $v1, -0xA
    /* 210 80063570 1400A3AF */  sw         $v1, 0x14($sp)
  .L80063574:
    /* 214 80063574 1F44000C */  jal        Task_Create
    /* 218 80063578 00000000 */   nop
  .L8006357C:
    /* 21C 8006357C 5145000C */  jal        Task_NextState0
    /* 220 80063580 21204002 */   addu      $a0, $s2, $zero
  .L80063584:
    /* 224 80063584 2400BF8F */  lw         $ra, 0x24($sp)
    /* 228 80063588 2000B28F */  lw         $s2, 0x20($sp)
    /* 22C 8006358C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 230 80063590 1800B08F */  lw         $s0, 0x18($sp)
    /* 234 80063594 0800E003 */  jr         $ra
    /* 238 80063598 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800633B0
