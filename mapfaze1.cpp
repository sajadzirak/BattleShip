#include <stdio.h>

#define namePlayer1 "FOCP1"
#define namePlayer2 "FOCP2"

int n, nship;
int mapPlayer1[100][100];
int mapPlayer2[100][100];

int initializeMap(int[][100], int);
int printMaps(int[][100], int[][100], int);
int printdetails(int, int);
int scan(int*);

int main()
{
	int scanSwitch = 1;
    printf("Give the map's size: ");
    scanf("%d", &n);

    initializeMap(mapPlayer1, n);
    initializeMap(mapPlayer2, n);
    scan(&scanSwitch);
	if(scanSwitch == 0)
	{
		printf("You can not put your ships in this way!!\n");	
		return 0;
	}
    printdetails(nship, n);
    printMaps(mapPlayer1, mapPlayer2, n);
    return 0;
}

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
int printdetails(int ships, int n)
{
    int i;
    printf(" FOCP1");
    for (i = 0; i < 2 * n + 14; i++)
    {
        printf(" ");
    }
    printf(" FOCP2\n\n");
    printf(" remaining ships: %d", ships);
    for (i = 0; i <= 2*n; i++)
    {
        printf(" ");
    }
    printf(" remaining ships: %d\n\n", ships);
}

int scan(int *scanSwitch)
{
	int i, j;
	char name[15], direction;
	printf("How many ships are there?: ");
	scanf("%d", &nship);
	
	printf("Name and locations for player1: \n");
	scanf("%s", name);
	for(int k = 0; k < nship; ++k)
	{
		scanf("%d %d %c", &i, &j, &direction);
		if(direction == 'v')
		{
			for(int p = 0; p < 3; ++p, ++j)
			{
				if(mapPlayer2[j][i] == -2) *scanSwitch =  0;
				mapPlayer1[j][i] = -2;
			}
		}
		else
		{
			for(int p = 0; p < 3; ++p, ++i)
			{
				if(mapPlayer2[j][i] == -2) *scanSwitch =  0;
				mapPlayer1[j][i] = -2;
			}
		}
	}
	
	scanf("%s", name);   // scanf for '---'
	
	printf("Name and locations for player2: \n");
	scanf("%s", name);
	for(int k = 0; k < nship; ++k)
	{
		scanf("%d %d %c", &i, &j, &direction);
		if(direction == 'v')
		{
			for(int p = 0; p < 3; ++p, ++j)
			{
				if(mapPlayer2[j][i] == -2) *scanSwitch =  0;
				mapPlayer2[j][i] = -2;
			}
		}
		else
		{
			for(int p = 0; p < 3; ++p, ++i)
			{
				if(mapPlayer2[j][i] == -2) *scanSwitch =  0;
				mapPlayer2[j][i] = -2;
			}
		}
	}
	return 0;
}