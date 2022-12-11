#include <stdio.h>

int main()
{
    int i, j, n;
    scanf("%d", &n);
    int mapPlayer1[100][100];
    int mapPlayer2[100][100];
    for (i = 0, j = 0; j < n; j++)
    {
        mapPlayer1[i][j] = j + 1;
    }
    for (i = 1; i <= n; i++)
    {
        mapPlayer1[i][0] = i;
        for (j = 1; j < n; j++)
        {
            mapPlayer1[i][j] = 0;
        }
    }
    for (i = 0, j = 0; j < n; j++)
    {
        mapPlayer2[i][j] = j + 1;
    }
    for (i = 1; i <= n; i++)
    {
        mapPlayer2[i][0] = i;
        for (j = 1; j < n; j++)
        {
            mapPlayer2[i][j] = 0;
        }
    }

    for (i = n; i > 0; i--)
    {
        // p1 map
        for (j = 0; j <= n; j++)
        {
            switch (mapPlayer1[i][j])
            {
            case 0:
                printf("~ ");
                break;
            case -1:
                // for bombs
                break;
            default:
            if (n>9)
            {
                if (i > 9)
                {
                    printf("%d ", mapPlayer1[i][j]);
                }
                else
                {
                    printf("%d  ", mapPlayer1[i][j]);
                }
            }else
            {
                printf("%d ", mapPlayer1[i][j]);
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
            switch (mapPlayer2[i][j])
            {
            case 0:
                printf("~ ");
                break;
            case -1:
                // for bombs
                break;
            default:
            if (n>9)
            {
                if (i > 9)
                {
                    printf("%d ", mapPlayer2[i][j]);
                }
                else
                {
                    printf("%d  ", mapPlayer2[i][j]);
                }
            }else
            {
                printf("%d ", mapPlayer2[i][j]);
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
        printf(" %d", mapPlayer1[i][j]);
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
        printf(" %d", mapPlayer2[i][j]);
    }
}
