nonmatching trapIntrVSync, 0x6C

glabel trapIntrVSync
    /* 21CBC 800314BC 0580023C */  lui        $v0, %hi(Sys_VSyncCount)
    /* 21CC0 800314C0 C0FB428C */  lw         $v0, %lo(Sys_VSyncCount)($v0)
    /* 21CC4 800314C4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 21CC8 800314C8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 21CCC 800314CC 21880000 */  addu       $s1, $zero, $zero
    /* 21CD0 800314D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 21CD4 800314D4 0580103C */  lui        $s0, %hi(Sys_VSyncCallbacks)
    /* 21CD8 800314D8 A0FB1026 */  addiu      $s0, $s0, %lo(Sys_VSyncCallbacks)
    /* 21CDC 800314DC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 21CE0 800314E0 01004224 */  addiu      $v0, $v0, 0x1
    /* 21CE4 800314E4 0580013C */  lui        $at, %hi(Sys_VSyncCount)
    /* 21CE8 800314E8 C0FB22AC */  sw         $v0, %lo(Sys_VSyncCount)($at)
  .L800314EC:
    /* 21CEC 800314EC 0000028E */  lw         $v0, 0x0($s0)
    /* 21CF0 800314F0 00000000 */  nop
    /* 21CF4 800314F4 03004010 */  beqz       $v0, .L80031504
    /* 21CF8 800314F8 00000000 */   nop
    /* 21CFC 800314FC 09F84000 */  jalr       $v0
    /* 21D00 80031500 00000000 */   nop
  .L80031504:
    /* 21D04 80031504 01003126 */  addiu      $s1, $s1, 0x1
    /* 21D08 80031508 0800222A */  slti       $v0, $s1, 0x8
    /* 21D0C 8003150C F7FF4014 */  bnez       $v0, .L800314EC
    /* 21D10 80031510 04001026 */   addiu     $s0, $s0, 0x4
    /* 21D14 80031514 1800BF8F */  lw         $ra, 0x18($sp)
    /* 21D18 80031518 1400B18F */  lw         $s1, 0x14($sp)
    /* 21D1C 8003151C 1000B08F */  lw         $s0, 0x10($sp)
    /* 21D20 80031520 0800E003 */  jr         $ra
    /* 21D24 80031524 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel trapIntrVSync
