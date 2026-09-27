nonmatching func_80022468, 0x84

glabel func_80022468
    /* 12C68 80022468 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12C6C 8002246C 2800848F */  lw         $a0, %gp_rel(D_80050720)($gp)
    /* 12C70 80022470 1000BFAF */  sw         $ra, 0x10($sp)
    /* 12C74 80022474 E38B000C */  jal        Mem_Zero
    /* 12C78 80022478 58100524 */   addiu     $a1, $zero, 0x1058
    /* 12C7C 8002247C 2800838F */  lw         $v1, %gp_rel(D_80050720)($gp)
    /* 12C80 80022480 01000224 */  addiu      $v0, $zero, 0x1
    /* 12C84 80022484 7287000C */  jal        func_80021DC8
    /* 12C88 80022488 000062A0 */   sb        $v0, 0x0($v1)
    /* 12C8C 8002248C 0680023C */  lui        $v0, %hi(D_8005E620)
    /* 12C90 80022490 20E64224 */  addiu      $v0, $v0, %lo(D_8005E620)
    /* 12C94 80022494 8F000324 */  addiu      $v1, $zero, 0x8F
    /* 12C98 80022498 140043A0 */  sb         $v1, 0x14($v0)
    /* 12C9C 8002249C 95000324 */  addiu      $v1, $zero, 0x95
    /* 12CA0 800224A0 150043A0 */  sb         $v1, 0x15($v0)
    /* 12CA4 800224A4 B7000324 */  addiu      $v1, $zero, 0xB7
    /* 12CA8 800224A8 FF000424 */  addiu      $a0, $zero, 0xFF
    /* 12CAC 800224AC 160043A0 */  sb         $v1, 0x16($v0)
    /* 12CB0 800224B0 F4010324 */  addiu      $v1, $zero, 0x1F4
    /* 12CB4 800224B4 080043AC */  sw         $v1, 0x8($v0)
    /* 12CB8 800224B8 9E000324 */  addiu      $v1, $zero, 0x9E
    /* 12CBC 800224BC D10043A0 */  sb         $v1, 0xD1($v0)
    /* 12CC0 800224C0 D5000324 */  addiu      $v1, $zero, 0xD5
    /* 12CC4 800224C4 D20043A0 */  sb         $v1, 0xD2($v0)
    /* 12CC8 800224C8 96000324 */  addiu      $v1, $zero, 0x96
    /* 12CCC 800224CC 170044A0 */  sb         $a0, 0x17($v0)
    /* 12CD0 800224D0 D30043A0 */  sb         $v1, 0xD3($v0)
    /* 12CD4 800224D4 D40044A0 */  sb         $a0, 0xD4($v0)
    /* 12CD8 800224D8 040040AC */  sw         $zero, 0x4($v0)
    /* 12CDC 800224DC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12CE0 800224E0 00000000 */  nop
    /* 12CE4 800224E4 0800E003 */  jr         $ra
    /* 12CE8 800224E8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80022468
