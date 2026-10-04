nonmatching Stg30_PopupUpdate, 0x13C

glabel Stg30_PopupUpdate
    /* C58C 8006F8EC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C590 8006F8F0 1400B1AF */  sw         $s1, 0x14($sp)
    /* C594 8006F8F4 21888000 */  addu       $s1, $a0, $zero
    /* C598 8006F8F8 01000224 */  addiu      $v0, $zero, 0x1
    /* C59C 8006F8FC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* C5A0 8006F900 1800B2AF */  sw         $s2, 0x18($sp)
    /* C5A4 8006F904 1000B0AF */  sw         $s0, 0x10($sp)
    /* C5A8 8006F908 1000248E */  lw         $a0, 0x10($s1)
    /* C5AC 8006F90C 2C00308E */  lw         $s0, 0x2C($s1)
    /* C5B0 8006F910 09008210 */  beq        $a0, $v0, .L8006F938
    /* C5B4 8006F914 02008228 */   slti      $v0, $a0, 0x2
    /* C5B8 8006F918 3D004010 */  beqz       $v0, .L8006FA10
    /* C5BC 8006F91C 00000000 */   nop
    /* C5C0 8006F920 3B008014 */  bnez       $a0, .L8006FA10
    /* C5C4 8006F924 00000000 */   nop
    /* C5C8 8006F928 5145000C */  jal        Task_NextState0
    /* C5CC 8006F92C 21202002 */   addu      $a0, $s1, $zero
    /* C5D0 8006F930 84BE0108 */  j          .L8006FA10
    /* C5D4 8006F934 00000000 */   nop
  .L8006F938:
    /* C5D8 8006F938 1400238E */  lw         $v1, 0x14($s1)
    /* C5DC 8006F93C 00000000 */  nop
    /* C5E0 8006F940 13006410 */  beq        $v1, $a0, .L8006F990
    /* C5E4 8006F944 02006228 */   slti      $v0, $v1, 0x2
    /* C5E8 8006F948 03004014 */  bnez       $v0, .L8006F958
    /* C5EC 8006F94C 02000224 */   addiu     $v0, $zero, 0x2
    /* C5F0 8006F950 27006210 */  beq        $v1, $v0, .L8006F9F0
    /* C5F4 8006F954 00000000 */   nop
  .L8006F958:
    /* C5F8 8006F958 1000028E */  lw         $v0, 0x10($s0)
    /* C5FC 8006F95C 0C00038E */  lw         $v1, 0xC($s0)
    /* C600 8006F960 01004224 */  addiu      $v0, $v0, 0x1
    /* C604 8006F964 00026324 */  addiu      $v1, $v1, 0x200
    /* C608 8006F968 100002AE */  sw         $v0, 0x10($s0)
    /* C60C 8006F96C 0C0003AE */  sw         $v1, 0xC($s0)
    /* C610 8006F970 21184000 */  addu       $v1, $v0, $zero
    /* C614 8006F974 07000224 */  addiu      $v0, $zero, 0x7
    /* C618 8006F978 25006214 */  bne        $v1, $v0, .L8006FA10
    /* C61C 8006F97C 21202002 */   addu      $a0, $s1, $zero
    /* C620 8006F980 00100224 */  addiu      $v0, $zero, 0x1000
    /* C624 8006F984 280020AE */  sw         $zero, 0x28($s1)
    /* C628 8006F988 5945000C */  jal        Task_NextState1
    /* C62C 8006F98C 0C0002AE */   sw        $v0, 0xC($s0)
  .L8006F990:
    /* C630 8006F990 0000128E */  lw         $s2, 0x0($s0)
    /* C634 8006F994 07000224 */  addiu      $v0, $zero, 0x7
    /* C638 8006F998 08004212 */  beq        $s2, $v0, .L8006F9BC
    /* C63C 8006F99C 02000524 */   addiu     $a1, $zero, 0x2
    /* C640 8006F9A0 2800228E */  lw         $v0, 0x28($s1)
    /* C644 8006F9A4 00000000 */  nop
    /* C648 8006F9A8 28004228 */  slti       $v0, $v0, 0x28
    /* C64C 8006F9AC 0E004010 */  beqz       $v0, .L8006F9E8
    /* C650 8006F9B0 00000000 */   nop
    /* C654 8006F9B4 84BE0108 */  j          .L8006FA10
    /* C658 8006F9B8 00000000 */   nop
  .L8006F9BC:
    /* C65C 8006F9BC 08000624 */  addiu      $a2, $zero, 0x8
    /* C660 8006F9C0 2800248E */  lw         $a0, 0x28($s1)
    /* C664 8006F9C4 FB88000C */  jal        Math_CycleRange
    /* C668 8006F9C8 0F000724 */   addiu     $a3, $zero, 0xF
    /* C66C 8006F9CC 100002AE */  sw         $v0, 0x10($s0)
    /* C670 8006F9D0 2800228E */  lw         $v0, 0x28($s1)
    /* C674 8006F9D4 00000000 */  nop
    /* C678 8006F9D8 90004228 */  slti       $v0, $v0, 0x90
    /* C67C 8006F9DC 0C004014 */  bnez       $v0, .L8006FA10
    /* C680 8006F9E0 00000000 */   nop
    /* C684 8006F9E4 100012AE */  sw         $s2, 0x10($s0)
  .L8006F9E8:
    /* C688 8006F9E8 5945000C */  jal        Task_NextState1
    /* C68C 8006F9EC 21202002 */   addu      $a0, $s1, $zero
  .L8006F9F0:
    /* C690 8006F9F0 1000028E */  lw         $v0, 0x10($s0)
    /* C694 8006F9F4 00000000 */  nop
    /* C698 8006F9F8 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* C69C 8006F9FC 04004104 */  bgez       $v0, .L8006FA10
    /* C6A0 8006FA00 100002AE */   sw        $v0, 0x10($s0)
    /* C6A4 8006FA04 21202002 */  addu       $a0, $s1, $zero
    /* C6A8 8006FA08 7045000C */  jal        Task_SetState0
    /* C6AC 8006FA0C 03000524 */   addiu     $a1, $zero, 0x3
  .L8006FA10:
    /* C6B0 8006FA10 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* C6B4 8006FA14 1800B28F */  lw         $s2, 0x18($sp)
    /* C6B8 8006FA18 1400B18F */  lw         $s1, 0x14($sp)
    /* C6BC 8006FA1C 1000B08F */  lw         $s0, 0x10($sp)
    /* C6C0 8006FA20 0800E003 */  jr         $ra
    /* C6C4 8006FA24 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_PopupUpdate
