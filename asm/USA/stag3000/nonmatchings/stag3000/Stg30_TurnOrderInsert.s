nonmatching Stg30_TurnOrderInsert, 0x58

glabel Stg30_TurnOrderInsert
    /* B1FC 8006E55C 0A000624 */  addiu      $a2, $zero, 0xA
    /* B200 8006E560 2A10C400 */  slt        $v0, $a2, $a0
    /* B204 8006E564 0E004014 */  bnez       $v0, .L8006E5A0
    /* B208 8006E568 0780033C */   lui       $v1, %hi(Stg30_TurnOrder)
    /* B20C 8006E56C 0780023C */  lui        $v0, %hi(Stg30_TurnOrder)
    /* B210 8006E570 203A4924 */  addiu      $t1, $v0, %lo(Stg30_TurnOrder)
    /* B214 8006E574 28002825 */  addiu      $t0, $t1, 0x28
    /* B218 8006E578 2C000724 */  addiu      $a3, $zero, 0x2C
  .L8006E57C:
    /* B21C 8006E57C 0000038D */  lw         $v1, 0x0($t0)
    /* B220 8006E580 FCFF0825 */  addiu      $t0, $t0, -0x4
    /* B224 8006E584 2110E900 */  addu       $v0, $a3, $t1
    /* B228 8006E588 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* B22C 8006E58C 000043AC */  sw         $v1, 0x0($v0)
    /* B230 8006E590 2A10C400 */  slt        $v0, $a2, $a0
    /* B234 8006E594 F9FF4010 */  beqz       $v0, .L8006E57C
    /* B238 8006E598 FCFFE724 */   addiu     $a3, $a3, -0x4
    /* B23C 8006E59C 0780033C */  lui        $v1, %hi(Stg30_TurnOrder)
  .L8006E5A0:
    /* B240 8006E5A0 203A6324 */  addiu      $v1, $v1, %lo(Stg30_TurnOrder)
    /* B244 8006E5A4 80100400 */  sll        $v0, $a0, 2
    /* B248 8006E5A8 21104300 */  addu       $v0, $v0, $v1
    /* B24C 8006E5AC 0800E003 */  jr         $ra
    /* B250 8006E5B0 000045AC */   sw        $a1, 0x0($v0)
endlabel Stg30_TurnOrderInsert
