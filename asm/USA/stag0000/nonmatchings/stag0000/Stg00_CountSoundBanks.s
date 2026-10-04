nonmatching Stg00_CountSoundBanks, 0x34

glabel Stg00_CountSoundBanks
    /* 4E30 80068190 0780033C */  lui        $v1, %hi(Stg00_SoundBanks)
    /* 4E34 80068194 5C92628C */  lw         $v0, %lo(Stg00_SoundBanks)($v1)
    /* 4E38 80068198 00000000 */  nop
    /* 4E3C 8006819C 07004010 */  beqz       $v0, .L800681BC
    /* 4E40 800681A0 21200000 */   addu      $a0, $zero, $zero
    /* 4E44 800681A4 5C926324 */  addiu      $v1, $v1, %lo(Stg00_SoundBanks)
  .L800681A8:
    /* 4E48 800681A8 04006324 */  addiu      $v1, $v1, 0x4
    /* 4E4C 800681AC 0000628C */  lw         $v0, 0x0($v1)
    /* 4E50 800681B0 00000000 */  nop
    /* 4E54 800681B4 FCFF4014 */  bnez       $v0, .L800681A8
    /* 4E58 800681B8 01008424 */   addiu     $a0, $a0, 0x1
  .L800681BC:
    /* 4E5C 800681BC 0800E003 */  jr         $ra
    /* 4E60 800681C0 21108000 */   addu      $v0, $a0, $zero
endlabel Stg00_CountSoundBanks
