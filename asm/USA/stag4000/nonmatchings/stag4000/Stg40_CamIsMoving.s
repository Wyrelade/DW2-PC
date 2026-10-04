nonmatching Stg40_CamIsMoving, 0x18

glabel Stg40_CamIsMoving
    /* EDB4 80072114 0780023C */  lui        $v0, %hi(Stg40_CameraTask)
    /* EDB8 80072118 C02B428C */  lw         $v0, %lo(Stg40_CameraTask)($v0)
    /* EDBC 8007211C 00000000 */  nop
    /* EDC0 80072120 1400428C */  lw         $v0, 0x14($v0)
    /* EDC4 80072124 0800E003 */  jr         $ra
    /* EDC8 80072128 00000000 */   nop
endlabel Stg40_CamIsMoving
