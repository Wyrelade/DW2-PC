nonmatching Actor_SetAxisMotion, 0x38

glabel Actor_SetAxisMotion
    /* 116B0 80020EB0 40100500 */  sll        $v0, $a1, 1
    /* 116B4 80020EB4 21104500 */  addu       $v0, $v0, $a1
    /* 116B8 80020EB8 80100200 */  sll        $v0, $v0, 2
    /* 116BC 80020EBC 6C004224 */  addiu      $v0, $v0, 0x6C
    /* 116C0 80020EC0 3800838C */  lw         $v1, 0x38($a0)
    /* 116C4 80020EC4 0000C48C */  lw         $a0, 0x0($a2)
    /* 116C8 80020EC8 21186200 */  addu       $v1, $v1, $v0
    /* 116CC 80020ECC 000064AC */  sw         $a0, 0x0($v1)
    /* 116D0 80020ED0 0400C28C */  lw         $v0, 0x4($a2)
    /* 116D4 80020ED4 00000000 */  nop
    /* 116D8 80020ED8 040062AC */  sw         $v0, 0x4($v1)
    /* 116DC 80020EDC 0800C28C */  lw         $v0, 0x8($a2)
    /* 116E0 80020EE0 0800E003 */  jr         $ra
    /* 116E4 80020EE4 080062AC */   sw        $v0, 0x8($v1)
endlabel Actor_SetAxisMotion
