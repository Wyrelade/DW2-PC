nonmatching Stg40_CamStartMove, 0x7C

glabel Stg40_CamStartMove
    /* EDCC 8007212C 0780023C */  lui        $v0, %hi(Stg40_CameraTask)
    /* EDD0 80072130 C02B438C */  lw         $v1, %lo(Stg40_CameraTask)($v0)
    /* EDD4 80072134 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EDD8 80072138 1000BFAF */  sw         $ra, 0x10($sp)
    /* EDDC 8007213C 2C00628C */  lw         $v0, 0x2C($v1)
    /* EDE0 80072140 0000888C */  lw         $t0, 0x0($a0)
    /* EDE4 80072144 0400898C */  lw         $t1, 0x4($a0)
    /* EDE8 80072148 08008A8C */  lw         $t2, 0x8($a0)
    /* EDEC 8007214C 0C008B8C */  lw         $t3, 0xC($a0)
    /* EDF0 80072150 880048AC */  sw         $t0, 0x88($v0)
    /* EDF4 80072154 8C0049AC */  sw         $t1, 0x8C($v0)
    /* EDF8 80072158 90004AAC */  sw         $t2, 0x90($v0)
    /* EDFC 8007215C 94004BAC */  sw         $t3, 0x94($v0)
    /* EE00 80072160 1000888C */  lw         $t0, 0x10($a0)
    /* EE04 80072164 1400898C */  lw         $t1, 0x14($a0)
    /* EE08 80072168 18008A8C */  lw         $t2, 0x18($a0)
    /* EE0C 8007216C 1C008B8C */  lw         $t3, 0x1C($a0)
    /* EE10 80072170 980048AC */  sw         $t0, 0x98($v0)
    /* EE14 80072174 9C0049AC */  sw         $t1, 0x9C($v0)
    /* EE18 80072178 A0004AAC */  sw         $t2, 0xA0($v0)
    /* EE1C 8007217C A4004BAC */  sw         $t3, 0xA4($v0)
    /* EE20 80072180 21206000 */  addu       $a0, $v1, $zero
    /* EE24 80072184 A80045AC */  sw         $a1, 0xA8($v0)
    /* EE28 80072188 01000524 */  addiu      $a1, $zero, 0x1
    /* EE2C 8007218C AC0046AC */  sw         $a2, 0xAC($v0)
    /* EE30 80072190 7745000C */  jal        Task_SetState1
    /* EE34 80072194 B00047AC */   sw        $a3, 0xB0($v0)
    /* EE38 80072198 1000BF8F */  lw         $ra, 0x10($sp)
    /* EE3C 8007219C 00000000 */  nop
    /* EE40 800721A0 0800E003 */  jr         $ra
    /* EE44 800721A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_CamStartMove
