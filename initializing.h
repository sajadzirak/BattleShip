#ifndef initializing
#define initializing

#include "data.h"
#include "general.h"
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

void fillCols()  // it can almost avoid half of the hits
{
	int i, j, fake_n = n;
	for(i = 1; i <= fake_n; ++i)
	{
		if(i%2 == 1)
		{
			for(j = 1; j <= fake_n; j += 2)
				saveHits[i][j] = 2;
		}
		else
		{
			if(n%2 == 1) ++fake_n;
			for(j = fake_n; j > 1; j -= 2)
				saveHits[i][j] = 2;
		}
	}
}

//--------------------------------------------------------------

void resetSaveHits()
{
	int i, j;
	for(i = 0; i < 13; ++i)
	{
		for(j = 0; j < 13; ++j)
		{
			saveHits[i][j] = 0;
		}
	}
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
    hitsw = 0;
    randomSeed();
    resetSaveHits();
	fillCols();
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

//------------------------------------------------------------

void resetAround(int i, int j)
{
	for(int k = 0; k < 4; ++k)
		around[k] = 0;
	if (i == 1) around[3] = 1;
	if (j == 1) around[2] = 1;
	if (i == n) around[1] = 1;
	if (j == n) around[0] = 1;
}



#endif