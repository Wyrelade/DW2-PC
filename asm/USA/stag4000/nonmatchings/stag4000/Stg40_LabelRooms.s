nonmatching Stg40_LabelRooms, 0xD4

glabel Stg40_LabelRooms
    /* D470 800707D0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* D474 800707D4 F83F0424 */  addiu      $a0, $zero, 0x3FF8
    /* D478 800707D8 0580023C */  lui        $v0, %hi(D_8005071C)
    /* D47C 800707DC 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* D480 800707E0 02000524 */  addiu      $a1, $zero, 0x2
    /* D484 800707E4 2800B4AF */  sw         $s4, 0x28($sp)
    /* D488 800707E8 0780143C */  lui        $s4, %hi(D_80072BB8)
    /* D48C 800707EC 2400B3AF */  sw         $s3, 0x24($sp)
    /* D490 800707F0 FFFF1324 */  addiu      $s3, $zero, -0x1
    /* D494 800707F4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* D498 800707F8 2000B2AF */  sw         $s2, 0x20($sp)
    /* D49C 800707FC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* D4A0 80070800 1800B0AF */  sw         $s0, 0x18($sp)
    /* D4A4 80070804 540E428C */  lw         $v0, 0xE54($v0)
    /* D4A8 80070808 00000000 */  nop
    /* D4AC 8007080C 00005084 */  lh         $s0, 0x0($v0)
    /* D4B0 80070810 CF8B000C */  jal        Mem_Alloc
    /* D4B4 80070814 00201224 */   addiu     $s2, $zero, 0x2000
    /* D4B8 80070818 0780033C */  lui        $v1, %hi(D_80072B60)
    /* D4BC 8007081C 602B638C */  lw         $v1, %lo(D_80072B60)($v1)
    /* D4C0 80070820 21884000 */  addu       $s1, $v0, $zero
    /* D4C4 80070824 000060AC */  sw         $zero, 0x0($v1)
  .L80070828:
    /* D4C8 80070828 B2C1010C */  jal        Stg40_FindUnlabeledRoom
    /* D4CC 8007082C 00000000 */   nop
    /* D4D0 80070830 12005310 */  beq        $v0, $s3, .L8007087C
    /* D4D4 80070834 B82B82AE */   sw        $v0, %lo(D_80072BB8)($s4)
    /* D4D8 80070838 1A005000 */  div        $zero, $v0, $s0
    /* D4DC 8007083C 12380000 */  mflo       $a3
    /* D4E0 80070840 10300000 */  mfhi       $a2
    /* D4E4 80070844 21202002 */  addu       $a0, $s1, $zero
    /* D4E8 80070848 21280000 */  addu       $a1, $zero, $zero
    /* D4EC 8007084C 24C1010C */  jal        Stg40_FloodFillRoom
    /* D4F0 80070850 1000B2AF */   sw        $s2, 0x10($sp)
    /* D4F4 80070854 D5C1010C */  jal        Stg40_LabelFilledCells
    /* D4F8 80070858 00000000 */   nop
    /* D4FC 8007085C 0780023C */  lui        $v0, %hi(D_80072B60)
    /* D500 80070860 602B438C */  lw         $v1, %lo(D_80072B60)($v0)
    /* D504 80070864 00000000 */  nop
    /* D508 80070868 0000628C */  lw         $v0, 0x0($v1)
    /* D50C 8007086C 00000000 */  nop
    /* D510 80070870 01004224 */  addiu      $v0, $v0, 0x1
    /* D514 80070874 0AC20108 */  j          .L80070828
    /* D518 80070878 000062AC */   sw        $v0, 0x0($v1)
  .L8007087C:
    /* D51C 8007087C 618B000C */  jal        Mem_Free
    /* D520 80070880 21202002 */   addu      $a0, $s1, $zero
    /* D524 80070884 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* D528 80070888 2800B48F */  lw         $s4, 0x28($sp)
    /* D52C 8007088C 2400B38F */  lw         $s3, 0x24($sp)
    /* D530 80070890 2000B28F */  lw         $s2, 0x20($sp)
    /* D534 80070894 1C00B18F */  lw         $s1, 0x1C($sp)
    /* D538 80070898 1800B08F */  lw         $s0, 0x18($sp)
    /* D53C 8007089C 0800E003 */  jr         $ra
    /* D540 800708A0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg40_LabelRooms
