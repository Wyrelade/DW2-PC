nonmatching Stg20_FilterPartsList, 0x2A0

glabel Stg20_FilterPartsList
    /* A1DC 8006D53C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* A1E0 8006D540 2800B6AF */  sw         $s6, 0x28($sp)
    /* A1E4 8006D544 21B0A000 */  addu       $s6, $a1, $zero
    /* A1E8 8006D548 1400B1AF */  sw         $s1, 0x14($sp)
    /* A1EC 8006D54C 21880000 */  addu       $s1, $zero, $zero
    /* A1F0 8006D550 3000BFAF */  sw         $ra, 0x30($sp)
    /* A1F4 8006D554 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* A1F8 8006D558 2400B5AF */  sw         $s5, 0x24($sp)
    /* A1FC 8006D55C 2000B4AF */  sw         $s4, 0x20($sp)
    /* A200 8006D560 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* A204 8006D564 1800B2AF */  sw         $s2, 0x18($sp)
    /* A208 8006D568 1000B0AF */  sw         $s0, 0x10($sp)
    /* A20C 8006D56C 2C00948C */  lw         $s4, 0x2C($a0)
    /* A210 8006D570 01000424 */  addiu      $a0, $zero, 0x1
    /* A214 8006D574 21188002 */  addu       $v1, $s4, $zero
  .L8006D578:
    /* A218 8006D578 EC0060A4 */  sh         $zero, 0xEC($v1)
    /* A21C 8006D57C 21109102 */  addu       $v0, $s4, $s1
    /* A220 8006D580 01003126 */  addiu      $s1, $s1, 0x1
    /* A224 8006D584 720144A0 */  sb         $a0, 0x172($v0)
    /* A228 8006D588 4300222A */  slti       $v0, $s1, 0x43
    /* A22C 8006D58C FAFF4014 */  bnez       $v0, .L8006D578
    /* A230 8006D590 02006324 */   addiu     $v1, $v1, 0x2
    /* A234 8006D594 21A80000 */  addu       $s5, $zero, $zero
    /* A238 8006D598 2188A002 */  addu       $s1, $s5, $zero
    /* A23C 8006D59C 0680023C */  lui        $v0, %hi(Save_GameState)
    /* A240 8006D5A0 20E65324 */  addiu      $s3, $v0, %lo(Save_GameState)
    /* A244 8006D5A4 40101100 */  sll        $v0, $s1, 1
  .L8006D5A8:
    /* A248 8006D5A8 21108202 */  addu       $v0, $s4, $v0
    /* A24C 8006D5AC 60005084 */  lh         $s0, 0x60($v0)
    /* A250 8006D5B0 00000000 */  nop
    /* A254 8006D5B4 3F000012 */  beqz       $s0, .L8006D6B4
    /* A258 8006D5B8 63000224 */   addiu     $v0, $zero, 0x63
    /* A25C 8006D5BC 0700C212 */  beq        $s6, $v0, .L8006D5DC
    /* A260 8006D5C0 00000000 */   nop
    /* A264 8006D5C4 3078000C */  jal        Item_GetCategory
    /* A268 8006D5C8 21200002 */   addu      $a0, $s0, $zero
    /* A26C 8006D5CC 39005614 */  bne        $v0, $s6, .L8006D6B4
    /* A270 8006D5D0 EC008426 */   addiu     $a0, $s4, 0xEC
    /* A274 8006D5D4 AAB50108 */  j          .L8006D6A8
    /* A278 8006D5D8 2128A002 */   addu      $a1, $s5, $zero
  .L8006D5DC:
    /* A27C 8006D5DC 3C006296 */  lhu        $v0, 0x3C($s3)
    /* A280 8006D5E0 00000000 */  nop
    /* A284 8006D5E4 05004014 */  bnez       $v0, .L8006D5FC
    /* A288 8006D5E8 21900000 */   addu      $s2, $zero, $zero
    /* A28C 8006D5EC 3078000C */  jal        Item_GetCategory
    /* A290 8006D5F0 21200002 */   addu      $a0, $s0, $zero
    /* A294 8006D5F4 07004238 */  xori       $v0, $v0, 0x7
    /* A298 8006D5F8 0100522C */  sltiu      $s2, $v0, 0x1
  .L8006D5FC:
    /* A29C 8006D5FC 3E006296 */  lhu        $v0, 0x3E($s3)
    /* A2A0 8006D600 00000000 */  nop
    /* A2A4 8006D604 07004014 */  bnez       $v0, .L8006D624
    /* A2A8 8006D608 00000000 */   nop
    /* A2AC 8006D60C 3078000C */  jal        Item_GetCategory
    /* A2B0 8006D610 21200002 */   addu      $a0, $s0, $zero
    /* A2B4 8006D614 08000324 */  addiu      $v1, $zero, 0x8
    /* A2B8 8006D618 02004314 */  bne        $v0, $v1, .L8006D624
    /* A2BC 8006D61C 00000000 */   nop
    /* A2C0 8006D620 01001224 */  addiu      $s2, $zero, 0x1
  .L8006D624:
    /* A2C4 8006D624 40006296 */  lhu        $v0, 0x40($s3)
    /* A2C8 8006D628 00000000 */  nop
    /* A2CC 8006D62C 07004014 */  bnez       $v0, .L8006D64C
    /* A2D0 8006D630 00000000 */   nop
    /* A2D4 8006D634 3078000C */  jal        Item_GetCategory
    /* A2D8 8006D638 21200002 */   addu      $a0, $s0, $zero
    /* A2DC 8006D63C 09000324 */  addiu      $v1, $zero, 0x9
    /* A2E0 8006D640 02004314 */  bne        $v0, $v1, .L8006D64C
    /* A2E4 8006D644 00000000 */   nop
    /* A2E8 8006D648 01001224 */  addiu      $s2, $zero, 0x1
  .L8006D64C:
    /* A2EC 8006D64C 42006296 */  lhu        $v0, 0x42($s3)
    /* A2F0 8006D650 00000000 */  nop
    /* A2F4 8006D654 07004014 */  bnez       $v0, .L8006D674
    /* A2F8 8006D658 00000000 */   nop
    /* A2FC 8006D65C 3078000C */  jal        Item_GetCategory
    /* A300 8006D660 21200002 */   addu      $a0, $s0, $zero
    /* A304 8006D664 0A000324 */  addiu      $v1, $zero, 0xA
    /* A308 8006D668 02004314 */  bne        $v0, $v1, .L8006D674
    /* A30C 8006D66C 00000000 */   nop
    /* A310 8006D670 01001224 */  addiu      $s2, $zero, 0x1
  .L8006D674:
    /* A314 8006D674 44006296 */  lhu        $v0, 0x44($s3)
    /* A318 8006D678 00000000 */  nop
    /* A31C 8006D67C 07004014 */  bnez       $v0, .L8006D69C
    /* A320 8006D680 00000000 */   nop
    /* A324 8006D684 3078000C */  jal        Item_GetCategory
    /* A328 8006D688 21200002 */   addu      $a0, $s0, $zero
    /* A32C 8006D68C 0B000324 */  addiu      $v1, $zero, 0xB
    /* A330 8006D690 02004314 */  bne        $v0, $v1, .L8006D69C
    /* A334 8006D694 00000000 */   nop
    /* A338 8006D698 01001224 */  addiu      $s2, $zero, 0x1
  .L8006D69C:
    /* A33C 8006D69C 05004012 */  beqz       $s2, .L8006D6B4
    /* A340 8006D6A0 EC008426 */   addiu     $a0, $s4, 0xEC
    /* A344 8006D6A4 2128A002 */  addu       $a1, $s5, $zero
  .L8006D6A8:
    /* A348 8006D6A8 3DB5010C */  jal        Stg20_InsertDescS16
    /* A34C 8006D6AC 21300002 */   addu      $a2, $s0, $zero
    /* A350 8006D6B0 0100B526 */  addiu      $s5, $s5, 0x1
  .L8006D6B4:
    /* A354 8006D6B4 01003126 */  addiu      $s1, $s1, 0x1
    /* A358 8006D6B8 4300222A */  slti       $v0, $s1, 0x43
    /* A35C 8006D6BC BAFF4014 */  bnez       $v0, .L8006D5A8
    /* A360 8006D6C0 40101100 */   sll       $v0, $s1, 1
    /* A364 8006D6C4 21980000 */  addu       $s3, $zero, $zero
    /* A368 8006D6C8 21886002 */  addu       $s1, $s3, $zero
    /* A36C 8006D6CC 01001724 */  addiu      $s7, $zero, 0x1
    /* A370 8006D6D0 21808002 */  addu       $s0, $s4, $zero
    /* A374 8006D6D4 21908002 */  addu       $s2, $s4, $zero
    /* A378 8006D6D8 4800838E */  lw         $v1, 0x48($s4)
    /* A37C 8006D6DC 01000224 */  addiu      $v0, $zero, 0x1
    /* A380 8006D6E0 E80095AE */  sw         $s5, 0xE8($s4)
    /* A384 8006D6E4 04A86200 */  sllv       $s5, $v0, $v1
  .L8006D6E8:
    /* A388 8006D6E8 EC004486 */  lh         $a0, 0xEC($s2)
    /* A38C 8006D6EC 00000000 */  nop
    /* A390 8006D6F0 0A008010 */  beqz       $a0, .L8006D71C
    /* A394 8006D6F4 00000000 */   nop
    /* A398 8006D6F8 6B78000C */  jal        Item_GetBodyMask
    /* A39C 8006D6FC 00000000 */   nop
    /* A3A0 8006D700 24105500 */  and        $v0, $v0, $s5
    /* A3A4 8006D704 04004010 */  beqz       $v0, .L8006D718
    /* A3A8 8006D708 00000000 */   nop
    /* A3AC 8006D70C 720100A2 */  sb         $zero, 0x172($s0)
    /* A3B0 8006D710 C7B50108 */  j          .L8006D71C
    /* A3B4 8006D714 01007326 */   addiu     $s3, $s3, 0x1
  .L8006D718:
    /* A3B8 8006D718 720117A2 */  sb         $s7, 0x172($s0)
  .L8006D71C:
    /* A3BC 8006D71C 01001026 */  addiu      $s0, $s0, 0x1
    /* A3C0 8006D720 01003126 */  addiu      $s1, $s1, 0x1
    /* A3C4 8006D724 4300222A */  slti       $v0, $s1, 0x43
    /* A3C8 8006D728 EFFF4014 */  bnez       $v0, .L8006D6E8
    /* A3CC 8006D72C 02005226 */   addiu     $s2, $s2, 0x2
    /* A3D0 8006D730 02006016 */  bnez       $s3, .L8006D73C
    /* A3D4 8006D734 01000224 */   addiu     $v0, $zero, 0x1
    /* A3D8 8006D738 E80080AE */  sw         $zero, 0xE8($s4)
  .L8006D73C:
    /* A3DC 8006D73C 0400C212 */  beq        $s6, $v0, .L8006D750
    /* A3E0 8006D740 21980000 */   addu      $s3, $zero, $zero
    /* A3E4 8006D744 03000224 */  addiu      $v0, $zero, 0x3
    /* A3E8 8006D748 1900C216 */  bne        $s6, $v0, .L8006D7B0
    /* A3EC 8006D74C 00000000 */   nop
  .L8006D750:
    /* A3F0 8006D750 21880000 */  addu       $s1, $zero, $zero
    /* A3F4 8006D754 01001624 */  addiu      $s6, $zero, 0x1
    /* A3F8 8006D758 21908002 */  addu       $s2, $s4, $zero
    /* A3FC 8006D75C 21804002 */  addu       $s0, $s2, $zero
  .L8006D760:
    /* A400 8006D760 0D006016 */  bnez       $s3, .L8006D798
    /* A404 8006D764 00000000 */   nop
    /* A408 8006D768 EC004486 */  lh         $a0, 0xEC($s2)
    /* A40C 8006D76C 00000000 */  nop
    /* A410 8006D770 09008010 */  beqz       $a0, .L8006D798
    /* A414 8006D774 00000000 */   nop
    /* A418 8006D778 6B78000C */  jal        Item_GetBodyMask
    /* A41C 8006D77C 00000000 */   nop
    /* A420 8006D780 24105500 */  and        $v0, $v0, $s5
    /* A424 8006D784 04004010 */  beqz       $v0, .L8006D798
    /* A428 8006D788 00000000 */   nop
    /* A42C 8006D78C 720100A2 */  sb         $zero, 0x172($s0)
    /* A430 8006D790 E7B50108 */  j          .L8006D79C
    /* A434 8006D794 01001324 */   addiu     $s3, $zero, 0x1
  .L8006D798:
    /* A438 8006D798 720116A2 */  sb         $s6, 0x172($s0)
  .L8006D79C:
    /* A43C 8006D79C 01001026 */  addiu      $s0, $s0, 0x1
    /* A440 8006D7A0 01003126 */  addiu      $s1, $s1, 0x1
    /* A444 8006D7A4 4300222A */  slti       $v0, $s1, 0x43
    /* A448 8006D7A8 EDFF4014 */  bnez       $v0, .L8006D760
    /* A44C 8006D7AC 02005226 */   addiu     $s2, $s2, 0x2
  .L8006D7B0:
    /* A450 8006D7B0 3000BF8F */  lw         $ra, 0x30($sp)
    /* A454 8006D7B4 2C00B78F */  lw         $s7, 0x2C($sp)
    /* A458 8006D7B8 2800B68F */  lw         $s6, 0x28($sp)
    /* A45C 8006D7BC 2400B58F */  lw         $s5, 0x24($sp)
    /* A460 8006D7C0 2000B48F */  lw         $s4, 0x20($sp)
    /* A464 8006D7C4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* A468 8006D7C8 1800B28F */  lw         $s2, 0x18($sp)
    /* A46C 8006D7CC 1400B18F */  lw         $s1, 0x14($sp)
    /* A470 8006D7D0 1000B08F */  lw         $s0, 0x10($sp)
    /* A474 8006D7D4 0800E003 */  jr         $ra
    /* A478 8006D7D8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg20_FilterPartsList
