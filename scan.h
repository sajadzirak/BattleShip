#ifndef scan
#define scan

#include "check.h"
#include "initializing.h"
#include "gameData.h"
//-------------------------------------------------------------------

int scanBasicInfo()
{
    White(1);
    printf("Give the map's size: ");
    Green(0);
    scanf_s("%d", &n);
    White(1);
    printf("How many ships are there?: ");
    Green(0);
    scanf_s("%d", &nship);
    Reset();

    return 0;
}
//-------------------------------------------------------------------

int scanPlayerInfo(int map[][100], char name[], int playerNum, struct ships shipPlayer[])
{
    int i, j, k;
    char direction;
    White(1);
    printf("Name and locations for player %d: \n", playerNum);
    Blue(1);
    scanf_s("%s", name,sizeof(name));
    for (k = 0; k < nship; k++)
    {
        Red(1);
        scanf_s("%d %d %c", &j, &i, &direction);
        if (checkOverlap(i, j, direction, map) == 1 && checkRange(i, j, direction) == 1)
        {
            putShips(map, i, j, direction);
            if (direction == 'v')
            {
                shipPlayer[k].shipPosition[0][0] = j;
                shipPlayer[k].shipPosition[0][1] = i;

                shipPlayer[k].shipPosition[1][0] = j;
                shipPlayer[k].shipPosition[1][1] = i + 1;

                shipPlayer[k].shipPosition[2][0] = j;
                shipPlayer[k].shipPosition[2][1] = i + 2;
            }
            else
            {
                shipPlayer[k].shipPosition[0][0] = j;
                shipPlayer[k].shipPosition[0][1] = i;

                shipPlayer[k].shipPosition[1][0] = j + 1;
                shipPlayer[k].shipPosition[1][1] = i;

                shipPlayer[k].shipPosition[2][0] = j + 2;
                shipPlayer[k].shipPosition[2][1] = i;
            }
        }
        else
            k--;
    }
    White(1);
    printf("Name and locations received for player %d.\n", playerNum);
    Reset();
    sleep(1500);
    return 0;
}
//-------------------------------------------------------------------

int scanSign()
{
    int i;
    char sign[5];
    White(1);
    printf("input the sign( < --- > for pass to player 2)\n");
    scanf_s("%s", sign,sizeof(sign)); // scanf for '---'
    Reset();
    for (i = 0; i < 3 && sign[i] == '-'; i++)
        ;
    if (i == 3)
    {
        return 1;
    }
    else
        return scanSign();
    // May be used for phase 6
    // for ( i = 0; i < 3 && sign[i]=='$'; i++)
    // {
    //     return 2;
    // }
    return 0;
}
//-------------------------------------------------------------------

void scanMultiPlayerByFile() {
    int i, j, k;
    char direction[2];
    char sign[4];
    input = fopen("input.txt", "rt");
    fscanf(input, "%d%d", &n, &nship);
    initializeMap(mapPlayer1);
    initializeMap(mapPlayer2);
    fscanf(input, "%s", namePlayer1);
    for ( k = 0; k < nship; k++)
    {
        fscanf(input, "%d%d%s", &j, &i, &direction);
        printf("%d %d %s\n",j,i, direction);
        sleep(2000);
        if (checkOverlap(i, j, direction[0], mapPlayer1) == 1 && checkRange(i, j, direction[0]) == 1)
        {
            putShips(mapPlayer1, i, j, direction[0]);
            if (direction[0] == 'v')
            {
                shipP1[k].shipPosition[0][0] = j;
                shipP1[k].shipPosition[0][1] = i;

                shipP1[k].shipPosition[1][0] = j;
                shipP1[k].shipPosition[1][1] = i + 1;

                shipP1[k].shipPosition[2][0] = j;
                shipP1[k].shipPosition[2][1] = i + 2;
            }
            else
            {
                shipP1[k].shipPosition[0][0] = j;
                shipP1[k].shipPosition[0][1] = i;

                shipP1[k].shipPosition[1][0] = j + 1;
                shipP1[k].shipPosition[1][1] = i;

                shipP1[k].shipPosition[2][0] = j + 2;
                shipP1[k].shipPosition[2][1] = i;
            }
        }
        else
            k--;
    }
    fscanf(input, "%s", sign);
    fscanf(input, "%s", namePlayer2);
    for (k = 0; k < nship; k++)
    {
        fscanf(input, "%d%d%s", &j, &i, &direction);
        printf("%d %d %s\n",j,i, direction);
        sleep(2000);
        if (checkOverlap(i, j, direction[0], mapPlayer2) == 1 && checkRange(i, j, direction[0]) == 1)
        {
            putShips(mapPlayer2, i, j, direction[0]);
            if (direction[0] == 'v')
            {
                shipP2[k].shipPosition[0][0] = j;
                shipP2[k].shipPosition[0][1] = i;

                shipP2[k].shipPosition[1][0] = j;
                shipP2[k].shipPosition[1][1] = i + 1;

                shipP2[k].shipPosition[2][0] = j;
                shipP2[k].shipPosition[2][1] = i + 2;
            }
            else
            {
                shipP2[k].shipPosition[0][0] = j;
                shipP2[k].shipPosition[0][1] = i;

                shipP2[k].shipPosition[1][0] = j + 1;
                shipP2[k].shipPosition[1][1] = i;

                shipP2[k].shipPosition[2][0] = j + 2;
                shipP2[k].shipPosition[2][1] = i;
            }
        }
        else
            k--;
    }
}
//---------------------------------------------------------------------
void scanSinglePlayerByFile() {
    int i, j, k;
    char direction[2];
    input = fopen("input2.txt", "rt");
    if (!input) {
        printf("File don't open");
        exit(1);
    }
    fscanf(input, "%d%d", &n, &nship);
    initializeMap(mapPlayer1);
    initializeMap(mapPlayer2);
    fscanf(input, "%s", namePlayer1);
    for (k = 0; k < nship; k++)
    {
        fscanf(input, "%d%d%s", &j, &i, &direction);
        printf("%d %d %s\n", j, i, direction);
        sleep(2000);
        if (checkOverlap(i, j, direction[0], mapPlayer1) == 1 && checkRange(i, j, direction[0]) == 1)
        {
            putShips(mapPlayer1, i, j, direction[0]);
            if (direction[0] == 'v')
            {
                shipP1[k].shipPosition[0][0] = j;
                shipP1[k].shipPosition[0][1] = i;

                shipP1[k].shipPosition[1][0] = j;
                shipP1[k].shipPosition[1][1] = i + 1;

                shipP1[k].shipPosition[2][0] = j;
                shipP1[k].shipPosition[2][1] = i + 2;
            }
            else
            {
                shipP1[k].shipPosition[0][0] = j;
                shipP1[k].shipPosition[0][1] = i;

                shipP1[k].shipPosition[1][0] = j + 1;
                shipP1[k].shipPosition[1][1] = i;

                shipP1[k].shipPosition[2][0] = j + 2;
                shipP1[k].shipPosition[2][1] = i;
            }
        }
        else
            k--;
    }
}
#endif