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

int putShips(int map[][12], int i, int j, char direction, int width, int length)
{
    int k, p;
    int holdj = j;
    if (direction == 'v')
    {
        for (p = 0; p < length; ++p, ++i)
        {
            j = holdj;
            for (k = 0; k < width; ++k, ++j)
            {
                map[i][j] = -2;
            }
        }
    }
    else if (direction == 'h')
    {
        for (p = 0; p < width; ++p, ++i)
        {
            j = holdj;
            for (k = 0; k < length; ++k, ++j)
            {
                map[i][j] = -2;
            }
        }
    }
    return 0;
}
//------------------------------------------------------------

void initializeComputerInfo()
{
    int width, lengh, temp, i, j, a, holdj, control;
    char direction;
    randomSeed();
    strcpy(P2.namePlayer, "Player2");
    initializeMap(mapPlayer2);
    do
    {
        P2.ncell = random();
    } while (P2.ncell == 0 || P2.ncell > ncell);
    //printf("P2.ncell = %d\n", P2.ncell);
    //sleep(2000);
    P2.nship = 0;
    P2.remainShip = 0;
    P2.remainRepair = nrepair;
    control = P2.ncell;
    while (control != 0)
    {
        //printf("control = %d\n", control);
        do
        {
            width = random();
            lengh = random();
            temp = random();
            //printf("zarb = %d\n", (width * lengh * temp));
        } while ((width * lengh * temp) > control);
        control -= (width * lengh * temp);
        for (int f = 0; f < temp; ++f)
        {
            a = 0;
            j = random();
            i = random();
            direction = random();
            if (direction % 2 == 1)
                direction = 'v';
            else
                direction = 'h';
            holdj = j;
            P2.ships[P2.nship].stats = 0;
            P2.ships[P2.nship].width = width;
            P2.ships[P2.nship].length = lengh;
            P2.ships[P2.nship].direction = direction;
            P2.ships[P2.nship].ncell = lengh * width;
            P2.ships[P2.nship].remainCell = lengh * width;
            //printf("width = %d  len = %d  temp = %d\n", width, lengh, temp);
            //printf("j = %d  i = %d  dir = %c\n", j, i, direction);
            //sleep(10000);
            if (checkOverlap(i, j, direction, mapPlayer2, width, lengh) == 1 && checkRange(i, j, direction, width, lengh) == 1)
            {
                putShips(mapPlayer2, i, j, direction, width, lengh);
                if (direction == 'v')
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
                else if (direction == 'h')
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
//-----------------------------------------------------------------
/*
void resetShipsSW(){
    int k;
    for (k = 0; k < nship; k++)
    {
        shipP1[k].sw[0] = shipP1[k].sw[1] = shipP1[k].sw[2] = 1;
        shipP2[k].sw[0] = shipP2[k].sw[1] = shipP2[k].sw[2] = 1;
    }
}
*/
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