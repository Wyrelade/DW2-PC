nonmatching Stg35_FindSkillGroup, 0x94

glabel Stg35_FindSkillGroup
    /* 6D74 8006A0D4 1000AB8F */  lw         $t3, 0x10($sp)
    /* 6D78 8006A0D8 21480000 */  addu       $t1, $zero, $zero
    /* 6D7C 8006A0DC FF008430 */  andi       $a0, $a0, 0xFF
    /* 6D80 8006A0E0 0780023C */  lui        $v0, %hi(Stg35_SkillGroups)
    /* 6D84 8006A0E4 24AA4A24 */  addiu      $t2, $v0, %lo(Stg35_SkillGroups)
  .L8006A0E8:
    /* 6D88 8006A0E8 0000438D */  lw         $v1, 0x0($t2)
    /* 6D8C 8006A0EC 00000000 */  nop
    /* 6D90 8006A0F0 00006284 */  lh         $v0, 0x0($v1)
    /* 6D94 8006A0F4 00000000 */  nop
    /* 6D98 8006A0F8 12004010 */  beqz       $v0, .L8006A144
    /* 6D9C 8006A0FC 21400000 */   addu      $t0, $zero, $zero
    /* 6DA0 8006A100 00006284 */  lh         $v0, 0x0($v1)
  .L8006A104:
    /* 6DA4 8006A104 00000000 */  nop
    /* 6DA8 8006A108 09004414 */  bne        $v0, $a0, .L8006A130
    /* 6DAC 8006A10C 00000000 */   nop
    /* 6DB0 8006A110 0000A9AC */  sw         $t1, 0x0($a1)
    /* 6DB4 8006A114 0000C8AC */  sw         $t0, 0x0($a2)
    /* 6DB8 8006A118 04006284 */  lh         $v0, 0x4($v1)
    /* 6DBC 8006A11C 00000000 */  nop
    /* 6DC0 8006A120 0000E2AC */  sw         $v0, 0x0($a3)
    /* 6DC4 8006A124 02006284 */  lh         $v0, 0x2($v1)
    /* 6DC8 8006A128 0800E003 */  jr         $ra
    /* 6DCC 8006A12C 000062AD */   sw        $v0, 0x0($t3)
  .L8006A130:
    /* 6DD0 8006A130 06006324 */  addiu      $v1, $v1, 0x6
    /* 6DD4 8006A134 00006284 */  lh         $v0, 0x0($v1)
    /* 6DD8 8006A138 00000000 */  nop
    /* 6DDC 8006A13C F1FF4014 */  bnez       $v0, .L8006A104
    /* 6DE0 8006A140 01000825 */   addiu     $t0, $t0, 0x1
  .L8006A144:
    /* 6DE4 8006A144 01002925 */  addiu      $t1, $t1, 0x1
    /* 6DE8 8006A148 06002229 */  slti       $v0, $t1, 0x6
    /* 6DEC 8006A14C E6FF4014 */  bnez       $v0, .L8006A0E8
    /* 6DF0 8006A150 04004A25 */   addiu     $t2, $t2, 0x4
    /* 6DF4 8006A154 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 6DF8 8006A158 0000A2AC */  sw         $v0, 0x0($a1)
    /* 6DFC 8006A15C 64000224 */  addiu      $v0, $zero, 0x64
    /* 6E00 8006A160 0800E003 */  jr         $ra
    /* 6E04 8006A164 0000C2AC */   sw        $v0, 0x0($a2)
endlabel Stg35_FindSkillGroup
