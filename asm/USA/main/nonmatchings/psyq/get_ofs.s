nonmatching get_ofs, 0x1C

glabel get_ofs
    /* 19084 80028884 FF07A530 */  andi       $a1, $a1, 0x7FF
    /* 19088 80028888 C02A0500 */  sll        $a1, $a1, 11
    /* 1908C 8002888C FF078230 */  andi       $v0, $a0, 0x7FF
    /* 19090 80028890 00E5033C */  lui        $v1, (0xE5000000 >> 16)
    /* 19094 80028894 25104300 */  or         $v0, $v0, $v1
    /* 19098 80028898 0800E003 */  jr         $ra
    /* 1909C 8002889C 2510A200 */   or        $v0, $a1, $v0
endlabel get_ofs
