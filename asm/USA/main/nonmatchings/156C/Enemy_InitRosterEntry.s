nonmatching Enemy_InitRosterEntry, 0x24C

glabel Enemy_InitRosterEntry
    /* E5A8 8001DDA8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* E5AC 8001DDAC 1400B1AF */  sw         $s1, 0x14($sp)
    /* E5B0 8001DDB0 2188A000 */  addu       $s1, $a1, $zero
    /* E5B4 8001DDB4 1000B0AF */  sw         $s0, 0x10($sp)
    /* E5B8 8001DDB8 2180C000 */  addu       $s0, $a2, $zero
    /* E5BC 8001DDBC 1800B2AF */  sw         $s2, 0x18($sp)
    /* E5C0 8001DDC0 2190E000 */  addu       $s2, $a3, $zero
    /* E5C4 8001DDC4 2000BFAF */  sw         $ra, 0x20($sp)
    /* E5C8 8001DDC8 C676000C */  jal        Enemy_FindSetById
    /* E5CC 8001DDCC 1C00B3AF */   sw        $s3, 0x1C($sp)
    /* E5D0 8001DDD0 0680033C */  lui        $v1, %hi(Sys_GameMode)
    /* E5D4 8001DDD4 21984000 */  addu       $s3, $v0, $zero
    /* E5D8 8001DDD8 88F7638C */  lw         $v1, %lo(Sys_GameMode)($v1)
    /* E5DC 8001DDDC 00050224 */  addiu      $v0, $zero, 0x500
    /* E5E0 8001DDE0 00FF6330 */  andi       $v1, $v1, 0xFF00
    /* E5E4 8001DDE4 09006214 */  bne        $v1, $v0, .L8001DE0C
    /* E5E8 8001DDE8 03002226 */   addiu     $v0, $s1, 0x3
    /* E5EC 8001DDEC 03002016 */  bnez       $s1, .L8001DDFC
    /* E5F0 8001DDF0 01000224 */   addiu     $v0, $zero, 0x1
    /* E5F4 8001DDF4 82770008 */  j          .L8001DE08
    /* E5F8 8001DDF8 01001124 */   addiu     $s1, $zero, 0x1
  .L8001DDFC:
    /* E5FC 8001DDFC 03002216 */  bne        $s1, $v0, .L8001DE0C
    /* E600 8001DE00 03002226 */   addiu     $v0, $s1, 0x3
    /* E604 8001DE04 21880000 */  addu       $s1, $zero, $zero
  .L8001DE08:
    /* E608 8001DE08 03002226 */  addiu      $v0, $s1, 0x3
  .L8001DE0C:
    /* E60C 8001DE0C 000002A2 */  sb         $v0, 0x0($s0)
    /* E610 8001DE10 00111100 */  sll        $v0, $s1, 4
    /* E614 8001DE14 23105100 */  subu       $v0, $v0, $s1
    /* E618 8001DE18 40100200 */  sll        $v0, $v0, 1
    /* E61C 8001DE1C 21106202 */  addu       $v0, $s3, $v0
    /* E620 8001DE20 08004390 */  lbu        $v1, 0x8($v0)
    /* E624 8001DE24 00000000 */  nop
    /* E628 8001DE28 010003A2 */  sb         $v1, 0x1($s0)
    /* E62C 8001DE2C 0A004394 */  lhu        $v1, 0xA($v0)
    /* E630 8001DE30 00000000 */  nop
    /* E634 8001DE34 140003A6 */  sh         $v1, 0x14($s0)
    /* E638 8001DE38 160003A6 */  sh         $v1, 0x16($s0)
    /* E63C 8001DE3C 0C004294 */  lhu        $v0, 0xC($v0)
    /* E640 8001DE40 01000392 */  lbu        $v1, 0x1($s0)
    /* E644 8001DE44 180002A6 */  sh         $v0, 0x18($s0)
    /* E648 8001DE48 63006010 */  beqz       $v1, .L8001DFD8
    /* E64C 8001DE4C 1A0002A6 */   sh        $v0, 0x1A($s0)
    /* E650 8001DE50 D679000C */  jal        Digi_GetDefaultName
    /* E654 8001DE54 21206000 */   addu      $a0, $v1, $zero
    /* E658 8001DE58 21284000 */  addu       $a1, $v0, $zero
    /* E65C 8001DE5C 21200000 */  addu       $a0, $zero, $zero
    /* E660 8001DE60 21180402 */  addu       $v1, $s0, $a0
  .L8001DE64:
    /* E664 8001DE64 2110A400 */  addu       $v0, $a1, $a0
    /* E668 8001DE68 00004290 */  lbu        $v0, 0x0($v0)
    /* E66C 8001DE6C 01008424 */  addiu      $a0, $a0, 0x1
    /* E670 8001DE70 4C0062A0 */  sb         $v0, 0x4C($v1)
    /* E674 8001DE74 0E008228 */  slti       $v0, $a0, 0xE
    /* E678 8001DE78 FAFF4014 */  bnez       $v0, .L8001DE64
    /* E67C 8001DE7C 21180402 */   addu      $v1, $s0, $a0
    /* E680 8001DE80 00111100 */  sll        $v0, $s1, 4
    /* E684 8001DE84 23105100 */  subu       $v0, $v0, $s1
    /* E688 8001DE88 40100200 */  sll        $v0, $v0, 1
    /* E68C 8001DE8C 21106202 */  addu       $v0, $s3, $v0
    /* E690 8001DE90 12004390 */  lbu        $v1, 0x12($v0)
    /* E694 8001DE94 00000000 */  nop
    /* E698 8001DE98 0D0003A2 */  sb         $v1, 0xD($s0)
    /* E69C 8001DE9C 0E004384 */  lh         $v1, 0xE($v0)
    /* E6A0 8001DEA0 00000000 */  nop
    /* E6A4 8001DEA4 100003AE */  sw         $v1, 0x10($s0)
    /* E6A8 8001DEA8 13004390 */  lbu        $v1, 0x13($v0)
    /* E6AC 8001DEAC 00000000 */  nop
    /* E6B0 8001DEB0 1C0003A6 */  sh         $v1, 0x1C($s0)
    /* E6B4 8001DEB4 14004394 */  lhu        $v1, 0x14($v0)
    /* E6B8 8001DEB8 00000000 */  nop
    /* E6BC 8001DEBC 1E0003A6 */  sh         $v1, 0x1E($s0)
    /* E6C0 8001DEC0 16004390 */  lbu        $v1, 0x16($v0)
    /* E6C4 8001DEC4 00000000 */  nop
    /* E6C8 8001DEC8 200003A6 */  sh         $v1, 0x20($s0)
    /* E6CC 8001DECC 17004390 */  lbu        $v1, 0x17($v0)
    /* E6D0 8001DED0 00000000 */  nop
    /* E6D4 8001DED4 220003A2 */  sb         $v1, 0x22($s0)
    /* E6D8 8001DED8 18004390 */  lbu        $v1, 0x18($v0)
    /* E6DC 8001DEDC 00000000 */  nop
    /* E6E0 8001DEE0 230003A2 */  sb         $v1, 0x23($s0)
    /* E6E4 8001DEE4 19004290 */  lbu        $v0, 0x19($v0)
    /* E6E8 8001DEE8 03000424 */  addiu      $a0, $zero, 0x3
    /* E6EC 8001DEEC 240002A2 */  sb         $v0, 0x24($s0)
    /* E6F0 8001DEF0 21100402 */  addu       $v0, $s0, $a0
  .L8001DEF4:
    /* E6F4 8001DEF4 220040A0 */  sb         $zero, 0x22($v0)
    /* E6F8 8001DEF8 01008424 */  addiu      $a0, $a0, 0x1
    /* E6FC 8001DEFC 0C008228 */  slti       $v0, $a0, 0xC
    /* E700 8001DF00 FCFF4014 */  bnez       $v0, .L8001DEF4
    /* E704 8001DF04 21100402 */   addu      $v0, $s0, $a0
    /* E708 8001DF08 00111100 */  sll        $v0, $s1, 4
    /* E70C 8001DF0C 23105100 */  subu       $v0, $v0, $s1
    /* E710 8001DF10 40100200 */  sll        $v0, $v0, 1
    /* E714 8001DF14 21106202 */  addu       $v0, $s3, $v0
    /* E718 8001DF18 17004390 */  lbu        $v1, 0x17($v0)
    /* E71C 8001DF1C 00000000 */  nop
    /* E720 8001DF20 020043A2 */  sb         $v1, 0x2($s2)
    /* E724 8001DF24 18004390 */  lbu        $v1, 0x18($v0)
    /* E728 8001DF28 00000000 */  nop
    /* E72C 8001DF2C 030043A2 */  sb         $v1, 0x3($s2)
    /* E730 8001DF30 19004390 */  lbu        $v1, 0x19($v0)
    /* E734 8001DF34 00000000 */  nop
    /* E738 8001DF38 040043A2 */  sb         $v1, 0x4($s2)
    /* E73C 8001DF3C 1B004390 */  lbu        $v1, 0x1B($v0)
    /* E740 8001DF40 00000000 */  nop
    /* E744 8001DF44 090043A2 */  sb         $v1, 0x9($s2)
    /* E748 8001DF48 1E004390 */  lbu        $v1, 0x1E($v0)
    /* E74C 8001DF4C 00000000 */  nop
    /* E750 8001DF50 0A0043A2 */  sb         $v1, 0xA($s2)
    /* E754 8001DF54 21004390 */  lbu        $v1, 0x21($v0)
    /* E758 8001DF58 00000000 */  nop
    /* E75C 8001DF5C 0B0043A2 */  sb         $v1, 0xB($s2)
    /* E760 8001DF60 24004390 */  lbu        $v1, 0x24($v0)
    /* E764 8001DF64 00000000 */  nop
    /* E768 8001DF68 0C0043A2 */  sb         $v1, 0xC($s2)
    /* E76C 8001DF6C 10004394 */  lhu        $v1, 0x10($v0)
    /* E770 8001DF70 00000000 */  nop
    /* E774 8001DF74 000043A6 */  sh         $v1, 0x0($s2)
    /* E778 8001DF78 1C004390 */  lbu        $v1, 0x1C($v0)
    /* E77C 8001DF7C 00000000 */  nop
    /* E780 8001DF80 0D0043A2 */  sb         $v1, 0xD($s2)
    /* E784 8001DF84 1F004390 */  lbu        $v1, 0x1F($v0)
    /* E788 8001DF88 00000000 */  nop
    /* E78C 8001DF8C 0E0043A2 */  sb         $v1, 0xE($s2)
    /* E790 8001DF90 22004390 */  lbu        $v1, 0x22($v0)
    /* E794 8001DF94 00000000 */  nop
    /* E798 8001DF98 0F0043A2 */  sb         $v1, 0xF($s2)
    /* E79C 8001DF9C 25004390 */  lbu        $v1, 0x25($v0)
    /* E7A0 8001DFA0 00000000 */  nop
    /* E7A4 8001DFA4 100043A2 */  sb         $v1, 0x10($s2)
    /* E7A8 8001DFA8 1A004390 */  lbu        $v1, 0x1A($v0)
    /* E7AC 8001DFAC 00000000 */  nop
    /* E7B0 8001DFB0 050043A2 */  sb         $v1, 0x5($s2)
    /* E7B4 8001DFB4 1D004390 */  lbu        $v1, 0x1D($v0)
    /* E7B8 8001DFB8 00000000 */  nop
    /* E7BC 8001DFBC 060043A2 */  sb         $v1, 0x6($s2)
    /* E7C0 8001DFC0 20004390 */  lbu        $v1, 0x20($v0)
    /* E7C4 8001DFC4 00000000 */  nop
    /* E7C8 8001DFC8 070043A2 */  sb         $v1, 0x7($s2)
    /* E7CC 8001DFCC 23004290 */  lbu        $v0, 0x23($v0)
    /* E7D0 8001DFD0 00000000 */  nop
    /* E7D4 8001DFD4 080042A2 */  sb         $v0, 0x8($s2)
  .L8001DFD8:
    /* E7D8 8001DFD8 2000BF8F */  lw         $ra, 0x20($sp)
    /* E7DC 8001DFDC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* E7E0 8001DFE0 1800B28F */  lw         $s2, 0x18($sp)
    /* E7E4 8001DFE4 1400B18F */  lw         $s1, 0x14($sp)
    /* E7E8 8001DFE8 1000B08F */  lw         $s0, 0x10($sp)
    /* E7EC 8001DFEC 0800E003 */  jr         $ra
    /* E7F0 8001DFF0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Enemy_InitRosterEntry
