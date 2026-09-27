nonmatching Actor_StopAxisMotion, 0x28

glabel Actor_StopAxisMotion
    /* 116E8 80020EE8 40100500 */  sll        $v0, $a1, 1
    /* 116EC 80020EEC 21104500 */  addu       $v0, $v0, $a1
    /* 116F0 80020EF0 80100200 */  sll        $v0, $v0, 2
    /* 116F4 80020EF4 3800838C */  lw         $v1, 0x38($a0)
    /* 116F8 80020EF8 6C004224 */  addiu      $v0, $v0, 0x6C
    /* 116FC 80020EFC 21186200 */  addu       $v1, $v1, $v0
    /* 11700 80020F00 080060AC */  sw         $zero, 0x8($v1)
    /* 11704 80020F04 040060AC */  sw         $zero, 0x4($v1)
    /* 11708 80020F08 0800E003 */  jr         $ra
    /* 1170C 80020F0C 000060AC */   sw        $zero, 0x0($v1)
endlabel Actor_StopAxisMotion
