#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int n, nship;
int mapPlayer1[100][100];
int mapPlayer2[100][100];
char namePlayer1[20];
char namePlayer2[20];

int scanBasicInf();
int initializeMap(int[][100], int);
int scanPlayerInf(int[][100], char[], int);
int checkOverlap(int, int, char, int[][100]);
int checkRange(int, int, char);
int putShips(int[][100], int, int, char);
int scanSign();
void clearScreen();
int printInf(int, int);
int printMaps(int[][100], int[][100], int);

int main()
{

    scanBasicInf();
    initializeMap(mapPlayer1, n);
    initializeMap(mapPlayer2, n);
    scanPlayerInf(mapPlayer1, namePlayer1, 1);
    if (scanSign()==1){
        clearScreen();
    }
    scanPlayerInf(mapPlayer2, namePlayer2, 2);
    clearScreen();
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

int scanPlayerInf(int map[][100], char name[], int playerNum)
{
    int i, j, k;
    char direction;
    printf("Name and locations for player %d: \n", playerNum);
    scanf("%s", name);
    for (k = 0; k < nship; k++)
    {
        scanf("%d %d %c", &j, &i, &direction);
        if (checkOverlap(i, j, direction, map) == 1 && checkRange(i, j, direction) == 1)
        {
            putShips(map, i, j, direction);
        }
        else
            k--;
    }
    printf("Name and locations received for player %d.\n",playerNum);
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
            if (map[i][j] == -2)
            {
                printf("Ships overlap with each other. Please input another location.\n");
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
                printf("Ships overlap with each other. Please input another location.\n");
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
int checkRange(int i, int j, char direction)
{
    int sw = 1;
    if ((i + 2 > n && direction == 'v') || (j + 2 > n && direction == 'h'))
    {
        printf("Ships are out of range. Please input another location.\n");
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
        map[i][j] = -2;
        if (direction == 'v')
            i++;
        else
            j++;
    }
    return 0;
}

//-------------------------------------------------------------------

int scanSign()
{
    int i;
    char sign[5];
    printf("input the sign(<---> for pass to player 2)");
    scanf("%s", sign); // scanf for '---'
    for (i = 0; i < 3 && sign[i] == '-'; i++);
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
void clearScreen(){
    system("cls");
}
//-------------------------------------------------------------------
int printInf(int ships, int n)
{
    int i;
    printf(" %s",namePlayer1);
    for (i = 0; i < 2 * n + 19-strlen(namePlayer1); i++)
    {
        printf(" ");
    }
    printf(" %s\n\n",namePlayer2);
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
            case -2:
                printf("> ");
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
            case -2:
                printf("> ");
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