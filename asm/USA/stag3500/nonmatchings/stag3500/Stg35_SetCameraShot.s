nonmatching Stg35_SetCameraShot, 0x54

glabel Stg35_SetCameraShot
    /* 6D20 8006A080 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6D24 8006A084 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6D28 8006A088 21808000 */  addu       $s0, $a0, $zero
    /* 6D2C 8006A08C 06070424 */  addiu      $a0, $zero, 0x706
    /* 6D30 8006A090 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 6D34 8006A094 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6D38 8006A098 4445000C */  jal        Task_FindFirst
    /* 6D3C 8006A09C 2130A000 */   addu      $a2, $a1, $zero
    /* 6D40 8006A0A0 21204000 */  addu       $a0, $v0, $zero
    /* 6D44 8006A0A4 07008010 */  beqz       $a0, .L8006A0C4
    /* 6D48 8006A0A8 01000224 */   addiu     $v0, $zero, 0x1
    /* 6D4C 8006A0AC 1000838C */  lw         $v1, 0x10($a0)
    /* 6D50 8006A0B0 00000000 */  nop
    /* 6D54 8006A0B4 03006214 */  bne        $v1, $v0, .L8006A0C4
    /* 6D58 8006A0B8 00000000 */   nop
    /* 6D5C 8006A0BC 7745000C */  jal        Task_SetState1
    /* 6D60 8006A0C0 FF000532 */   andi      $a1, $s0, 0xFF
  .L8006A0C4:
    /* 6D64 8006A0C4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6D68 8006A0C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6D6C 8006A0CC 0800E003 */  jr         $ra
    /* 6D70 8006A0D0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_SetCameraShot
