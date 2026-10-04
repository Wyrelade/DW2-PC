nonmatching Stg40_PlayerFoundObject, 0x100

glabel Stg40_PlayerFoundObject
    /* 61FC 8006955C 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 6200 80069560 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 6204 80069564 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6208 80069568 1000B0AF */  sw         $s0, 0x10($sp)
    /* 620C 8006956C 21808000 */  addu       $s0, $a0, $zero
    /* 6210 80069570 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6214 80069574 01001124 */  addiu      $s1, $zero, 0x1
    /* 6218 80069578 2000BFAF */  sw         $ra, 0x20($sp)
    /* 621C 8006957C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6220 80069580 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6224 80069584 1800038E */  lw         $v1, 0x18($s0)
    /* 6228 80069588 4000538C */  lw         $s3, 0x40($v0)
    /* 622C 8006958C 3C00528C */  lw         $s2, 0x3C($v0)
    /* 6230 80069590 0D007110 */  beq        $v1, $s1, .L800695C8
    /* 6234 80069594 02006228 */   slti      $v0, $v1, 0x2
    /* 6238 80069598 03004014 */  bnez       $v0, .L800695A8
    /* 623C 8006959C 02000224 */   addiu     $v0, $zero, 0x2
    /* 6240 800695A0 21006210 */  beq        $v1, $v0, .L80069628
    /* 6244 800695A4 00000000 */   nop
  .L800695A8:
    /* 6248 800695A8 2E000424 */  addiu      $a0, $zero, 0x2E
    /* 624C 800695AC A369000C */  jal        Snd_PlayById
    /* 6250 800695B0 21280000 */   addu      $a1, $zero, $zero
    /* 6254 800695B4 21200002 */  addu       $a0, $s0, $zero
    /* 6258 800695B8 37B9010C */  jal        Stg40_ObjSetAnim
    /* 625C 800695BC 2D000524 */   addiu     $a1, $zero, 0x2D
    /* 6260 800695C0 86A50108 */  j          .L80069618
    /* 6264 800695C4 00000000 */   nop
  .L800695C8:
    /* 6268 800695C8 62B9010C */  jal        Stg40_ObjWaitAnimOrSkip
    /* 626C 800695CC 21200002 */   addu      $a0, $s0, $zero
    /* 6270 800695D0 1B005114 */  bne        $v0, $s1, .L80069640
    /* 6274 800695D4 21200002 */   addu      $a0, $s0, $zero
    /* 6278 800695D8 37B9010C */  jal        Stg40_ObjSetAnim
    /* 627C 800695DC 28000524 */   addiu     $a1, $zero, 0x28
    /* 6280 800695E0 21204002 */  addu       $a0, $s2, $zero
    /* 6284 800695E4 7745000C */  jal        Task_SetState1
    /* 6288 800695E8 05000524 */   addiu     $a1, $zero, 0x5
    /* 628C 800695EC FD01023C */  lui        $v0, (0x1FD0064 >> 16)
    /* 6290 800695F0 08006492 */  lbu        $a0, 0x8($s3)
    /* 6294 800695F4 64004234 */  ori        $v0, $v0, (0x1FD0064 & 0xFFFF)
    /* 6298 800695F8 688E000C */  jal        Cd_GetFileEntry
    /* 629C 800695FC 21208200 */   addu      $a0, $a0, $v0
    /* 62A0 80069600 01000424 */  addiu      $a0, $zero, 0x1
    /* 62A4 80069604 FD01053C */  lui        $a1, (0x1FD0010 >> 16)
    /* 62A8 80069608 1000A534 */  ori        $a1, $a1, (0x1FD0010 & 0xFFFF)
    /* 62AC 8006960C 21304000 */  addu       $a2, $v0, $zero
    /* 62B0 80069610 849D010C */  jal        Stg40_MsgWinOpen
    /* 62B4 80069614 21380000 */   addu      $a3, $zero, $zero
  .L80069618:
    /* 62B8 80069618 6045000C */  jal        Task_NextState2
    /* 62BC 8006961C 21200002 */   addu      $a0, $s0, $zero
    /* 62C0 80069620 90A50108 */  j          .L80069640
    /* 62C4 80069624 00000000 */   nop
  .L80069628:
    /* 62C8 80069628 C19D010C */  jal        Stg40_MsgWinCloseIfDone
    /* 62CC 8006962C 01000424 */   addiu     $a0, $zero, 0x1
    /* 62D0 80069630 03005114 */  bne        $v0, $s1, .L80069640
    /* 62D4 80069634 21200002 */   addu      $a0, $s0, $zero
    /* 62D8 80069638 7745000C */  jal        Task_SetState1
    /* 62DC 8006963C 06000524 */   addiu     $a1, $zero, 0x6
  .L80069640:
    /* 62E0 80069640 2000BF8F */  lw         $ra, 0x20($sp)
    /* 62E4 80069644 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 62E8 80069648 1800B28F */  lw         $s2, 0x18($sp)
    /* 62EC 8006964C 1400B18F */  lw         $s1, 0x14($sp)
    /* 62F0 80069650 1000B08F */  lw         $s0, 0x10($sp)
    /* 62F4 80069654 0800E003 */  jr         $ra
    /* 62F8 80069658 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_PlayerFoundObject
