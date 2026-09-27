nonmatching Task_ClearList, 0x44

glabel Task_ClearList
    /* 1990 80011190 21180000 */  addu       $v1, $zero, $zero
    /* 1994 80011194 0580023C */  lui        $v0, %hi(Task_List)
    /* 1998 80011198 98074424 */  addiu      $a0, $v0, %lo(Task_List)
    /* 199C 8001119C 00140300 */  sll        $v0, $v1, 16
  .L800111A0:
    /* 19A0 800111A0 83130200 */  sra        $v0, $v0, 14
    /* 19A4 800111A4 21104400 */  addu       $v0, $v0, $a0
    /* 19A8 800111A8 040040AC */  sw         $zero, 0x4($v0)
    /* 19AC 800111AC 01006224 */  addiu      $v0, $v1, 0x1
    /* 19B0 800111B0 21184000 */  addu       $v1, $v0, $zero
    /* 19B4 800111B4 00140200 */  sll        $v0, $v0, 16
    /* 19B8 800111B8 03140200 */  sra        $v0, $v0, 16
    /* 19BC 800111BC 64004228 */  slti       $v0, $v0, 0x64
    /* 19C0 800111C0 F7FF4014 */  bnez       $v0, .L800111A0
    /* 19C4 800111C4 00140300 */   sll       $v0, $v1, 16
    /* 19C8 800111C8 0580023C */  lui        $v0, %hi(Task_List)
    /* 19CC 800111CC 0800E003 */  jr         $ra
    /* 19D0 800111D0 980740AC */   sw        $zero, %lo(Task_List)($v0)
endlabel Task_ClearList
