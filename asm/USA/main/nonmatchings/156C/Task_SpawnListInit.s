nonmatching Task_SpawnListInit, 0x10

glabel Task_SpawnListInit
    /* A640 80019E40 2C00838C */  lw         $v1, 0x2C($a0)
    /* A644 80019E44 0000A28C */  lw         $v0, 0x0($a1)
    /* A648 80019E48 0800E003 */  jr         $ra
    /* A64C 80019E4C 000062AC */   sw        $v0, 0x0($v1)
endlabel Task_SpawnListInit
