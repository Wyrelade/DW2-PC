nonmatching SetDrawMode, 0x94

glabel SetDrawMode
    /* 1B3B4 8002ABB4 21408000 */  addu       $t0, $a0, $zero
    /* 1B3B8 8002ABB8 00E1033C */  lui        $v1, (0xE1000200 >> 16)
    /* 1B3BC 8002ABBC 1000A98F */  lw         $t1, 0x10($sp)
    /* 1B3C0 8002ABC0 02000224 */  addiu      $v0, $zero, 0x2
    /* 1B3C4 8002ABC4 0200C010 */  beqz       $a2, .L8002ABD0
    /* 1B3C8 8002ABC8 030002A1 */   sb        $v0, 0x3($t0)
    /* 1B3CC 8002ABCC 00026334 */  ori        $v1, $v1, (0xE1000200 & 0xFFFF)
  .L8002ABD0:
    /* 1B3D0 8002ABD0 0200A010 */  beqz       $a1, .L8002ABDC
    /* 1B3D4 8002ABD4 FF09E230 */   andi      $v0, $a3, 0x9FF
    /* 1B3D8 8002ABD8 00044234 */  ori        $v0, $v0, 0x400
  .L8002ABDC:
    /* 1B3DC 8002ABDC 25106200 */  or         $v0, $v1, $v0
    /* 1B3E0 8002ABE0 16002011 */  beqz       $t1, .L8002AC3C
    /* 1B3E4 8002ABE4 040002AD */   sw        $v0, 0x4($t0)
    /* 1B3E8 8002ABE8 00E2033C */  lui        $v1, (0xE2000000 >> 16)
    /* 1B3EC 8002ABEC 02002491 */  lbu        $a0, 0x2($t1)
    /* 1B3F0 8002ABF0 00002291 */  lbu        $v0, 0x0($t1)
    /* 1B3F4 8002ABF4 C2200400 */  srl        $a0, $a0, 3
    /* 1B3F8 8002ABF8 C0230400 */  sll        $a0, $a0, 15
    /* 1B3FC 8002ABFC C2100200 */  srl        $v0, $v0, 3
    /* 1B400 8002AC00 80120200 */  sll        $v0, $v0, 10
    /* 1B404 8002AC04 25104300 */  or         $v0, $v0, $v1
    /* 1B408 8002AC08 25208200 */  or         $a0, $a0, $v0
    /* 1B40C 8002AC0C 06002385 */  lh         $v1, 0x6($t1)
    /* 1B410 8002AC10 04002285 */  lh         $v0, 0x4($t1)
    /* 1B414 8002AC14 23180300 */  negu       $v1, $v1
    /* 1B418 8002AC18 80180300 */  sll        $v1, $v1, 2
    /* 1B41C 8002AC1C E0036330 */  andi       $v1, $v1, 0x3E0
    /* 1B420 8002AC20 25208300 */  or         $a0, $a0, $v1
    /* 1B424 8002AC24 23100200 */  negu       $v0, $v0
    /* 1B428 8002AC28 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1B42C 8002AC2C C3100200 */  sra        $v0, $v0, 3
    /* 1B430 8002AC30 25208200 */  or         $a0, $a0, $v0
    /* 1B434 8002AC34 10AB0008 */  j          .L8002AC40
    /* 1B438 8002AC38 080004AD */   sw        $a0, 0x8($t0)
  .L8002AC3C:
    /* 1B43C 8002AC3C 080000AD */  sw         $zero, 0x8($t0)
  .L8002AC40:
    /* 1B440 8002AC40 0800E003 */  jr         $ra
    /* 1B444 8002AC44 00000000 */   nop
endlabel SetDrawMode
    /* 1B448 8002AC48 00000000 */  nop
    /* 1B44C 8002AC4C 00000000 */  nop
    /* 1B450 8002AC50 00000000 */  nop
