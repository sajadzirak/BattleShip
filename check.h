#ifndef check
#define check

#include "gameColor.h"
#include "gameData.h"

int checkOverlap(int i, int j, char direction, int map[][12], int width, int length)
{
    int sw = 1, p, k;
    int holdj = j;
    if (direction == 'v')
    {
        for (p = 0; p < length && sw == 1; p++, i++)
        {
            j = holdj;
            for (k = 0; k < width && sw == 1; k++)
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
    }
    else if (direction == 'h')
    {
        for (int p = 0; p < 3 && sw == 1; ++p, j++)
        {
            j = holdj;
            for ( k = 0; k < width; k++)
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

int checkRange(int i, int j, char direction, int width, int length)
{
    int sw = 1;
    if (direction == 'v')
    {
        if ((i + (length - 1) > n) || (j + (width - 1) > n))
        {
            White(1);
            printf("Ships are out of range. Please input another location.\n");
            Reset();
            sw = 0;
        }
    }
    if (direction == 'h')
    {
        if ((i + (width - 1) > n) || (j + (length - 1) > n))
        {
            White(1);
            printf("Ships are out of range. Please input another location.\n");
            Reset();
            sw = 0;
        }
    }
    return sw;
}
//---------------------------------------------------------------

void hitShip(int playerNum, int x, int y)
{
    int i, k, contsw = 1;
    if (playerNum == 1)
    {
        for (k = 0; k < P1.nship && contsw == 1; k++)
        {
            for (i = 0; i < P1.ships[k].ncell && contsw == 1; ++i)
            {
                if (P1.ships[k].shipPosition[i][0] == x && P1.ships[k].shipPosition[i][1] == y)
                {
                    P1.ships[k].remainCell = P1.ships[k].remainCell - 1;
                    contsw = 0;
                }

            }
        }
    }
    else if (playerNum == 2)
    {
        for (k = 0; k < P2.nship && contsw == 1; k++)
        {
            for (i = 0; i < P2.ships[k].ncell && contsw == 1; ++i)
            {
                if (P2.ships[k].shipPosition[i][0] == x && P2.ships[k].shipPosition[i][1] == y)
                {
                    P2.ships[k].remainCell = P2.ships[k].remainCell - 1;
                    contsw = 0;
                }

            }
        }
    }
}

//---------------------------------------------------------------
int checkShip(int playerNum)
{
    int k;
    if (playerNum == 1)
    {
        for (k = 0; k < P1.nship; k++)
        {
            if (P1.ships[k].remainCell == 0 && P1.ships[k].stats == 0)
            {
                P1.ships[k].stats = 1;
                return 1;
            }
        }
    }
    else if (playerNum == 2)
    {
        for (k = 0; k < P2.nship; k++)
        {
            if (P2.ships[k].remainCell == 0 && P2.ships[k].stats == 0)
            {
                P2.ships[k].stats = 1;
                return 1;
            }
        }
    }
    return 0;
}
//--------------------------------------------------------------------
int passShip(int playerNum, int x, int y)
{
    int i, k;
    if (playerNum == 1)
    {
        for (k = 0; k < P1.nship; ++k)
        {
            for (i = 0; i < P1.ships[k].ncell; ++i)
            {
                if (P1.ships[k].shipPosition[i][0] == x && P1.ships[k].shipPosition[i][1] == y)
                {
                    if (mapPlayer1[y][x] == -4)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    else if (playerNum == 2)
    {
        for (k = 0; k < P2.nship; ++k)
        {
            for (i = 0; i < P2.ships[k].ncell; ++i)
            {
                if (P2.ships[k].shipPosition[i][0] == x && P2.ships[k].shipPosition[i][1] == y)
                {
                    if (mapPlayer2[y][x] == -4)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
//--------------------------------------------------------------------

int checkComputerOverlap(int i, int j, char direction, int map[][12])
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
    else
        return 1;

}

//-------------------------------------------------------------------

int isFinishAround()
{
    int p;
    for (p = 0; p < 4 && around[p] == 1; ++p);
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

//-------------------------------------------------------------------
void Hcheck(int x, int y, int i, int j, int* sw)
{
    while (x >= j && *sw == 1)
    {
        if (saveHits[y][x] == 1)
        {
            *sw = 0;
        }
        x--;
    }
}
//--------------------------------------------------------------------

void Vcheck(int x, int y, int i, int j, int* sw)
{
    while (y >= i && *sw == 1)
    {
        if (saveHits[y][x] == 1)
        {
            *sw = 0;
        }
        y--;
    }
}
//--------------------------------------------------------------

int fileCheck() {
    FILE *f = fopen("gameData.dat", "rb");
    int x;
    fread(&x, sizeof(int), 1, f);
    if (feof(f))
        return 0;
    return 1;
}


#endif