#ifndef match
#define match
#include"printing.h"
#include"general.h"
#include"conio.h"
#include"scan.h"
#include"initializing.h"


//-------------------------------------------------------------------


void bombing(int map[][100], char name[], char name2[], int *ship,int n)
{
    int x, i = 1, j = 1, save;
    clearScreen();
    save = map[i][j];
    map[i][j] = -1;
    printInfo(*ship, n, name, name2);
    printMaps(map, n);
    x = getch();
    while (x != 13)
    {
        while (x != 224 && x != 13)
        {
            x = getch();
        }
        if (x == 224)
        {
            x = getch();
        }

        map[i][j] = save;
        if (x == 77)
        {
            if (j < n)
                j++;
        }
        else if (x == 75)
        {
            if (j > 1)
                j--;
        }
        else if (x == 72)
        {
            if (i < n)
                i++;
        }
        else if (x == 80)
        {
            if (i > 1)
                i--;
        }
        save = map[i][j];
        map[i][j] = -1;
        clearScreen();
        printInfo(*ship, n, name, name2);
        printMaps(map, n);
    }
    if (save == -2)
    {
        *ship -= 1;
        Green(1);
        printf("\n  You hit the ship!");
        Reset();
    }
    else
    {
        map[i][j] = save;
        Red(1);
        printf("\n  You missed!");
        Reset();
    }
    sleep(2000);
}
//------------------------------------------------------------

int rematch(int winner)
{
    int x, i = 0;
    printf("\n\n   do you want a rematch?\n      ");
    WhiteBack();
    printf("Yes");
    Reset();
    printf("   ");
    printf("No\n");
    x = getch();
    while (x != 13)
    {
        while (x != 224 && x != 13)
        {
            x = getch();
        }
        if (x == 224)
            x = getch();
        switch (x)
        {
        case 77:
            if (i < 1)
            {
                i++;
            }

            break;
        case 75:
            if (i > 0)
            {
                i--;
            }
            break;
        }
        clearScreen();
        if (winner == 1)
            printEnd1();
        else
            printEnd2();

        printf("\n\n   do you want a rematch?\n      ");
        switch (i)
        {
        case 0:
            WhiteBack();
            printf("Yes");
            Reset();
            printf("   ");
            printf("No\n");
            break;
        case 1:
            printf("Yes");
            printf("   ");
            WhiteBack();
            printf("No");
            Reset();
            printf("\n");
            break;
        default:
            break;
        }
    }
    return i;
}
//----------------------------------------------------------------
int startNewGame(int n,int nship,int mapPlayer1[][100],int mapPlayer2[][100],char namePlayer1[],char namePlayer2[],int shipPlayer1,int shipPlayer2)
{

    clearScreen();
    scanBasicInfo(&n, &nship);
    initializeMap(mapPlayer1, n);
    initializeMap(mapPlayer2, n);
    scanPlayerInfo(mapPlayer1, namePlayer1, 1, n, nship);
    if (scanSign() == 1)
    {
        clearScreen();
    }
    scanPlayerInfo(mapPlayer2, namePlayer2, 2, n, nship);
    shipPlayer1 = nship * 3;
    shipPlayer2 = nship * 3;
    while (1)
    {
        bombing(mapPlayer2, namePlayer2, namePlayer1, &shipPlayer2, n);
        if (shipPlayer2 == 0)
        {
            break;
        }
        bombing(mapPlayer1, namePlayer1, namePlayer2, &shipPlayer1, n);
        if (shipPlayer1 == 0)
        {
            break;
        }
    }
    clearScreen();
    if (shipPlayer1 == 0)
    {
        printEnd2();
        if (rematch(2) == 0)
            startNewGame(n,nship,mapPlayer1,mapPlayer2,namePlayer1,namePlayer2,shipPlayer1,shipPlayer2);
        else
            return 0;
    }
    else
    {
        printEnd1();
        if (rematch(1) == 0)
            startNewGame(n,nship,mapPlayer1,mapPlayer2,namePlayer1,namePlayer2,shipPlayer1,shipPlayer2);
        else
            return 0;
    }
    return 0;
}
#endif