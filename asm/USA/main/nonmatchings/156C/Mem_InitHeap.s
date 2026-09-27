nonmatching Mem_InitHeap, 0x30

glabel Mem_InitHeap
    /* 13660 80022E60 8C0085AF */  sw         $a1, %gp_rel(D_80050784)($gp)
    /* 13664 80022E64 21288500 */  addu       $a1, $a0, $a1
    /* 13668 80022E68 F4FFA324 */  addiu      $v1, $a1, -0xC
    /* 1366C 80022E6C 01000224 */  addiu      $v0, $zero, 0x1
    /* 13670 80022E70 900084AF */  sw         $a0, %gp_rel(D_80050788)($gp)
    /* 13674 80022E74 000080AC */  sw         $zero, 0x0($a0)
    /* 13678 80022E78 040083AC */  sw         $v1, 0x4($a0)
    /* 1367C 80022E7C 080080AC */  sw         $zero, 0x8($a0)
    /* 13680 80022E80 F4FFA4AC */  sw         $a0, -0xC($a1)
    /* 13684 80022E84 040060AC */  sw         $zero, 0x4($v1)
    /* 13688 80022E88 0800E003 */  jr         $ra
    /* 1368C 80022E8C 080062AC */   sw        $v0, 0x8($v1)
endlabel Mem_InitHeap
