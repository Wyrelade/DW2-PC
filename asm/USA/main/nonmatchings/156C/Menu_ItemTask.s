nonmatching Menu_ItemTask, 0x600

glabel Menu_ItemTask
    /* 71DC 800169DC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 71E0 800169E0 3000B2AF */  sw         $s2, 0x30($sp)
    /* 71E4 800169E4 21908000 */  addu       $s2, $a0, $zero
    /* 71E8 800169E8 01000424 */  addiu      $a0, $zero, 0x1
    /* 71EC 800169EC 3400BFAF */  sw         $ra, 0x34($sp)
    /* 71F0 800169F0 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 71F4 800169F4 2800B0AF */  sw         $s0, 0x28($sp)
    /* 71F8 800169F8 1000438E */  lw         $v1, 0x10($s2)
    /* 71FC 800169FC 2C00508E */  lw         $s0, 0x2C($s2)
    /* 7200 80016A00 22006410 */  beq        $v1, $a0, .L80016A8C
    /* 7204 80016A04 02006228 */   slti      $v0, $v1, 0x2
    /* 7208 80016A08 03004014 */  bnez       $v0, .L80016A18
    /* 720C 80016A0C 02000224 */   addiu     $v0, $zero, 0x2
    /* 7210 80016A10 56016210 */  beq        $v1, $v0, .L80016F6C
    /* 7214 80016A14 00000000 */   nop
  .L80016A18:
    /* 7218 80016A18 1305043C */  lui        $a0, (0x5130017 >> 16)
    /* 721C 80016A1C 688E000C */  jal        Cd_GetFileEntry
    /* 7220 80016A20 17008434 */   ori       $a0, $a0, (0x5130017 & 0xFFFF)
    /* 7224 80016A24 03004888 */  lwl        $t0, 0x3($v0)
    /* 7228 80016A28 00004898 */  lwr        $t0, 0x0($v0)
    /* 722C 80016A2C 07004988 */  lwl        $t1, 0x7($v0)
    /* 7230 80016A30 04004998 */  lwr        $t1, 0x4($v0)
    /* 7234 80016A34 0B004A88 */  lwl        $t2, 0xB($v0)
    /* 7238 80016A38 08004A98 */  lwr        $t2, 0x8($v0)
    /* 723C 80016A3C 5B0008AA */  swl        $t0, 0x5B($s0)
    /* 7240 80016A40 580008BA */  swr        $t0, 0x58($s0)
    /* 7244 80016A44 5F0009AA */  swl        $t1, 0x5F($s0)
    /* 7248 80016A48 5C0009BA */  swr        $t1, 0x5C($s0)
    /* 724C 80016A4C 63000AAA */  swl        $t2, 0x63($s0)
    /* 7250 80016A50 60000ABA */  swr        $t2, 0x60($s0)
    /* 7254 80016A54 AB89000C */  jal        Item_SortList
    /* 7258 80016A58 00000000 */   nop
    /* 725C 80016A5C 21200002 */  addu       $a0, $s0, $zero
    /* 7260 80016A60 6E0000A6 */  sh         $zero, 0x6E($s0)
    /* 7264 80016A64 560000A6 */  sh         $zero, 0x56($s0)
    /* 7268 80016A68 DA57000C */  jal        Item_BuildMenuList
    /* 726C 80016A6C 540000A6 */   sh        $zero, 0x54($s0)
    /* 7270 80016A70 21200002 */  addu       $a0, $s0, $zero
    /* 7274 80016A74 2270000C */  jal        Mem_FillWordsNeg1
    /* 7278 80016A78 15000524 */   addiu     $a1, $zero, 0x15
    /* 727C 80016A7C 5145000C */  jal        Task_NextState0
    /* 7280 80016A80 21204002 */   addu      $a0, $s2, $zero
    /* 7284 80016A84 F15B0008 */  j          .L80016FC4
    /* 7288 80016A88 00000000 */   nop
  .L80016A8C:
    /* 728C 80016A8C 1400438E */  lw         $v1, 0x14($s2)
    /* 7290 80016A90 00000000 */  nop
    /* 7294 80016A94 0700622C */  sltiu      $v0, $v1, 0x7
    /* 7298 80016A98 08004010 */  beqz       $v0, .L80016ABC
    /* 729C 80016A9C 0180023C */   lui       $v0, %hi(jtbl_800100C0)
    /* 72A0 80016AA0 C0004224 */  addiu      $v0, $v0, %lo(jtbl_800100C0)
    /* 72A4 80016AA4 80180300 */  sll        $v1, $v1, 2
    /* 72A8 80016AA8 21186200 */  addu       $v1, $v1, $v0
    /* 72AC 80016AAC 0000628C */  lw         $v0, 0x0($v1)
    /* 72B0 80016AB0 00000000 */  nop
    /* 72B4 80016AB4 08004000 */  jr         $v0
    /* 72B8 80016AB8 00000000 */   nop
  jlabel .L80016ABC
    /* 72BC 80016ABC 21204002 */  addu       $a0, $s2, $zero
    /* 72C0 80016AC0 B94D000C */  jal        Math_RampToOne
    /* 72C4 80016AC4 68000526 */   addiu     $a1, $s0, 0x68
    /* 72C8 80016AC8 3E014014 */  bnez       $v0, .L80016FC4
    /* 72CC 80016ACC 1305043C */   lui       $a0, (0x5130018 >> 16)
    /* 72D0 80016AD0 64000586 */  lh         $a1, 0x64($s0)
    /* 72D4 80016AD4 18008434 */  ori        $a0, $a0, (0x5130018 & 0xFFFF)
    /* 72D8 80016AD8 AC4E000C */  jal        Cd_GetFileEntrySubPtr
    /* 72DC 80016ADC FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 72E0 80016AE0 4C000426 */  addiu      $a0, $s0, 0x4C
    /* 72E4 80016AE4 21284000 */  addu       $a1, $v0, $zero
    /* 72E8 80016AE8 564D000C */  jal        Text_PrintIdList
    /* 72EC 80016AEC 02000624 */   addiu     $a2, $zero, 0x2
    /* 72F0 80016AF0 DA57000C */  jal        Item_BuildMenuList
    /* 72F4 80016AF4 21200002 */   addu      $a0, $s0, $zero
    /* 72F8 80016AF8 21200002 */  addu       $a0, $s0, $zero
    /* 72FC 80016AFC 6658000C */  jal        Menu_DrawItemGrid
    /* 7300 80016B00 01000524 */   addiu     $a1, $zero, 0x1
    /* 7304 80016B04 E65B0008 */  j          .L80016F98
    /* 7308 80016B08 00000000 */   nop
  jlabel .L80016B0C
    /* 730C 80016B0C 64000386 */  lh         $v1, 0x64($s0)
    /* 7310 80016B10 00000000 */  nop
    /* 7314 80016B14 03006228 */  slti       $v0, $v1, 0x3
    /* 7318 80016B18 07004014 */  bnez       $v0, .L80016B38
    /* 731C 80016B1C 21204002 */   addu      $a0, $s2, $zero
    /* 7320 80016B20 05006228 */  slti       $v0, $v1, 0x5
    /* 7324 80016B24 13004014 */  bnez       $v0, .L80016B74
    /* 7328 80016B28 04000224 */   addiu     $v0, $zero, 0x4
    /* 732C 80016B2C 05000224 */  addiu      $v0, $zero, 0x5
    /* 7330 80016B30 05006210 */  beq        $v1, $v0, .L80016B48
    /* 7334 80016B34 00000000 */   nop
  .L80016B38:
    /* 7338 80016B38 3C5A000C */  jal        Menu_ShowSelItemText
    /* 733C 80016B3C 21280002 */   addu      $a1, $s0, $zero
    /* 7340 80016B40 E65B0008 */  j          .L80016F98
    /* 7344 80016B44 00000000 */   nop
  .L80016B48:
    /* 7348 80016B48 6C000286 */  lh         $v0, 0x6C($s0)
    /* 734C 80016B4C 00000000 */  nop
    /* 7350 80016B50 03004014 */  bnez       $v0, .L80016B60
    /* 7354 80016B54 FD01043C */   lui       $a0, (0x1FD0151 >> 16)
    /* 7358 80016B58 CC5B0008 */  j          .L80016F30
    /* 735C 80016B5C 51018434 */   ori       $a0, $a0, (0x1FD0151 & 0xFFFF)
  .L80016B60:
    /* 7360 80016B60 21204002 */  addu       $a0, $s2, $zero
    /* 7364 80016B64 3C5A000C */  jal        Menu_ShowSelItemText
    /* 7368 80016B68 21280002 */   addu      $a1, $s0, $zero
    /* 736C 80016B6C E65B0008 */  j          .L80016F98
    /* 7370 80016B70 00000000 */   nop
  .L80016B74:
    /* 7374 80016B74 05006214 */  bne        $v1, $v0, .L80016B8C
    /* 7378 80016B78 FD01023C */   lui       $v0, (0x1FD011D >> 16)
    /* 737C 80016B7C 6C000286 */  lh         $v0, 0x6C($s0)
    /* 7380 80016B80 00000000 */  nop
    /* 7384 80016B84 E8004010 */  beqz       $v0, .L80016F28
    /* 7388 80016B88 FD01023C */   lui       $v0, (0x1FD011D >> 16)
  .L80016B8C:
    /* 738C 80016B8C 64000486 */  lh         $a0, 0x64($s0)
    /* 7390 80016B90 1D014234 */  ori        $v0, $v0, (0x1FD011D & 0xFFFF)
    /* 7394 80016B94 688E000C */  jal        Cd_GetFileEntry
    /* 7398 80016B98 21208200 */   addu      $a0, $a0, $v0
    /* 739C 80016B9C 40000426 */  addiu      $a0, $s0, 0x40
    /* 73A0 80016BA0 21284000 */  addu       $a1, $v0, $zero
    /* 73A4 80016BA4 80000624 */  addiu      $a2, $zero, 0x80
    /* 73A8 80016BA8 0E008797 */  lhu        $a3, %gp_rel(D_80050706)($gp)
    /* 73AC 80016BAC 0C008297 */  lhu        $v0, %gp_rel(Menu_ItemMsgPos)($gp)
    /* 73B0 80016BB0 003C0700 */  sll        $a3, $a3, 16
    /* 73B4 80016BB4 3E4D000C */  jal        Text_OpenPacked
    /* 73B8 80016BB8 25384700 */   or        $a3, $v0, $a3
    /* 73BC 80016BBC E65B0008 */  j          .L80016F98
    /* 73C0 80016BC0 00000000 */   nop
  jlabel .L80016BC4
    /* 73C4 80016BC4 54000426 */  addiu      $a0, $s0, 0x54
    /* 73C8 80016BC8 844E000C */  jal        Menu_MoveGridCursorP1
    /* 73CC 80016BCC 58000526 */   addiu     $a1, $s0, 0x58
    /* 73D0 80016BD0 15004010 */  beqz       $v0, .L80016C28
    /* 73D4 80016BD4 0D000424 */   addiu     $a0, $zero, 0xD
    /* 73D8 80016BD8 A369000C */  jal        Snd_PlayById
    /* 73DC 80016BDC 21280000 */   addu      $a1, $zero, $zero
    /* 73E0 80016BE0 54000586 */  lh         $a1, 0x54($s0)
    /* 73E4 80016BE4 6E000486 */  lh         $a0, 0x6E($s0)
    /* 73E8 80016BE8 54000396 */  lhu        $v1, 0x54($s0)
    /* 73EC 80016BEC 2310A400 */  subu       $v0, $a1, $a0
    /* 73F0 80016BF0 02004228 */  slti       $v0, $v0, 0x2
    /* 73F4 80016BF4 04004014 */  bnez       $v0, .L80016C08
    /* 73F8 80016BF8 2A10A400 */   slt       $v0, $a1, $a0
    /* 73FC 80016BFC FFFF6224 */  addiu      $v0, $v1, -0x1
    /* 7400 80016C00 055B0008 */  j          .L80016C14
    /* 7404 80016C04 6E0002A6 */   sh        $v0, 0x6E($s0)
  .L80016C08:
    /* 7408 80016C08 9A004010 */  beqz       $v0, .L80016E74
    /* 740C 80016C0C 21204002 */   addu      $a0, $s2, $zero
    /* 7410 80016C10 6E0003A6 */  sh         $v1, 0x6E($s0)
  .L80016C14:
    /* 7414 80016C14 21200002 */  addu       $a0, $s0, $zero
    /* 7418 80016C18 6658000C */  jal        Menu_DrawItemGrid
    /* 741C 80016C1C 21280000 */   addu      $a1, $zero, $zero
    /* 7420 80016C20 9D5B0008 */  j          .L80016E74
    /* 7424 80016C24 21204002 */   addu      $a0, $s2, $zero
  .L80016C28:
    /* 7428 80016C28 0680023C */  lui        $v0, %hi(Pad_State)
    /* 742C 80016C2C F0F64324 */  addiu      $v1, $v0, %lo(Pad_State)
    /* 7430 80016C30 1C00628C */  lw         $v0, 0x1C($v1)
    /* 7434 80016C34 00000000 */  nop
    /* 7438 80016C38 06004018 */  blez       $v0, .L80016C54
    /* 743C 80016C3C 0B000424 */   addiu     $a0, $zero, 0xB
    /* 7440 80016C40 A369000C */  jal        Snd_PlayById
    /* 7444 80016C44 21280000 */   addu      $a1, $zero, $zero
    /* 7448 80016C48 21204002 */  addu       $a0, $s2, $zero
    /* 744C 80016C4C EF5B0008 */  j          .L80016FBC
    /* 7450 80016C50 02000524 */   addiu     $a1, $zero, 0x2
  .L80016C54:
    /* 7454 80016C54 1400628C */  lw         $v0, 0x14($v1)
    /* 7458 80016C58 00000000 */  nop
    /* 745C 80016C5C D9004018 */  blez       $v0, .L80016FC4
    /* 7460 80016C60 02000224 */   addiu     $v0, $zero, 0x2
    /* 7464 80016C64 64000386 */  lh         $v1, 0x64($s0)
    /* 7468 80016C68 00000000 */  nop
    /* 746C 80016C6C 12006210 */  beq        $v1, $v0, .L80016CB8
    /* 7470 80016C70 03006228 */   slti      $v0, $v1, 0x3
    /* 7474 80016C74 05004010 */  beqz       $v0, .L80016C8C
    /* 7478 80016C78 01000224 */   addiu     $v0, $zero, 0x1
    /* 747C 80016C7C 0A006210 */  beq        $v1, $v0, .L80016CA8
    /* 7480 80016C80 21204002 */   addu      $a0, $s2, $zero
    /* 7484 80016C84 F15B0008 */  j          .L80016FC4
    /* 7488 80016C88 00000000 */   nop
  .L80016C8C:
    /* 748C 80016C8C 03000224 */  addiu      $v0, $zero, 0x3
    /* 7490 80016C90 0E006210 */  beq        $v1, $v0, .L80016CCC
    /* 7494 80016C94 04000224 */   addiu     $v0, $zero, 0x4
    /* 7498 80016C98 11006210 */  beq        $v1, $v0, .L80016CE0
    /* 749C 80016C9C 21204002 */   addu      $a0, $s2, $zero
    /* 74A0 80016CA0 F15B0008 */  j          .L80016FC4
    /* 74A4 80016CA4 00000000 */   nop
  .L80016CA8:
    /* 74A8 80016CA8 BF59000C */  jal        Menu_PickItemToUse
    /* 74AC 80016CAC 21280002 */   addu      $a1, $s0, $zero
    /* 74B0 80016CB0 F15B0008 */  j          .L80016FC4
    /* 74B4 80016CB4 00000000 */   nop
  .L80016CB8:
    /* 74B8 80016CB8 21204002 */  addu       $a0, $s2, $zero
    /* 74BC 80016CBC 0D5A000C */  jal        Menu_ItemGridSelect
    /* 74C0 80016CC0 21280002 */   addu      $a1, $s0, $zero
    /* 74C4 80016CC4 F15B0008 */  j          .L80016FC4
    /* 74C8 80016CC8 00000000 */   nop
  .L80016CCC:
    /* 74CC 80016CCC 21204002 */  addu       $a0, $s2, $zero
    /* 74D0 80016CD0 E558000C */  jal        Item_MoveToStorage
    /* 74D4 80016CD4 21280002 */   addu      $a1, $s0, $zero
    /* 74D8 80016CD8 F15B0008 */  j          .L80016FC4
    /* 74DC 80016CDC 00000000 */   nop
  .L80016CE0:
    /* 74E0 80016CE0 2B59000C */  jal        Item_TakeFromStorage
    /* 74E4 80016CE4 21280002 */   addu      $a1, $s0, $zero
    /* 74E8 80016CE8 F15B0008 */  j          .L80016FC4
    /* 74EC 80016CEC 00000000 */   nop
  jlabel .L80016CF0
    /* 74F0 80016CF0 01000224 */  addiu      $v0, $zero, 0x1
    /* 74F4 80016CF4 1800438E */  lw         $v1, 0x18($s2)
    /* 74F8 80016CF8 3400518E */  lw         $s1, 0x34($s2)
    /* 74FC 80016CFC 0A006210 */  beq        $v1, $v0, .L80016D28
    /* 7500 80016D00 02006228 */   slti      $v0, $v1, 0x2
    /* 7504 80016D04 04004014 */  bnez       $v0, .L80016D18
    /* 7508 80016D08 21200002 */   addu      $a0, $s0, $zero
    /* 750C 80016D0C 02000224 */  addiu      $v0, $zero, 0x2
    /* 7510 80016D10 14006210 */  beq        $v1, $v0, .L80016D64
    /* 7514 80016D14 00000000 */   nop
  .L80016D18:
    /* 7518 80016D18 2C70000C */  jal        Text_CloseArray
    /* 751C 80016D1C 15000524 */   addiu     $a1, $zero, 0x15
    /* 7520 80016D20 AE5B0008 */  j          .L80016EB8
    /* 7524 80016D24 00000000 */   nop
  .L80016D28:
    /* 7528 80016D28 21204002 */  addu       $a0, $s2, $zero
    /* 752C 80016D2C C54D000C */  jal        Math_RampToZero
    /* 7530 80016D30 68000526 */   addiu     $a1, $s0, 0x68
    /* 7534 80016D34 A3004014 */  bnez       $v0, .L80016FC4
    /* 7538 80016D38 0480033C */   lui       $v1, %hi(Menu_ItemSubTasks)
    /* 753C 80016D3C 66000286 */  lh         $v0, 0x66($s0)
    /* 7540 80016D40 FC0E6324 */  addiu      $v1, $v1, %lo(Menu_ItemSubTasks)
    /* 7544 80016D44 80100200 */  sll        $v0, $v0, 2
    /* 7548 80016D48 21104300 */  addu       $v0, $v0, $v1
    /* 754C 80016D4C 00004484 */  lh         $a0, 0x0($v0)
    /* 7550 80016D50 02004684 */  lh         $a2, 0x2($v0)
    /* 7554 80016D54 1F44000C */  jal        Task_Create
    /* 7558 80016D58 21282002 */   addu      $a1, $s1, $zero
    /* 755C 80016D5C AE5B0008 */  j          .L80016EB8
    /* 7560 80016D60 00000000 */   nop
  .L80016D64:
    /* 7564 80016D64 0000228E */  lw         $v0, 0x0($s1)
    /* 7568 80016D68 00000000 */  nop
    /* 756C 80016D6C 95004014 */  bnez       $v0, .L80016FC4
    /* 7570 80016D70 21204002 */   addu      $a0, $s2, $zero
    /* 7574 80016D74 7745000C */  jal        Task_SetState1
    /* 7578 80016D78 21280000 */   addu      $a1, $zero, $zero
    /* 757C 80016D7C F15B0008 */  j          .L80016FC4
    /* 7580 80016D80 00000000 */   nop
  jlabel .L80016D84
    /* 7584 80016D84 0580033C */  lui        $v1, %hi(Menu_Ctx)
    /* 7588 80016D88 6807638C */  lw         $v1, %lo(Menu_Ctx)($v1)
    /* 758C 80016D8C 10000224 */  addiu      $v0, $zero, 0x10
    /* 7590 80016D90 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 7594 80016D94 BA000224 */  addiu      $v0, $zero, 0xBA
    /* 7598 80016D98 1E00A2A7 */  sh         $v0, 0x1E($sp)
    /* 759C 80016D9C 81000224 */  addiu      $v0, $zero, 0x81
    /* 75A0 80016DA0 2000A2A3 */  sb         $v0, 0x20($sp)
    /* 75A4 80016DA4 2100A0A3 */  sb         $zero, 0x21($sp)
    /* 75A8 80016DA8 08016484 */  lh         $a0, 0x108($v1)
    /* 75AC 80016DAC 1278000C */  jal        Item_GetNameText
    /* 75B0 80016DB0 00000000 */   nop
    /* 75B4 80016DB4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 75B8 80016DB8 1800518E */  lw         $s1, 0x18($s2)
    /* 75BC 80016DBC 00000000 */  nop
    /* 75C0 80016DC0 03002012 */  beqz       $s1, .L80016DD0
    /* 75C4 80016DC4 01000224 */   addiu     $v0, $zero, 0x1
    /* 75C8 80016DC8 0A002212 */  beq        $s1, $v0, .L80016DF4
    /* 75CC 80016DCC 00000000 */   nop
  .L80016DD0:
    /* 75D0 80016DD0 FD01043C */  lui        $a0, (0x1FD00B9 >> 16)
    /* 75D4 80016DD4 688E000C */  jal        Cd_GetFileEntry
    /* 75D8 80016DD8 B9008434 */   ori       $a0, $a0, (0x1FD00B9 & 0xFFFF)
    /* 75DC 80016DDC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 75E0 80016DE0 44000426 */  addiu      $a0, $s0, 0x44
    /* 75E4 80016DE4 1C4D000C */  jal        Text_OpenDesc
    /* 75E8 80016DE8 1000A527 */   addiu     $a1, $sp, 0x10
    /* 75EC 80016DEC AE5B0008 */  j          .L80016EB8
    /* 75F0 80016DF0 00000000 */   nop
  .L80016DF4:
    /* 75F4 80016DF4 4400048E */  lw         $a0, 0x44($s0)
    /* 75F8 80016DF8 A94D000C */  jal        Text_WaitYesNo
    /* 75FC 80016DFC 00000000 */   nop
    /* 7600 80016E00 21184000 */  addu       $v1, $v0, $zero
    /* 7604 80016E04 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 7608 80016E08 1A006210 */  beq        $v1, $v0, .L80016E74
    /* 760C 80016E0C 21204002 */   addu      $a0, $s2, $zero
    /* 7610 80016E10 6C007114 */  bne        $v1, $s1, .L80016FC4
    /* 7614 80016E14 00000000 */   nop
    /* 7618 80016E18 0580023C */  lui        $v0, %hi(Menu_Ctx)
    /* 761C 80016E1C 6807428C */  lw         $v0, %lo(Menu_Ctx)($v0)
    /* 7620 80016E20 00000000 */  nop
    /* 7624 80016E24 0A014484 */  lh         $a0, 0x10A($v0)
    /* 7628 80016E28 FC89000C */  jal        Item_RemoveFromBag
    /* 762C 80016E2C 00000000 */   nop
    /* 7630 80016E30 FD01043C */  lui        $a0, (0x1FD00BA >> 16)
    /* 7634 80016E34 688E000C */  jal        Cd_GetFileEntry
    /* 7638 80016E38 BA008434 */   ori       $a0, $a0, (0x1FD00BA & 0xFFFF)
    /* 763C 80016E3C 44000426 */  addiu      $a0, $s0, 0x44
    /* 7640 80016E40 1000A527 */  addiu      $a1, $sp, 0x10
    /* 7644 80016E44 1C4D000C */  jal        Text_OpenDesc
    /* 7648 80016E48 1000A2AF */   sw        $v0, 0x10($sp)
    /* 764C 80016E4C DA57000C */  jal        Item_BuildMenuList
    /* 7650 80016E50 21200002 */   addu      $a0, $s0, $zero
    /* 7654 80016E54 21200002 */  addu       $a0, $s0, $zero
    /* 7658 80016E58 6658000C */  jal        Menu_DrawItemGrid
    /* 765C 80016E5C 21280000 */   addu      $a1, $zero, $zero
    /* 7660 80016E60 21204002 */  addu       $a0, $s2, $zero
    /* 7664 80016E64 7745000C */  jal        Task_SetState1
    /* 7668 80016E68 02000524 */   addiu     $a1, $zero, 0x2
    /* 766C 80016E6C F15B0008 */  j          .L80016FC4
    /* 7670 80016E70 00000000 */   nop
  .L80016E74:
    /* 7674 80016E74 7745000C */  jal        Task_SetState1
    /* 7678 80016E78 01000524 */   addiu     $a1, $zero, 0x1
    /* 767C 80016E7C F15B0008 */  j          .L80016FC4
    /* 7680 80016E80 00000000 */   nop
  jlabel .L80016E84
    /* 7684 80016E84 1800438E */  lw         $v1, 0x18($s2)
    /* 7688 80016E88 00000000 */  nop
    /* 768C 80016E8C 05006010 */  beqz       $v1, .L80016EA4
    /* 7690 80016E90 01000224 */   addiu     $v0, $zero, 0x1
    /* 7694 80016E94 0C006210 */  beq        $v1, $v0, .L80016EC8
    /* 7698 80016E98 0680023C */   lui       $v0, %hi(Pad_State)
    /* 769C 80016E9C F15B0008 */  j          .L80016FC4
    /* 76A0 80016EA0 00000000 */   nop
  .L80016EA4:
    /* 76A4 80016EA4 4000048E */  lw         $a0, 0x40($s0)
    /* 76A8 80016EA8 826F000C */  jal        Text_IsFinished
    /* 76AC 80016EAC 00000000 */   nop
    /* 76B0 80016EB0 44004010 */  beqz       $v0, .L80016FC4
    /* 76B4 80016EB4 00000000 */   nop
  .L80016EB8:
    /* 76B8 80016EB8 6045000C */  jal        Task_NextState2
    /* 76BC 80016EBC 21204002 */   addu      $a0, $s2, $zero
    /* 76C0 80016EC0 F15B0008 */  j          .L80016FC4
    /* 76C4 80016EC4 00000000 */   nop
  .L80016EC8:
    /* 76C8 80016EC8 F0F64324 */  addiu      $v1, $v0, %lo(Pad_State)
    /* 76CC 80016ECC 1C00628C */  lw         $v0, 0x1C($v1)
    /* 76D0 80016ED0 00000000 */  nop
    /* 76D4 80016ED4 0D00401C */  bgtz       $v0, .L80016F0C
    /* 76D8 80016ED8 21204002 */   addu      $a0, $s2, $zero
    /* 76DC 80016EDC 1400628C */  lw         $v0, 0x14($v1)
    /* 76E0 80016EE0 00000000 */  nop
    /* 76E4 80016EE4 3500401C */  bgtz       $v0, .L80016FBC
    /* 76E8 80016EE8 02000524 */   addiu     $a1, $zero, 0x2
    /* 76EC 80016EEC 2000428E */  lw         $v0, 0x20($s2)
    /* 76F0 80016EF0 00000000 */  nop
    /* 76F4 80016EF4 21184000 */  addu       $v1, $v0, $zero
    /* 76F8 80016EF8 01004224 */  addiu      $v0, $v0, 0x1
    /* 76FC 80016EFC 1F006328 */  slti       $v1, $v1, 0x1F
    /* 7700 80016F00 30006014 */  bnez       $v1, .L80016FC4
    /* 7704 80016F04 200042AE */   sw        $v0, 0x20($s2)
    /* 7708 80016F08 21204002 */  addu       $a0, $s2, $zero
  .L80016F0C:
    /* 770C 80016F0C EF5B0008 */  j          .L80016FBC
    /* 7710 80016F10 02000524 */   addiu     $a1, $zero, 0x2
  jlabel .L80016F14
    /* 7714 80016F14 4000048E */  lw         $a0, 0x40($s0)
    /* 7718 80016F18 826F000C */  jal        Text_IsFinished
    /* 771C 80016F1C 00000000 */   nop
    /* 7720 80016F20 28004010 */  beqz       $v0, .L80016FC4
    /* 7724 80016F24 00000000 */   nop
  .L80016F28:
    /* 7728 80016F28 FD01043C */  lui        $a0, (0x1FD0127 >> 16)
    /* 772C 80016F2C 27018434 */  ori        $a0, $a0, (0x1FD0127 & 0xFFFF)
  .L80016F30:
    /* 7730 80016F30 688E000C */  jal        Cd_GetFileEntry
    /* 7734 80016F34 00000000 */   nop
    /* 7738 80016F38 40000426 */  addiu      $a0, $s0, 0x40
    /* 773C 80016F3C 21284000 */  addu       $a1, $v0, $zero
    /* 7740 80016F40 81000624 */  addiu      $a2, $zero, 0x81
    /* 7744 80016F44 0E008797 */  lhu        $a3, %gp_rel(D_80050706)($gp)
    /* 7748 80016F48 0C008297 */  lhu        $v0, %gp_rel(Menu_ItemMsgPos)($gp)
    /* 774C 80016F4C 003C0700 */  sll        $a3, $a3, 16
    /* 7750 80016F50 3E4D000C */  jal        Text_OpenPacked
    /* 7754 80016F54 25384700 */   or        $a3, $v0, $a3
    /* 7758 80016F58 21204002 */  addu       $a0, $s2, $zero
    /* 775C 80016F5C 7745000C */  jal        Task_SetState1
    /* 7760 80016F60 05000524 */   addiu     $a1, $zero, 0x5
    /* 7764 80016F64 F15B0008 */  j          .L80016FC4
    /* 7768 80016F68 00000000 */   nop
  .L80016F6C:
    /* 776C 80016F6C 1400428E */  lw         $v0, 0x14($s2)
    /* 7770 80016F70 00000000 */  nop
    /* 7774 80016F74 03004010 */  beqz       $v0, .L80016F84
    /* 7778 80016F78 00000000 */   nop
    /* 777C 80016F7C 0A004410 */  beq        $v0, $a0, .L80016FA8
    /* 7780 80016F80 21204002 */   addu      $a0, $s2, $zero
  .L80016F84:
    /* 7784 80016F84 AB89000C */  jal        Item_SortList
    /* 7788 80016F88 00000000 */   nop
    /* 778C 80016F8C 21200002 */  addu       $a0, $s0, $zero
    /* 7790 80016F90 2C70000C */  jal        Text_CloseArray
    /* 7794 80016F94 15000524 */   addiu     $a1, $zero, 0x15
  .L80016F98:
    /* 7798 80016F98 5945000C */  jal        Task_NextState1
    /* 779C 80016F9C 21204002 */   addu      $a0, $s2, $zero
    /* 77A0 80016FA0 F15B0008 */  j          .L80016FC4
    /* 77A4 80016FA4 00000000 */   nop
  .L80016FA8:
    /* 77A8 80016FA8 C54D000C */  jal        Math_RampToZero
    /* 77AC 80016FAC 68000526 */   addiu     $a1, $s0, 0x68
    /* 77B0 80016FB0 04004014 */  bnez       $v0, .L80016FC4
    /* 77B4 80016FB4 21204002 */   addu      $a0, $s2, $zero
    /* 77B8 80016FB8 03000524 */  addiu      $a1, $zero, 0x3
  .L80016FBC:
    /* 77BC 80016FBC 7045000C */  jal        Task_SetState0
    /* 77C0 80016FC0 00000000 */   nop
  .L80016FC4:
    /* 77C4 80016FC4 3400BF8F */  lw         $ra, 0x34($sp)
    /* 77C8 80016FC8 3000B28F */  lw         $s2, 0x30($sp)
    /* 77CC 80016FCC 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 77D0 80016FD0 2800B08F */  lw         $s0, 0x28($sp)
    /* 77D4 80016FD4 0800E003 */  jr         $ra
    /* 77D8 80016FD8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Menu_ItemTask
