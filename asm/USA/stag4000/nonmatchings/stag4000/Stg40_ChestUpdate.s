nonmatching Stg40_ChestUpdate, 0x288

glabel Stg40_ChestUpdate
    /* 94EC 8006C84C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 94F0 8006C850 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 94F4 8006C854 21888000 */  addu       $s1, $a0, $zero
    /* 94F8 8006C858 2400BFAF */  sw         $ra, 0x24($sp)
    /* 94FC 8006C85C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 9500 8006C860 1800B0AF */  sw         $s0, 0x18($sp)
    /* 9504 8006C864 2C00328E */  lw         $s2, 0x2C($s1)
    /* 9508 8006C868 00000000 */  nop
    /* 950C 8006C86C 2C00508E */  lw         $s0, 0x2C($s2)
    /* 9510 8006C870 00000000 */  nop
    /* 9514 8006C874 18000486 */  lh         $a0, 0x18($s0)
    /* 9518 8006C878 1A000586 */  lh         $a1, 0x1A($s0)
    /* 951C 8006C87C 3FC2010C */  jal        Stg40_SetCellOccupied
    /* 9520 8006C880 01000624 */   addiu     $a2, $zero, 0x1
    /* 9524 8006C884 18000486 */  lh         $a0, 0x18($s0)
    /* 9528 8006C888 1A000586 */  lh         $a1, 0x1A($s0)
    /* 952C 8006C88C F8C0010C */  jal        Stg40_GetCellFlags
    /* 9530 8006C890 00000000 */   nop
    /* 9534 8006C894 00204230 */  andi       $v0, $v0, 0x2000
    /* 9538 8006C898 05004010 */  beqz       $v0, .L8006C8B0
    /* 953C 8006C89C 00000000 */   nop
    /* 9540 8006C8A0 0000028E */  lw         $v0, 0x0($s0)
    /* 9544 8006C8A4 00000000 */  nop
    /* 9548 8006C8A8 00104234 */  ori        $v0, $v0, 0x1000
    /* 954C 8006C8AC 000002AE */  sw         $v0, 0x0($s0)
  .L8006C8B0:
    /* 9550 8006C8B0 0000028E */  lw         $v0, 0x0($s0)
    /* 9554 8006C8B4 00000000 */  nop
    /* 9558 8006C8B8 00104230 */  andi       $v0, $v0, 0x1000
    /* 955C 8006C8BC 07004010 */  beqz       $v0, .L8006C8DC
    /* 9560 8006C8C0 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 9564 8006C8C4 18000486 */  lh         $a0, 0x18($s0)
    /* 9568 8006C8C8 1A000586 */  lh         $a1, 0x1A($s0)
    /* 956C 8006C8CC 08000292 */  lbu        $v0, 0x8($s0)
    /* 9570 8006C8D0 2138C000 */  addu       $a3, $a2, $zero
    /* 9574 8006C8D4 FDBA010C */  jal        Stg40_AutomapMoveMarker
    /* 9578 8006C8D8 1000A2AF */   sw        $v0, 0x10($sp)
  .L8006C8DC:
    /* 957C 8006C8DC 1000038E */  lw         $v1, 0x10($s0)
    /* 9580 8006C8E0 00000000 */  nop
    /* 9584 8006C8E4 01006290 */  lbu        $v0, 0x1($v1)
    /* 9588 8006C8E8 00000000 */  nop
    /* 958C 8006C8EC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 9590 8006C8F0 0500422C */  sltiu      $v0, $v0, 0x5
    /* 9594 8006C8F4 04004010 */  beqz       $v0, .L8006C908
    /* 9598 8006C8F8 21204002 */   addu      $a0, $s2, $zero
    /* 959C 8006C8FC 01006590 */  lbu        $a1, 0x1($v1)
    /* 95A0 8006C900 F3B1010C */  jal        Stg40_ChestQueueModel
    /* 95A4 8006C904 FFFFA524 */   addiu     $a1, $a1, -0x1
  .L8006C908:
    /* 95A8 8006C908 1400238E */  lw         $v1, 0x14($s1)
    /* 95AC 8006C90C 00000000 */  nop
    /* 95B0 8006C910 0600622C */  sltiu      $v0, $v1, 0x6
    /* 95B4 8006C914 08004010 */  beqz       $v0, .L8006C938
    /* 95B8 8006C918 0680023C */   lui       $v0, %hi(jtbl_80063534)
    /* 95BC 8006C91C 34354224 */  addiu      $v0, $v0, %lo(jtbl_80063534)
    /* 95C0 8006C920 80180300 */  sll        $v1, $v1, 2
    /* 95C4 8006C924 21186200 */  addu       $v1, $v1, $v0
    /* 95C8 8006C928 0000628C */  lw         $v0, 0x0($v1)
    /* 95CC 8006C92C 00000000 */  nop
    /* 95D0 8006C930 08004000 */  jr         $v0
    /* 95D4 8006C934 00000000 */   nop
  jlabel .L8006C938
    /* 95D8 8006C938 1000028E */  lw         $v0, 0x10($s0)
    /* 95DC 8006C93C 00000000 */  nop
    /* 95E0 8006C940 01004390 */  lbu        $v1, 0x1($v0)
    /* 95E4 8006C944 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 95E8 8006C948 03006214 */  bne        $v1, $v0, .L8006C958
    /* 95EC 8006C94C 21202002 */   addu      $a0, $s1, $zero
    /* 95F0 8006C950 57B20108 */  j          .L8006C95C
    /* 95F4 8006C954 29000524 */   addiu     $a1, $zero, 0x29
  .L8006C958:
    /* 95F8 8006C958 28000524 */  addiu      $a1, $zero, 0x28
  .L8006C95C:
    /* 95FC 8006C95C 37B9010C */  jal        Stg40_ObjSetAnim
    /* 9600 8006C960 00000000 */   nop
    /* 9604 8006C964 21202002 */  addu       $a0, $s1, $zero
    /* 9608 8006C968 ADB20108 */  j          .L8006CAB4
    /* 960C 8006C96C 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006C970
    /* 9610 8006C970 1000028E */  lw         $v0, 0x10($s0)
    /* 9614 8006C974 00000000 */  nop
    /* 9618 8006C978 01004390 */  lbu        $v1, 0x1($v0)
    /* 961C 8006C97C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 9620 8006C980 05006214 */  bne        $v1, $v0, .L8006C998
    /* 9624 8006C984 21202002 */   addu      $a0, $s1, $zero
    /* 9628 8006C988 37B9010C */  jal        Stg40_ObjSetAnim
    /* 962C 8006C98C 29000524 */   addiu     $a1, $zero, 0x29
    /* 9630 8006C990 AFB20108 */  j          .L8006CABC
    /* 9634 8006C994 00000000 */   nop
  .L8006C998:
    /* 9638 8006C998 37B9010C */  jal        Stg40_ObjSetAnim
    /* 963C 8006C99C 28000524 */   addiu     $a1, $zero, 0x28
    /* 9640 8006C9A0 AFB20108 */  j          .L8006CABC
    /* 9644 8006C9A4 00000000 */   nop
  jlabel .L8006C9A8
    /* 9648 8006C9A8 18000486 */  lh         $a0, 0x18($s0)
    /* 964C 8006C9AC 1A000586 */  lh         $a1, 0x1A($s0)
    /* 9650 8006C9B0 5DC2010C */  jal        Stg40_ClearCellOccupied
    /* 9654 8006C9B4 00000000 */   nop
    /* 9658 8006C9B8 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 965C 8006C9BC 18000686 */  lh         $a2, 0x18($s0)
    /* 9660 8006C9C0 1A000786 */  lh         $a3, 0x1A($s0)
    /* 9664 8006C9C4 08000292 */  lbu        $v0, 0x8($s0)
    /* 9668 8006C9C8 21288000 */  addu       $a1, $a0, $zero
    /* 966C 8006C9CC FDBA010C */  jal        Stg40_AutomapMoveMarker
    /* 9670 8006C9D0 1000A2AF */   sw        $v0, 0x10($sp)
    /* 9674 8006C9D4 21202002 */  addu       $a0, $s1, $zero
    /* 9678 8006C9D8 03000524 */  addiu      $a1, $zero, 0x3
    /* 967C 8006C9DC 7045000C */  jal        Task_SetState0
    /* 9680 8006C9E0 000000AE */   sw        $zero, 0x0($s0)
    /* 9684 8006C9E4 AFB20108 */  j          .L8006CABC
    /* 9688 8006C9E8 00000000 */   nop
  jlabel .L8006C9EC
    /* 968C 8006C9EC 1800308E */  lw         $s0, 0x18($s1)
    /* 9690 8006C9F0 00000000 */  nop
    /* 9694 8006C9F4 03000012 */  beqz       $s0, .L8006CA04
    /* 9698 8006C9F8 01000224 */   addiu     $v0, $zero, 0x1
    /* 969C 8006C9FC 0B000212 */  beq        $s0, $v0, .L8006CA2C
    /* 96A0 8006CA00 00000000 */   nop
  .L8006CA04:
    /* 96A4 8006CA04 21202002 */  addu       $a0, $s1, $zero
    /* 96A8 8006CA08 37B9010C */  jal        Stg40_ObjSetAnim
    /* 96AC 8006CA0C 2A000524 */   addiu     $a1, $zero, 0x2A
    /* 96B0 8006CA10 6045000C */  jal        Task_NextState2
    /* 96B4 8006CA14 21202002 */   addu      $a0, $s1, $zero
    /* 96B8 8006CA18 02000424 */  addiu      $a0, $zero, 0x2
    /* 96BC 8006CA1C A369000C */  jal        Snd_PlayById
    /* 96C0 8006CA20 21280000 */   addu      $a1, $zero, $zero
    /* 96C4 8006CA24 AFB20108 */  j          .L8006CABC
    /* 96C8 8006CA28 00000000 */   nop
  .L8006CA2C:
    /* 96CC 8006CA2C 62B9010C */  jal        Stg40_ObjWaitAnimOrSkip
    /* 96D0 8006CA30 21202002 */   addu      $a0, $s1, $zero
    /* 96D4 8006CA34 21005014 */  bne        $v0, $s0, .L8006CABC
    /* 96D8 8006CA38 21202002 */   addu      $a0, $s1, $zero
    /* 96DC 8006CA3C 37B9010C */  jal        Stg40_ObjSetAnim
    /* 96E0 8006CA40 29000524 */   addiu     $a1, $zero, 0x29
    /* 96E4 8006CA44 21202002 */  addu       $a0, $s1, $zero
    /* 96E8 8006CA48 ADB20108 */  j          .L8006CAB4
    /* 96EC 8006CA4C 03000524 */   addiu     $a1, $zero, 0x3
  jlabel .L8006CA50
    /* 96F0 8006CA50 1800308E */  lw         $s0, 0x18($s1)
    /* 96F4 8006CA54 00000000 */  nop
    /* 96F8 8006CA58 03000012 */  beqz       $s0, .L8006CA68
    /* 96FC 8006CA5C 01000224 */   addiu     $v0, $zero, 0x1
    /* 9700 8006CA60 0F000212 */  beq        $s0, $v0, .L8006CAA0
    /* 9704 8006CA64 00000000 */   nop
  .L8006CA68:
    /* 9708 8006CA68 2000228E */  lw         $v0, 0x20($s1)
    /* 970C 8006CA6C 00000000 */  nop
    /* 9710 8006CA70 21184000 */  addu       $v1, $v0, $zero
    /* 9714 8006CA74 01004224 */  addiu      $v0, $v0, 0x1
    /* 9718 8006CA78 0B006328 */  slti       $v1, $v1, 0xB
    /* 971C 8006CA7C 0F006014 */  bnez       $v1, .L8006CABC
    /* 9720 8006CA80 200022AE */   sw        $v0, 0x20($s1)
    /* 9724 8006CA84 21202002 */  addu       $a0, $s1, $zero
    /* 9728 8006CA88 37B9010C */  jal        Stg40_ObjSetAnim
    /* 972C 8006CA8C 2B000524 */   addiu     $a1, $zero, 0x2B
    /* 9730 8006CA90 6045000C */  jal        Task_NextState2
    /* 9734 8006CA94 21202002 */   addu      $a0, $s1, $zero
    /* 9738 8006CA98 AFB20108 */  j          .L8006CABC
    /* 973C 8006CA9C 00000000 */   nop
  .L8006CAA0:
    /* 9740 8006CAA0 62B9010C */  jal        Stg40_ObjWaitAnimOrSkip
    /* 9744 8006CAA4 21202002 */   addu      $a0, $s1, $zero
    /* 9748 8006CAA8 04005014 */  bne        $v0, $s0, .L8006CABC
    /* 974C 8006CAAC 21202002 */   addu      $a0, $s1, $zero
    /* 9750 8006CAB0 02000524 */  addiu      $a1, $zero, 0x2
  .L8006CAB4:
    /* 9754 8006CAB4 7745000C */  jal        Task_SetState1
    /* 9758 8006CAB8 00000000 */   nop
  jlabel .L8006CABC
    /* 975C 8006CABC 2400BF8F */  lw         $ra, 0x24($sp)
    /* 9760 8006CAC0 2000B28F */  lw         $s2, 0x20($sp)
    /* 9764 8006CAC4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 9768 8006CAC8 1800B08F */  lw         $s0, 0x18($sp)
    /* 976C 8006CACC 0800E003 */  jr         $ra
    /* 9770 8006CAD0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_ChestUpdate
