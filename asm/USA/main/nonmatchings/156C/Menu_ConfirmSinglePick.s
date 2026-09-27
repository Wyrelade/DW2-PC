nonmatching Menu_ConfirmSinglePick, 0xA8

glabel Menu_ConfirmSinglePick
    /* 8144 80017944 0680023C */  lui        $v0, %hi(D_8005F704)
    /* 8148 80017948 04F7428C */  lw         $v0, %lo(D_8005F704)($v0)
    /* 814C 8001794C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 8150 80017950 1800B2AF */  sw         $s2, 0x18($sp)
    /* 8154 80017954 21908000 */  addu       $s2, $a0, $zero
    /* 8158 80017958 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 815C 8001795C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8160 80017960 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8164 80017964 2C00508E */  lw         $s0, 0x2C($s2)
    /* 8168 80017968 1A004018 */  blez       $v0, .L800179D4
    /* 816C 8001796C 50000426 */   addiu     $a0, $s0, 0x50
    /* 8170 80017970 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 8174 80017974 54000526 */   addiu     $a1, $s0, 0x54
    /* 8178 80017978 C0100200 */  sll        $v0, $v0, 3
    /* 817C 8001797C 21180202 */  addu       $v1, $s0, $v0
    /* 8180 80017980 6C007190 */  lbu        $s1, 0x6C($v1)
    /* 8184 80017984 01000224 */  addiu      $v0, $zero, 0x1
    /* 8188 80017988 0F002216 */  bne        $s1, $v0, .L800179C8
    /* 818C 8001798C 10000424 */   addiu     $a0, $zero, 0x10
    /* 8190 80017990 21204002 */  addu       $a0, $s2, $zero
    /* 8194 80017994 0580023C */  lui        $v0, %hi(Menu_Ctx)
    /* 8198 80017998 6807428C */  lw         $v0, %lo(Menu_Ctx)($v0)
    /* 819C 8001799C 7000638C */  lw         $v1, 0x70($v1)
    /* 81A0 800179A0 03000524 */  addiu      $a1, $zero, 0x3
    /* 81A4 800179A4 100143AC */  sw         $v1, 0x110($v0)
    /* 81A8 800179A8 7745000C */  jal        Task_SetState1
    /* 81AC 800179AC 620000A6 */   sh        $zero, 0x62($s0)
    /* 81B0 800179B0 0E000424 */  addiu      $a0, $zero, 0xE
    /* 81B4 800179B4 0580023C */  lui        $v0, %hi(Menu_Ctx)
    /* 81B8 800179B8 6807428C */  lw         $v0, %lo(Menu_Ctx)($v0)
    /* 81BC 800179BC 21280000 */  addu       $a1, $zero, $zero
    /* 81C0 800179C0 735E0008 */  j          .L800179CC
    /* 81C4 800179C4 5C0351A4 */   sh        $s1, 0x35C($v0)
  .L800179C8:
    /* 81C8 800179C8 21280000 */  addu       $a1, $zero, $zero
  .L800179CC:
    /* 81CC 800179CC A369000C */  jal        Snd_PlayById
    /* 81D0 800179D0 00000000 */   nop
  .L800179D4:
    /* 81D4 800179D4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 81D8 800179D8 1800B28F */  lw         $s2, 0x18($sp)
    /* 81DC 800179DC 1400B18F */  lw         $s1, 0x14($sp)
    /* 81E0 800179E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 81E4 800179E4 0800E003 */  jr         $ra
    /* 81E8 800179E8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Menu_ConfirmSinglePick
