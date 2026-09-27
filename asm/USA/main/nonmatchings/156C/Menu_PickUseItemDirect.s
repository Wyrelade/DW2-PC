nonmatching Menu_PickUseItemDirect, 0xC0

glabel Menu_PickUseItemDirect
    /* 8084 80017884 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 8088 80017888 81000224 */  addiu      $v0, $zero, 0x81
    /* 808C 8001788C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 8090 80017890 2800B0AF */  sw         $s0, 0x28($sp)
    /* 8094 80017894 2C00908C */  lw         $s0, 0x2C($a0)
    /* 8098 80017898 0580033C */  lui        $v1, %hi(Menu_Ctx)
    /* 809C 8001789C 6807638C */  lw         $v1, %lo(Menu_Ctx)($v1)
    /* 80A0 800178A0 21300000 */  addu       $a2, $zero, $zero
    /* 80A4 800178A4 1700888B */  lwl        $t0, %gp_rel(D_8005070F)($gp)
    /* 80A8 800178A8 1400889B */  lwr        $t0, %gp_rel(D_8005070C)($gp)
    /* 80AC 800178AC 00000000 */  nop
    /* 80B0 800178B0 1F00A8AB */  swl        $t0, 0x1F($sp)
    /* 80B4 800178B4 1C00A8BB */  swr        $t0, 0x1C($sp)
    /* 80B8 800178B8 2100A0A3 */  sb         $zero, 0x21($sp)
    /* 80BC 800178BC 2000A2A3 */  sb         $v0, 0x20($sp)
    /* 80C0 800178C0 08016484 */  lh         $a0, 0x108($v1)
    /* 80C4 800178C4 0A016584 */  lh         $a1, 0x10A($v1)
    /* 80C8 800178C8 DE49000C */  jal        Item_Use
    /* 80CC 800178CC 2138C000 */   addu      $a3, $a2, $zero
    /* 80D0 800178D0 10004010 */  beqz       $v0, .L80017914
    /* 80D4 800178D4 00000000 */   nop
    /* 80D8 800178D8 FD01043C */  lui        $a0, (0x1FD00FD >> 16)
    /* 80DC 800178DC 688E000C */  jal        Cd_GetFileEntry
    /* 80E0 800178E0 FD008434 */   ori       $a0, $a0, (0x1FD00FD & 0xFFFF)
    /* 80E4 800178E4 0580033C */  lui        $v1, %hi(Menu_Ctx)
    /* 80E8 800178E8 6807638C */  lw         $v1, %lo(Menu_Ctx)($v1)
    /* 80EC 800178EC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 80F0 800178F0 08016484 */  lh         $a0, 0x108($v1)
    /* 80F4 800178F4 1278000C */  jal        Item_GetNameText
    /* 80F8 800178F8 00000000 */   nop
    /* 80FC 800178FC 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 8100 80017900 21280000 */  addu       $a1, $zero, $zero
    /* 8104 80017904 A369000C */  jal        Snd_PlayById
    /* 8108 80017908 1400A2AF */   sw        $v0, 0x14($sp)
    /* 810C 8001790C 4B5E0008 */  j          .L8001792C
    /* 8110 80017910 40000426 */   addiu     $a0, $s0, 0x40
  .L80017914:
    /* 8114 80017914 FD01043C */  lui        $a0, (0x1FD00A0 >> 16)
    /* 8118 80017918 688E000C */  jal        Cd_GetFileEntry
    /* 811C 8001791C A0008434 */   ori       $a0, $a0, (0x1FD00A0 & 0xFFFF)
    /* 8120 80017920 1000A2AF */  sw         $v0, 0x10($sp)
    /* 8124 80017924 1400A0AF */  sw         $zero, 0x14($sp)
    /* 8128 80017928 40000426 */  addiu      $a0, $s0, 0x40
  .L8001792C:
    /* 812C 8001792C 1C4D000C */  jal        Text_OpenDesc
    /* 8130 80017930 1000A527 */   addiu     $a1, $sp, 0x10
    /* 8134 80017934 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 8138 80017938 2800B08F */  lw         $s0, 0x28($sp)
    /* 813C 8001793C 0800E003 */  jr         $ra
    /* 8140 80017940 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Menu_PickUseItemDirect
