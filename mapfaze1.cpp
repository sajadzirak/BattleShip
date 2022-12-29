
#include <string.h>
#include <conio.h>
#include "general.h"
#include "scan.h"
#include "check.h"
#include "introduction.h"
#include "printing.h"
#include "match.h"
#include "gamesetting.h"

// int n, nship;
// int mapPlayer1[100][100];
// int mapPlayer2[100][100];
// char namePlayer1[20];
// char namePlayer2[20];
// int shipPlayer1, shipPlayer2;
// struct shipPosition
// {
//     int shipPosition[3][2];
// }shipPos[15];


// int startNewGame();

// void setting();
// int rematch(int);
// int scanBasicInfo(int*,int*);
// int initializeMap(int[][100], int);
// int scanPlayerInfo(int[][100], char[], int,int,int);
// int checkOverlap(int, int, char, int[][100]);
// int checkRange(int, int, char);
// int putShips(int[][100], int, int, char);
// int scanSign();
// void clearScreen();
// int printInfo(int, int, char[], char[]);
// int printMaps(int[][100], int);
// void printEnd1();
// void printEnd2();
// void bombing(int[][100], char[], char[], int *);

// void sleep(unsigned int mseconds);

// void Black(int);
// void Red(int);
// void Green(int);
// void Yellow(int);
// void Blue(int);
// void Purple(int);
// void Cyan(int);
// void White(int);
// void Reset();
// void WhiteBack();

int main()
{
    switch (animate())
    {
    case 1:
        if(startNewGame()==0)
            main();
        break;
    case 2:
        if (setting() == 0)
            main();
        break;
    case 3:
        return 0;
        break;
    }
}


