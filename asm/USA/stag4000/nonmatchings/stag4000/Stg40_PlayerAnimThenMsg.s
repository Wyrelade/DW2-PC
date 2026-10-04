nonmatching Stg40_PlayerAnimThenMsg, 0x8C

glabel Stg40_PlayerAnimThenMsg
    /* 4D50 800680B0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4D54 800680B4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4D58 800680B8 4000B38F */  lw         $s3, 0x40($sp)
    /* 4D5C 800680BC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 4D60 800680C0 4400B48F */  lw         $s4, 0x44($sp)
    /* 4D64 800680C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4D68 800680C8 21808000 */  addu       $s0, $a0, $zero
    /* 4D6C 800680CC 2400B5AF */  sw         $s5, 0x24($sp)
    /* 4D70 800680D0 4800B58F */  lw         $s5, 0x48($sp)
    /* 4D74 800680D4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4D78 800680D8 2188C000 */  addu       $s1, $a2, $zero
    /* 4D7C 800680DC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4D80 800680E0 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4D84 800680E4 37B9010C */  jal        Stg40_ObjSetAnim
    /* 4D88 800680E8 2190E000 */   addu      $s2, $a3, $zero
    /* 4D8C 800680EC 21200002 */  addu       $a0, $s0, $zero
    /* 4D90 800680F0 7745000C */  jal        Task_SetState1
    /* 4D94 800680F4 09000524 */   addiu     $a1, $zero, 0x9
    /* 4D98 800680F8 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 4D9C 800680FC 602B428C */  lw         $v0, %lo(Stg40_RootState)($v0)
    /* 4DA0 80068100 00000000 */  nop
    /* 4DA4 80068104 340051AC */  sw         $s1, 0x34($v0)
    /* 4DA8 80068108 380052AC */  sw         $s2, 0x38($v0)
    /* 4DAC 8006810C 440053AC */  sw         $s3, 0x44($v0)
    /* 4DB0 80068110 480054AC */  sw         $s4, 0x48($v0)
    /* 4DB4 80068114 4C0055AC */  sw         $s5, 0x4C($v0)
    /* 4DB8 80068118 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4DBC 8006811C 2400B58F */  lw         $s5, 0x24($sp)
    /* 4DC0 80068120 2000B48F */  lw         $s4, 0x20($sp)
    /* 4DC4 80068124 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4DC8 80068128 1800B28F */  lw         $s2, 0x18($sp)
    /* 4DCC 8006812C 1400B18F */  lw         $s1, 0x14($sp)
    /* 4DD0 80068130 1000B08F */  lw         $s0, 0x10($sp)
    /* 4DD4 80068134 0800E003 */  jr         $ra
    /* 4DD8 80068138 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg40_PlayerAnimThenMsg
