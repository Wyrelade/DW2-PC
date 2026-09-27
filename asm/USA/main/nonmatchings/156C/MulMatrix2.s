/* Handwritten function */
nonmatching MulMatrix2, 0x10C

glabel MulMatrix2
    /* 1DB34 8002D334 0000888C */  lw         $t0, 0x0($a0)
    /* 1DB38 8002D338 0400898C */  lw         $t1, 0x4($a0)
    /* 1DB3C 8002D33C 08008A8C */  lw         $t2, 0x8($a0)
    /* 1DB40 8002D340 0C008B8C */  lw         $t3, 0xC($a0)
    /* 1DB44 8002D344 10008C8C */  lw         $t4, 0x10($a0)
    /* 1DB48 8002D348 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 1DB4C 8002D34C 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 1DB50 8002D350 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 1DB54 8002D354 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 1DB58 8002D358 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 1DB5C 8002D35C 0000A894 */  lhu        $t0, 0x0($a1)
    /* 1DB60 8002D360 0400A98C */  lw         $t1, 0x4($a1)
    /* 1DB64 8002D364 0C00AA8C */  lw         $t2, 0xC($a1)
    /* 1DB68 8002D368 FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 1DB6C 8002D36C 24482101 */  and        $t1, $t1, $at
    /* 1DB70 8002D370 25400901 */  or         $t0, $t0, $t1
    /* 1DB74 8002D374 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 1DB78 8002D378 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 1DB7C 8002D37C 00000000 */  nop
    /* 1DB80 8002D380 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 1DB84 8002D384 0200A894 */  lhu        $t0, 0x2($a1)
    /* 1DB88 8002D388 0800A98C */  lw         $t1, 0x8($a1)
    /* 1DB8C 8002D38C 0E00AA84 */  lh         $t2, 0xE($a1)
    /* 1DB90 8002D390 004C0900 */  sll        $t1, $t1, 16
    /* 1DB94 8002D394 25400901 */  or         $t0, $t0, $t1
    /* 1DB98 8002D398 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 1DB9C 8002D39C 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 1DBA0 8002D3A0 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 1DBA4 8002D3A4 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 1DBA8 8002D3A8 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 1DBAC 8002D3AC 00000000 */  nop
    /* 1DBB0 8002D3B0 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 1DBB4 8002D3B4 0400A894 */  lhu        $t0, 0x4($a1)
    /* 1DBB8 8002D3B8 0800A98C */  lw         $t1, 0x8($a1)
    /* 1DBBC 8002D3BC 1000AA8C */  lw         $t2, 0x10($a1)
    /* 1DBC0 8002D3C0 FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 1DBC4 8002D3C4 24482101 */  and        $t1, $t1, $at
    /* 1DBC8 8002D3C8 25400901 */  or         $t0, $t0, $t1
    /* 1DBCC 8002D3CC 00480E48 */  mfc2       $t6, $9 /* handwritten instruction */
    /* 1DBD0 8002D3D0 00500F48 */  mfc2       $t7, $10 /* handwritten instruction */
    /* 1DBD4 8002D3D4 00581848 */  mfc2       $t8, $11 /* handwritten instruction */
    /* 1DBD8 8002D3D8 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 1DBDC 8002D3DC 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 1DBE0 8002D3E0 00000000 */  nop
    /* 1DBE4 8002D3E4 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 1DBE8 8002D3E8 FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 1DBEC 8002D3EC 00740E00 */  sll        $t6, $t6, 16
    /* 1DBF0 8002D3F0 2570CB01 */  or         $t6, $t6, $t3
    /* 1DBF4 8002D3F4 0000AEAC */  sw         $t6, 0x0($a1)
    /* 1DBF8 8002D3F8 FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 1DBFC 8002D3FC 00C41800 */  sll        $t8, $t8, 16
    /* 1DC00 8002D400 25C00D03 */  or         $t8, $t8, $t5
    /* 1DC04 8002D404 0C00B8AC */  sw         $t8, 0xC($a1)
    /* 1DC08 8002D408 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 1DC0C 8002D40C 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 1DC10 8002D410 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 1DC14 8002D414 00640C00 */  sll        $t4, $t4, 16
    /* 1DC18 8002D418 25400C01 */  or         $t0, $t0, $t4
    /* 1DC1C 8002D41C 0400A8AC */  sw         $t0, 0x4($a1)
    /* 1DC20 8002D420 FFFFEF31 */  andi       $t7, $t7, 0xFFFF
    /* 1DC24 8002D424 004C0900 */  sll        $t1, $t1, 16
    /* 1DC28 8002D428 25482F01 */  or         $t1, $t1, $t7
    /* 1DC2C 8002D42C 0800A9AC */  sw         $t1, 0x8($a1)
    /* 1DC30 8002D430 1000ABE8 */  swc2       $11, 0x10($a1)
    /* 1DC34 8002D434 2110A000 */  addu       $v0, $a1, $zero
    /* 1DC38 8002D438 0800E003 */  jr         $ra
    /* 1DC3C 8002D43C 00000000 */   nop
endlabel MulMatrix2
    /* 1DC40 8002D440 00000000 */  nop
