#ifndef check
#define check

#include "color.h"
#include "data.h"

int checkOverlap(int i, int j, char direction, int map[][100])
{
    int sw = 1, p;
    if (direction == 'v')
    {
        for (p = 0; p < 3 && sw == 1; p++, i++)
        {
            if (map[i][j] == -2)
            {
                White(1);
                printf("Ships overlap with each other. Please input another location.\n");
                Reset();
                sw = 0;
            }
        }
    }
    else if (direction == 'h')
    {
        for (int p = 0; p < 3 && sw == 1; ++p, j++)
        {
            if (map[i][j] == -2)
            {
                White(1);
                printf("Ships overlap with each other. Please input another location.\n");
                Reset();
                sw = 0;
            }
        }
    }
    else
    {
        White(1);
        printf("Direction is not valid. Please input the correct direction (v/h)\n");
        Reset();
        sw = 0;
    }
    return sw;
}

//---------------------------------------------------------

int checkRange(int i, int j, char direction)
{
    int sw = 1;
    if ((i + 2 > n && direction == 'v') || (j + 2 > n && direction == 'h'))
    {
        White(1);
        printf("Ships are out of range. Please input another location.\n");
        Reset();
        sw = 0;
    }
    return sw;
}
//---------------------------------------------------------------

void hitShip(struct shipPosition shipPos[], int x, int y)
{
    int i, j, k;
    for (k = 0; k < nship; k++)
    {
        for (i = 0; i < 3; i++)
        {
            if (shipPos[k].shipPosition[i][0] == x && shipPos[k].shipPosition[i][1] == y)
                shipPos[k].sw[i] = 0;
        }
    }
}

//---------------------------------------------------------------
int checkShip(struct shipPosition shipPos[])
{
    int i, j, k;
    for (k = 0; k < nship; k++)
    {
        for (i = 0; i < 3 && shipPos[k].sw[i] == 0; i++)
            ;
        if (i==3)
        {
        for (i = 0; i < 3; i++)
            shipPos[k].sw[i] = -1;
        return 1;
        }
    }
    return 0;
}

#endif