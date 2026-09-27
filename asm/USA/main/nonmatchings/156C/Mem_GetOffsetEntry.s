nonmatching Mem_GetOffsetEntry, 0x24

glabel Mem_GetOffsetEntry
    /* 141E4 800239E4 06008010 */  beqz       $a0, .L80023A00
    /* 141E8 800239E8 FFFF8230 */   andi      $v0, $a0, 0xFFFF
    /* 141EC 800239EC 80100200 */  sll        $v0, $v0, 2
    /* 141F0 800239F0 21104500 */  addu       $v0, $v0, $a1
    /* 141F4 800239F4 0000428C */  lw         $v0, 0x0($v0)
    /* 141F8 800239F8 0800E003 */  jr         $ra
    /* 141FC 800239FC 21104500 */   addu      $v0, $v0, $a1
  .L80023A00:
    /* 14200 80023A00 0800E003 */  jr         $ra
    /* 14204 80023A04 21100000 */   addu      $v0, $zero, $zero
endlabel Mem_GetOffsetEntry
