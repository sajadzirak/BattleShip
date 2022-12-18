#include <stdio.h>

int n, nship;
int mapPlayer1[100][100];
int mapPlayer2[100][100];
char namePlayer1[20];
char namePlayer2[20];

int scanBasicInf();
int initializeMap(int[][100], int);
int scanPlayerInf(int[][100], char[],int);
int checkOverlap(int, int, char, int[][100]);
int putShips(int[][100], int, int, char);
int scanSign();
int printInf(int, int);
int printMaps(int[][100], int[][100], int);

int main()
{

    scanBasicInf();
    initializeMap(mapPlayer1, n);
    initializeMap(mapPlayer2, n);
    scanPlayerInf(mapPlayer1, namePlayer1,1);
    scanSign();
    scanPlayerInf(mapPlayer2, namePlayer2,2);
    printInf(nship, n);
    printMaps(mapPlayer1, mapPlayer2, n);
    return 0;
}

//-------------------------------------------------------------------

int scanBasicInf()
{
    printf("Give the map's size: ");
    scanf("%d", &n);
    printf("How many ships are there?: ");
    scanf("%d", &nship);
    return 0;
}

//-------------------------------------------------------------------

int initializeMap(int map[][100], int n)
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

//-------------------------------------------------------------------

int scanPlayerInf(int map[][100], char name[],int playerNum)
{
    int i, j, k;
    char direction;
    printf("Name and locations for player %d: \n",playerNum);
    scanf("%s", name);
    for (k = 0; k < nship; k++)
    {
        scanf("%d %d %c", &i, &j, &direction);
        if (checkOverlap(i, j, direction, map) == 1)
        {
            putShips(map, i, j, direction);
        }
        else
            k--;
    }
    return 0;
}

//-------------------------------------------------------------------

int checkOverlap(int i, int j, char direction, int map[][100])
{
    int sw = 1, p;
    if (direction == 'v')
    {
        for (p = 0; p < 3 && sw == 1; p++, i++)
        {
            if (map[j][i] == -2)
            {
                printf("Ships overlap with each other. Please input another location\n");
                sw = 0;
            }
        }
    }
    else if (direction == 'h')
    {
        for (int p = 0; p < 3 && sw == 1; ++p, j++)
        {
            if (map[j][i] == -2)
            {
                printf("Ships overlap with each other. Please input another location\n");
                sw = 0;
            }
        }
    }
    else
    {
        printf("Direction is not valid. Please input the correct direction (v/h)\n");
        sw = 0;
    }
    return sw;
}

//-------------------------------------------------------------------

int putShips(int map[][100], int i, int j, char direction)
{
    int k = 0;
    for (k = 0; k < 3; k++)
    {
        map[j][i] = -2;
        if (direction == 'v')
            j++;
        else
            i++;
    }
    return 0;
}

//-------------------------------------------------------------------

int scanSign()
{
    int i;
    char sign[5];
    scanf("%s", sign); // scanf for '---'
    for (i = 0; i < 3 && sign[i] == '-'; i++)
        ;
    if (i == 3)
    {
        return 1;
    }
    // May be used for phase 6
    // for ( i = 0; i < 3 && sign[i]=='$'; i++)
    // {
    //     return 2;
    // }
    return 0;
}

//-------------------------------------------------------------------

int printInf(int ships, int n)
{
    int i;
    printf(" FOCP1");
    for (i = 0; i < 2 * n + 14; i++)
    {
        printf(" ");
    }
    printf(" FOCP2\n\n");
    printf(" remaining ships: %d", ships);
    for (i = 0; i <= 2 * n; i++)
    {
        printf(" ");
    }
    printf(" remaining ships: %d\n\n", ships);
    return 0;
}

//-------------------------------------------------------------------

int printMaps(int map1[][100], int map2[][100], int n)
{
    int i, j;
    for (i = n; i > 0; i--)
    {
        // p1 map
        for (j = 0; j <= n; j++)
        {
            switch (map1[i][j])
            {
            case 0:
                printf("~ ");
                break;
            case -1:
                printf("* ");
                break;
            default:
                if (n > 9)
                {
                    if (i > 9)
                    {
                        printf("%d ", map1[i][j]);
                    }
                    else
                    {
                        printf("%d  ", map1[i][j]);
                    }
                }
                else
                {
                    printf("%d ", map1[i][j]);
                }

                break;
            }
        }
        // space between p1 and p2
        for (j = 0; j < 18; j++)
            printf(" ");
        // p2 map
        for (j = 0; j <= n; j++)
        {
            switch (map2[i][j])
            {
            case 0:
                printf("~ ");
                break;
            case -1:
                printf("* ");
                break;
            default:
                if (n > 9)
                {
                    if (i > 9)
                    {
                        printf("%d ", map2[i][j]);
                    }
                    else
                    {
                        printf("%d  ", map2[i][j]);
                    }
                }
                else
                {
                    printf("%d ", map2[i][j]);
                }
                break;
            }
        }
        printf("\n");
    }
    if (n > 9)
    {
        printf("  ");
    }
    else
    {
        printf(" ");
    }

    // numbers at the bottom of the graph p1
    for (i = 0, j = 0; j < n; j++)
    {
        printf(" %d", map1[i][j]);
    }
    // space between p1 and p2
    if (n > 9)
    {
        for (i = 0; i < 20; i++)
            printf(" ");
    }
    else
    {
        for (i = 0; i < 20; i++)
            printf(" ");
    }
    // numbers at the bottom of the graph p2
    for (i = 0, j = 0; j < n; j++)
    {
        printf(" %d", map2[i][j]);
    }
    return 0;
}
