nonmatching MemCardFormat, 0x74

glabel MemCardFormat
    /* 2FBA4 8003F3A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2FBA8 8003F3A8 0680023C */  lui        $v0, %hi(D_80062F80)
    /* 2FBAC 8003F3AC 802F4224 */  addiu      $v0, $v0, %lo(D_80062F80)
    /* 2FBB0 8003F3B0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2FBB4 8003F3B4 0000428C */  lw         $v0, 0x0($v0)
    /* 2FBB8 8003F3B8 00000000 */  nop
    /* 2FBBC 8003F3BC 06004010 */  beqz       $v0, .L8003F3D8
    /* 2FBC0 8003F3C0 00000000 */   nop
    /* 2FBC4 8003F3C4 0180043C */  lui        $a0, %hi(D_80010D18)
    /* 2FBC8 8003F3C8 05A8000C */  jal        printf
    /* 2FBCC 8003F3CC 180D8424 */   addiu     $a0, $a0, %lo(D_80010D18)
    /* 2FBD0 8003F3D0 02FD0008 */  j          .L8003F408
    /* 2FBD4 8003F3D4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8003F3D8:
    /* 2FBD8 8003F3D8 7900010C */  jal        Card_Format
    /* 2FBDC 8003F3DC 00000000 */   nop
    /* 2FBE0 8003F3E0 21204000 */  addu       $a0, $v0, $zero
    /* 2FBE4 8003F3E4 07008010 */  beqz       $a0, .L8003F404
    /* 2FBE8 8003F3E8 04000224 */   addiu     $v0, $zero, 0x4
    /* 2FBEC 8003F3EC 06008210 */  beq        $a0, $v0, .L8003F408
    /* 2FBF0 8003F3F0 02000224 */   addiu     $v0, $zero, 0x2
    /* 2FBF4 8003F3F4 06FD000C */  jal        Card_EventToMcErr
    /* 2FBF8 8003F3F8 00000000 */   nop
    /* 2FBFC 8003F3FC 02FD0008 */  j          .L8003F408
    /* 2FC00 8003F400 00000000 */   nop
  .L8003F404:
    /* 2FC04 8003F404 21100000 */  addu       $v0, $zero, $zero
  .L8003F408:
    /* 2FC08 8003F408 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2FC0C 8003F40C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2FC10 8003F410 0800E003 */  jr         $ra
    /* 2FC14 8003F414 00000000 */   nop
endlabel MemCardFormat
