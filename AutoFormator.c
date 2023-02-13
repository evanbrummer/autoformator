#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//STRUCTS
struct playerInfo_struct {
    int strength[7];
    char init[2];
    int canSub;
    int onField;
} playerInfo_struct;

//PROTOTYPES
char *find(int num, struct playerInfo_struct *players);

//MAIN
int main()
{
    printf("// EVAN'S AUTO-FORMATOR //\n");
    
    struct playerInfo_struct player[18];
    
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
    printf("Current Roster: ");
    for (int i = 0; i < 18; i++) {
        printf("%s", player[i].init);
        if (i != 18) { 
            printf(","); 
        }
    }
    
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
    
    /* printf("\nChoose a formation <433, 451, 352, 442>: ");
    int form;
    scanf("%d", &form); */
    
    printf("// GENERATING FORMATION //\n");
    // 0-GK, 1-OB, 2-CB, 3-DM, 4-WG, 5-CM, 6-FW
    char *pos0 = find(0,player)/*GK*/, *pos9 = find(6,player)/*ST*/,
         *pos6 = find(5,player/*CM*/), *pos7 = find(5,player)/*CM*/,
         *pos2 = find(2,player)/*CB*/, *pos3 = find(2,player)/*CB*/,
         *pos8 = find(4,player)/*LW*/, *pos10= find(4,player)/*RW*/,
         *pos1 = find(1,player)/*LB*/, *pos4 = find(1,player)/*RB*/,
         *pos5 = find(3,player)/*DM*/;
    printf("\n4-3-3:\n");
    printf("[%s]     [%s]     [%s]\n", pos8,pos9,pos10);
    printf("     [%s]    [%s]\n", pos6,pos7);
    printf("         [%s]\n", pos5);
    printf("[%s]  [%s]  [%s]  [%s]\n", pos1,pos2,pos3,pos4);
    printf("         [%s]\n\n", pos0);
    
    scanf("%s");
    fclose(fp);
    printf("// GLHF //");
    return 0;
}

// 0-GK, 1-OB, 2-CB, 3-DM, 4-WG, 5-CM, 6-FW
char *find(int num, struct playerInfo_struct *player) {
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