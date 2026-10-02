nonmatching Card_EventToMcErr, 0x54

glabel Card_EventToMcErr
    /* 2FC18 8003F418 01000224 */  addiu      $v0, $zero, 0x1
    /* 2FC1C 8003F41C 10008210 */  beq        $a0, $v0, .L8003F460
    /* 2FC20 8003F420 21180000 */   addu      $v1, $zero, $zero
    /* 2FC24 8003F424 02008228 */  slti       $v0, $a0, 0x2
    /* 2FC28 8003F428 05004010 */  beqz       $v0, .L8003F440
    /* 2FC2C 8003F42C 00000000 */   nop
    /* 2FC30 8003F430 0C008010 */  beqz       $a0, .L8003F464
    /* 2FC34 8003F434 00000000 */   nop
    /* 2FC38 8003F438 19FD0008 */  j          .L8003F464
    /* 2FC3C 8003F43C 00808334 */   ori       $v1, $a0, 0x8000
  .L8003F440:
    /* 2FC40 8003F440 02000224 */  addiu      $v0, $zero, 0x2
    /* 2FC44 8003F444 07008210 */  beq        $a0, $v0, .L8003F464
    /* 2FC48 8003F448 01000324 */   addiu     $v1, $zero, 0x1
    /* 2FC4C 8003F44C 04000224 */  addiu      $v0, $zero, 0x4
    /* 2FC50 8003F450 04008214 */  bne        $a0, $v0, .L8003F464
    /* 2FC54 8003F454 00808334 */   ori       $v1, $a0, 0x8000
    /* 2FC58 8003F458 19FD0008 */  j          .L8003F464
    /* 2FC5C 8003F45C 03000324 */   addiu     $v1, $zero, 0x3
  .L8003F460:
    /* 2FC60 8003F460 02000324 */  addiu      $v1, $zero, 0x2
  .L8003F464:
    /* 2FC64 8003F464 0800E003 */  jr         $ra
    /* 2FC68 8003F468 21106000 */   addu      $v0, $v1, $zero
endlabel Card_EventToMcErr
