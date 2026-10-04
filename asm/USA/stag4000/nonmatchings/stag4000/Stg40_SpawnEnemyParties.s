nonmatching Stg40_SpawnEnemyParties, 0x2E0

glabel Stg40_SpawnEnemyParties
    /* A3D8 8006D738 0780023C */  lui        $v0, %hi(D_80072B60)
    /* A3DC 8006D73C 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* A3E0 8006D740 A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* A3E4 8006D744 5C00BFAF */  sw         $ra, 0x5C($sp)
    /* A3E8 8006D748 5800B6AF */  sw         $s6, 0x58($sp)
    /* A3EC 8006D74C 5400B5AF */  sw         $s5, 0x54($sp)
    /* A3F0 8006D750 5000B4AF */  sw         $s4, 0x50($sp)
    /* A3F4 8006D754 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* A3F8 8006D758 4800B2AF */  sw         $s2, 0x48($sp)
    /* A3FC 8006D75C 4400B1AF */  sw         $s1, 0x44($sp)
    /* A400 8006D760 4000B0AF */  sw         $s0, 0x40($sp)
    /* A404 8006D764 1400428C */  lw         $v0, 0x14($v0)
    /* A408 8006D768 00000000 */  nop
    /* A40C 8006D76C 1000538C */  lw         $s3, 0x10($v0)
    /* A410 8006D770 00000000 */  nop
    /* A414 8006D774 00006392 */  lbu        $v1, 0x0($s3)
    /* A418 8006D778 FF000224 */  addiu      $v0, $zero, 0xFF
    /* A41C 8006D77C 9C006210 */  beq        $v1, $v0, .L8006D9F0
    /* A420 8006D780 0780023C */   lui       $v0, %hi(Stg40_EnemyPaceTable)
    /* A424 8006D784 04295524 */  addiu      $s5, $v0, %lo(Stg40_EnemyPaceTable)
    /* A428 8006D788 0780023C */  lui        $v0, %hi(Stg40_EnemyAiTable)
    /* A42C 8006D78C F4285424 */  addiu      $s4, $v0, %lo(Stg40_EnemyAiTable)
    /* A430 8006D790 1800B627 */  addiu      $s6, $sp, 0x18
    /* A434 8006D794 0580023C */  lui        $v0, %hi(D_8005071C)
  .L8006D798:
    /* A438 8006D798 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* A43C 8006D79C 00000000 */  nop
    /* A440 8006D7A0 0E004284 */  lh         $v0, 0xE($v0)
    /* A444 8006D7A4 00000000 */  nop
    /* A448 8006D7A8 0A004228 */  slti       $v0, $v0, 0xA
    /* A44C 8006D7AC 90004010 */  beqz       $v0, .L8006D9F0
    /* A450 8006D7B0 00000000 */   nop
    /* A454 8006D7B4 71C4010C */  jal        Stg40_RandInt
    /* A458 8006D7B8 04000424 */   addiu     $a0, $zero, 0x4
    /* A45C 8006D7BC 21184000 */  addu       $v1, $v0, $zero
    /* A460 8006D7C0 01000224 */  addiu      $v0, $zero, 0x1
    /* A464 8006D7C4 0A006210 */  beq        $v1, $v0, .L8006D7F0
    /* A468 8006D7C8 02006228 */   slti      $v0, $v1, 0x2
    /* A46C 8006D7CC 05004014 */  bnez       $v0, .L8006D7E4
    /* A470 8006D7D0 02000224 */   addiu     $v0, $zero, 0x2
    /* A474 8006D7D4 0B006210 */  beq        $v1, $v0, .L8006D804
    /* A478 8006D7D8 03000224 */   addiu     $v0, $zero, 0x3
    /* A47C 8006D7DC 0C006210 */  beq        $v1, $v0, .L8006D810
    /* A480 8006D7E0 00000000 */   nop
  .L8006D7E4:
    /* A484 8006D7E4 02006396 */  lhu        $v1, 0x2($s3)
    /* A488 8006D7E8 07B60108 */  j          .L8006D81C
    /* A48C 8006D7EC 0F006330 */   andi      $v1, $v1, 0xF
  .L8006D7F0:
    /* A490 8006D7F0 0000628E */  lw         $v0, 0x0($s3)
    /* A494 8006D7F4 00000000 */  nop
    /* A498 8006D7F8 021D0200 */  srl        $v1, $v0, 20
    /* A49C 8006D7FC 07B60108 */  j          .L8006D81C
    /* A4A0 8006D800 0F006330 */   andi      $v1, $v1, 0xF
  .L8006D804:
    /* A4A4 8006D804 03006392 */  lbu        $v1, 0x3($s3)
    /* A4A8 8006D808 07B60108 */  j          .L8006D81C
    /* A4AC 8006D80C 0F006330 */   andi      $v1, $v1, 0xF
  .L8006D810:
    /* A4B0 8006D810 0000628E */  lw         $v0, 0x0($s3)
    /* A4B4 8006D814 00000000 */  nop
    /* A4B8 8006D818 021F0200 */  srl        $v1, $v0, 28
  .L8006D81C:
    /* A4BC 8006D81C 6F006010 */  beqz       $v1, .L8006D9DC
    /* A4C0 8006D820 0780023C */   lui       $v0, %hi(D_80072B60)
    /* A4C4 8006D824 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* A4C8 8006D828 00000000 */  nop
    /* A4CC 8006D82C 1000428C */  lw         $v0, 0x10($v0)
    /* A4D0 8006D830 00000000 */  nop
    /* A4D4 8006D834 21106200 */  addu       $v0, $v1, $v0
    /* A4D8 8006D838 2F005090 */  lbu        $s0, 0x2F($v0)
    /* A4DC 8006D83C 1800A527 */  addiu      $a1, $sp, 0x18
    /* A4E0 8006D840 DA76000C */  jal        Enemy_GetSetSummary
    /* A4E4 8006D844 21200002 */   addu      $a0, $s0, $zero
    /* A4E8 8006D848 01000424 */  addiu      $a0, $zero, 0x1
    /* A4EC 8006D84C 1800A68F */  lw         $a2, 0x18($sp)
    /* A4F0 8006D850 00006292 */  lbu        $v0, 0x0($s3)
    /* A4F4 8006D854 21280000 */  addu       $a1, $zero, $zero
    /* A4F8 8006D858 1000A2AF */  sw         $v0, 0x10($sp)
    /* A4FC 8006D85C 01006292 */  lbu        $v0, 0x1($s3)
    /* A500 8006D860 2138A000 */  addu       $a3, $a1, $zero
    /* A504 8006D864 38B5010C */  jal        Stg40_AddEntity
    /* A508 8006D868 1400A2AF */   sw        $v0, 0x14($sp)
    /* A50C 8006D86C 0580023C */  lui        $v0, %hi(D_8005071C)
    /* A510 8006D870 1C07448C */  lw         $a0, %lo(D_8005071C)($v0)
    /* A514 8006D874 00000000 */  nop
    /* A518 8006D878 0E008384 */  lh         $v1, 0xE($a0)
    /* A51C 8006D87C 00000000 */  nop
    /* A520 8006D880 C0100300 */  sll        $v0, $v1, 3
    /* A524 8006D884 23104300 */  subu       $v0, $v0, $v1
    /* A528 8006D888 80100200 */  sll        $v0, $v0, 2
    /* A52C 8006D88C 9C0B4224 */  addiu      $v0, $v0, 0xB9C
    /* A530 8006D890 21888200 */  addu       $s1, $a0, $v0
    /* A534 8006D894 000030A6 */  sh         $s0, 0x0($s1)
    /* A538 8006D898 2800A28F */  lw         $v0, 0x28($sp)
    /* A53C 8006D89C 00000000 */  nop
    /* A540 8006D8A0 2B100200 */  sltu       $v0, $zero, $v0
    /* A544 8006D8A4 020022A2 */  sb         $v0, 0x2($s1)
    /* A548 8006D8A8 2400A293 */  lbu        $v0, 0x24($sp)
    /* A54C 8006D8AC 00000000 */  nop
    /* A550 8006D8B0 030022A2 */  sb         $v0, 0x3($s1)
    /* A554 8006D8B4 3000A297 */  lhu        $v0, 0x30($sp)
    /* A558 8006D8B8 00000000 */  nop
    /* A55C 8006D8BC 21184000 */  addu       $v1, $v0, $zero
    /* A560 8006D8C0 00140300 */  sll        $v0, $v1, 16
    /* A564 8006D8C4 02004014 */  bnez       $v0, .L8006D8D0
    /* A568 8006D8C8 0E0023A6 */   sh        $v1, 0xE($s1)
    /* A56C 8006D8CC 01000324 */  addiu      $v1, $zero, 0x1
  .L8006D8D0:
    /* A570 8006D8D0 0E0023A6 */  sh         $v1, 0xE($s1)
    /* A574 8006D8D4 0A0020A2 */  sb         $zero, 0xA($s1)
    /* A578 8006D8D8 0C0020A6 */  sh         $zero, 0xC($s1)
    /* A57C 8006D8DC 2000A28F */  lw         $v0, 0x20($sp)
    /* A580 8006D8E0 00000000 */  nop
    /* A584 8006D8E4 40100200 */  sll        $v0, $v0, 1
    /* A588 8006D8E8 21105500 */  addu       $v0, $v0, $s5
    /* A58C 8006D8EC 00004290 */  lbu        $v0, 0x0($v0)
    /* A590 8006D8F0 00000000 */  nop
    /* A594 8006D8F4 070022A2 */  sb         $v0, 0x7($s1)
    /* A598 8006D8F8 2000A28F */  lw         $v0, 0x20($sp)
    /* A59C 8006D8FC 00000000 */  nop
    /* A5A0 8006D900 40100200 */  sll        $v0, $v0, 1
    /* A5A4 8006D904 01004224 */  addiu      $v0, $v0, 0x1
    /* A5A8 8006D908 21105500 */  addu       $v0, $v0, $s5
    /* A5AC 8006D90C 00004290 */  lbu        $v0, 0x0($v0)
    /* A5B0 8006D910 00000000 */  nop
    /* A5B4 8006D914 060022A2 */  sb         $v0, 0x6($s1)
    /* A5B8 8006D918 1C00A28F */  lw         $v0, 0x1C($sp)
    /* A5BC 8006D91C 00000000 */  nop
    /* A5C0 8006D920 40100200 */  sll        $v0, $v0, 1
    /* A5C4 8006D924 21105400 */  addu       $v0, $v0, $s4
    /* A5C8 8006D928 00004290 */  lbu        $v0, 0x0($v0)
    /* A5CC 8006D92C 00000000 */  nop
    /* A5D0 8006D930 040022A2 */  sb         $v0, 0x4($s1)
    /* A5D4 8006D934 1C00A28F */  lw         $v0, 0x1C($sp)
    /* A5D8 8006D938 00000000 */  nop
    /* A5DC 8006D93C 40100200 */  sll        $v0, $v0, 1
    /* A5E0 8006D940 01004224 */  addiu      $v0, $v0, 0x1
    /* A5E4 8006D944 21105400 */  addu       $v0, $v0, $s4
    /* A5E8 8006D948 00004290 */  lbu        $v0, 0x0($v0)
    /* A5EC 8006D94C 00000000 */  nop
    /* A5F0 8006D950 FF005230 */  andi       $s2, $v0, 0xFF
    /* A5F4 8006D954 050022A2 */  sb         $v0, 0x5($s1)
    /* A5F8 8006D958 02000224 */  addiu      $v0, $zero, 0x2
    /* A5FC 8006D95C 0B004216 */  bne        $s2, $v0, .L8006D98C
    /* A600 8006D960 00000000 */   nop
    /* A604 8006D964 00006492 */  lbu        $a0, 0x0($s3)
    /* A608 8006D968 01006592 */  lbu        $a1, 0x1($s3)
    /* A60C 8006D96C 04003092 */  lbu        $s0, 0x4($s1)
    /* A610 8006D970 F8C0010C */  jal        Stg40_GetCellFlags
    /* A614 8006D974 00000000 */   nop
    /* A618 8006D978 0F004230 */  andi       $v0, $v0, 0xF
    /* A61C 8006D97C 03000212 */  beq        $s0, $v0, .L8006D98C
    /* A620 8006D980 00000000 */   nop
    /* A624 8006D984 040032A2 */  sb         $s2, 0x4($s1)
    /* A628 8006D988 050020A2 */  sb         $zero, 0x5($s1)
  .L8006D98C:
    /* A62C 8006D98C 0B0020A2 */  sb         $zero, 0xB($s1)
    /* A630 8006D990 21300000 */  addu       $a2, $zero, $zero
    /* A634 8006D994 21282002 */  addu       $a1, $s1, $zero
    /* A638 8006D998 2120C002 */  addu       $a0, $s6, $zero
  .L8006D99C:
    /* A63C 8006D99C 1C008284 */  lh         $v0, 0x1C($a0)
    /* A640 8006D9A0 1C008394 */  lhu        $v1, 0x1C($a0)
    /* A644 8006D9A4 0D004010 */  beqz       $v0, .L8006D9DC
    /* A648 8006D9A8 00000000 */   nop
    /* A64C 8006D9AC 1000A3A4 */  sh         $v1, 0x10($a1)
    /* A650 8006D9B0 22008294 */  lhu        $v0, 0x22($a0)
    /* A654 8006D9B4 02008424 */  addiu      $a0, $a0, 0x2
    /* A658 8006D9B8 0100C624 */  addiu      $a2, $a2, 0x1
    /* A65C 8006D9BC 1600A2A4 */  sh         $v0, 0x16($a1)
    /* A660 8006D9C0 0B002292 */  lbu        $v0, 0xB($s1)
    /* A664 8006D9C4 00000000 */  nop
    /* A668 8006D9C8 01004224 */  addiu      $v0, $v0, 0x1
    /* A66C 8006D9CC 0B0022A2 */  sb         $v0, 0xB($s1)
    /* A670 8006D9D0 0300C228 */  slti       $v0, $a2, 0x3
    /* A674 8006D9D4 F1FF4014 */  bnez       $v0, .L8006D99C
    /* A678 8006D9D8 0200A524 */   addiu     $a1, $a1, 0x2
  .L8006D9DC:
    /* A67C 8006D9DC 04007326 */  addiu      $s3, $s3, 0x4
    /* A680 8006D9E0 00006392 */  lbu        $v1, 0x0($s3)
    /* A684 8006D9E4 FF000224 */  addiu      $v0, $zero, 0xFF
    /* A688 8006D9E8 6BFF6214 */  bne        $v1, $v0, .L8006D798
    /* A68C 8006D9EC 0580023C */   lui       $v0, %hi(D_8005071C)
  .L8006D9F0:
    /* A690 8006D9F0 5C00BF8F */  lw         $ra, 0x5C($sp)
    /* A694 8006D9F4 5800B68F */  lw         $s6, 0x58($sp)
    /* A698 8006D9F8 5400B58F */  lw         $s5, 0x54($sp)
    /* A69C 8006D9FC 5000B48F */  lw         $s4, 0x50($sp)
    /* A6A0 8006DA00 4C00B38F */  lw         $s3, 0x4C($sp)
    /* A6A4 8006DA04 4800B28F */  lw         $s2, 0x48($sp)
    /* A6A8 8006DA08 4400B18F */  lw         $s1, 0x44($sp)
    /* A6AC 8006DA0C 4000B08F */  lw         $s0, 0x40($sp)
    /* A6B0 8006DA10 0800E003 */  jr         $ra
    /* A6B4 8006DA14 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel Stg40_SpawnEnemyParties
