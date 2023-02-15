#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Find.h"

// 0-GK, 1-OB, 2-CB, 3-DM, 4-WG, 5-CM, 6-FW
char *find(int num, struct playerInfo *player) {
    char *name;
    name = (char*)malloc(2 * sizeof(char));
    
    int sel = 10;
    int playerNum = 19;

    for (int i = 0; i < 18; i++) {
        if (player[i].strength[num] < sel && player[i].strength[num] != 0 && player[i].canSub == 1) {
            sel = player[i].strength[num];
            playerNum = i;
            //printf("** selected %s playerNum\n", player[playerNum].init);
        }
    }
    if (playerNum != 19) {
        player[playerNum].canSub = 0;
        //printf("** returning %s ", player[playerNum].init);
        return player[playerNum].init;
    }
    
    return "??";
}