#ifndef printing
#define printing

#include"color.h"

int printInfo(int ships, int n, char namePlayer[], char namePlayer2[])
{
    int i;
    printf(" %s's turn", namePlayer2);
    printf("\n\n");
    Blue(1);
    printf(" %s's map", namePlayer);

    printf("\n\n");
    White(1);
    printf(" remaining ships: %d", ships);

    printf("\n\n");
    Reset();
    return 0;
}
int printMaps(int map[][100], int n)
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
                Cyan(1);
                WhiteBack();
                printf("~ ");
                Reset();
                break;
            case -1:
                printf("*");
                WhiteBack();
                printf(" ");
                Reset();
                break;
            case -2:
                Cyan(1);
                WhiteBack();
                printf("~ ");
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

#endif