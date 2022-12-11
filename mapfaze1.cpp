#include <stdio.h>

#define namePlayer1 "FOCP1"
#define namePlayer2 "FOCP2"

int initializeMap(int [][100], int);
int printMaps(int [][100], int [][100], int);

int main()
{
    int i, j, n, nship;
    scanf("%d", &n);
    int mapPlayer1[100][100];
    int mapPlayer2[100][100];
    
    initializeMap(mapPlayer1, n);
    initializeMap(mapPlayer2, n);
    
    printf("how many ships are there?: \n");
    scanf("%d", &nship);
    
    printf("Locations for player1: \n");
    for(int k = 0; k < 3; ++k){
    	scanf("%d %d", &i, &j);
    	mapPlayer1[i][j] = -1;
	}
	
	printf("Locations for player2: \n");
	for(int k = 0; k < 3; ++k){
		scanf("%d %d", &i, &j);
		mapPlayer2[i][j] = -1;
	}
    printMaps(mapPlayer1, mapPlayer2, n);
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
            if (n>9)
            {
                if (i > 9)
                {
                    printf("%d ", map1[i][j]);
                }
                else
                {
                    printf("%d  ", map1[i][j]);
                }
            }else
            {
                printf("%d ", map1[i][j]);
            }

            break;
            }
        }
        // space between p1 and p2
        for (j = 2; j < n; j++)
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
            if (n>9)
            {
                if (i > 9)
                {
                    printf("%d ", map2[i][j]);
                }
                else
                {
                    printf("%d  ", map2[i][j]);
                }
            }else
            {
                printf("%d ", map2[i][j]);
            }
            break;
            }
        }
        printf("\n");
    }
    if (n>9)
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
        for (i = 0; i < n; i++)
            printf(" ");
    }
    else
    {
        for (i = 0; i < n; i++)
            printf(" ");
    }
    // numbers at the bottom of the graph p2
    for (i = 0, j = 0; j < n; j++)
    {
        printf(" %d", map2[i][j]);
    }
    return 0;
}