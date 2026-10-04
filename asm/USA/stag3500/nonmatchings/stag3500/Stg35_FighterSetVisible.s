nonmatching Stg35_FighterSetVisible, 0x24

glabel Stg35_FighterSetVisible
    /* 4174 800674D4 2C00828C */  lw         $v0, 0x2C($a0)
    /* 4178 800674D8 0400A010 */  beqz       $a1, .L800674EC
    /* 417C 800674DC 280045AC */   sw        $a1, 0x28($v0)
    /* 4180 800674E0 04000224 */  addiu      $v0, $zero, 0x4
    /* 4184 800674E4 0800E003 */  jr         $ra
    /* 4188 800674E8 300082AC */   sw        $v0, 0x30($a0)
  .L800674EC:
    /* 418C 800674EC 03000224 */  addiu      $v0, $zero, 0x3
    /* 4190 800674F0 0800E003 */  jr         $ra
    /* 4194 800674F4 300082AC */   sw        $v0, 0x30($a0)
endlabel Stg35_FighterSetVisible
