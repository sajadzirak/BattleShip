#ifndef match
#define match
#include "printing.h"
#include "general.h"
#include "conio.h"
#include "scan.h"
#include "initializing.h"
#include "introduction.h"
#include "data.h"
//-------------------------------------------------------------------

void bombing(int map[][100], int *ship, int playerTurn)
{
    int x, i = 1, j = 1, save;
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
            hitShip(shipPosP2, j, i);
            if (checkShip(shipPosP2) == 1)
                shipPlayer2--;
        }
        else
        {
            hitShip(shipPosP1, j, i);
            if (checkShip(shipPosP1) == 1)
                shipPlayer1--;
        }

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

void computerBombing()
{
	int i, j, save;
	clearScreen();
	do
	{
		i = random();
		j = random();
	} while (checkHit(i, j, saveHits) == 1);
	saveHits[i][j] = 1;
	save = mapPlayer1[i][j];
	mapPlayer1[i][j] = -1;
	printInfo(shipPlayer1, namePlayer1, namePlayer2);
	printMaps(mapPlayer1);
	if (save == -2)
	{
        hitShip(shipPosP1,j,i);
        if (checkShip(shipPosP1) == 1)
        {
        	shipPlayer1--;
        	previousHit = 1;
		}
		Green(1);
		printf("\n  player 2 hit the ship!");
		Reset();
	}
	else
	{
		mapPlayer1[i][j] = save;
        Red(1);
		printf("\n  player 2 missed!");
		Reset();
	}

	sleep(3500);
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

//--------------------------------------------------------------------
int multiPlayer()
{
    clearScreen();
    scanBasicInfo();
    initializeMap(mapPlayer1);
    initializeMap(mapPlayer2);
    scanPlayerInfo(mapPlayer1, namePlayer1, 1, shipPosP1);
    if (scanSign() == 1)
    {
        clearScreen();
    }
    scanPlayerInfo(mapPlayer2, namePlayer2, 2, shipPosP2);
    shipPlayer1 = nship;
    shipPlayer2 = nship;
    while (1)
    {
        bombing(mapPlayer2, &shipPlayer2, 1);
        if (shipPlayer2 == 0)
        {
            break;
        }
        bombing(mapPlayer1, &shipPlayer1, 2);
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
    scanBasicInfo();
    initializeMap(mapPlayer1);
    initializeMap(mapPlayer2);
    scanPlayerInfo(mapPlayer1, namePlayer1, 1, shipPosP1);
    initializeComputerInfo();
    shipPlayer1 = nship;
    shipPlayer2 = nship;

    while (1)
    {
        bombing(mapPlayer2, &shipPlayer2, 1);
        if (shipPlayer2 == 0)
        {
            break;
        }
        computerBombing();//*****
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