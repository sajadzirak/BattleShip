#include <stdio.h>
#include<io.h>
#include<fcntl.h>
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

    for ( i = 0; i <  n+1; i++)
    {
        printf(" _");// make the top border for p1
    }
    for (i = 1; i < n; i++)
        printf(" ");// space between p1 and p2
    for ( i = 0; i <  n+1; i++)
    {
        printf(" _");// make the top border for p2
    }
    printf("\n");

    for (i = n; i > 0; i--)
    {
        // p1 map
        for (j = 0; j <= n; j++)
        {
            switch (map[i][j])
            {
            case 0:
                printf("~|");
                break;
            case -1:
                // for bombs
                break;
            default:
                printf("|%d|", map[i][j]);
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
                printf("~|");
                break;
            case -1:
                // for bombs
                break;
            default:
                printf("|%d|", map[i][j]);
                break;
            }
        }
        printf("\n ");
        // top and bottom border p1
        for ( j = 0; j <  n+1; j++)
        {
            _setmode(_fileno(stdout),0x00020000);
            wprintf(L"\x035E\x035F  ");
            _setmode(_fileno(stdout),_O_TEXT);
        }
        // space between p1 and p2
        for (j = 1; j < n; j++)
            printf(" ");
        // top and bottom border p2
        for ( j = 0; j <  n+1; j++)
        {
            _setmode(_fileno(stdout),0x00020000);
            wprintf(L"\x035E\x035F  ");
            _setmode(_fileno(stdout),_O_TEXT);
        }
        printf("\n");
    }

    printf("|0|");
    // numbers at the bottom of the graph p1
    for (i = 0, j = 0; j < n; j++)
    {
        printf("%d|", map[i][j]);
    }
    for (i = 2; i < n; i++)
        printf(" ");
    printf("|0|");
    // numbers at the bottom of the graph p1
    for (i = 0, j = 0; j < n; j++)
    {
        printf("%d|", map[i][j]);
    }
    printf("\n ");
    // bottom border p1
    for ( j = 0; j <  n+1; j++)
    {
        _setmode(_fileno(stdout),0x00020000);
        wprintf(L"\x035E  ");
        _setmode(_fileno(stdout),_O_TEXT);
    }
    // space between p1 and p2
    for (i = 1; i < n; i++)
        printf(" ");
    // top and bottom border p2
    for ( j = 0; j <  n+1; j++)
    {
        _setmode(_fileno(stdout),0x00020000);
        wprintf(L"\x035E  ");
        _setmode(_fileno(stdout),_O_TEXT);
    }
}