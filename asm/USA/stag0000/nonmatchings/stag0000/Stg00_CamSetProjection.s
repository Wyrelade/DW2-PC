nonmatching Stg00_CamSetProjection, 0x20

glabel Stg00_CamSetProjection
    /* 5680 800689E0 05008010 */  beqz       $a0, .L800689F8
    /* 5684 800689E4 01000224 */   addiu     $v0, $zero, 0x1
    /* 5688 800689E8 2C00838C */  lw         $v1, 0x2C($a0)
    /* 568C 800689EC 00000000 */  nop
    /* 5690 800689F0 180065AC */  sw         $a1, 0x18($v1)
    /* 5694 800689F4 840062AC */  sw         $v0, 0x84($v1)
  .L800689F8:
    /* 5698 800689F8 0800E003 */  jr         $ra
    /* 569C 800689FC 00000000 */   nop
endlabel Stg00_CamSetProjection
