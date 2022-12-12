#include <stdio.h>

int main()
{
    int i, j, n;
    scanf("%d", &n);
    int map[100][100];
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
    printf(" ");
    // numbers at the bottom of the graph p1
    for (i = 0, j = 0; j < n; j++)
    {
        printf(" %d", map[i][j]);
    }
    // space between p1 and p2
    if (n > 9)
    {
        for (i = 1; i < n; i++)
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
        printf(" %d", map[i][j]);
    }
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        // p1 map
        for (j = 0; j <= n; j++)
        {
            switch (map[i][j])
            {
            case 0:
                printf("~ ");
                break;
            case -1:
                // for bombs
                break;
            default:
                if (i > 9)
                {
                    printf("%d", map[i][j]);
                }
                else
                {
                    printf("%d ", map[i][j]);
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
            switch (map[i][j])
            {
            case 0:
                printf("~ ");
                break;
            case -1:
                // for bombs
                break;
            default:
                if (i > 9)
                {
                    printf("%d", map[i][j]);
                }
                else
                {
                    printf("%d ", map[i][j]);
                }
                break;
            }
        }
        printf("\n");
    }
    
}