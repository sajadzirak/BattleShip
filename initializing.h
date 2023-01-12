#ifndef initializing
#define initializing

#include "gameData.h"
#include "general.h"
#include <string.h>
int initializeMap(int map[][12])
{
    int i, j;
    for (i = 0, j = 0; j < n; j++)
    {
        map[i][j] = j + 1;
    }
    for (i = 1; i <= n; i++)
    {
        map[i][0] = i;
        for (j = 1; j <= n; j++)
        {
            map[i][j] = 0;
        }
    }
    return 0;
}
//--------------------------------------------------------------

int putShips(int map[][12], int i, int j, char direction)
{
    int k = 0;
    for (k = 0; k < 3; k++)
    {
        map[i][j] = -2;
        if (direction == 'v')
            i++;
        else
            j++;
    }
    return 0;
}
//------------------------------------------------------------

void initializeComputerInfo()
{
    int i, j, k;
    char direction;
    strcpy(namePlayer2, "Player2");
    randomSeed();
    for (k = 0; k < nship; ++k)
    {
        i = random();
        j = random();
        direction = random();
        if (direction % 2 == 1)
            direction = 'v';
        else
            direction = 'h';
        if (checkComputerOverlap(i, j, direction, mapPlayer2) == 1 && checkComputerRange(i, j, direction) == 1)
        {
            putShips(mapPlayer2, i, j, direction);
            if (direction == 'v')
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
            --k;
    }
}
//-----------------------------------------------------------------

void resetShipsSW(){
    int k;
    for (k = 0; k < nship; k++)
    {
        shipP1[k].sw[0] = shipP1[k].sw[1] = shipP1[k].sw[2] = 1;
        shipP2[k].sw[0] = shipP2[k].sw[1] = shipP2[k].sw[2] = 1;
    }
}
//-----------------------------------------------------------------------

void resetSaveHits() {
    int i, j;
    for ( i = 0;  i < 13;  i++)
    {
        for (j = 0; j < 13; j++) {
            saveHits[i][j] = 0;
        }
    }
}
//-----------------------------------------------------------------------
void resetAround(int i, int j)
{
    for (int k = 0; k < 4; ++k)
        around[k] = 0;
    if (i == 1) around[3] = 1;
    if (j == 1) around[2] = 1;
    if (i == n) around[1] = 1;
    if (j == n) around[0] = 1;
}
//------------------------------------------------------------

void resetPrevHit()
{
    prevHit[0] = hitPos[0];
    prevHit[1] = hitPos[1];
}

#endif