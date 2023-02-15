#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Find.h"
#include "Formation.h"
#include "LoadPlayers.h"
#include "PlayerInfo.h"


//MAIN
int main()
{
    printf("// EVAN'S AUTO-FORMATOR //\n");
    
    struct playerInfo player[] = loadPlayers();

    printRoster();
    promptUpdatePlayers();

    generatePositions(player);
    printFormation(0);
    
    scanf("%s");
    
    printf("// GLHF //");
    return 0;
}