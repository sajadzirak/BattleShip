#ifndef match
#define match
#include "printing.h"
#include "scan.h"
#include "introduction.h"
#include "gamesetting.h"

//-------------------------------------------------------------------

int bombing(int map[][100], int *ship, int playerTurn, struct ships shipPlayer[])
{
    int x, i = 1, j = 1, save, midMenu;
    while (passShip(shipPlayer, j, i) == 1 && j != n)
        {
            j++;
        }
    if (passShip(shipPlayer, j, i) == 1 && j == n){
        j=1;
        while (passShip(shipPlayer, j, i) == 1 && i != n)
        {
            i++;
        }
    }
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
        while (x != 224 && x != 13 && x != 27)
        {
            x = getch();
        }
        if (x == 224)
        {
            x = getch();
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
            x=0;
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
    }
    sleep(2000);
    return 1;
}
//------------------------------------------------------------

void computerBombing()
{
    int i, j, k, p, save, loopsw = 1;
    clearScreen();
    if(hitsw == 1)
    {
    	for(k = 0; k < 4 && loopsw == 1; ++k)
    	{
    		if(around[k] == 0)
    		{
    			loopsw = 0;
    			switch(k)
    			{
    				case 0:  // right side
    					++prevHit[1];
    					if (prevHit[1] > n)
    					{
    						around[0] = 1;
							if (isFinishAround() == 1)
							{
								computerBombing();	
							}	
							resetPrevHit();
    						loopsw = 1;
						}
    					else if(checkHit(prevHit[0], prevHit[1], saveHits) != 1)
    					{
    						saveHits[prevHit[0]][prevHit[1]] = 1;
    						clearScreen();
    						if (mapPlayer1[prevHit[0]][prevHit[1]] == -2)
    						{
    							hitShip(shipP1, prevHit[1], prevHit[0]);
    							if (checkShip(shipP1) == 1)
            						shipPlayer1--;
            					mapPlayer1[prevHit[0]][prevHit[1]] = -4;  
								printComputerStats(1);
    							around[1] = 1; 
    							around[3] = 1; 
							}
							else
							{
								around[0] = 1;
								save = mapPlayer1[prevHit[0]][prevHit[1]];
								mapPlayer1[prevHit[0]][prevHit[1]] = -3;
								printComputerStats(0);
        						mapPlayer1[prevHit[0]][prevHit[1]] = save;
								resetPrevHit();
							}
						}
						else if(checkHit(prevHit[0], prevHit[1], saveHits) == 1)
						{
							around[0] = 1;
							loopsw = 1;
							resetPrevHit();
						}
						break;
    				case 1: // up
    					++prevHit[0];
    					if (prevHit[0] > n)
    					{
    						around[1] = 1;
							if (isFinishAround() == 1)
							{
								computerBombing();	
							}	
							resetPrevHit();
    						loopsw = 1;
						}
    					else if(checkHit(prevHit[0], prevHit[1], saveHits) != 1)
    					{
    						saveHits[prevHit[0]][prevHit[1]] = 1;
    						clearScreen();
    						if (mapPlayer1[prevHit[0]][prevHit[1]] == -2)
    						{
    							hitShip(shipP1, prevHit[1], prevHit[0]);
    							if (checkShip(shipP1) == 1)
            						shipPlayer1--;
            					mapPlayer1[prevHit[0]][prevHit[1]] = -4;
								printComputerStats(1);
    							around[0] = 1; 
    							around[2] = 1; 
							}
							else
							{
								around[1] = 1;
								save = mapPlayer1[prevHit[0]][prevHit[1]];
								mapPlayer1[prevHit[0]][prevHit[1]] = -3;
								printComputerStats(0);
        						mapPlayer1[prevHit[0]][prevHit[1]] = save;
								resetPrevHit();
							}
						}
						else if(checkHit(prevHit[0], prevHit[1], saveHits) == 1)
						{
							around[1] = 1;
							loopsw = 1;
							resetPrevHit();
						}
						break;
    				case 2:  // left side
    					--prevHit[1];
    					if (prevHit[1] < 1)
    					{
    						around[2] = 1;
							if (isFinishAround() == 1)
							{
								computerBombing();	
							}
							resetPrevHit();
    						loopsw = 1;
						}
    					else if(checkHit(prevHit[0], prevHit[1], saveHits) != 1)
    					{
    						saveHits[prevHit[0]][prevHit[1]] = 1;
    						clearScreen();
    						if (mapPlayer1[prevHit[0]][prevHit[1]] == -2)
    						{
    							hitShip(shipP1, prevHit[1], prevHit[0]);	
    							if (checkShip(shipP1) == 1)
            						shipPlayer1--;
            					mapPlayer1[prevHit[0]][prevHit[1]] = -4;
								printComputerStats(1);
    							around[1] = 1; 
    							around[3] = 1; 
							}
							else
							{
								around[2] = 1;
								save = mapPlayer1[prevHit[0]][prevHit[1]];
								mapPlayer1[prevHit[0]][prevHit[1]] = -3;
								printComputerStats(0);
        						mapPlayer1[prevHit[0]][prevHit[1]] = save;
								resetPrevHit();
							}
						}
						else if(checkHit(prevHit[0], prevHit[1], saveHits) == 1)
						{
							around[2] = 1;
							loopsw = 1;
							resetPrevHit();
						}
						break;
    				case 3:  // down
    					--prevHit[0];
    					if (prevHit[0] < 1)
    					{
    						around[3] = 1;
							if (isFinishAround() == 1)
							{
								computerBombing();	
							}
							resetPrevHit();
    						loopsw = 1;
						}
    					else if(checkHit(prevHit[0], prevHit[1], saveHits) != 1)
    					{
    						saveHits[prevHit[0]][prevHit[1]] = 1;
    						clearScreen();
    						if (mapPlayer1[prevHit[0]][prevHit[1]] == -2)
    						{
    							hitShip(shipP1, prevHit[1], prevHit[0]);    							
    							if (checkShip(shipP1) == 1)
            						shipPlayer1--;
            					mapPlayer1[prevHit[0]][prevHit[1]] = -4;
								printComputerStats(1);
    							around[0] = 1; 
    							around[2] = 1; 
							}
							else
							{
								around[3] = 1;
								save = mapPlayer1[prevHit[0]][prevHit[1]];
								mapPlayer1[prevHit[0]][prevHit[1]] = -3;
								printComputerStats(0);
        						mapPlayer1[prevHit[0]][prevHit[1]] = save;
								resetPrevHit();
							}
						}
						else if(checkHit(prevHit[0], prevHit[1], saveHits) == 1)
						{
							around[3] = 1;
							loopsw = 1;
							resetPrevHit();
						}
						break;
				}
				isFinishAround();
			}
		}
	}
	else
	{
		do
    	{
        	i = random();
        	j = random();
    	} while (checkHit(i, j, saveHits) != 0);
    	saveHits[i][j] = 1;
    	save = mapPlayer1[i][j];
    	mapPlayer1[i][j] = -1;
    	printInfo(shipPlayer1, namePlayer1, namePlayer2);
    	printMaps(mapPlayer1);
    	if (save == -2)
    	{
    		hitsw = 1;
    		hitPos[0] = i;
    		hitPos[1]= j;
			resetPrevHit();
    		resetAround(i, j);
        	hitShip(shipP1, j, i);
        	if (checkShip(shipP1) == 1)
            	shipPlayer1--;
        	mapPlayer1[i][j] = -4;
        	clearScreen();
			printComputerStats(1);
    	}
    	else
    	{
        	mapPlayer1[i][j] = -3;
        	clearScreen();
			printComputerStats(0);
        	mapPlayer1[i][j] = save;
    	}
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
    scanPlayerInfo(mapPlayer1, namePlayer1, 1, shipP1);
    if (scanSign() == 1)
    {
        clearScreen();
    }
    scanPlayerInfo(mapPlayer2, namePlayer2, 2, shipP2);
    shipPlayer1 = nship;
    shipPlayer2 = nship;
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
    scanBasicInfo();
    initializeMap(mapPlayer1);
    initializeMap(mapPlayer2);
    scanPlayerInfo(mapPlayer1, namePlayer1, 1, shipP1);
    initializeComputerInfo();
    shipPlayer1 = nship;
    shipPlayer2 = nship;

    while (1)
    {
        bombing(mapPlayer2, &shipPlayer2, 1, shipP2);
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
