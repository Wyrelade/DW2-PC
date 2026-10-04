nonmatching Stg00_SpawnRandomGroup, 0x120

glabel Stg00_SpawnRandomGroup
    /* 3574 800668D4 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 3578 800668D8 5000BEAF */  sw         $fp, 0x50($sp)
    /* 357C 800668DC 21F00000 */  addu       $fp, $zero, $zero
    /* 3580 800668E0 4800B6AF */  sw         $s6, 0x48($sp)
    /* 3584 800668E4 00EC1624 */  addiu      $s6, $zero, -0x1400
    /* 3588 800668E8 4400B5AF */  sw         $s5, 0x44($sp)
    /* 358C 800668EC 00081524 */  addiu      $s5, $zero, 0x800
    /* 3590 800668F0 5400BFAF */  sw         $ra, 0x54($sp)
    /* 3594 800668F4 4C00B7AF */  sw         $s7, 0x4C($sp)
    /* 3598 800668F8 4000B4AF */  sw         $s4, 0x40($sp)
    /* 359C 800668FC 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 35A0 80066900 3800B2AF */  sw         $s2, 0x38($sp)
    /* 35A4 80066904 3400B1AF */  sw         $s1, 0x34($sp)
    /* 35A8 80066908 3000B0AF */  sw         $s0, 0x30($sp)
    /* 35AC 8006690C 3400848C */  lw         $a0, 0x34($a0)
    /* 35B0 80066910 21B8C003 */  addu       $s7, $fp, $zero
    /* 35B4 80066914 2800A4AF */  sw         $a0, 0x28($sp)
  .L80066918:
    /* 35B8 80066918 21A00000 */  addu       $s4, $zero, $zero
    /* 35BC 8006691C 2190E002 */  addu       $s2, $s7, $zero
    /* 35C0 80066920 00F61324 */  addiu      $s3, $zero, -0xA00
  .L80066924:
    /* 35C4 80066924 2800A38F */  lw         $v1, 0x28($sp)
    /* 35C8 80066928 80201200 */  sll        $a0, $s2, 2
    /* 35CC 8006692C B543000C */  jal        Task_Destroy
    /* 35D0 80066930 21206400 */   addu      $a0, $v1, $a0
  .L80066934:
    /* 35D4 80066934 448E000C */  jal        Rand_Next
    /* 35D8 80066938 00000000 */   nop
    /* 35DC 8006693C 4E7A000C */  jal        Digi_GetModelListCount
    /* 35E0 80066940 21804000 */   addu      $s0, $v0, $zero
    /* 35E4 80066944 FFFF1032 */  andi       $s0, $s0, 0xFFFF
    /* 35E8 80066948 1A000202 */  div        $zero, $s0, $v0
    /* 35EC 8006694C 10880000 */  mfhi       $s1
    /* 35F0 80066950 3D7A000C */  jal        Digi_GetModelListId
    /* 35F4 80066954 21202002 */   addu      $a0, $s1, $zero
    /* 35F8 80066958 F0004228 */  slti       $v0, $v0, 0xF0
    /* 35FC 8006695C F5FF4010 */  beqz       $v0, .L80066934
    /* 3600 80066960 00000000 */   nop
    /* 3604 80066964 3D7A000C */  jal        Digi_GetModelListId
    /* 3608 80066968 21202002 */   addu      $a0, $s1, $zero
    /* 360C 8006696C 05010424 */  addiu      $a0, $zero, 0x105
    /* 3610 80066970 80281200 */  sll        $a1, $s2, 2
    /* 3614 80066974 2800A38F */  lw         $v1, 0x28($sp)
    /* 3618 80066978 1000A627 */  addiu      $a2, $sp, 0x10
    /* 361C 8006697C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3620 80066980 2000B5AF */  sw         $s5, 0x20($sp)
    /* 3624 80066984 1400B3AF */  sw         $s3, 0x14($sp)
    /* 3628 80066988 1800A0AF */  sw         $zero, 0x18($sp)
    /* 362C 8006698C 1C00B6AF */  sw         $s6, 0x1C($sp)
    /* 3630 80066990 1F44000C */  jal        Task_Create
    /* 3634 80066994 21286500 */   addu      $a1, $v1, $a1
    /* 3638 80066998 01005226 */  addiu      $s2, $s2, 0x1
    /* 363C 8006699C 01009426 */  addiu      $s4, $s4, 0x1
    /* 3640 800669A0 0300822A */  slti       $v0, $s4, 0x3
    /* 3644 800669A4 DFFF4014 */  bnez       $v0, .L80066924
    /* 3648 800669A8 000A7326 */   addiu     $s3, $s3, 0xA00
    /* 364C 800669AC 0028D626 */  addiu      $s6, $s6, 0x2800
    /* 3650 800669B0 0008B526 */  addiu      $s5, $s5, 0x800
    /* 3654 800669B4 0100DE27 */  addiu      $fp, $fp, 0x1
    /* 3658 800669B8 0200C22B */  slti       $v0, $fp, 0x2
    /* 365C 800669BC D6FF4014 */  bnez       $v0, .L80066918
    /* 3660 800669C0 0300F726 */   addiu     $s7, $s7, 0x3
    /* 3664 800669C4 5400BF8F */  lw         $ra, 0x54($sp)
    /* 3668 800669C8 5000BE8F */  lw         $fp, 0x50($sp)
    /* 366C 800669CC 4C00B78F */  lw         $s7, 0x4C($sp)
    /* 3670 800669D0 4800B68F */  lw         $s6, 0x48($sp)
    /* 3674 800669D4 4400B58F */  lw         $s5, 0x44($sp)
    /* 3678 800669D8 4000B48F */  lw         $s4, 0x40($sp)
    /* 367C 800669DC 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 3680 800669E0 3800B28F */  lw         $s2, 0x38($sp)
    /* 3684 800669E4 3400B18F */  lw         $s1, 0x34($sp)
    /* 3688 800669E8 3000B08F */  lw         $s0, 0x30($sp)
    /* 368C 800669EC 0800E003 */  jr         $ra
    /* 3690 800669F0 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel Stg00_SpawnRandomGroup
