nonmatching Text_SetOtLayer, 0x70

glabel Text_SetOtLayer
    /* C758 8001BF58 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C75C 8001BF5C 1000B0AF */  sw         $s0, 0x10($sp)
    /* C760 8001BF60 21808000 */  addu       $s0, $a0, $zero
    /* C764 8001BF64 1400B1AF */  sw         $s1, 0x14($sp)
    /* C768 8001BF68 2188A000 */  addu       $s1, $a1, $zero
    /* C76C 8001BF6C 09000424 */  addiu      $a0, $zero, 0x9
    /* C770 8001BF70 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* C774 8001BF74 1800BFAF */  sw         $ra, 0x18($sp)
    /* C778 8001BF78 4445000C */  jal        Task_FindFirst
    /* C77C 8001BF7C 2130A000 */   addu      $a2, $a1, $zero
    /* C780 8001BF80 21184000 */  addu       $v1, $v0, $zero
    /* C784 8001BF84 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* C788 8001BF88 0A000212 */  beq        $s0, $v0, .L8001BFB4
    /* C78C 8001BF8C 00000000 */   nop
    /* C790 8001BF90 08006010 */  beqz       $v1, .L8001BFB4
    /* C794 8001BF94 40101000 */   sll       $v0, $s0, 1
    /* C798 8001BF98 21105000 */  addu       $v0, $v0, $s0
    /* C79C 8001BF9C 80100200 */  sll        $v0, $v0, 2
    /* C7A0 8001BFA0 21105000 */  addu       $v0, $v0, $s0
    /* C7A4 8001BFA4 2C00638C */  lw         $v1, 0x2C($v1)
    /* C7A8 8001BFA8 80100200 */  sll        $v0, $v0, 2
    /* C7AC 8001BFAC 21186200 */  addu       $v1, $v1, $v0
    /* C7B0 8001BFB0 310071A0 */  sb         $s1, 0x31($v1)
  .L8001BFB4:
    /* C7B4 8001BFB4 1800BF8F */  lw         $ra, 0x18($sp)
    /* C7B8 8001BFB8 1400B18F */  lw         $s1, 0x14($sp)
    /* C7BC 8001BFBC 1000B08F */  lw         $s0, 0x10($sp)
    /* C7C0 8001BFC0 0800E003 */  jr         $ra
    /* C7C4 8001BFC4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Text_SetOtLayer
