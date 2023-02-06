#ifndef gameReplay
#define gameReplay

#include <stdio.h>
#include <conio.h>
#include "printing.h"
#include "gameData.h"
#include "general.h"

void saveInfoGameRaplay() {
    FILE* replay = fopen("replay.dat", "wb");
    fwrite(&n, sizeof(int), 1, replay);
    fwrite(&nship, sizeof(int), 1, replay);
    fwrite(&gameType, sizeof(int), 1, replay);
    fwrite(mapPlayer1, sizeof(int), 144, replay);
    fwrite(mapPlayer2, sizeof(int), 144, replay);
    fwrite(namePlayer1, sizeof(char), 20, replay);
    fwrite(namePlayer2, sizeof(char), 20, replay);
    fwrite(&shipPlayer1, sizeof(int), 1, replay);
    fwrite(&shipPlayer2, sizeof(int), 1, replay);
    fclose(replay);
}
//-------------------------------------------------------------------

void loadInfoGameRaplay(FILE* replay) {
    fread(&n, sizeof(int), 1, replay);
    fread(&nship, sizeof(int), 1, replay);
    fread(&gameType, sizeof(int), 1, replay);
    fread(mapPlayer1, sizeof(int), 144, replay);
    fread(mapPlayer2, sizeof(int), 144, replay);
    fread(namePlayer1, sizeof(char), 20, replay);
    fread(namePlayer2, sizeof(char), 20, replay);
    fread(&shipPlayer1, sizeof(int), 1, replay);
    fread(&shipPlayer2, sizeof(int), 1, replay);
}
//-------------------------------------------------------------------

void saveBoardData() {
    FILE* replay = fopen("replay.dat", "ab");
    fwrite(&playerTurn, sizeof(int), 1, replay);
    fwrite(mapPlayer1, sizeof(int), 144, replay);
    fwrite(mapPlayer2, sizeof(int), 144, replay);
    fwrite(&shipPlayer1, sizeof(int), 1, replay);
    fwrite(&shipPlayer2, sizeof(int), 1, replay);
    fclose(replay);
}
//-------------------------------------------------------------------

void loadBoardData(FILE* replay) {
    // FILE* replay = fopen("replay.dat", "rb");
    fread(&playerTurn, sizeof(int), 1, replay);
    fread(mapPlayer1, sizeof(int), 144, replay);
    fread(mapPlayer2, sizeof(int), 144, replay);
    fread(&shipPlayer1, sizeof(int), 1, replay);
    fread(&shipPlayer2, sizeof(int), 1, replay);
    //fclose(replay);
}
//-------------------------------------------------------------------

int loadReplay() {
    int x;
    int intSize = sizeof(int);
    int pageNumber = 1;
    
    FILE* replay = fopen("replay.dat", "rb");
    if (!replay) {
        printf("FIle don't open");
        exit(1);
    }
    fseek(replay, 0, SEEK_END);
    int allPages = ftell(replay);
    allPages -= (293 * sizeof(int));
    allPages -= (40 * sizeof(char));
    allPages /= (291 * sizeof(int));
    fseek(replay, 0, SEEK_SET);
    loadInfoGameRaplay(replay);
    loadBoardData(replay);
    clearScreen();
    printInfo(P2.remainShip, P2.remainRepair, P2.namePlayer, P1.namePlayer);
    printMaps(mapPlayer2);
    printf("\n page: %d of %d", pageNumber, allPages);
    while (1) {// !feof(replay)
        x = _getch();
        while (x!=224 && x!= 13 && x!= 27)
        {
            x = _getch();
        }
        if (x==224)
        {
            x = _getch();
        }
        switch (x)
        {
        case 13:
        case 77: // right
            loadBoardData(replay);
            clearScreen();
            if (playerTurn == 1)
            {
                printInfo(P2.remainShip, P2.remainRepair, P2.namePlayer, P1.namePlayer);
                printMaps(mapPlayer2);
            }
            else
            {
                printInfo(P1.remainShip, P2.remainRepair, P1.namePlayer, P2.namePlayer);
                printMaps(mapPlayer1);
            }
            if (!feof(replay))
            {
                pageNumber++;
            }
            printf("\n page: %d of %d",pageNumber,allPages);
            break;
        case 75: // left
            if(pageNumber>1)
            {
                fseek(replay, -(intSize * 291 * 2), SEEK_CUR);

                loadBoardData(replay);
                clearScreen();
                if (playerTurn == 1)
                {
                    printInfo(P2.remainShip, P1.remainRepair, P2.namePlayer, P1.namePlayer);
                    printMaps(mapPlayer2);
                }
                else
                {
                    printInfo(P1.remainShip, P2.remainRepair, P1.namePlayer, P2.namePlayer);
                    printMaps(mapPlayer1);
                }
                pageNumber--;
                printf("\n page: %d of %d", pageNumber, allPages);
            }
            break;
        case 27://escape
            return 0;
            break;
        }
    }
}
#endif