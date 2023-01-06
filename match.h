#ifndef match
#define match
#include "printing.h"
#include "scan.h"
#include "introduction.h"
#include "gamesetting.h"
#include "music.h"
//-------------------------------------------------------------------

int bombing(int map[][100], int *ship, int playerTurn, struct ships shipPlayer[])
{
    int x, i = 1, j = 1, save, midMenu;
    do
    {
        i = random();
        j = random();
    } while (passShip(shipPlayer, j, i) == 1);
    clearScreen();
    save = map[i][j];
    map[i][j] = -1;
    if (playerTurn == 1)
    {
        printInfo(*ship, namePlayer2, namePlayer1);
    }
    else
        printInfo(*ship, namePlayer1, namePlayer2);

    printMaps(map);
    x = _getch();
    while (x != 13)
    {
        while (x != 224 && x != 13 && x != 27)
        {
            x = _getch();
        }
        if (x == 224)
        {
            x = _getch();
        }
        if (x == 27)
        {
            midMenu = midGameMenu();
            while (midMenu == 1)
            {
                setting();
                midMenu = midGameMenu();
            }
            if (midMenu == 2)
                return 0;
            x = 0;
        }

        map[i][j] = save;
        if (x == 77)
        {
            if (j < n)
            {
                j++;
                while (passShip(shipPlayer, j, i) == 1 && j != n)
                {
                    j++;
                }
                while (passShip(shipPlayer, j, i) == 1)
                {
                    j--;
                }
            }
        }
        else if (x == 75)
        {
            if (j > 1)
            {
                j--;
                while (passShip(shipPlayer, j, i) == 1 && j != 1)
                {
                    j--;
                }
                while (passShip(shipPlayer, j, i) == 1)
                {
                    j++;
                }
            }
        }
        else if (x == 72)
        {
            if (i < n)
            {
                i++;
                while (passShip(shipPlayer, j, i) == 1 && i != n)
                {
                    i++;
                }
                while (passShip(shipPlayer, j, i) == 1)
                {
                    i--;
                }
            }
        }
        else if (x == 80)
        {
            if (i > 1)
            {
                i--;
                while (passShip(shipPlayer, j, i) == 1 && i != 1)
                {
                    i--;
                }
                while (passShip(shipPlayer, j, i) == 1)
                {
                    i++;
                }
            }
        }
        save = map[i][j];
        map[i][j] = -1;
        clearScreen();
        if (playerTurn == 1)
        {
            printInfo(*ship, namePlayer2, namePlayer1);
        }
        else
            printInfo(*ship, namePlayer1, namePlayer2);

        printMaps(map);
    }
    if (save == -2)
    {
        if (playerTurn == 1)
        {
            hitShip(shipP2, j, i);
            if (checkShip(shipP2) == 1)
                shipPlayer2--;
        }
        else
        {
            hitShip(shipP1, j, i);
            if (checkShip(shipP1) == 1)
                shipPlayer1--;
        }
        map[i][j] = -4;
        clearScreen();
        if (playerTurn == 1)
        {
            printInfo(*ship, namePlayer2, namePlayer1);
        }
        else
            printInfo(*ship, namePlayer1, namePlayer2);
        printMaps(map);
        Green(1);
        printf("\n  You hit the ship!");
        Reset();
        if (soundEffectSw == 1)
            fire();
        else
            sleep(2000);
    }
    else
    {
        map[i][j] = -3;
        clearScreen();
        if (playerTurn == 1)
        {
            printInfo(*ship, namePlayer2, namePlayer1);
        }
        else
            printInfo(*ship, namePlayer1, namePlayer2);
        printMaps(map);
        Red(1);
        printf("\n  You missed!");
        Reset();
        map[i][j] = save;
        if (soundEffectSw == 1)
            water();
        else
            sleep(2000);
        
    }
    return 1;
}
//------------------------------------------------------------

void findCleanArea(int *firstX,int *firstY,int *lastX,int *lastY) {
    int i, j;
    int y, x;
    int swV, swH;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (saveHits[i][j] == 0)
            {
                swV = swH = 1;
                for (x = j, y = i; swV == 1 && swH == 1 && x <= n && y <= n; x++, y++)
                {
                    Hcheck(x, y, i, j, &swH);
                    Vcheck(x, y, i, j, &swV);
                }
                x--;
                y--;
                if (swH == 0 && swV == 0)
                {
                    x--;
                    y--;
                }
                else if (swH == 0)
                {
                    y--;
                    for (; x <= n && swV == 1; x++)
                    {
                        Vcheck(x, y, i, j, &swV);
                    }
                    x--;
                    if (swV == 0)
                    {
                        x--;
                    }
                }
                else if (swV == 0)
                {
                    x--;
                    for (; y <= n && swH == 1; y++)
                    {
                        Hcheck(x, y, i, j, &swH);
                    }
                    y--;
                    if (swH == 0)
                    {
                        y--;
                    }
                }
                else if (x == n)
                {
                    for (; y <= n && swH == 1; y++)
                    {
                        Hcheck(x, y, i, j, &swH);
                    }
                    y--;
                    if (swH == 0)
                    {
                        y--;
                    }
                }
                else if (y == n)
                {
                    for (; x <= n && swV == 1; x++)
                    {
                        Hcheck(x, y, i, j, &swV);
                    }
                    x--;
                    if (swV == 0)
                    {
                        x--;
                    }
                }

                if (((x - j + 1) * (y - i + 1)) >= ((*lastX - *firstX + 1) * (*lastY - *firstY + 1)))
                {
                    *lastX = x;
                    *firstX = j;
                    *lastY = y;
                    *firstY = i;
                }
            }
        }
    }
}
//------------------------------------------------------------
void computerBombing()
{
    int firstX = 0, firstY = 0;
    int lastX = 0, lastY = 0;
    int i, j, save;
    findCleanArea(&firstX, &firstY, &lastX, &lastY);
    do
    {
        i = random();
        j = random();
    } while ((i < firstY || i > lastY) || (j < firstX || j > lastX));
    saveHits[i][j] = 1;
    save = mapPlayer1[i][j];
    mapPlayer1[i][j] = -1;
    clearScreen();
    printInfo(shipPlayer1, namePlayer1, namePlayer2);
    printMaps(mapPlayer1);
    sleep(750);
    if (save == -2)
    {

        hitShip(shipP1, j, i);
        if (checkShip(shipP1) == 1)
            shipPlayer1--;
        mapPlayer1[i][j] = -4;
        clearScreen();
        printInfo(shipPlayer1, namePlayer1, namePlayer2);
        printMaps(mapPlayer1);
        Green(1);
        printf("\n  player 2 hit the ship!");
        Reset();
        if (soundEffectSw == 1)
            fire();
        else
            sleep(2000);
    }
    else
    {
        mapPlayer1[i][j] = -3;
        clearScreen();
        printInfo(shipPlayer1, namePlayer1, namePlayer2);
        printMaps(mapPlayer1);
        Red(1);
        printf("\n  Player2 missed!");
        Reset();
        mapPlayer1[i][j] = save;
        if (soundEffectSw == 1)
            water();
        else
            sleep(2000);
    }

}
//------------------------------------------------------------
int rematch(int winner)
{
    int x, i = 0;
    printf("\n\n   do you want a rematch?\n      ");
    WhiteBack();
    Black(1);
    printf("Yes");
    Reset();
    printf("   ");
    printf("No\n");
    x = _getch();
    while (x != 13)
    {
        while (x != 224 && x != 13)
        {
            x = _getch();
        }
        if (x == 224)
            x = _getch();
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
            Black(1);
            printf("Yes");
            Reset();
            printf("   ");
            printf("No\n");
            break;
        case 1:
            printf("Yes");
            printf("   ");
            WhiteBack();
            Black(1);
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

//--------------------------------------------------------------------
int multiPlayer()
{
    clearScreen();
    //scanBasicInfo();
    scanMultiPlayerByFile();
    
    //scanPlayerInfo(mapPlayer1, namePlayer1, 1, shipP1);
    //if (scanSign() == 1)
    //{
        //clearScreen();
    //}
    //scanPlayerInfo(mapPlayer2, namePlayer2, 2, shipP2);
    shipPlayer1 = nship;
    shipPlayer2 = nship;
    restoreShipsSW();
    while (1)
    {
        if (bombing(mapPlayer2, &shipPlayer2, 1, shipP2) == 0)
            return 0;
        if (shipPlayer2 == 0)
        {
            break;
        }
        if (bombing(mapPlayer1, &shipPlayer1, 2, shipP1) == 0)
            return 0;
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
            multiPlayer();
        else
            return 0;
    }
    else
    {
        printEnd1();
        if (rematch(1) == 0)
            multiPlayer();
        else
            return 0;
    }
    return 0;
}
//--------------------------------------------------------------------

int singlePlayer()
{
    clearScreen();
    //scanBasicInfo();
    //initializeMap(mapPlayer1);
    //initializeMap(mapPlayer2);
    //scanPlayerInfo(mapPlayer1, namePlayer1, 1, shipP1);
    scanSinglePlayerByFile();
    initializeComputerInfo();
    shipPlayer1 = nship;
    shipPlayer2 = nship;
    restoreShipsSW();
    while (1)
    {
        if (bombing(mapPlayer2, &shipPlayer2, 1, shipP2)==0)
            return 0;
        if (shipPlayer2 == 0)
        {
            break;
        }
        computerBombing(); //*****
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
            singlePlayer();
        else
            return 0;
    }
    else
    {
        printEnd1();
        if (rematch(1) == 0)
            singlePlayer();
        else
            return 0;
    }
    return 0;
}
//----------------------------------------------------------------
int startNewGame()
{
    int x;
    x = startNewGameMenu();
    if (x == 0)
    {
        return singlePlayer();
    }
    else if (x == 1)
    {
        return multiPlayer();
    }
    else
    {
        return 0;
    }
}
#endif