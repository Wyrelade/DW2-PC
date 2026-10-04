nonmatching Stg30_JoinPromptInit, 0x38

glabel Stg30_JoinPromptInit
    /* F540 800728A0 0000A38C */  lw         $v1, 0x0($a1)
    /* F544 800728A4 0780053C */  lui        $a1, %hi(Stg30_Battle)
    /* F548 800728A8 2C00828C */  lw         $v0, 0x2C($a0)
    /* F54C 800728AC C03CA524 */  addiu      $a1, $a1, %lo(Stg30_Battle)
    /* F550 800728B0 000043AC */  sw         $v1, 0x0($v0)
    /* F554 800728B4 40100300 */  sll        $v0, $v1, 1
    /* F558 800728B8 21104300 */  addu       $v0, $v0, $v1
    /* F55C 800728BC C0100200 */  sll        $v0, $v0, 3
    /* F560 800728C0 23104300 */  subu       $v0, $v0, $v1
    /* F564 800728C4 80100200 */  sll        $v0, $v0, 2
    /* F568 800728C8 21104500 */  addu       $v0, $v0, $a1
    /* F56C 800728CC 19004290 */  lbu        $v0, 0x19($v0)
    /* F570 800728D0 0800E003 */  jr         $ra
    /* F574 800728D4 0C0082AC */   sw        $v0, 0xC($a0)
endlabel Stg30_JoinPromptInit
