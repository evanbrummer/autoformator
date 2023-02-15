#include <stdio.h>

struct playerInfo {
    int strength[7];
    char init[2];
    int canSub;
    int onField;
};

// Prompt user to enter missing players
void promptUpdatePlayers();

void printRoster();