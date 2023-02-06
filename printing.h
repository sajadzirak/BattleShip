#ifndef printing
#define printing

#include "gameColor.h"
#include "gameData.h"

//-------------------------------------------------------------------

int printInfo(int remainingShips, int remainingRepair , char namePlayer[], char namePlayer2[])
{

    printf(" %s's turn", namePlayer2);
    printf("\n\n");
    Blue(1);
    printf(" %s's map", namePlayer);

    printf("\n\n");
    White(1);
    printf(" %s's remaining ships: %d\n", namePlayer, remainingShips);
    printf(" %s's remaining repairs: %d", namePlayer2, remainingRepair);
    Reset();
    printf("\n\n");
    return 0;
}
//-------------------------------------------------------------------

int printMaps(int map[][12])
{
    int i, j;
    for (i = n; i > 0; i--)
    {
        // p1 map
        for (j = 0; j <= n; j++)
        {
            switch (map[i][j])
            {
            case 0:
                Blue(1); // free space
                WhiteBack();
                printf("~ ");
                Reset();
                break;
            case -1: // the bomb
                printf("*");
                WhiteBack();
                printf(" ");
                Reset();
                break;
            case -2: // Ships that have not been hit yet
                Blue(1);
                WhiteBack();
                printf("~ ");
                Reset();
                break;
            case -3: // Missed shot
                Red(1);
                printf("*");
                WhiteBack();
                printf(" ");
                Reset();
                break;
            case -4: // Ships that have been hit
                Green(1);
                printf(">");
                WhiteBack();
                printf(" ");
                Reset();
                break;
            default:
                if (n > 9)
                {
                    if (i > 9)
                    {
                        Yellow(1);
                        printf("%d ", map[i][j]);
                        Reset();
                    }
                    else
                    {
                        Yellow(1);
                        printf("%d  ", map[i][j]);
                        Reset();
                    }
                }
                else
                {
                    Yellow(1);
                    printf("%d ", map[i][j]);
                    Reset();
                }

                break;
            }
        }
        printf("\n");
    }
    if (n > 9)
    {
        printf("  ");
    }
    else
    {
        printf(" ");
    }

    // numbers at the bottom of the graph p1
    for (i = 0, j = 0; j < n; j++)
    {
        Yellow(1);
        printf(" %d", map[i][j]);
        Reset();
    }
    printf("\n");

    return 0;
}
//-------------------------------------------------------------------

void printEnd1()
{
    printf("  _____  _                         __            _           \n");
    printf(" |  __ \\| |                       /_ |          (_)          \n");
    printf(" | |__) | | __ _ _   _  ___ _ __   | | __      ___ _ __  ___ \n");
    printf(" |  ___/| |/ _` | | | |/ _ \\ '__|  | | \\ \\ /\\ / / | '_ \\/ __|\n");
    printf(" | |    | | (_| | |_| |  __/ |     | |  \\ V  V /| | | | \\__ \\ \n");
    printf(" |_|    |_|\\__,_|\\__, |\\___|_|     |_|   \\_/\\_/ |_|_| |_|___/\n");
    printf("                  __/ |                                      \n");
    printf("                 |___/                                       \n");
}
//-------------------------------------------------------------------

void printEnd2()
{
    printf("  _____  _                         ___             _           \n");
    printf(" |  __ \\| |                       |__ \\           (_)          \n");
    printf(" | |__) | | __ _ _   _  ___ _ __     ) | __      ___ _ __  ___ \n");
    printf(" |  ___/| |/ _` | | | |/ _ \\ '__|   / /  \\ \\ /\\ / / | '_ \\/ __|\n");
    printf(" | |    | | (_| | |_| |  __/ |     / /_   \\ V  V /| | | | \\__ \\\n");
    printf(" |_|    |_|\\__,_|\\__, |\\___|_|    |____|   \\_/\\_/ |_|_| |_|___/\n");
    printf("                  __/ |                                        \n");
    printf("                 |___/                                         \n");
}
//---------------------------------------------------------------------------------------

void printComputerStats(int x)
{
    printInfo(P1.remainShip, P2.remainRepair, P1.namePlayer, P2.namePlayer);
    printMaps(mapPlayer1);
    if (x == 1)
    {
        Green(1);
        printf("\n  player 2 hit the ship!");
        Reset();
    }
    else if (x == -1)
    {
        Red(1);
        printf("\n  Player2 missed!");
        Reset();
    }
    
}
#endif