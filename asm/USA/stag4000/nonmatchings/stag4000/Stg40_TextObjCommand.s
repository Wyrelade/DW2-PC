nonmatching Stg40_TextObjCommand, 0x130

glabel Stg40_TextObjCommand
    /* EC5C 80071FBC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* EC60 80071FC0 1400B1AF */  sw         $s1, 0x14($sp)
    /* EC64 80071FC4 0780113C */  lui        $s1, %hi(D_80072B60)
    /* EC68 80071FC8 602B258E */  lw         $a1, %lo(D_80072B60)($s1)
    /* EC6C 80071FCC 21188000 */  addu       $v1, $a0, $zero
    /* EC70 80071FD0 1800BFAF */  sw         $ra, 0x18($sp)
    /* EC74 80071FD4 1000B0AF */  sw         $s0, 0x10($sp)
    /* EC78 80071FD8 0000628C */  lw         $v0, 0x0($v1)
    /* EC7C 80071FDC 04006324 */  addiu      $v1, $v1, 0x4
    /* EC80 80071FE0 7801A2AC */  sw         $v0, 0x178($a1)
    /* EC84 80071FE4 00006294 */  lhu        $v0, 0x0($v1)
    /* EC88 80071FE8 7801A48C */  lw         $a0, 0x178($a1)
    /* EC8C 80071FEC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* EC90 80071FF0 7C01A2A4 */  sh         $v0, 0x17C($a1)
    /* EC94 80071FF4 04006294 */  lhu        $v0, 0x4($v1)
    /* EC98 80071FF8 FFFF1024 */  addiu      $s0, $zero, -0x1
    /* EC9C 80071FFC 8001A0A4 */  sh         $zero, 0x180($a1)
    /* ECA0 80072000 8401A0AC */  sw         $zero, 0x184($a1)
    /* ECA4 80072004 21105000 */  addu       $v0, $v0, $s0
    /* ECA8 80072008 D4C7010C */  jal        Stg40_FindEntByDigiId
    /* ECAC 8007200C 7E01A2A4 */   sh        $v0, 0x17E($a1)
    /* ECB0 80072010 21304000 */  addu       $a2, $v0, $zero
    /* ECB4 80072014 3000C010 */  beqz       $a2, .L800720D8
    /* ECB8 80072018 01000224 */   addiu     $v0, $zero, 0x1
    /* ECBC 8007201C 602B258E */  lw         $a1, %lo(D_80072B60)($s1)
    /* ECC0 80072020 1400C48C */  lw         $a0, 0x14($a2)
    /* ECC4 80072024 7C01A384 */  lh         $v1, 0x17C($a1)
    /* ECC8 80072028 8001A2A4 */  sh         $v0, 0x180($a1)
    /* ECCC 8007202C 61000224 */  addiu      $v0, $zero, 0x61
    /* ECD0 80072030 13006210 */  beq        $v1, $v0, .L80072080
    /* ECD4 80072034 62006228 */   slti      $v0, $v1, 0x62
    /* ECD8 80072038 05004010 */  beqz       $v0, .L80072050
    /* ECDC 8007203C 60000224 */   addiu     $v0, $zero, 0x60
    /* ECE0 80072040 1B006210 */  beq        $v1, $v0, .L800720B0
    /* ECE4 80072044 00000000 */   nop
    /* ECE8 80072048 31C80108 */  j          .L800720C4
    /* ECEC 8007204C 05001024 */   addiu     $s0, $zero, 0x5
  .L80072050:
    /* ECF0 80072050 62000224 */  addiu      $v0, $zero, 0x62
    /* ECF4 80072054 03006210 */  beq        $v1, $v0, .L80072064
    /* ECF8 80072058 00000000 */   nop
    /* ECFC 8007205C 31C80108 */  j          .L800720C4
    /* ED00 80072060 05001024 */   addiu     $s0, $zero, 0x5
  .L80072064:
    /* ED04 80072064 7E01A284 */  lh         $v0, 0x17E($a1)
    /* ED08 80072068 00000000 */  nop
    /* ED0C 8007206C 14005014 */  bne        $v0, $s0, .L800720C0
    /* ED10 80072070 06001024 */   addiu     $s0, $zero, 0x6
    /* ED14 80072074 04001024 */  addiu      $s0, $zero, 0x4
    /* ED18 80072078 31C80108 */  j          .L800720C4
    /* ED1C 8007207C 8401A4AC */   sw        $a0, 0x184($a1)
  .L80072080:
    /* ED20 80072080 0BB6033C */  lui        $v1, (0xB60B60B7 >> 16)
    /* ED24 80072084 7E01A284 */  lh         $v0, 0x17E($a1)
    /* ED28 80072088 B7606334 */  ori        $v1, $v1, (0xB60B60B7 & 0xFFFF)
    /* ED2C 8007208C 00130200 */  sll        $v0, $v0, 12
    /* ED30 80072090 18004300 */  mult       $v0, $v1
    /* ED34 80072094 10380000 */  mfhi       $a3
    /* ED38 80072098 2118E200 */  addu       $v1, $a3, $v0
    /* ED3C 8007209C 031A0300 */  sra        $v1, $v1, 8
    /* ED40 800720A0 C3170200 */  sra        $v0, $v0, 31
    /* ED44 800720A4 23186200 */  subu       $v1, $v1, $v0
    /* ED48 800720A8 30C80108 */  j          .L800720C0
    /* ED4C 800720AC 0E00C3A4 */   sh        $v1, 0xE($a2)
  .L800720B0:
    /* ED50 800720B0 0000C28C */  lw         $v0, 0x0($a2)
    /* ED54 800720B4 00000000 */  nop
    /* ED58 800720B8 00024234 */  ori        $v0, $v0, 0x200
    /* ED5C 800720BC 0000C2AC */  sw         $v0, 0x0($a2)
  .L800720C0:
    /* ED60 800720C0 8001A0A4 */  sh         $zero, 0x180($a1)
  .L800720C4:
    /* ED64 800720C4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* ED68 800720C8 03000212 */  beq        $s0, $v0, .L800720D8
    /* ED6C 800720CC 00000000 */   nop
    /* ED70 800720D0 7745000C */  jal        Task_SetState1
    /* ED74 800720D4 FF000532 */   andi      $a1, $s0, 0xFF
  .L800720D8:
    /* ED78 800720D8 1800BF8F */  lw         $ra, 0x18($sp)
    /* ED7C 800720DC 1400B18F */  lw         $s1, 0x14($sp)
    /* ED80 800720E0 1000B08F */  lw         $s0, 0x10($sp)
    /* ED84 800720E4 0800E003 */  jr         $ra
    /* ED88 800720E8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_TextObjCommand
