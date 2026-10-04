nonmatching Stg40_AutomapSetCell, 0x70

glabel Stg40_AutomapSetCell
    /* B824 8006EB84 0780023C */  lui        $v0, %hi(Stg40_AutomapWork)
    /* B828 8006EB88 B02B498C */  lw         $t1, %lo(Stg40_AutomapWork)($v0)
    /* B82C 8006EB8C 02008104 */  bgez       $a0, .L8006EB98
    /* B830 8006EB90 21388000 */   addu      $a3, $a0, $zero
    /* B834 8006EB94 03008724 */  addiu      $a3, $a0, 0x3
  .L8006EB98:
    /* B838 8006EB98 83380700 */  sra        $a3, $a3, 2
    /* B83C 8006EB9C 80100700 */  sll        $v0, $a3, 2
    /* B840 8006EBA0 23108200 */  subu       $v0, $a0, $v0
    /* B844 8006EBA4 80400200 */  sll        $t0, $v0, 2
    /* B848 8006EBA8 0100A324 */  addiu      $v1, $a1, 0x1
    /* B84C 8006EBAC C0100300 */  sll        $v0, $v1, 3
    /* B850 8006EBB0 21104300 */  addu       $v0, $v0, $v1
    /* B854 8006EBB4 40100200 */  sll        $v0, $v0, 1
    /* B858 8006EBB8 21184700 */  addu       $v1, $v0, $a3
    /* B85C 8006EBBC 40180300 */  sll        $v1, $v1, 1
    /* B860 8006EBC0 42006324 */  addiu      $v1, $v1, 0x42
    /* B864 8006EBC4 21182301 */  addu       $v1, $t1, $v1
    /* B868 8006EBC8 0F000224 */  addiu      $v0, $zero, 0xF
    /* B86C 8006EBCC 04100201 */  sllv       $v0, $v0, $t0
    /* B870 8006EBD0 00006494 */  lhu        $a0, 0x0($v1)
    /* B874 8006EBD4 27100200 */  nor        $v0, $zero, $v0
    /* B878 8006EBD8 24208200 */  and        $a0, $a0, $v0
    /* B87C 8006EBDC 04100601 */  sllv       $v0, $a2, $t0
    /* B880 8006EBE0 25208200 */  or         $a0, $a0, $v0
    /* B884 8006EBE4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* B888 8006EBE8 000064A4 */  sh         $a0, 0x0($v1)
    /* B88C 8006EBEC 0800E003 */  jr         $ra
    /* B890 8006EBF0 600722A5 */   sh        $v0, 0x760($t1)
endlabel Stg40_AutomapSetCell
