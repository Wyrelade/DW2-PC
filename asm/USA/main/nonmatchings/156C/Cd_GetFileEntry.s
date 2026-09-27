nonmatching Cd_GetFileEntry, 0x44

glabel Cd_GetFileEntry
    /* 141A0 800239A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 141A4 800239A4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 141A8 800239A8 09008010 */  beqz       $a0, .L800239D0
    /* 141AC 800239AC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 141B0 800239B0 FFFF9030 */  andi       $s0, $a0, 0xFFFF
    /* 141B4 800239B4 6C8F000C */  jal        Cd_GetFileSync
    /* 141B8 800239B8 02240400 */   srl       $a0, $a0, 16
    /* 141BC 800239BC 80801000 */  sll        $s0, $s0, 2
    /* 141C0 800239C0 21800202 */  addu       $s0, $s0, $v0
    /* 141C4 800239C4 0000038E */  lw         $v1, 0x0($s0)
    /* 141C8 800239C8 758E0008 */  j          .L800239D4
    /* 141CC 800239CC 21106200 */   addu      $v0, $v1, $v0
  .L800239D0:
    /* 141D0 800239D0 21100000 */  addu       $v0, $zero, $zero
  .L800239D4:
    /* 141D4 800239D4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 141D8 800239D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 141DC 800239DC 0800E003 */  jr         $ra
    /* 141E0 800239E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Cd_GetFileEntry
