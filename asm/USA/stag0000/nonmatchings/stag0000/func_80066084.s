nonmatching func_80066084, 0xAC

glabel func_80066084
    /* 2D24 80066084 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2D28 80066088 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2D2C 8006608C 2C00828C */  lw         $v0, 0x2C($a0)
    /* 2D30 80066090 00000000 */  nop
    /* 2D34 80066094 0000438C */  lw         $v1, 0x0($v0)
    /* 2D38 80066098 01000224 */  addiu      $v0, $zero, 0x1
    /* 2D3C 8006609C 10006210 */  beq        $v1, $v0, .L800660E0
    /* 2D40 800660A0 02006228 */   slti      $v0, $v1, 0x2
    /* 2D44 800660A4 05004010 */  beqz       $v0, .L800660BC
    /* 2D48 800660A8 02000224 */   addiu     $v0, $zero, 0x2
    /* 2D4C 800660AC 10006010 */  beqz       $v1, .L800660F0
    /* 2D50 800660B0 E0010524 */   addiu     $a1, $zero, 0x1E0
    /* 2D54 800660B4 32980108 */  j          .L800660C8
    /* 2D58 800660B8 40010424 */   addiu     $a0, $zero, 0x140
  .L800660BC:
    /* 2D5C 800660BC 05006210 */  beq        $v1, $v0, .L800660D4
    /* 2D60 800660C0 E0010524 */   addiu     $a1, $zero, 0x1E0
    /* 2D64 800660C4 40010424 */  addiu      $a0, $zero, 0x140
  .L800660C8:
    /* 2D68 800660C8 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 2D6C 800660CC 3E980108 */  j          .L800660F8
    /* 2D70 800660D0 21300000 */   addu      $a2, $zero, $zero
  .L800660D4:
    /* 2D74 800660D4 40010424 */  addiu      $a0, $zero, 0x140
    /* 2D78 800660D8 3E980108 */  j          .L800660F8
    /* 2D7C 800660DC 02000624 */   addiu     $a2, $zero, 0x2
  .L800660E0:
    /* 2D80 800660E0 80020424 */  addiu      $a0, $zero, 0x280
    /* 2D84 800660E4 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 2D88 800660E8 3E980108 */  j          .L800660F8
    /* 2D8C 800660EC 21300000 */   addu      $a2, $zero, $zero
  .L800660F0:
    /* 2D90 800660F0 80020424 */  addiu      $a0, $zero, 0x280
    /* 2D94 800660F4 01000624 */  addiu      $a2, $zero, 0x1
  .L800660F8:
    /* 2D98 800660F8 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 2D9C 800660FC 21380000 */   addu      $a3, $zero, $zero
    /* 2DA0 80066100 21200000 */  addu       $a0, $zero, $zero
    /* 2DA4 80066104 21288000 */  addu       $a1, $a0, $zero
    /* 2DA8 80066108 6570000C */  jal        Gpu_SetBgClearColor
    /* 2DAC 8006610C 21308000 */   addu      $a2, $a0, $zero
    /* 2DB0 80066110 4170000C */  jal        Gpu_ClearScreens
    /* 2DB4 80066114 00000000 */   nop
    /* 2DB8 80066118 3271000C */  jal        Gfx_FadeInFromBlack
    /* 2DBC 8006611C 00010424 */   addiu     $a0, $zero, 0x100
    /* 2DC0 80066120 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2DC4 80066124 00000000 */  nop
    /* 2DC8 80066128 0800E003 */  jr         $ra
    /* 2DCC 8006612C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80066084
