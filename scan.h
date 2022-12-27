#ifndef scan
#define scan


#include"color.h"
#include"check.h"
#include"initializing.h"

int scanBasicInfo(int *n , int *nship)
{
    White(1);
    printf("Give the map's size: ");
    Green(0);
    scanf("%d", n);
    White(1);
    printf("How many ships are there?: ");
    Green(0);
    scanf("%d", nship);
    Reset();
    return 0;
}

int scanPlayerInfo(int map[][100], char name[], int playerNum,int n,int nship)
{
    int i, j, k;
    char direction;
    White(1);
    printf("Name and locations for player %d: \n", playerNum);
    Blue(1);
    scanf("%s", name);
    for (k = 0; k < nship; k++)
    {
        Red(1);
        scanf("%d %d %c", &j, &i, &direction);
        if (checkOverlap(i, j, direction, map) == 1 && checkRange(i, j, direction,n) == 1)
        {
            putShips(map, i, j, direction);
        }
        else
            k--;
    }
    White(1);
    printf("Name and locations received for player %d.\n", playerNum);
    Reset();
    return 0;
}

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

#endif