#ifndef initializing
#define initializing

#include "data.h"

int initializeMap(int map[][100])
{
    int i, j;
    for (i = 0, j = 0; j < n; j++)
    {
        map[i][j] = j + 1;
    }
    for (i = 1; i <= n; i++)
    {
        map[i][0] = i;
        for (j = 1; j < n; j++)
        {
            map[i][j] = 0;
        }
    }
    return 0;
}
//--------------------------------------------------------------

int putShips(int map[][100], int i, int j, char direction)
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
                shipPosP2[k].shipPosition[0][0] = j;
                shipPosP2[k].shipPosition[0][1] = i;

                shipPosP2[k].shipPosition[1][0] = j;
                shipPosP2[k].shipPosition[1][1] = i + 1;

                shipPosP2[k].shipPosition[2][0] = j;
                shipPosP2[k].shipPosition[2][1] = i + 2;
            }
            else
            {
                shipPosP2[k].shipPosition[0][0] = j;
                shipPosP2[k].shipPosition[0][1] = i;

                shipPosP2[k].shipPosition[1][0] = j + 1;
                shipPosP2[k].shipPosition[1][1] = i;

                shipPosP2[k].shipPosition[2][0] = j + 2;
                shipPosP2[k].shipPosition[2][1] = i;
            }
        }
        else
            --k;
    }
}

#endif