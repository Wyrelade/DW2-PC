nonmatching func_80065D2C, 0x58

glabel func_80065D2C
    /* 29CC 80065D2C 0A000624 */  addiu      $a2, $zero, 0xA
    /* 29D0 80065D30 2A10C400 */  slt        $v0, $a2, $a0
    /* 29D4 80065D34 0E004014 */  bnez       $v0, .L80065D70
    /* 29D8 80065D38 0780033C */   lui       $v1, %hi(D_8006AA58)
    /* 29DC 80065D3C 0780023C */  lui        $v0, %hi(D_8006AA58)
    /* 29E0 80065D40 58AA4924 */  addiu      $t1, $v0, %lo(D_8006AA58)
    /* 29E4 80065D44 28002825 */  addiu      $t0, $t1, 0x28
    /* 29E8 80065D48 2C000724 */  addiu      $a3, $zero, 0x2C
  .L80065D4C:
    /* 29EC 80065D4C 0000038D */  lw         $v1, 0x0($t0)
    /* 29F0 80065D50 FCFF0825 */  addiu      $t0, $t0, -0x4
    /* 29F4 80065D54 2110E900 */  addu       $v0, $a3, $t1
    /* 29F8 80065D58 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 29FC 80065D5C 000043AC */  sw         $v1, 0x0($v0)
    /* 2A00 80065D60 2A10C400 */  slt        $v0, $a2, $a0
    /* 2A04 80065D64 F9FF4010 */  beqz       $v0, .L80065D4C
    /* 2A08 80065D68 FCFFE724 */   addiu     $a3, $a3, -0x4
    /* 2A0C 80065D6C 0780033C */  lui        $v1, %hi(D_8006AA58)
  .L80065D70:
    /* 2A10 80065D70 58AA6324 */  addiu      $v1, $v1, %lo(D_8006AA58)
    /* 2A14 80065D74 80100400 */  sll        $v0, $a0, 2
    /* 2A18 80065D78 21104300 */  addu       $v0, $v0, $v1
    /* 2A1C 80065D7C 0800E003 */  jr         $ra
    /* 2A20 80065D80 000045AC */   sw        $a1, 0x0($v0)
endlabel func_80065D2C
