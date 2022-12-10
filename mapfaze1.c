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

    for (i = n; i > 0; i--)
    {
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
                printf("%d ", map[i][j]);
                break;
            }
        }
        for (j = 2; j < n; j++)
            printf(" ");
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
                printf("%d ", map[i][j]);
                break;
            }
        }
        printf("\n");
    }
    printf(" ");
    for (i = 0, j = 0; j < n; j++)
    {
        printf(" %d", map[i][j]);
    }
    for (i = 0; i < n; i++)
        printf(" ");
    for (i = 0, j = 0; j < n; j++)
    {
        printf(" %d", map[i][j]);
    }
}