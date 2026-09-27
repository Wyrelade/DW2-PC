nonmatching func_8006F62C, 0x90

glabel func_8006F62C
    /* C2CC 8006F62C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C2D0 8006F630 1400B1AF */  sw         $s1, 0x14($sp)
    /* C2D4 8006F634 21888000 */  addu       $s1, $a0, $zero
    /* C2D8 8006F638 1800B2AF */  sw         $s2, 0x18($sp)
    /* C2DC 8006F63C 2190A000 */  addu       $s2, $a1, $zero
    /* C2E0 8006F640 1000B0AF */  sw         $s0, 0x10($sp)
    /* C2E4 8006F644 2180C000 */  addu       $s0, $a2, $zero
    /* C2E8 8006F648 21204002 */  addu       $a0, $s2, $zero
    /* C2EC 8006F64C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* C2F0 8006F650 F8C0010C */  jal        func_800703E0
    /* C2F4 8006F654 21280002 */   addu      $a1, $s0, $zero
    /* C2F8 8006F658 00804230 */  andi       $v0, $v0, 0x8000
    /* C2FC 8006F65C 11004010 */  beqz       $v0, .L8006F6A4
    /* C300 8006F660 21204002 */   addu      $a0, $s2, $zero
    /* C304 8006F664 66072286 */  lh         $v0, 0x766($s1)
    /* C308 8006F668 00000000 */  nop
    /* C30C 8006F66C 18005000 */  mult       $v0, $s0
    /* C310 8006F670 0580023C */  lui        $v0, %hi(D_8005071C)
    /* C314 8006F674 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* C318 8006F678 21280002 */  addu       $a1, $s0, $zero
    /* C31C 8006F67C 580E428C */  lw         $v0, 0xE58($v0)
    /* C320 8006F680 12380000 */  mflo       $a3
    /* C324 8006F684 2118E400 */  addu       $v1, $a3, $a0
    /* C328 8006F688 80180300 */  sll        $v1, $v1, 2
    /* C32C 8006F68C 21186200 */  addu       $v1, $v1, $v0
    /* C330 8006F690 00006294 */  lhu        $v0, 0x0($v1)
    /* C334 8006F694 01000624 */  addiu      $a2, $zero, 0x1
    /* C338 8006F698 00204234 */  ori        $v0, $v0, 0x2000
    /* C33C 8006F69C E1BA010C */  jal        func_8006EB84
    /* C340 8006F6A0 000062A4 */   sh        $v0, 0x0($v1)
  .L8006F6A4:
    /* C344 8006F6A4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* C348 8006F6A8 1800B28F */  lw         $s2, 0x18($sp)
    /* C34C 8006F6AC 1400B18F */  lw         $s1, 0x14($sp)
    /* C350 8006F6B0 1000B08F */  lw         $s0, 0x10($sp)
    /* C354 8006F6B4 0800E003 */  jr         $ra
    /* C358 8006F6B8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006F62C
