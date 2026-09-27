nonmatching SetDrawMove, 0x60

glabel SetDrawMove
    /* 1B354 8002AB54 21408000 */  addu       $t0, $a0, $zero
    /* 1B358 8002AB58 0400A284 */  lh         $v0, 0x4($a1)
    /* 1B35C 8002AB5C 00000000 */  nop
    /* 1B360 8002AB60 05004010 */  beqz       $v0, .L8002AB78
    /* 1B364 8002AB64 05000424 */   addiu     $a0, $zero, 0x5
    /* 1B368 8002AB68 0600A284 */  lh         $v0, 0x6($a1)
    /* 1B36C 8002AB6C 00000000 */  nop
    /* 1B370 8002AB70 03004014 */  bnez       $v0, .L8002AB80
    /* 1B374 8002AB74 0001023C */   lui       $v0, (0x1000000 >> 16)
  .L8002AB78:
    /* 1B378 8002AB78 21200000 */  addu       $a0, $zero, $zero
    /* 1B37C 8002AB7C 0001023C */  lui        $v0, (0x1000000 >> 16)
  .L8002AB80:
    /* 1B380 8002AB80 040002AD */  sw         $v0, 0x4($t0)
    /* 1B384 8002AB84 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 1B388 8002AB88 080002AD */  sw         $v0, 0x8($t0)
    /* 1B38C 8002AB8C 00140700 */  sll        $v0, $a3, 16
    /* 1B390 8002AB90 FFFFC330 */  andi       $v1, $a2, 0xFFFF
    /* 1B394 8002AB94 030004A1 */  sb         $a0, 0x3($t0)
    /* 1B398 8002AB98 0000A48C */  lw         $a0, 0x0($a1)
    /* 1B39C 8002AB9C 25104300 */  or         $v0, $v0, $v1
    /* 1B3A0 8002ABA0 100002AD */  sw         $v0, 0x10($t0)
    /* 1B3A4 8002ABA4 0C0004AD */  sw         $a0, 0xC($t0)
    /* 1B3A8 8002ABA8 0400A28C */  lw         $v0, 0x4($a1)
    /* 1B3AC 8002ABAC 0800E003 */  jr         $ra
    /* 1B3B0 8002ABB0 140002AD */   sw        $v0, 0x14($t0)
endlabel SetDrawMove
