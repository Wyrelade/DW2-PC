nonmatching Anim_SetModelAnimFile, 0x28

glabel Anim_SetModelAnimFile
    /* FA4C 8001F24C 3C00828C */  lw         $v0, 0x3C($a0)
    /* FA50 8001F250 01000324 */  addiu      $v1, $zero, 0x1
    /* FA54 8001F254 540045AC */  sw         $a1, 0x54($v0)
    /* FA58 8001F258 580040AC */  sw         $zero, 0x58($v0)
    /* FA5C 8001F25C 500040AC */  sw         $zero, 0x50($v0)
    /* FA60 8001F260 480046AC */  sw         $a2, 0x48($v0)
    /* FA64 8001F264 4C0040AC */  sw         $zero, 0x4C($v0)
    /* FA68 8001F268 5C0043AC */  sw         $v1, 0x5C($v0)
    /* FA6C 8001F26C 0800E003 */  jr         $ra
    /* FA70 8001F270 600040AC */   sw        $zero, 0x60($v0)
endlabel Anim_SetModelAnimFile
