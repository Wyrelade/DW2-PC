nonmatching _SsInit, 0xA0

glabel _SsInit
    /* 23074 80032874 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23078 80032878 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2307C 8003287C 801F053C */  lui        $a1, (0x1F801D80 >> 16)
    /* 23080 80032880 801DA534 */  ori        $a1, $a1, (0x1F801D80 & 0xFFFF)
    /* 23084 80032884 21180000 */  addu       $v1, $zero, $zero
    /* 23088 80032888 0580043C */  lui        $a0, %hi(D_8004FC24)
    /* 2308C 8003288C 24FC8424 */  addiu      $a0, $a0, %lo(D_8004FC24)
  .L80032890:
    /* 23090 80032890 00008294 */  lhu        $v0, 0x0($a0)
    /* 23094 80032894 02008424 */  addiu      $a0, $a0, 0x2
    /* 23098 80032898 01006324 */  addiu      $v1, $v1, 0x1
    /* 2309C 8003289C 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 230A0 800328A0 10006228 */  slti       $v0, $v1, 0x10
    /* 230A4 800328A4 FAFF4014 */  bnez       $v0, .L80032890
    /* 230A8 800328A8 0200A524 */   addiu     $a1, $a1, 0x2
    /* 230AC 800328AC 15DB000C */  jal        _SsVmInit
    /* 230B0 800328B0 18000424 */   addiu     $a0, $zero, 0x18
    /* 230B4 800328B4 21280000 */  addu       $a1, $zero, $zero
    /* 230B8 800328B8 0680043C */  lui        $a0, %hi(Snd_MarkCallbacks)
    /* 230BC 800328BC D01C8424 */  addiu      $a0, $a0, %lo(Snd_MarkCallbacks)
  .L800328C0:
    /* 230C0 800328C0 0F000324 */  addiu      $v1, $zero, 0xF
    /* 230C4 800328C4 3C008224 */  addiu      $v0, $a0, 0x3C
  .L800328C8:
    /* 230C8 800328C8 000040AC */  sw         $zero, 0x0($v0)
    /* 230CC 800328CC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 230D0 800328D0 FDFF6104 */  bgez       $v1, .L800328C8
    /* 230D4 800328D4 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* 230D8 800328D8 0100A524 */  addiu      $a1, $a1, 0x1
    /* 230DC 800328DC 2000A228 */  slti       $v0, $a1, 0x20
    /* 230E0 800328E0 F7FF4014 */  bnez       $v0, .L800328C0
    /* 230E4 800328E4 40008424 */   addiu     $a0, $a0, 0x40
    /* 230E8 800328E8 3C000224 */  addiu      $v0, $zero, 0x3C
    /* 230EC 800328EC 0680013C */  lui        $at, %hi(Snd_TicksPerSec)
    /* 230F0 800328F0 4C1C22AC */  sw         $v0, %lo(Snd_TicksPerSec)($at)
    /* 230F4 800328F4 0680013C */  lui        $at, %hi(D_80061C48)
    /* 230F8 800328F8 481C20AC */  sw         $zero, %lo(D_80061C48)($at)
    /* 230FC 800328FC 0680013C */  lui        $at, %hi(D_80061C44)
    /* 23100 80032900 441C20AC */  sw         $zero, %lo(D_80061C44)($at)
    /* 23104 80032904 1000BF8F */  lw         $ra, 0x10($sp)
    /* 23108 80032908 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2310C 8003290C 0800E003 */  jr         $ra
    /* 23110 80032910 00000000 */   nop
endlabel _SsInit
