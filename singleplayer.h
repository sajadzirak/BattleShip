#ifndef singleplayer
#define singleplayer

#include <stdio.h>
#include <conio.h>
#include "general.h"

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
void initializeComputerInfo()
{
	
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
}
#endif