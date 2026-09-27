nonmatching Item_MoveToStorage, 0x118

glabel Item_MoveToStorage
    /* 6B94 80016394 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 6B98 80016398 3000B2AF */  sw         $s2, 0x30($sp)
    /* 6B9C 8001639C 21908000 */  addu       $s2, $a0, $zero
    /* 6BA0 800163A0 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 6BA4 800163A4 2188A000 */  addu       $s1, $a1, $zero
    /* 6BA8 800163A8 54002426 */  addiu      $a0, $s1, 0x54
    /* 6BAC 800163AC 58002526 */  addiu      $a1, $s1, 0x58
    /* 6BB0 800163B0 3400BFAF */  sw         $ra, 0x34($sp)
    /* 6BB4 800163B4 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 6BB8 800163B8 2800B0AF */   sw        $s0, 0x28($sp)
    /* 6BBC 800163BC 40180200 */  sll        $v1, $v0, 1
    /* 6BC0 800163C0 21186200 */  addu       $v1, $v1, $v0
    /* 6BC4 800163C4 40180300 */  sll        $v1, $v1, 1
    /* 6BC8 800163C8 72006324 */  addiu      $v1, $v1, 0x72
    /* 6BCC 800163CC 21282302 */  addu       $a1, $s1, $v1
    /* 6BD0 800163D0 0000A294 */  lhu        $v0, 0x0($a1)
    /* 6BD4 800163D4 00000000 */  nop
    /* 6BD8 800163D8 03004014 */  bnez       $v0, .L800163E8
    /* 6BDC 800163DC 00000000 */   nop
    /* 6BE0 800163E0 23590008 */  j          .L8001648C
    /* 6BE4 800163E4 10000424 */   addiu     $a0, $zero, 0x10
  .L800163E8:
    /* 6BE8 800163E8 0000B094 */  lhu        $s0, 0x0($a1)
    /* 6BEC 800163EC 0580033C */  lui        $v1, %hi(D_80050720)
    /* 6BF0 800163F0 2007638C */  lw         $v1, %lo(D_80050720)($v1)
    /* 6BF4 800163F4 40101000 */  sll        $v0, $s0, 1
    /* 6BF8 800163F8 21186200 */  addu       $v1, $v1, $v0
    /* 6BFC 800163FC D40D6494 */  lhu        $a0, 0xDD4($v1)
    /* 6C00 80016400 00000000 */  nop
    /* 6C04 80016404 01008224 */  addiu      $v0, $a0, 0x1
    /* 6C08 80016408 64004228 */  slti       $v0, $v0, 0x64
    /* 6C0C 8001640C 21108200 */  addu       $v0, $a0, $v0
    /* 6C10 80016410 D40D62A4 */  sh         $v0, 0xDD4($v1)
    /* 6C14 80016414 0400A484 */  lh         $a0, 0x4($a1)
    /* 6C18 80016418 FC89000C */  jal        func_800227F0
    /* 6C1C 8001641C 00000000 */   nop
    /* 6C20 80016420 21200002 */  addu       $a0, $s0, $zero
    /* 6C24 80016424 81000224 */  addiu      $v0, $zero, 0x81
    /* 6C28 80016428 0F00868B */  lwl        $a2, %gp_rel(D_80050707)($gp)
    /* 6C2C 8001642C 0C00869B */  lwr        $a2, %gp_rel(D_80050704)($gp)
    /* 6C30 80016430 00000000 */  nop
    /* 6C34 80016434 1F00A6AB */  swl        $a2, 0x1F($sp)
    /* 6C38 80016438 1C00A6BB */  swr        $a2, 0x1C($sp)
    /* 6C3C 8001643C 2000A2A3 */  sb         $v0, 0x20($sp)
    /* 6C40 80016440 1278000C */  jal        func_8001E048
    /* 6C44 80016444 2100A0A3 */   sb        $zero, 0x21($sp)
    /* 6C48 80016448 FD01043C */  lui        $a0, (0x1FD0122 >> 16)
    /* 6C4C 8001644C 22018434 */  ori        $a0, $a0, (0x1FD0122 & 0xFFFF)
    /* 6C50 80016450 688E000C */  jal        Cd_GetFileEntry
    /* 6C54 80016454 1400A2AF */   sw        $v0, 0x14($sp)
    /* 6C58 80016458 40002426 */  addiu      $a0, $s1, 0x40
    /* 6C5C 8001645C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6C60 80016460 1C4D000C */  jal        func_80013470
    /* 6C64 80016464 1000A2AF */   sw        $v0, 0x10($sp)
    /* 6C68 80016468 DA57000C */  jal        Item_BuildMenuList
    /* 6C6C 8001646C 21202002 */   addu      $a0, $s1, $zero
    /* 6C70 80016470 21202002 */  addu       $a0, $s1, $zero
    /* 6C74 80016474 6658000C */  jal        func_80016198
    /* 6C78 80016478 21280000 */   addu      $a1, $zero, $zero
    /* 6C7C 8001647C 21204002 */  addu       $a0, $s2, $zero
    /* 6C80 80016480 7745000C */  jal        Task_SetState1
    /* 6C84 80016484 02000524 */   addiu     $a1, $zero, 0x2
    /* 6C88 80016488 0E000424 */  addiu      $a0, $zero, 0xE
  .L8001648C:
    /* 6C8C 8001648C A369000C */  jal        Snd_PlayById
    /* 6C90 80016490 21280000 */   addu      $a1, $zero, $zero
    /* 6C94 80016494 3400BF8F */  lw         $ra, 0x34($sp)
    /* 6C98 80016498 3000B28F */  lw         $s2, 0x30($sp)
    /* 6C9C 8001649C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 6CA0 800164A0 2800B08F */  lw         $s0, 0x28($sp)
    /* 6CA4 800164A4 0800E003 */  jr         $ra
    /* 6CA8 800164A8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Item_MoveToStorage
