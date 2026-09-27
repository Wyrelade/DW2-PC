nonmatching Gpu_AllocPacketBufs, 0x78

glabel Gpu_AllocPacketBufs
    /* D1B0 8001C9B0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D1B4 8001C9B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* D1B8 8001C9B8 21808000 */  addu       $s0, $a0, $zero
    /* D1BC 8001C9BC 02000524 */  addiu      $a1, $zero, 0x2
    /* D1C0 8001C9C0 1800B2AF */  sw         $s2, 0x18($sp)
    /* D1C4 8001C9C4 0480123C */  lui        $s2, %hi(D_80041670)
    /* D1C8 8001C9C8 1400B1AF */  sw         $s1, 0x14($sp)
    /* D1CC 8001C9CC 70165126 */  addiu      $s1, $s2, %lo(D_80041670)
    /* D1D0 8001C9D0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* D1D4 8001C9D4 CF8B000C */  jal        Mem_Alloc
    /* D1D8 8001C9D8 080030AE */   sw        $s0, 0x8($s1)
    /* D1DC 8001C9DC 21200002 */  addu       $a0, $s0, $zero
    /* D1E0 8001C9E0 02000524 */  addiu      $a1, $zero, 0x2
    /* D1E4 8001C9E4 CF8B000C */  jal        Mem_Alloc
    /* D1E8 8001C9E8 701642AE */   sw        $v0, %lo(D_80041670)($s2)
    /* D1EC 8001C9EC 0680043C */  lui        $a0, %hi(D_8005F770)
    /* D1F0 8001C9F0 70F78424 */  addiu      $a0, $a0, %lo(D_8005F770)
    /* D1F4 8001C9F4 2800838C */  lw         $v1, 0x28($a0)
    /* D1F8 8001C9F8 040022AE */  sw         $v0, 0x4($s1)
    /* D1FC 8001C9FC 80180300 */  sll        $v1, $v1, 2
    /* D200 8001CA00 21187100 */  addu       $v1, $v1, $s1
    /* D204 8001CA04 0000628C */  lw         $v0, 0x0($v1)
    /* D208 8001CA08 00000000 */  nop
    /* D20C 8001CA0C 2C0082AC */  sw         $v0, 0x2C($a0)
    /* D210 8001CA10 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* D214 8001CA14 1800B28F */  lw         $s2, 0x18($sp)
    /* D218 8001CA18 1400B18F */  lw         $s1, 0x14($sp)
    /* D21C 8001CA1C 1000B08F */  lw         $s0, 0x10($sp)
    /* D220 8001CA20 0800E003 */  jr         $ra
    /* D224 8001CA24 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Gpu_AllocPacketBufs
