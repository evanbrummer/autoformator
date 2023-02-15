#include <stdio.h>
#include <stdlib.h>

#include "LoadPlayers.h"
#include "PlayerInfo.h"

struct playerInfo[] loadPlayers() {
    struct playerInfo result[];
    FILE* fp;
    printf("Loading Players");
    fp = fopen("players.txt", "r"); // opens info.txt for reading
    for (int i = 0; i < 18; i++) { // for each player[]
        player[i].canSub = 1;
        player[i].onField = 0;
        fscanf(fp, "%s", player[i].init);
        for (int j = 0; j < 7; j++) { // scan in initials and each strength rating
            fscanf(fp, "%d", &player[i].strength[j]);
        }
        printf(".");
    }
    printf("Done!\n");
    fclose(fp);

    return result;
}