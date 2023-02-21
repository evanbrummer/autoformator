#include <stdio.h>
#include <stdlib.h>

#include "LoadPlayers.h"
#include "PlayerInfo.h"

struct playerInfo *loadPlayers(int n) {
    struct playerInfo *result = malloc(sizeof(struct playerInfo) * n);
    

    FILE* fp;
    printf("Loading Players");
    fp = fopen("players.txt", "r"); // opens info.txt for reading
    for (int i = 0; i < 18; i++) { // for each player[]
        result[i].canSub = 1;
        result[i].onField = 0;
        fscanf(fp, "%s", result[i].init);
        for (int j = 0; j < 7; j++) { // scan in initials and each strength rating
            fscanf(fp, "%d", &result[i].strength[j]);
        }
        printf(".");
    }
    printf("Done!\n");
    fclose(fp);

    return result;
}