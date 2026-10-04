nonmatching Stg11_CardMenuInit, 0xC8

glabel Stg11_CardMenuInit
    /* 2CC8 80066028 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2CCC 8006602C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2CD0 80066030 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2CD4 80066034 2C00908C */  lw         $s0, 0x2C($a0)
    /* 2CD8 80066038 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 2CDC 8006603C 780005A6 */  sh         $a1, 0x78($s0)
    /* 2CE0 80066040 002C0500 */  sll        $a1, $a1, 16
    /* 2CE4 80066044 78000386 */  lh         $v1, 0x78($s0)
    /* 2CE8 80066048 78000496 */  lhu        $a0, 0x78($s0)
    /* 2CEC 8006604C 2A284500 */  slt        $a1, $v0, $a1
    /* 2CF0 80066050 7A0005A6 */  sh         $a1, 0x7A($s0)
    /* 2CF4 80066054 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2CF8 80066058 C2170300 */  srl        $v0, $v1, 31
    /* 2CFC 8006605C 21106200 */  addu       $v0, $v1, $v0
    /* 2D00 80066060 43100200 */  sra        $v0, $v0, 1
    /* 2D04 80066064 40100200 */  sll        $v0, $v0, 1
    /* 2D08 80066068 23186200 */  subu       $v1, $v1, $v0
    /* 2D0C 8006606C 78000296 */  lhu        $v0, 0x78($s0)
    /* 2D10 80066070 F9FF8424 */  addiu      $a0, $a0, -0x7
    /* 2D14 80066074 840003A6 */  sh         $v1, 0x84($s0)
    /* 2D18 80066078 78000396 */  lhu        $v1, 0x78($s0)
    /* 2D1C 8006607C 0200842C */  sltiu      $a0, $a0, 0x2
    /* 2D20 80066080 7E0004A6 */  sh         $a0, 0x7E($s0)
    /* 2D24 80066084 FBFF4224 */  addiu      $v0, $v0, -0x5
    /* 2D28 80066088 0400422C */  sltiu      $v0, $v0, 0x4
    /* 2D2C 8006608C F7FF6324 */  addiu      $v1, $v1, -0x9
    /* 2D30 80066090 7C0002A6 */  sh         $v0, 0x7C($s0)
    /* 2D34 80066094 78000296 */  lhu        $v0, 0x78($s0)
    /* 2D38 80066098 0200632C */  sltiu      $v1, $v1, 0x2
    /* 2D3C 8006609C F7FF4224 */  addiu      $v0, $v0, -0x9
    /* 2D40 800660A0 0200422C */  sltiu      $v0, $v0, 0x2
    /* 2D44 800660A4 05004010 */  beqz       $v0, .L800660BC
    /* 2D48 800660A8 800003A6 */   sh        $v1, 0x80($s0)
    /* 2D4C 800660AC 0680043C */  lui        $a0, %hi(Stg11_TransferFileName)
    /* 2D50 800660B0 54348424 */  addiu      $a0, $a0, %lo(Stg11_TransferFileName)
    /* 2D54 800660B4 32980108 */  j          .L800660C8
    /* 2D58 800660B8 01000524 */   addiu     $a1, $zero, 0x1
  .L800660BC:
    /* 2D5C 800660BC 0680043C */  lui        $a0, %hi(Stg11_SaveFileName)
    /* 2D60 800660C0 64348424 */  addiu      $a0, $a0, %lo(Stg11_SaveFileName)
    /* 2D64 800660C4 21280000 */  addu       $a1, $zero, $zero
  .L800660C8:
    /* 2D68 800660C8 0E9E010C */  jal        Stg11_CardSetFileName
    /* 2D6C 800660CC 00000000 */   nop
    /* 2D70 800660D0 BD9D010C */  jal        Stg11_CardGetDataBuf
    /* 2D74 800660D4 00000000 */   nop
    /* 2D78 800660D8 900002AE */  sw         $v0, 0x90($s0)
    /* 2D7C 800660DC 940000A6 */  sh         $zero, 0x94($s0)
    /* 2D80 800660E0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2D84 800660E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D88 800660E8 0800E003 */  jr         $ra
    /* 2D8C 800660EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg11_CardMenuInit
