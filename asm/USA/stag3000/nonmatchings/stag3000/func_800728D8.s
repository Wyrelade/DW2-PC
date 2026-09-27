nonmatching func_800728D8, 0x54

glabel func_800728D8
    /* F578 800728D8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* F57C 800728DC 1000B0AF */  sw         $s0, 0x10($sp)
    /* F580 800728E0 2180A000 */  addu       $s0, $a1, $zero
    /* F584 800728E4 1400B1AF */  sw         $s1, 0x14($sp)
    /* F588 800728E8 0680113C */  lui        $s1, %hi(D_8005F398)
    /* F58C 800728EC 1800BFAF */  sw         $ra, 0x18($sp)
    /* F590 800728F0 2C00828C */  lw         $v0, 0x2C($a0)
    /* F594 800728F4 98F32626 */  addiu      $a2, $s1, %lo(D_8005F398)
    /* F598 800728F8 0000458C */  lw         $a1, 0x0($v0)
    /* F59C 800728FC 0680023C */  lui        $v0, %hi(D_8005F794)
    /* F5A0 80072900 94F7448C */  lw         $a0, %lo(D_8005F794)($v0)
    /* F5A4 80072904 0977000C */  jal        Digi_InitFromTable
    /* F5A8 80072908 FDFFA524 */   addiu     $a1, $a1, -0x3
    /* F5AC 8007290C 02000012 */  beqz       $s0, .L80072918
    /* F5B0 80072910 01000224 */   addiu     $v0, $zero, 0x1
    /* F5B4 80072914 98F322A2 */  sb         $v0, %lo(D_8005F398)($s1)
  .L80072918:
    /* F5B8 80072918 1800BF8F */  lw         $ra, 0x18($sp)
    /* F5BC 8007291C 1400B18F */  lw         $s1, 0x14($sp)
    /* F5C0 80072920 1000B08F */  lw         $s0, 0x10($sp)
    /* F5C4 80072924 0800E003 */  jr         $ra
    /* F5C8 80072928 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800728D8
