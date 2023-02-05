#ifndef scan
#define scan

#include "check.h"
#include "initializing.h"
#include "gameData.h"
#include <string.h>
//-------------------------------------------------------------------
void scanShipByFile(FILE*, int);
//-------------------------------------------------------------------

int scanBasicInfo()
{
    White(1);
    printf("Give the map's size: ");
    Green(0);
    scanf("%d", &n);
    White(1);
    printf("How many ships are there?: ");
    Green(0);
    scanf("%d", &nship);
    Reset();

    return 0;
}
//-------------------------------------------------------------------

//int scanPlayerInfo(int map[][12], char name[], int playerNum, struct ships shipPlayer[])
//{
//    int i, j, k;
//    char direction;
//    White(1);
//    printf("Name and locations for player %d: \n", playerNum);
//    Blue(1);
//    scanf("%s", name);
//    for (k = 0; k < nship; k++)
//    {
//        Red(1);
//        scanf("%d %d %c", &j, &i, &direction);
//        if (checkOverlap(i, j, direction, map) == 1 && checkRange(i, j, direction) == 1)
//        {
//            putShips(map, i, j, direction);
//            if (direction == 'v')
//            {
//                shipPlayer[k].shipPosition[0][0] = j;
//                shipPlayer[k].shipPosition[0][1] = i;
//
//                shipPlayer[k].shipPosition[1][0] = j;
//                shipPlayer[k].shipPosition[1][1] = i + 1;
//
//                shipPlayer[k].shipPosition[2][0] = j;
//                shipPlayer[k].shipPosition[2][1] = i + 2;
//            }
//            else
//            {
//                shipPlayer[k].shipPosition[0][0] = j;
//                shipPlayer[k].shipPosition[0][1] = i;
//
//                shipPlayer[k].shipPosition[1][0] = j + 1;
//                shipPlayer[k].shipPosition[1][1] = i;
//
//                shipPlayer[k].shipPosition[2][0] = j + 2;
//                shipPlayer[k].shipPosition[2][1] = i;
//            }
//        }
//        else
//            k--;
//    }
//    White(1);
//    printf("Name and locations received for player %d.\n", playerNum);
//    Reset();
//    sleep(1500);
//    return 0;
//}
//-------------------------------------------------------------------

int scanSign()
{
    int i;
    char sign[5];
    White(1);
    printf("input the sign( < --- > for pass to player 2)\n");
    scanf("%s", sign); // scanf for '---'
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
    char sign[4];
    input = fopen("input.txt", "rt");
    if (!input) {
        printf("File don't open");
        exit(1);
    }
    fscanf(input, "%d%d", &n, &ncell);
    initializeMap(mapPlayer1);
    initializeMap(mapPlayer2);
    fscanf(input, "%s", P1.namePlayer);
    P1.ncell = 0;
    P1.nship = 0;
    P1.remainShip = 0;
    scanShipByFile(input, 1);
    fscanf(input, "%s", sign);
    while (strcmp(sign, "$$$") == 0)
    {
        scanShipByFile(input, 1);
        fscanf(input, "%s", sign);
    }
    fscanf(input, "%s", P2.namePlayer);
    P2.ncell = 0;
    P2.nship = 0;
    P2.remainShip = 0;
    scanShipByFile(input, 2);
    fscanf(input, "%s", sign);
    while (strcmp(sign, "$$$") == 0)
    {
        scanShipByFile(input, 2);
        fscanf(input, "%s", sign);
    }
    fscanf(input, "%d", &nrepair);
    P1.remainRepair = nrepair;
    P2.remainRepair = nrepair;
    fclose(input);
}
//---------------------------------------------------------------------
void scanSinglePlayerByFile() {    // temporary
    int i, j, k;
    char sign[4];
    FILE* input;
    input = fopen("input2.txt", "rt");
    if (!input) {
        printf("File don't open");
        exit(1);
    }
    fscanf(input, "%d%d", &n, &ncell);
    initializeMap(mapPlayer1);
    fscanf(input, "%s", P1.namePlayer);
    P1.ncell = 0;
    P1.nship = 0;
    P1.remainShip = 0;
    scanShipByFile(input, 1);
    fscanf(input, "%s", sign);
    while (strcmp(sign, "$$$") == 0)
    {
        scanShipByFile(input, 1);
        fscanf(input, "%s", sign);
    }
    fscanf(input, "%d", &nrepair);
    P1.remainRepair = nrepair;
    fclose(input);
}
//---------------------------------------------------------------------
void scanShipByFile(FILE* input, int playerNum)
{
    char direction[2];
    int width, lengh, temp, i, j, a, holdj;
    fscanf(input, "%d %d %d", &width, &lengh, &temp);
    if (playerNum == 1)
    {
        for (int f = 0; f < temp; ++f)
        {
            a = 0;
            fscanf(input, "%d %d %s", &j, &i, &direction);
            holdj = j;
            P1.ships[P1.nship].stats = 0;
            P1.ships[P1.nship].width = width;
            P1.ships[P1.nship].lengh = lengh;
            P1.ships[P1.nship].direction = direction[0];
            P1.ships[P1.nship].ncell = lengh * width;
            P1.ships[P1.nship].remainCell = lengh * width;
            P1.ncell += lengh * width;
            if (checkOverlap(i, j, direction[0], mapPlayer1, width, lengh) == 1 && checkRange(i, j, direction[0], width, lengh) == 1)
            {
                putShips(mapPlayer1, i, j, direction[0], width, lengh);
                if (direction[0] == 'v')
                {
                    for (int p = 0; p < lengh; ++p, ++i)
                    {
                        j = holdj;
                        for ( int k = 0; k < width; ++k, ++j)
                        {
                            P1.ships[P1.nship].shipPosition[a][0] = j;
                            P1.ships[P1.nship].shipPosition[a][1] = i;
                            ++a;
                        }
                    }
                }
                else if (direction[0] == 'h')
                {
                    for (int p = 0; p < width; ++p, ++i)
                    {
                        j = holdj;
                        for (int k = 0; k < lengh; ++k, ++j)
                        {
                            P1.ships[P1.nship].shipPosition[a][0] = j;
                            P1.ships[P1.nship].shipPosition[a][1] = i;
                            ++a;
                        }
                    }
                }
                P1.nship++;
                P1.remainShip++;
            }
            else
            {
                --f;
            }
        }
    }
    else if (playerNum == 2)
    {
        for (int f = 0; f < temp; ++f)
        {
            a = 0;
            fscanf(input, "%d%d%s", &j, &i, &direction);
            holdj = j;
            P2.ships[P2.nship].stats = 0;
            P2.ships[P2.nship].width = width;
            P2.ships[P2.nship].lengh = lengh;
            P2.ships[P2.nship].direction = direction[0];
            P2.ships[P2.nship].ncell = lengh * width;
            P2.ships[P2.nship].remainCell = lengh * width;
            P2.ncell += lengh * width;
            if (checkOverlap(i, j, direction[0], mapPlayer2, width, lengh) == 1 && checkRange(i, j, direction[0], width, lengh) == 1)
            {
                putShips(mapPlayer2, i, j, direction[0], width, lengh);
                if (direction[0] == 'v')
                {
                    for (int p = 0; p < lengh; ++p, ++i)
                    {
                        j = holdj;
                        for (int k = 0; k < width; ++k, ++j)
                        {
                            P2.ships[P2.nship].shipPosition[a][0] = j;
                            P2.ships[P2.nship].shipPosition[a][1] = i;
                            ++a;
                        }
                    }
                }
                else if (direction[0] == 'h')
                {
                    for (int p = 0; p < width; ++p, ++i)
                    {
                        j = holdj;
                        for (int k = 0; k < lengh; ++k, ++j)
                        {
                            P2.ships[P2.nship].shipPosition[a][0] = j;
                            P2.ships[P2.nship].shipPosition[a][1] = i;
                            ++a;
                        }
                    }
                }
                P2.nship++;
                P2.remainShip++;
            }
            else
            {
                --f;
            }
        }
    }
}
#endif
