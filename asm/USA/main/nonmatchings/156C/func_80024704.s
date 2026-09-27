nonmatching func_80024704, 0xF0

glabel func_80024704
    /* 14F04 80024704 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14F08 80024708 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14F0C 8002470C 0680103C */  lui        $s0, %hi(D_8005FDD8)
    /* 14F10 80024710 D8FD1026 */  addiu      $s0, $s0, %lo(D_8005FDD8)
    /* 14F14 80024714 21200002 */  addu       $a0, $s0, $zero
    /* 14F18 80024718 1400BFAF */  sw         $ra, 0x14($sp)
    /* 14F1C 8002471C 059C000C */  jal        bzero
    /* 14F20 80024720 E0010524 */   addiu     $a1, $zero, 0x1E0
    /* 14F24 80024724 0680023C */  lui        $v0, %hi(D_8005FFB8)
    /* 14F28 80024728 B8FF4224 */  addiu      $v0, $v0, %lo(D_8005FFB8)
    /* 14F2C 8002472C 0680033C */  lui        $v1, %hi(D_80060000)
    /* 14F30 80024730 00006324 */  addiu      $v1, $v1, %lo(D_80060000)
    /* 14F34 80024734 3C0002AE */  sw         $v0, 0x3C($s0)
    /* 14F38 80024738 23004224 */  addiu      $v0, $v0, 0x23
    /* 14F3C 8002473C 400003AE */  sw         $v1, 0x40($s0)
    /* 14F40 80024740 23006324 */  addiu      $v1, $v1, 0x23
    /* 14F44 80024744 2C0102AE */  sw         $v0, 0x12C($s0)
    /* 14F48 80024748 0280023C */  lui        $v0, %hi(func_8002485C)
    /* 14F4C 8002474C 5C484224 */  addiu      $v0, $v0, %lo(func_8002485C)
    /* 14F50 80024750 0580013C */  lui        $at, %hi(D_80048E18)
    /* 14F54 80024754 188E22AC */  sw         $v0, %lo(D_80048E18)($at)
    /* 14F58 80024758 0280023C */  lui        $v0, %hi(func_800247F4)
    /* 14F5C 8002475C F4474224 */  addiu      $v0, $v0, %lo(func_800247F4)
    /* 14F60 80024760 0580013C */  lui        $at, %hi(D_80048E1C)
    /* 14F64 80024764 1C8E22AC */  sw         $v0, %lo(D_80048E1C)($at)
    /* 14F68 80024768 0280023C */  lui        $v0, %hi(func_80024960)
    /* 14F6C 8002476C 60494224 */  addiu      $v0, $v0, %lo(func_80024960)
    /* 14F70 80024770 0580013C */  lui        $at, %hi(D_80048E20)
    /* 14F74 80024774 208E22AC */  sw         $v0, %lo(D_80048E20)($at)
    /* 14F78 80024778 0280023C */  lui        $v0, %hi(func_80024A1C)
    /* 14F7C 8002477C 1C4A4224 */  addiu      $v0, $v0, %lo(func_80024A1C)
    /* 14F80 80024780 0580013C */  lui        $at, %hi(D_80048E24)
    /* 14F84 80024784 248E22AC */  sw         $v0, %lo(D_80048E24)($at)
    /* 14F88 80024788 0280023C */  lui        $v0, %hi(Pad_GetPortBlock)
    /* 14F8C 8002478C 984C4224 */  addiu      $v0, $v0, %lo(Pad_GetPortBlock)
    /* 14F90 80024790 0580013C */  lui        $at, %hi(D_80048E2C)
    /* 14F94 80024794 2C8E22AC */  sw         $v0, %lo(D_80048E2C)($at)
    /* 14F98 80024798 0280023C */  lui        $v0, %hi(func_80024950)
    /* 14F9C 8002479C 50494224 */  addiu      $v0, $v0, %lo(func_80024950)
    /* 14FA0 800247A0 0580013C */  lui        $at, %hi(D_80048E3C)
    /* 14FA4 800247A4 3C8E22AC */  sw         $v0, %lo(D_80048E3C)($at)
    /* 14FA8 800247A8 0280023C */  lui        $v0, %hi(func_80024CB8)
    /* 14FAC 800247AC B84C4224 */  addiu      $v0, $v0, %lo(func_80024CB8)
    /* 14FB0 800247B0 0580013C */  lui        $at, %hi(D_80048E30)
    /* 14FB4 800247B4 308E22AC */  sw         $v0, %lo(D_80048E30)($at)
    /* 14FB8 800247B8 0280023C */  lui        $v0, %hi(func_80025114)
    /* 14FBC 800247BC 14514224 */  addiu      $v0, $v0, %lo(func_80025114)
    /* 14FC0 800247C0 0580013C */  lui        $at, %hi(D_80048E34)
    /* 14FC4 800247C4 348E22AC */  sw         $v0, %lo(D_80048E34)($at)
    /* 14FC8 800247C8 0280023C */  lui        $v0, %hi(func_80024DC8)
    /* 14FCC 800247CC C84D4224 */  addiu      $v0, $v0, %lo(func_80024DC8)
    /* 14FD0 800247D0 0580013C */  lui        $at, %hi(D_80048E4C)
    /* 14FD4 800247D4 4C8E30AC */  sw         $s0, %lo(D_80048E4C)($at)
    /* 14FD8 800247D8 300103AE */  sw         $v1, 0x130($s0)
    /* 14FDC 800247DC 0580013C */  lui        $at, %hi(D_80048E38)
    /* 14FE0 800247E0 388E22AC */  sw         $v0, %lo(D_80048E38)($at)
    /* 14FE4 800247E4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 14FE8 800247E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 14FEC 800247EC 0800E003 */  jr         $ra
    /* 14FF0 800247F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80024704
