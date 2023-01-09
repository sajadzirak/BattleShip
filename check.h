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

void hitShip(struct ships shipPlayer[], int x, int y)
{
    int i, j, k;
    for (k = 0; k < nship; k++)
    {
        for (i = 0; i < 3; i++)
        {
            if (shipPlayer[k].shipPosition[i][0] == x && shipPlayer[k].shipPosition[i][1] == y)
                shipPlayer[k].sw[i] = 0;
        }
    }
}

//---------------------------------------------------------------
int checkShip(struct ships shipPlayer[])
{
    int i, j, k;
    for (k = 0; k < nship; k++)
    {
        for (i = 0; i < 3 && shipPlayer[k].sw[i] == 0; i++);
        if (i == 3)
        {
            for (i = 0; i < 3; i++)
                shipPlayer[k].sw[i] = -1;
            return 1;
        }
    }
    return 0;
}
//--------------------------------------------------------------------
int passShip(struct ships shipPlayer[], int x, int y)
{
    int i, j, k;
    for (k = 0; k < nship; k++)
    {
        for (i = 0; i < 3; i++)
        {
            if (shipPlayer[k].shipPosition[i][0] == x && shipPlayer[k].shipPosition[i][1] == y)
            {
                if (shipPlayer[k].sw[i] == 0 || shipPlayer[k].sw[i] == -1)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
//--------------------------------------------------------------------

int checkComputerOverlap(int i, int j, char direction, int map[][100])
{
    int sw = 1, p;
    if (direction == 'v')
    {
        for (p = 0; p < 3 && sw == 1; p++, i++)
        {
            if (map[i][j] == -2)
            {
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
                sw = 0;
            }
        }
    }
    return sw;
}
//-------------------------------------------------------------------

int checkComputerRange(int i, int j, char direction)
{
    int sw = 1;
    if ((i + 2 > n && direction == 'v') || (j + 2 > n && direction == 'h'))
    {
        sw = 0;
    }
    return sw;
}
//-------------------------------------------------------------------

int checkHit(int i, int j, int arr[][13])
{
    if (arr[i][j] == 0)
        return 0;
    else if (arr[i][j] == 1)
        return 1;
    else if (arr[i][j] == 2)
    	return 2;
}

//-------------------------------------------------------------------

int isFinishAround()
{
	int p;
	for(p = 0; p < 4 && around[p] == 1; ++p);
	if (p == 4)
	{
		hitsw = 0;
		return 1;	
	}
	else
	{
		return 0;
	}
}

#endif