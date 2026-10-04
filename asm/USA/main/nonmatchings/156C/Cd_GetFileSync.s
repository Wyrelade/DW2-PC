nonmatching Cd_GetFileSync, 0x70

glabel Cd_GetFileSync
    /* 145B0 80023DB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 145B4 80023DB4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 145B8 80023DB8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 145BC 80023DBC 9E8E000C */  jal        Cd_FindCachedFile
    /* 145C0 80023DC0 21808000 */   addu      $s0, $a0, $zero
    /* 145C4 80023DC4 21204000 */  addu       $a0, $v0, $zero
    /* 145C8 80023DC8 08008010 */  beqz       $a0, .L80023DEC
    /* 145CC 80023DCC 03000224 */   addiu     $v0, $zero, 0x3
    /* 145D0 80023DD0 00008384 */  lh         $v1, 0x0($a0)
    /* 145D4 80023DD4 00000000 */  nop
    /* 145D8 80023DD8 04006214 */  bne        $v1, $v0, .L80023DEC
    /* 145DC 80023DDC 0680023C */   lui       $v0, %hi(Sys_State)
    /* 145E0 80023DE0 70F7428C */  lw         $v0, %lo(Sys_State)($v0)
    /* 145E4 80023DE4 818F0008 */  j          .L80023E04
    /* 145E8 80023DE8 080082AC */   sw        $v0, 0x8($a0)
  .L80023DEC:
    /* 145EC 80023DEC 8890000C */  jal        Cd_PollRead
    /* 145F0 80023DF0 00000000 */   nop
    /* 145F4 80023DF4 FDFF4014 */  bnez       $v0, .L80023DEC
    /* 145F8 80023DF8 00000000 */   nop
    /* 145FC 80023DFC 5A8F000C */  jal        Cd_LoadFileSync
    /* 14600 80023E00 21200002 */   addu      $a0, $s0, $zero
  .L80023E04:
    /* 14604 80023E04 9E8E000C */  jal        Cd_FindCachedFile
    /* 14608 80023E08 21200002 */   addu      $a0, $s0, $zero
    /* 1460C 80023E0C 0C00428C */  lw         $v0, 0xC($v0)
    /* 14610 80023E10 1400BF8F */  lw         $ra, 0x14($sp)
    /* 14614 80023E14 1000B08F */  lw         $s0, 0x10($sp)
    /* 14618 80023E18 0800E003 */  jr         $ra
    /* 1461C 80023E1C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Cd_GetFileSync
