nonmatching Gpu_ClearScreens, 0x90

glabel Gpu_ClearScreens
    /* C904 8001C104 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* C908 8001C108 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* C90C 8001C10C 21880000 */  addu       $s1, $zero, $zero
    /* C910 8001C110 2000B2AF */  sw         $s2, 0x20($sp)
    /* C914 8001C114 1000B227 */  addiu      $s2, $sp, 0x10
    /* C918 8001C118 0680023C */  lui        $v0, %hi(Sys_State)
    /* C91C 8001C11C 1800B0AF */  sw         $s0, 0x18($sp)
    /* C920 8001C120 70F75024 */  addiu      $s0, $v0, %lo(Sys_State)
    /* C924 8001C124 2400BFAF */  sw         $ra, 0x24($sp)
  .L8001C128:
    /* C928 8001C128 EB00038A */  lwl        $v1, 0xEB($s0)
    /* C92C 8001C12C E800039A */  lwr        $v1, 0xE8($s0)
    /* C930 8001C130 EF00088A */  lwl        $t0, 0xEF($s0)
    /* C934 8001C134 EC00089A */  lwr        $t0, 0xEC($s0)
    /* C938 8001C138 1300A3AB */  swl        $v1, 0x13($sp)
    /* C93C 8001C13C 1000A3BB */  swr        $v1, 0x10($sp)
    /* C940 8001C140 1700A8AB */  swl        $t0, 0x17($sp)
    /* C944 8001C144 1400A8BB */  swr        $t0, 0x14($sp)
    /* C948 8001C148 419C000C */  jal        ResetGraph
    /* C94C 8001C14C 01000424 */   addiu     $a0, $zero, 0x1
    /* C950 8001C150 21204002 */  addu       $a0, $s2, $zero
    /* C954 8001C154 21280000 */  addu       $a1, $zero, $zero
    /* C958 8001C158 2130A000 */  addu       $a2, $a1, $zero
    /* C95C 8001C15C A59D000C */  jal        ClearImage2
    /* C960 8001C160 2138A000 */   addu      $a3, $a1, $zero
    /* C964 8001C164 209D000C */  jal        DrawSync
    /* C968 8001C168 21200000 */   addu      $a0, $zero, $zero
    /* C96C 8001C16C 01003126 */  addiu      $s1, $s1, 0x1
    /* C970 8001C170 0200222A */  slti       $v0, $s1, 0x2
    /* C974 8001C174 ECFF4014 */  bnez       $v0, .L8001C128
    /* C978 8001C178 14001026 */   addiu     $s0, $s0, 0x14
    /* C97C 8001C17C 2400BF8F */  lw         $ra, 0x24($sp)
    /* C980 8001C180 2000B28F */  lw         $s2, 0x20($sp)
    /* C984 8001C184 1C00B18F */  lw         $s1, 0x1C($sp)
    /* C988 8001C188 1800B08F */  lw         $s0, 0x18($sp)
    /* C98C 8001C18C 0800E003 */  jr         $ra
    /* C990 8001C190 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Gpu_ClearScreens
