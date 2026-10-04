nonmatching Stg20_LabCaptionDraw, 0xB0

glabel Stg20_LabCaptionDraw
    /* 5C58 80068FB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5C5C 80068FBC 120D043C */  lui        $a0, (0xD120001 >> 16)
    /* 5C60 80068FC0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5C64 80068FC4 688E000C */  jal        Cd_GetFileEntry
    /* 5C68 80068FC8 01008434 */   ori       $a0, $a0, (0xD120001 & 0xFFFF)
    /* 5C6C 80068FCC 21204000 */  addu       $a0, $v0, $zero
    /* 5C70 80068FD0 0000828C */  lw         $v0, 0x0($a0)
    /* 5C74 80068FD4 00000000 */  nop
    /* 5C78 80068FD8 1D004010 */  beqz       $v0, .L80069050
    /* 5C7C 80068FDC 21388000 */   addu      $a3, $a0, $zero
    /* 5C80 80068FE0 0780023C */  lui        $v0, %hi(D_800709B0)
    /* 5C84 80068FE4 B0094A24 */  addiu      $t2, $v0, %lo(D_800709B0)
    /* 5C88 80068FE8 01000924 */  addiu      $t1, $zero, 0x1
    /* 5C8C 80068FEC 02000824 */  addiu      $t0, $zero, 0x2
    /* 5C90 80068FF0 0F008624 */  addiu      $a2, $a0, 0xF
  .L80068FF4:
    /* 5C94 80068FF4 0D00C58C */  lw         $a1, 0xD($a2)
    /* 5C98 80068FF8 00000000 */  nop
    /* 5C9C 80068FFC 0600A230 */  andi       $v0, $a1, 0x6
    /* 5CA0 80069000 0E004010 */  beqz       $v0, .L8006903C
    /* 5CA4 80069004 00000000 */   nop
    /* 5CA8 80069008 2000438D */  lw         $v1, 0x20($t2)
    /* 5CAC 8006900C 00000000 */  nop
    /* 5CB0 80069010 07006910 */  beq        $v1, $t1, .L80069030
    /* 5CB4 80069014 02006228 */   slti      $v0, $v1, 0x2
    /* 5CB8 80069018 03004014 */  bnez       $v0, .L80069028
    /* 5CBC 8006901C 00000000 */   nop
    /* 5CC0 80069020 04006810 */  beq        $v1, $t0, .L80069034
    /* 5CC4 80069024 82100500 */   srl       $v0, $a1, 2
  .L80069028:
    /* 5CC8 80069028 0FA40108 */  j          .L8006903C
    /* 5CCC 8006902C 0000C0A0 */   sb        $zero, 0x0($a2)
  .L80069030:
    /* 5CD0 80069030 42100500 */  srl        $v0, $a1, 1
  .L80069034:
    /* 5CD4 80069034 01004230 */  andi       $v0, $v0, 0x1
    /* 5CD8 80069038 0000C2A0 */  sb         $v0, 0x0($a2)
  .L8006903C:
    /* 5CDC 8006903C 2800E724 */  addiu      $a3, $a3, 0x28
    /* 5CE0 80069040 0000E28C */  lw         $v0, 0x0($a3)
    /* 5CE4 80069044 00000000 */  nop
    /* 5CE8 80069048 EAFF4014 */  bnez       $v0, .L80068FF4
    /* 5CEC 8006904C 2800C624 */   addiu     $a2, $a2, 0x28
  .L80069050:
    /* 5CF0 80069050 2176000C */  jal        Gfx_DrawParts
    /* 5CF4 80069054 00000000 */   nop
    /* 5CF8 80069058 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5CFC 8006905C 00000000 */  nop
    /* 5D00 80069060 0800E003 */  jr         $ra
    /* 5D04 80069064 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg20_LabCaptionDraw
