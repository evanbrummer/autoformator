#include <stdio.h>
#include "PlayerInfo.h"
#include "Formation.h"
#include "Find.h"

void generatePositions(struct playerInfo *player[]) {
    char *pos0 = find(0,player)/*GK*/, *pos9 = find(6,player)/*ST*/,
         *pos6 = find(5,player)/*CM*/, *pos7 = find(5,player)/*CM*/,
         *pos2 = find(2,player)/*CB*/, *pos3 = find(2,player)/*CB*/,
         *pos8 = find(4,player)/*LW*/, *pos10= find(4,player)/*RW*/,
         *pos1 = find(1,player)/*LB*/, *pos4 = find(1,player)/*RB*/,
         *pos5 = find(3,player)/*DM*/;
}

void printFormation(int f) {
    printf("\n4-3-3:\n");
    printf("[%s]     [%s]     [%s]\n", pos8,pos9,pos10);
    printf("     [%s]    [%s]\n", pos6,pos7);
    printf("         [%s]\n", pos5);
    printf("[%s]  [%s]  [%s]  [%s]\n", pos1,pos2,pos3,pos4);
    printf("         [%s]\n\n", pos0);
}