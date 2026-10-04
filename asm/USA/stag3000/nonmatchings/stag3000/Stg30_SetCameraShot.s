nonmatching Stg30_SetCameraShot, 0x54

glabel Stg30_SetCameraShot
    /* D9B4 80070D14 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D9B8 80070D18 1000B0AF */  sw         $s0, 0x10($sp)
    /* D9BC 80070D1C 21808000 */  addu       $s0, $a0, $zero
    /* D9C0 80070D20 03050424 */  addiu      $a0, $zero, 0x503
    /* D9C4 80070D24 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* D9C8 80070D28 1400BFAF */  sw         $ra, 0x14($sp)
    /* D9CC 80070D2C 4445000C */  jal        Task_FindFirst
    /* D9D0 80070D30 2130A000 */   addu      $a2, $a1, $zero
    /* D9D4 80070D34 21204000 */  addu       $a0, $v0, $zero
    /* D9D8 80070D38 07008010 */  beqz       $a0, .L80070D58
    /* D9DC 80070D3C 01000224 */   addiu     $v0, $zero, 0x1
    /* D9E0 80070D40 1000838C */  lw         $v1, 0x10($a0)
    /* D9E4 80070D44 00000000 */  nop
    /* D9E8 80070D48 03006214 */  bne        $v1, $v0, .L80070D58
    /* D9EC 80070D4C 00000000 */   nop
    /* D9F0 80070D50 7745000C */  jal        Task_SetState1
    /* D9F4 80070D54 FF000532 */   andi      $a1, $s0, 0xFF
  .L80070D58:
    /* D9F8 80070D58 1400BF8F */  lw         $ra, 0x14($sp)
    /* D9FC 80070D5C 1000B08F */  lw         $s0, 0x10($sp)
    /* DA00 80070D60 0800E003 */  jr         $ra
    /* DA04 80070D64 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg30_SetCameraShot
