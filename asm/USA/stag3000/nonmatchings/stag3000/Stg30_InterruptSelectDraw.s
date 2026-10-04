nonmatching Stg30_InterruptSelectDraw, 0x22C

glabel Stg30_InterruptSelectDraw
    /* CC70 8006FFD0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* CC74 8006FFD4 01000324 */  addiu      $v1, $zero, 0x1
    /* CC78 8006FFD8 1800BFAF */  sw         $ra, 0x18($sp)
    /* CC7C 8006FFDC 1400B1AF */  sw         $s1, 0x14($sp)
    /* CC80 8006FFE0 1000B0AF */  sw         $s0, 0x10($sp)
    /* CC84 8006FFE4 1000828C */  lw         $v0, 0x10($a0)
    /* CC88 8006FFE8 2C00908C */  lw         $s0, 0x2C($a0)
    /* CC8C 8006FFEC 52004314 */  bne        $v0, $v1, .L80070138
    /* CC90 8006FFF0 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* CC94 8006FFF4 1400828C */  lw         $v0, 0x14($a0)
    /* CC98 8006FFF8 00000000 */  nop
    /* CC9C 8006FFFC 4E004014 */  bnez       $v0, .L80070138
    /* CCA0 80070000 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* CCA4 80070004 A101043C */  lui        $a0, (0x1A10008 >> 16)
    /* CCA8 80070008 688E000C */  jal        Cd_GetFileEntry
    /* CCAC 8007000C 08008434 */   ori       $a0, $a0, (0x1A10008 & 0xFFFF)
    /* CCB0 80070010 21204000 */  addu       $a0, $v0, $zero
    /* CCB4 80070014 0000828C */  lw         $v0, 0x0($a0)
    /* CCB8 80070018 00000000 */  nop
    /* CCBC 8007001C 43004010 */  beqz       $v0, .L8007012C
    /* CCC0 80070020 21388000 */   addu      $a3, $a0, $zero
    /* CCC4 80070024 04000A24 */  addiu      $t2, $zero, 0x4
    /* CCC8 80070028 10000924 */  addiu      $t1, $zero, 0x10
    /* CCCC 8007002C 0680063C */  lui        $a2, %hi(Sys_State)
    /* CCD0 80070030 01000824 */  addiu      $t0, $zero, 0x1
    /* CCD4 80070034 0F008524 */  addiu      $a1, $a0, 0xF
  .L80070038:
    /* CCD8 80070038 00000286 */  lh         $v0, 0x0($s0)
    /* CCDC 8007003C 00000000 */  nop
    /* CCE0 80070040 0100A2AC */  sw         $v0, 0x1($a1)
    /* CCE4 80070044 02000286 */  lh         $v0, 0x2($s0)
    /* CCE8 80070048 00000000 */  nop
    /* CCEC 8007004C 0500A2AC */  sw         $v0, 0x5($a1)
    /* CCF0 80070050 04000292 */  lbu        $v0, 0x4($s0)
    /* CCF4 80070054 00000000 */  nop
    /* CCF8 80070058 FDFFA2A0 */  sb         $v0, -0x3($a1)
    /* CCFC 8007005C 0C00028E */  lw         $v0, 0xC($s0)
    /* CD00 80070060 00000000 */  nop
    /* CD04 80070064 12004014 */  bnez       $v0, .L800700B0
    /* CD08 80070068 08000224 */   addiu     $v0, $zero, 0x8
    /* CD0C 8007006C 0D00A38C */  lw         $v1, 0xD($a1)
    /* CD10 80070070 00000000 */  nop
    /* CD14 80070074 20006210 */  beq        $v1, $v0, .L800700F8
    /* CD18 80070078 09006228 */   slti      $v0, $v1, 0x9
    /* CD1C 8007007C 05004010 */  beqz       $v0, .L80070094
    /* CD20 80070080 00000000 */   nop
    /* CD24 80070084 07006A10 */  beq        $v1, $t2, .L800700A4
    /* CD28 80070088 00000000 */   nop
    /* CD2C 8007008C 46C00108 */  j          .L80070118
    /* CD30 80070090 0000A8A0 */   sb        $t0, 0x0($a1)
  .L80070094:
    /* CD34 80070094 1F006914 */  bne        $v1, $t1, .L80070114
    /* CD38 80070098 00000000 */   nop
  .L8007009C:
    /* CD3C 8007009C 46C00108 */  j          .L80070118
    /* CD40 800700A0 0000A0A0 */   sb        $zero, 0x0($a1)
  .L800700A4:
    /* CD44 800700A4 70F7C28C */  lw         $v0, %lo(Sys_State)($a2)
    /* CD48 800700A8 42C00108 */  j          .L80070108
    /* CD4C 800700AC 42100200 */   srl       $v0, $v0, 1
  .L800700B0:
    /* CD50 800700B0 0D00A38C */  lw         $v1, 0xD($a1)
    /* CD54 800700B4 00000000 */  nop
    /* CD58 800700B8 0C006910 */  beq        $v1, $t1, .L800700EC
    /* CD5C 800700BC 00000000 */   nop
    /* CD60 800700C0 11006228 */  slti       $v0, $v1, 0x11
    /* CD64 800700C4 05004010 */  beqz       $v0, .L800700DC
    /* CD68 800700C8 20000224 */   addiu     $v0, $zero, 0x20
    /* CD6C 800700CC F3FF6A10 */  beq        $v1, $t2, .L8007009C
    /* CD70 800700D0 00000000 */   nop
    /* CD74 800700D4 46C00108 */  j          .L80070118
    /* CD78 800700D8 0000A8A0 */   sb        $t0, 0x0($a1)
  .L800700DC:
    /* CD7C 800700DC 06006210 */  beq        $v1, $v0, .L800700F8
    /* CD80 800700E0 00000000 */   nop
    /* CD84 800700E4 46C00108 */  j          .L80070118
    /* CD88 800700E8 0000A8A0 */   sb        $t0, 0x0($a1)
  .L800700EC:
    /* CD8C 800700EC 70F7C28C */  lw         $v0, %lo(Sys_State)($a2)
    /* CD90 800700F0 42C00108 */  j          .L80070108
    /* CD94 800700F4 42100200 */   srl       $v0, $v0, 1
  .L800700F8:
    /* CD98 800700F8 70F7C28C */  lw         $v0, %lo(Sys_State)($a2)
    /* CD9C 800700FC 00000000 */  nop
    /* CDA0 80070100 42100200 */  srl        $v0, $v0, 1
    /* CDA4 80070104 01004238 */  xori       $v0, $v0, 0x1
  .L80070108:
    /* CDA8 80070108 01004230 */  andi       $v0, $v0, 0x1
    /* CDAC 8007010C 46C00108 */  j          .L80070118
    /* CDB0 80070110 0000A2A0 */   sb        $v0, 0x0($a1)
  .L80070114:
    /* CDB4 80070114 0000A8A0 */  sb         $t0, 0x0($a1)
  .L80070118:
    /* CDB8 80070118 2800E724 */  addiu      $a3, $a3, 0x28
    /* CDBC 8007011C 0000E28C */  lw         $v0, 0x0($a3)
    /* CDC0 80070120 00000000 */  nop
    /* CDC4 80070124 C4FF4014 */  bnez       $v0, .L80070038
    /* CDC8 80070128 2800A524 */   addiu     $a1, $a1, 0x28
  .L8007012C:
    /* CDCC 8007012C 2176000C */  jal        Gfx_DrawParts
    /* CDD0 80070130 00000000 */   nop
    /* CDD4 80070134 0780023C */  lui        $v0, %hi(Stg30_Battle)
  .L80070138:
    /* CDD8 80070138 C03C5124 */  addiu      $s1, $v0, %lo(Stg30_Battle)
    /* CDDC 8007013C D403228E */  lw         $v0, 0x3D4($s1)
    /* CDE0 80070140 00000000 */  nop
    /* CDE4 80070144 28004010 */  beqz       $v0, .L800701E8
    /* CDE8 80070148 A101043C */   lui       $a0, (0x1A1000B >> 16)
    /* CDEC 8007014C 688E000C */  jal        Cd_GetFileEntry
    /* CDF0 80070150 0B008434 */   ori       $a0, $a0, (0x1A1000B & 0xFFFF)
    /* CDF4 80070154 1000058E */  lw         $a1, 0x10($s0)
    /* CDF8 80070158 21204000 */  addu       $a0, $v0, $zero
    /* CDFC 8007015C 00110500 */  sll        $v0, $a1, 4
    /* CE00 80070160 21105100 */  addu       $v0, $v0, $s1
    /* CE04 80070164 AC02438C */  lw         $v1, 0x2AC($v0)
    /* CE08 80070168 03000224 */  addiu      $v0, $zero, 0x3
    /* CE0C 8007016C 02006210 */  beq        $v1, $v0, .L80070178
    /* CE10 80070170 00000000 */   nop
    /* CE14 80070174 2128A200 */  addu       $a1, $a1, $v0
  .L80070178:
    /* CE18 80070178 0000828C */  lw         $v0, 0x0($a0)
    /* CE1C 8007017C 00000000 */  nop
    /* CE20 80070180 17004010 */  beqz       $v0, .L800701E0
    /* CE24 80070184 21308000 */   addu      $a2, $a0, $zero
    /* CE28 80070188 0780023C */  lui        $v0, %hi(Stg30_InterruptCursorMasks)
    /* CE2C 8007018C 40334224 */  addiu      $v0, $v0, %lo(Stg30_InterruptCursorMasks)
    /* CE30 80070190 80180500 */  sll        $v1, $a1, 2
    /* CE34 80070194 21386200 */  addu       $a3, $v1, $v0
    /* CE38 80070198 01000824 */  addiu      $t0, $zero, 0x1
    /* CE3C 8007019C 0F008524 */  addiu      $a1, $a0, 0xF
  .L800701A0:
    /* CE40 800701A0 0D00A28C */  lw         $v0, 0xD($a1)
    /* CE44 800701A4 0000E38C */  lw         $v1, 0x0($a3)
    /* CE48 800701A8 00000000 */  nop
    /* CE4C 800701AC 24104300 */  and        $v0, $v0, $v1
    /* CE50 800701B0 05004010 */  beqz       $v0, .L800701C8
    /* CE54 800701B4 00000000 */   nop
    /* CE58 800701B8 0000A8A0 */  sb         $t0, 0x0($a1)
    /* CE5C 800701BC 08000292 */  lbu        $v0, 0x8($s0)
    /* CE60 800701C0 73C00108 */  j          .L800701CC
    /* CE64 800701C4 FDFFA2A0 */   sb        $v0, -0x3($a1)
  .L800701C8:
    /* CE68 800701C8 0000A0A0 */  sb         $zero, 0x0($a1)
  .L800701CC:
    /* CE6C 800701CC 2800C624 */  addiu      $a2, $a2, 0x28
    /* CE70 800701D0 0000C28C */  lw         $v0, 0x0($a2)
    /* CE74 800701D4 00000000 */  nop
    /* CE78 800701D8 F1FF4014 */  bnez       $v0, .L800701A0
    /* CE7C 800701DC 2800A524 */   addiu     $a1, $a1, 0x28
  .L800701E0:
    /* CE80 800701E0 2176000C */  jal        Gfx_DrawParts
    /* CE84 800701E4 00000000 */   nop
  .L800701E8:
    /* CE88 800701E8 1800BF8F */  lw         $ra, 0x18($sp)
    /* CE8C 800701EC 1400B18F */  lw         $s1, 0x14($sp)
    /* CE90 800701F0 1000B08F */  lw         $s0, 0x10($sp)
    /* CE94 800701F4 0800E003 */  jr         $ra
    /* CE98 800701F8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_InterruptSelectDraw
