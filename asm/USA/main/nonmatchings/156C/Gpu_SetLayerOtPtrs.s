nonmatching Gpu_SetLayerOtPtrs, 0xA0

glabel Gpu_SetLayerOtPtrs
    /* CF60 8001C760 21380000 */  addu       $a3, $zero, $zero
    /* CF64 8001C764 0480023C */  lui        $v0, %hi(D_80041570)
    /* CF68 8001C768 70154C24 */  addiu      $t4, $v0, %lo(D_80041570)
    /* CF6C 8001C76C 0580023C */  lui        $v0, %hi(Gpu_OtBufs)
    /* CF70 8001C770 F84C4B24 */  addiu      $t3, $v0, %lo(Gpu_OtBufs)
    /* CF74 8001C774 0680023C */  lui        $v0, %hi(D_8005CCF8)
    /* CF78 8001C778 F8CC4824 */  addiu      $t0, $v0, %lo(D_8005CCF8)
    /* CF7C 8001C77C 0480023C */  lui        $v0, %hi(D_800415F0)
    /* CF80 8001C780 F0154A24 */  addiu      $t2, $v0, %lo(D_800415F0)
    /* CF84 8001C784 0680023C */  lui        $v0, %hi(D_8005F770)
    /* CF88 8001C788 70F74924 */  addiu      $t1, $v0, %lo(D_8005F770)
    /* CF8C 8001C78C 21302001 */  addu       $a2, $t1, $zero
  .L8001C790:
    /* CF90 8001C790 6000028D */  lw         $v0, 0x60($t0)
    /* CF94 8001C794 80280700 */  sll        $a1, $a3, 2
    /* CF98 8001C798 40110200 */  sll        $v0, $v0, 5
    /* CF9C 8001C79C 2110A200 */  addu       $v0, $a1, $v0
    /* CFA0 8001C7A0 21104C00 */  addu       $v0, $v0, $t4
    /* CFA4 8001C7A4 0000428C */  lw         $v0, 0x0($v0)
    /* CFA8 8001C7A8 0100E724 */  addiu      $a3, $a3, 0x1
    /* CFAC 8001C7AC 1801C2AC */  sw         $v0, 0x118($a2)
    /* CFB0 8001C7B0 2800248D */  lw         $a0, 0x28($t1)
    /* CFB4 8001C7B4 6000028D */  lw         $v0, 0x60($t0)
    /* CFB8 8001C7B8 001A0400 */  sll        $v1, $a0, 8
    /* CFBC 8001C7BC 21186400 */  addu       $v1, $v1, $a0
    /* CFC0 8001C7C0 80180300 */  sll        $v1, $v1, 2
    /* CFC4 8001C7C4 23186400 */  subu       $v1, $v1, $a0
    /* CFC8 8001C7C8 40110200 */  sll        $v0, $v0, 5
    /* CFCC 8001C7CC 2128A200 */  addu       $a1, $a1, $v0
    /* CFD0 8001C7D0 2128AA00 */  addu       $a1, $a1, $t2
    /* CFD4 8001C7D4 0000A28C */  lw         $v0, 0x0($a1)
    /* CFD8 8001C7D8 00190300 */  sll        $v1, $v1, 4
    /* CFDC 8001C7DC 80100200 */  sll        $v0, $v0, 2
    /* CFE0 8001C7E0 21104B00 */  addu       $v0, $v0, $t3
    /* CFE4 8001C7E4 21186200 */  addu       $v1, $v1, $v0
    /* CFE8 8001C7E8 3801C3AC */  sw         $v1, 0x138($a2)
    /* CFEC 8001C7EC 0800E228 */  slti       $v0, $a3, 0x8
    /* CFF0 8001C7F0 E7FF4014 */  bnez       $v0, .L8001C790
    /* CFF4 8001C7F4 0400C624 */   addiu     $a2, $a2, 0x4
    /* CFF8 8001C7F8 0800E003 */  jr         $ra
    /* CFFC 8001C7FC 00000000 */   nop
endlabel Gpu_SetLayerOtPtrs
