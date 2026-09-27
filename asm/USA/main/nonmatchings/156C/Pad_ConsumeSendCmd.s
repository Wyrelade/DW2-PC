nonmatching Pad_ConsumeSendCmd, 0x10

glabel Pad_ConsumeSendCmd
    /* 15150 80024950 37008290 */  lbu        $v0, 0x37($a0)
    /* 15154 80024954 370080A0 */  sb         $zero, 0x37($a0)
    /* 15158 80024958 0800E003 */  jr         $ra
    /* 1515C 8002495C 380082A0 */   sb        $v0, 0x38($a0)
endlabel Pad_ConsumeSendCmd
