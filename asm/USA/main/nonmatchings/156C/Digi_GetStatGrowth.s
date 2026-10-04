nonmatching Digi_GetStatGrowth, 0xB4

glabel Digi_GetStatGrowth
    /* E1CC 8001D9CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E1D0 8001D9D0 0500A22C */  sltiu      $v0, $a1, 0x5
    /* E1D4 8001D9D4 09004010 */  beqz       $v0, .L8001D9FC
    /* E1D8 8001D9D8 1000BFAF */   sw        $ra, 0x10($sp)
    /* E1DC 8001D9DC 0180023C */  lui        $v0, %hi(jtbl_800101B4)
    /* E1E0 8001D9E0 B4014224 */  addiu      $v0, $v0, %lo(jtbl_800101B4)
    /* E1E4 8001D9E4 80180500 */  sll        $v1, $a1, 2
    /* E1E8 8001D9E8 21186200 */  addu       $v1, $v1, $v0
    /* E1EC 8001D9EC 0000628C */  lw         $v0, 0x0($v1)
    /* E1F0 8001D9F0 00000000 */  nop
    /* E1F4 8001D9F4 08004000 */  jr         $v0
    /* E1F8 8001D9F8 00000000 */   nop
  jlabel .L8001D9FC
    /* E1FC 8001D9FC 3176000C */  jal        Digi_FindBaseData
    /* E200 8001DA00 00000000 */   nop
    /* E204 8001DA04 04004294 */  lhu        $v0, 0x4($v0)
    /* E208 8001DA08 9C760008 */  j          .L8001DA70
    /* E20C 8001DA0C 02130200 */   srl       $v0, $v0, 12
  jlabel .L8001DA10
    /* E210 8001DA10 3176000C */  jal        Digi_FindBaseData
    /* E214 8001DA14 00000000 */   nop
    /* E218 8001DA18 06004290 */  lbu        $v0, 0x6($v0)
    /* E21C 8001DA1C 9C760008 */  j          .L8001DA70
    /* E220 8001DA20 0F004230 */   andi      $v0, $v0, 0xF
  jlabel .L8001DA24
    /* E224 8001DA24 3176000C */  jal        Digi_FindBaseData
    /* E228 8001DA28 00000000 */   nop
    /* E22C 8001DA2C 06004294 */  lhu        $v0, 0x6($v0)
    /* E230 8001DA30 00000000 */  nop
    /* E234 8001DA34 02110200 */  srl        $v0, $v0, 4
    /* E238 8001DA38 9C760008 */  j          .L8001DA70
    /* E23C 8001DA3C 0F004230 */   andi      $v0, $v0, 0xF
  jlabel .L8001DA40
    /* E240 8001DA40 3176000C */  jal        Digi_FindBaseData
    /* E244 8001DA44 00000000 */   nop
    /* E248 8001DA48 06004294 */  lhu        $v0, 0x6($v0)
    /* E24C 8001DA4C 00000000 */  nop
    /* E250 8001DA50 02120200 */  srl        $v0, $v0, 8
    /* E254 8001DA54 9C760008 */  j          .L8001DA70
    /* E258 8001DA58 0F004230 */   andi      $v0, $v0, 0xF
  jlabel .L8001DA5C
    /* E25C 8001DA5C 3176000C */  jal        Digi_FindBaseData
    /* E260 8001DA60 00000000 */   nop
    /* E264 8001DA64 06004294 */  lhu        $v0, 0x6($v0)
    /* E268 8001DA68 00000000 */  nop
    /* E26C 8001DA6C 02130200 */  srl        $v0, $v0, 12
  .L8001DA70:
    /* E270 8001DA70 1000BF8F */  lw         $ra, 0x10($sp)
    /* E274 8001DA74 00000000 */  nop
    /* E278 8001DA78 0800E003 */  jr         $ra
    /* E27C 8001DA7C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Digi_GetStatGrowth
