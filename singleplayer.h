#ifndef singleplayer
#define singleplayer

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "general.h"
#include"initializing.h"
#include"printing.h"
#include "color.h"
#include "match.h"


int saveHits[11][11] = {0};

int hitButton2(int* i)
{
	if(kbhit())
	{
		int x;
		x = getch();
		if(x == 224) x = getch();
		switch(x)
		{
			case 72: // up
				if(*i == 1) *i = 0;
				break;
			case 80: // down
				if(*i == 0) *i = 1;
				break;
			case 13:
				return *i;
				break;
		}	
	}
	return -1;	
}
//-------------------------------------------------------------------
void singlePlayerButton()
{
	printf("\e[47m\033[1;30msingle player\033[0m\n");
	printf("multiplayer\n");
}
//-------------------------------------------------------------------
void multiPlayerButton()
{
	printf("single player\n");
	printf("\e[47m\033[1;30mmultiplayer\033[0m\n");
}
//-------------------------------------------------------------------
int chooseMode()
{
	int i = 0;
	while(hitButton2(&i) == -1)
	{
		clearScreen();
		if(i == 0) singlePlayerButton();
		else multiPlayerButton();
		sleep(500);
		if(hitButton2(&i) != -1) break;	
	}
	return i;
}
//-------------------------------------------------------------------
void randomSeed()
{
	time_t x; 
	x = time(NULL);
	srand(x);	
}
//-------------------------------------------------------------------
int random(int n)
{
	// This function return a random int between 1 and n
	int i;
	i = rand() % n + 1;
	return i;
}
//-------------------------------------------------------------------
int checkComputerOverlap(int i, int j, char direction, int map[][100])
{
	int sw = 1, p;
    if (direction == 'v')
    {
        for (p = 0; p < 3 && sw == 1; p++, i++)
        {
            if (map[i][j] == -2)
            {
                sw = 0;
            }
        }
    }
    else if (direction == 'h')
    {
        for (int p = 0; p < 3 && sw == 1; ++p, j++)
        {
            if (map[i][j] == -2)
            {
                sw = 0;
            }
        }
    }
    return sw;
}
//-------------------------------------------------------------------
int checkComputerRange(int i, int j, char direction , int n)
{
	int sw = 1;
    if ((i + 2 > n && direction == 'v') || (j + 2 > n && direction == 'h'))
    {
        sw = 0;
    }
    return sw;
}
//-------------------------------------------------------------------
int checkHit(int i, int j, int arr[][11])
{
	if(arr[i][j] == 1) return 1;
	else return 0;
}
//-------------------------------------------------------------------
void initializeComputerInfo(int map[][100], char name[], int playerNum,int n,int nship)
{
	int i, j, k;
	char direction;
	strcpy(name, "player 2");
	randomSeed();
	for(k = 0; k < nship; ++k)
	{
		i = random(n);
		j = random(n);
		direction = random(2);
		if(direction == 1) direction = 'v';
		else direction = 'h';
		if(checkComputerOverlap(i, j, direction, map) == 1 && checkComputerRange(i, j, direction, n) == 1) putShips(map, i, j, direction);
		else --k;
	}
}
//-------------------------------------------------------------------
void computerBombing(int map[][100], char name[], char name2[], int *ship,int n)
{
	int i, j, hitsw = 0, save;
	clearScreen();
	do
	{
		i = random(n);
		j = random(n);
	}while(checkHit(i, j, saveHits) == 1);
	saveHits[i][j] = 1;
	save = map[i][j];
	map[i][j] = -1;
	printInfo(*ship, n, name, name2);
	printMaps(map, n);
	if(save == -2)
	{
		hitsw = 1;
		*ship -= 1;
	}
	else
	{
		map[i][j] = save;
	}
	if(hitsw == 1)
	{
		Green(1);
        printf("\n  player 2 hit the ship!");
        Reset();
	}
	else
	{
		Red(1);
        printf("\n  player 2 missed!");
        Reset();
	}
	sleep(3500);
}
//-------------------------------------------------------------------
int startNewSinglePlayerGame(int n,int nship,int mapPlayer1[][100],int mapPlayer2[][100],char namePlayer1[],char namePlayer2[],int shipPlayer1,int shipPlayer2)
{
	clearScreen();
    scanBasicInfo(&n, &nship);
    initializeMap(mapPlayer1, n);
    initializeMap(mapPlayer2, n);
    scanPlayerInfo(mapPlayer1, namePlayer1, 1, n, nship);
    initializeComputerInfo(mapPlayer2, namePlayer2, 2, n, nship);
    shipPlayer1 = nship * 3;
    shipPlayer2 = nship * 3;
	while(1)
	{
   		bombing(mapPlayer2, namePlayer2, namePlayer1, &shipPlayer2, n);
        if (shipPlayer2 == 0)
        {
            break;
        }
        computerBombing(mapPlayer1, namePlayer1, namePlayer2, &shipPlayer1, n);
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
            startNewSinglePlayerGame(n,nship,mapPlayer1,mapPlayer2,namePlayer1,namePlayer2,shipPlayer1,shipPlayer2);
        else
            return 0;
    }
    else
    {
        printEnd1();
        if (rematch(1) == 0)
            startNewSinglePlayerGame(n,nship,mapPlayer1,mapPlayer2,namePlayer1,namePlayer2,shipPlayer1,shipPlayer2);
        else
            return 0;
    }
    return 0;
}
#endif