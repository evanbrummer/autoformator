#include <stdio.h>
#include "PlayerInfo.h"

void promptUpdatePlayers() {
    char missing[2];
    printf("\n\nEnter any missing players, type \"go\" when complete: \n");
    
    while (strcmp(missing, "go") != 0) { // while "go" is not entered
        scanf("%s", missing);
        for (int i = 0; i < 18; i++) {
            if (strcmp(missing, player[i].init) == 0) { 
                player[i].canSub = 0;
                printf("%s can no longer sub. ", player[i].init);
            }
        }
    }
    printf("\n");
}

void printRoster() {
    printf("Current Roster: ");
    for (int i = 0; i < 18; i++) {
        printf("%s", player[i].init);
        if (i != 18) { 
            printf(","); 
        }
    }
}
