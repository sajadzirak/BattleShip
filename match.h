#ifndef match
#define match
#include "printing.h"
#include "scan.h"
#include "introduction.h"
#include "gamesetting.h"
#include "music.h"

int repair(int, int map[][12]);
//-------------------------------------------------------------------

int bombing(int map[][12], int *ship, int playerNum)
{
    int x, i = 1, j = 1, save, midMenu;
    do       
    {
        i = random();
        j = random();
    } while (passShip(playerNum, j, i) == 1);
    clearScreen();
    save = map[i][j];
    map[i][j] = -1;
    if (playerTurn == 1)
    {
        printInfo(P2.remainShip, P1.remainRepair, P2.namePlayer, P1.namePlayer);
    }
    else
        printInfo(P1.remainShip, P2.remainRepair, P1.namePlayer, P2.namePlayer);

    printMaps(map);
    x = _getch();
    while (x != 13)
    {
        while (x != 224 && x != 13 && x != 27 && x != 8)
        {
            x = _getch();
        }
        if (x == 224)
        {
            x = _getch();
        }
        if (x == 8)  // backspace for repair
        {
            map[i][j] = save;
            if (playerNum == 1)
            {
                if (repair(2, mapPlayer2) == 1)
                {
                    return 1;
                }
                else
                {
                    clearScreen();
                    save = map[i][j];
                    map[i][j] = -1;
                    if (playerTurn == 1)
                    {
                        printInfo(P2.remainShip, P1.remainRepair, P2.namePlayer, P1.namePlayer);
                    }
                    else
                        printInfo(P1.remainShip, P2.remainRepair, P1.namePlayer, P2.namePlayer);

                    printMaps(map);
                    x = _getch();
                }
            }
            else if (playerNum == 2)
            {
                if (repair(1, mapPlayer1) == 1)
                {
                    return 1;
                }
                else
                {
                    clearScreen();
                    save = map[i][j];
                    map[i][j] = -1;
                    if (playerTurn == 1)
                    {
                        printInfo(P2.remainShip, P1.remainRepair, P2.namePlayer, P1.namePlayer);
                    }
                    else
                        printInfo(P1.remainShip, P2.remainRepair, P1.namePlayer, P2.namePlayer);

                    printMaps(map);
                    x = _getch();
                }
            }
        }
        if (x == 27)
        {
            midMenu = midGameMenu();
            if (midMenu == 1)
            {
                map[i][j] = save;
                saveGame();
                map[i][j] = -1;
            }
            while (midMenu == 2)
            {
                setting();
                midMenu = midGameMenu();
            }
            if (midMenu == 3)
                return 0;
            x = 0;
        }

        map[i][j] = save;
        if (x == 77)
        {
            if (j < n)
            {
                j++;
                while (passShip(playerNum, j, i) == 1 && j != n) 
                {
                    j++;
                }
                while (passShip(playerNum, j, i) == 1)
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
                while (passShip(playerNum, j, i) == 1 && j != 1) 
                {
                    j--;
                }
                while (passShip(playerNum, j, i) == 1)
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
                while (passShip(playerNum, j, i) == 1 && i != n)    
                {
                    i++;
                }
                while (passShip(playerNum, j, i) == 1)
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
                while (passShip(playerNum, j, i) == 1 && i != 1)     
                {
                    i--;
                }
                while (passShip(playerNum, j, i) == 1)
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
            printInfo(P2.remainShip, P1.remainRepair, P2.namePlayer, P1.namePlayer);
        }
        else
            printInfo(P1.remainShip, P2.remainRepair, P1.namePlayer, P2.namePlayer);
        printMaps(map);
    }
    if (save == -2)
    {
        if (playerTurn == 1)
        {
            hitShip(2, j, i);
            if (checkShip(2) == 1)
            {
                P2.remainShip--;
            }
        }
        else
        {
            hitShip(1, j, i);
            if (checkShip(1) == 1)
            {
                P1.remainShip--;
            }
        }
        map[i][j] = -4;
        clearScreen();
        if (playerTurn == 1)
        {
            printInfo(P2.remainShip, P1.remainRepair, P2.namePlayer, P1.namePlayer);
        }
        else
            printInfo(P1.remainShip, P2.remainRepair, P1.namePlayer, P2.namePlayer);
        printMaps(map);
        Green(1);
        printf("\n  You hit the ship!");
        Reset();
        if (soundEffectSw == 1)
            playFire();
    }
    else
    {
        map[i][j] = -3;
        clearScreen();
        if (playerTurn == 1)
        {
            printInfo(P2.remainShip, P1.remainRepair, P2.namePlayer, P1.namePlayer);
        }
        else
            printInfo(P1.remainShip, P2.remainRepair, P1.namePlayer, P2.namePlayer);
        printMaps(map);
        Red(1);
        printf("\n  You missed!");
        Reset();
        map[i][j] = save;
        if (soundEffectSw == 1)
            playWater();
    }
    sleep(4000);
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
                for (x = j, y = i; saveHits[y][x]==0 && swV == 1 && swH == 1 && x <= n && y <= n; x++, y++)
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
                else if (x == n && saveHits[y][x] == 0)
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
                else if (y == n && saveHits[y][x] == 0)
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
                else
                {
                    for (; x <= n && swV == 1; x++)
                    {
                        Vcheck(x, y, i, j, &swV);
                    }
                    x--;
                    if (swV == 0)
                    {
                        x--;
                    }
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
//void computerBombing()
//{
//    int firstX = 0, firstY = 0;
//    int lastX = 0, lastY = 0;
//    int i, j, k, save, loopsw = 1;
//    if (hitsw == 1)
//    {
//        for (k = 0; k < 4 && loopsw == 1; ++k)
//        {
//            if (around[k] == 0)
//            {
//                loopsw = 0;
//                switch (k)
//                {
//                case 0:  // right side
//                    ++prevHit[1];
//                    if (prevHit[1] > n)
//                    {
//                        around[0] = 1;
//                        if (isFinishAround() == 1)
//                        {
//                            computerBombing();
//                        }
//                        resetPrevHit();
//                        loopsw = 1;
//                    }
//                    else if (checkHit(prevHit[0], prevHit[1], saveHits) != 1)
//                    {
//                        saveHits[prevHit[0]][prevHit[1]] = 1;
//                        save = mapPlayer1[prevHit[0]][prevHit[1]];
//                        mapPlayer1[prevHit[0]][prevHit[1]] = -1;
//                        clearScreen();
//                        printComputerStats(0);
//                        sleep(750);
//                        clearScreen();
//                        if (save == -2)
//                        {
//                            hitShip(shipP1, prevHit[1], prevHit[0]);
//                            if (checkShip(shipP1) == 1)
//                                shipPlayer1--;
//                            mapPlayer1[prevHit[0]][prevHit[1]] = -4;
//                            printComputerStats(1);
//                            if (soundEffectSw == 1)
//                                playFire();
//                            around[1] = 1;
//                            around[3] = 1;
//                        }
//                        else
//                        {
//                            around[0] = 1;
//                            mapPlayer1[prevHit[0]][prevHit[1]] = -3;
//                            printComputerStats(-1);
//                            if (soundEffectSw == 1)
//                                playWater();
//                            mapPlayer1[prevHit[0]][prevHit[1]] = save;
//                            resetPrevHit();
//                        }
//                    }
//                    else if (checkHit(prevHit[0], prevHit[1], saveHits) == 1)
//                    {
//                        around[0] = 1;
//                        loopsw = 1;
//                        resetPrevHit();
//                    }
//                    break;
//                case 1: // up
//                    ++prevHit[0];
//                    if (prevHit[0] > n)
//                    {
//                        around[1] = 1;
//                        if (isFinishAround() == 1)
//                        {
//                            computerBombing();
//                        }
//                        resetPrevHit();
//                        loopsw = 1;
//                    }
//                    else if (checkHit(prevHit[0], prevHit[1], saveHits) != 1)
//                    {
//                        saveHits[prevHit[0]][prevHit[1]] = 1;
//                        save = mapPlayer1[prevHit[0]][prevHit[1]];
//                        mapPlayer1[prevHit[0]][prevHit[1]] = -1;
//                        clearScreen();
//                        printComputerStats(0);
//                        sleep(750);
//                        clearScreen();
//                        if (save == -2)
//                        {
//                            hitShip(shipP1, prevHit[1], prevHit[0]);
//                            if (checkShip(shipP1) == 1)
//                                shipPlayer1--;
//                            mapPlayer1[prevHit[0]][prevHit[1]] = -4;
//                            printComputerStats(1);
//                            if (soundEffectSw == 1)
//                                playFire();
//                            around[0] = 1;
//                            around[2] = 1;
//                        }
//                        else
//                        {
//                            around[1] = 1;
//                            mapPlayer1[prevHit[0]][prevHit[1]] = -3;
//                            printComputerStats(-1);
//                            if (soundEffectSw == 1)
//                                playWater();
//                            mapPlayer1[prevHit[0]][prevHit[1]] = save;
//                            resetPrevHit();
//                        }
//                    }
//                    else if (checkHit(prevHit[0], prevHit[1], saveHits) == 1)
//                    {
//                        around[1] = 1;
//                        loopsw = 1;
//                        resetPrevHit();
//                    }
//                    break;
//                case 2:  // left side
//                    --prevHit[1];
//                    if (prevHit[1] < 1)
//                    {
//                        around[2] = 1;
//                        if (isFinishAround() == 1)
//                        {
//                            computerBombing();
//                        }
//                        resetPrevHit();
//                        loopsw = 1;
//                    }
//                    else if (checkHit(prevHit[0], prevHit[1], saveHits) != 1)
//                    {
//                        saveHits[prevHit[0]][prevHit[1]] = 1;
//                        save = mapPlayer1[prevHit[0]][prevHit[1]];
//                        mapPlayer1[prevHit[0]][prevHit[1]] = -1;
//                        clearScreen();
//                        printComputerStats(0);
//                        sleep(750);
//                        clearScreen();
//                        if (save == -2)
//                        {
//                            hitShip(shipP1, prevHit[1], prevHit[0]);
//                            if (checkShip(shipP1) == 1)
//                                shipPlayer1--;
//                            mapPlayer1[prevHit[0]][prevHit[1]] = -4;
//                            printComputerStats(1);
//                            if (soundEffectSw == 1)
//                                playFire();
//                            around[1] = 1;
//                            around[3] = 1;
//                        }
//                        else
//                        {
//                            around[2] = 1;
//                            mapPlayer1[prevHit[0]][prevHit[1]] = -3;
//                            printComputerStats(-1);
//                            if (soundEffectSw == 1)
//                                playWater();
//                            mapPlayer1[prevHit[0]][prevHit[1]] = save;
//                            resetPrevHit();
//                        }
//                    }
//                    else if (checkHit(prevHit[0], prevHit[1], saveHits) == 1)
//                    {
//                        around[2] = 1;
//                        loopsw = 1;
//                        resetPrevHit();
//                    }
//                    break;
//                case 3:  // down
//                    --prevHit[0];
//                    if (prevHit[0] < 1)
//                    {
//                        around[3] = 1;
//                        if (isFinishAround() == 1)
//                        {
//                            computerBombing();
//                        }
//                        resetPrevHit();
//                        loopsw = 1;
//                    }
//                    else if (checkHit(prevHit[0], prevHit[1], saveHits) != 1)
//                    {
//                        saveHits[prevHit[0]][prevHit[1]] = 1;
//                        save = mapPlayer1[prevHit[0]][prevHit[1]];
//                        mapPlayer1[prevHit[0]][prevHit[1]] = -1;
//                        clearScreen();
//                        printComputerStats(0);
//                        sleep(750);
//                        clearScreen();
//                        if (save == -2)
//                        {
//                            hitShip(shipP1, prevHit[1], prevHit[0]);
//                            if (checkShip(shipP1) == 1)
//                                shipPlayer1--;
//                            mapPlayer1[prevHit[0]][prevHit[1]] = -4;
//                            printComputerStats(1);
//                            if (soundEffectSw == 1)
//                                playFire();
//                            around[0] = 1;
//                            around[2] = 1;
//                        }
//                        else
//                        {
//                            around[3] = 1;
//                            mapPlayer1[prevHit[0]][prevHit[1]] = -3;
//                            printComputerStats(-1);
//                            if (soundEffectSw == 1)
//                                playWater();
//                            mapPlayer1[prevHit[0]][prevHit[1]] = save;
//                            resetPrevHit();
//                        }
//                    }
//                    else if (checkHit(prevHit[0], prevHit[1], saveHits) == 1)
//                    {
//                        around[3] = 1;
//                        loopsw = 1;
//                        resetPrevHit();
//                    }
//                    break;
//                }
//                isFinishAround();
//            }
//        }
//    }
//    else
//    {
//        findCleanArea(&firstX, &firstY, &lastX, &lastY);
//        if (firstX == lastX && firstY == lastY)
//        {
//            do
//            {
//                i = random();
//                j = random();
//            } while (saveHits[i][j] != 0);
//        }
//        else
//        {
//            do
//            {
//                i = random();
//                j = random();
//            } while ((i < firstY || i > lastY) || (j < firstX || j > lastX));
//        }
//        saveHits[i][j] = 1;
//        save = mapPlayer1[i][j];
//        mapPlayer1[i][j] = -1;
//        clearScreen();
//        printInfo(shipPlayer1, namePlayer1, namePlayer2);
//        printMaps(mapPlayer1);
//        sleep(750);
//        if (save == -2)
//        {
//            hitsw = 1;
//            hitPos[0] = i;
//            hitPos[1] = j;
//            resetPrevHit();
//            resetAround(i, j);
//            hitShip(shipP1, j, i);
//            if (checkShip(shipP1) == 1)
//                shipPlayer1--;
//            mapPlayer1[i][j] = -4;
//            clearScreen();
//            printComputerStats(1);
//            if (soundEffectSw == 1)
//                playFire();
//        }
//        else
//        {
//            mapPlayer1[i][j] = -3;
//            clearScreen();
//            printComputerStats(-1);
//            mapPlayer1[i][j] = save;
//            if (soundEffectSw == 1)
//                playWater();
//        }
//    }
//    sleep(4000);
//}
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
    {
    //    clearScreen();
    }
    //scanPlayerInfo(mapPlayer2, namePlayer2, 2, shipP2);  
    gameType = 2;
    while (1)
    {
        playerTurn = 1;
        if (bombing(mapPlayer2, &shipPlayer2, 2) == 0)
            return 0;
        if (P2.remainShip == 0)
        {
            break;
        }
        playerTurn = 2;
        if (bombing(mapPlayer1, &shipPlayer1, 1) == 0)
            return 0;
        if (P1.remainShip == 0)
        {
            break;
        }
    }
    clearScreen();
    if(P1.remainShip == 0)
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
    //scanSinglePlayerByFile();    // temporary
    //initializeComputerInfo();    // temporary
    resetSaveHits();
    shipPlayer1 = nship;
    shipPlayer2 = nship;
    //resetShipsSW();
    gameType = 1;
    while (1)
    {
        playerTurn = 1;
        if (bombing(mapPlayer2, &shipPlayer2, 2)==0)
            return 0;
        if (shipPlayer2 == 0)
        {
            break;
        }
        //computerBombing(); //*****     // temporary
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
        gameType = 1;
        return singlePlayer();
    }
    else if (x == 1)
    {
        gameType = 2;
        return multiPlayer();
    }
    else
    {
        return 0;
    }
}
//----------------------------------------------------------------
int repair(int playerNum, int map[][12])
{
    if (playerNum == 1)
    {
        if (P1.remainRepair == 0)
        {
            return 0;
        }
    }
    else
    {
        if (P2.remainRepair == 0)
        {
            return 0;
        }
    }
    int x, i = 1, j = 1, k, f, save, midMenu;
    do
    {
        i = random();
        j = random();
    } while (passShip(playerNum, j, i) == 1);
    clearScreen();
    save = map[i][j];
    map[i][j] = -1;
    if (playerTurn == 1)
    {
        printInfo(P1.remainShip, P1.remainRepair, P1.namePlayer, P1.namePlayer);
    }
    else
        printInfo(P2.remainShip, P2.remainRepair, P2.namePlayer, P2.namePlayer);
    printf("  Repair Mode\n\n");
    printMaps(map);
    x = _getch();
    while (x != 13 || save != -4)
    {
        while (x != 224 && x != 13 && x != 27 && x != 8)
        {
            x = _getch();
        }
        if (x == 224)
        {
            x = _getch();
        }
        if (x == 8)  // backspace for return to bombing
        {
            map[i][j] = save;
            return 0;
        }
        if (x == 27)
        {
            midMenu = midGameMenu();
            if (midMenu == 1)
            {
                map[i][j] = save;
                saveGame();
                map[i][j] = -1;
            }
            while (midMenu == 2)
            {
                setting();
                midMenu = midGameMenu();
            }
            if (midMenu == 3)
                return 0;
            x = 0;
        }

        map[i][j] = save;
        if (x == 77)
        {
            if (j < n)
            {
                j++;
            }
        }
        else if (x == 75)
        {
            if (j > 1)
            {
                j--;
            }
        }
        else if (x == 72)
        {
            if (i < n)
            {
                i++;
            }
        }
        else if (x == 80)
        {
            if (i > 1)
            {
                i--;
            }
        }
        save = map[i][j];
        map[i][j] = -1;
        clearScreen();
        if (playerTurn == 1)
        {
            printInfo(P1.remainShip, P1.remainRepair, P1.namePlayer, P1.namePlayer);
        }
        else
            printInfo(P2.remainShip, P2.remainRepair, P2.namePlayer, P2.namePlayer);
        printf("  Repair Mode\n\n");
        printMaps(map);
    }
    if (save == -4)
    {
        if (playerNum == 1)
        {
            P1.remainRepair--;
            for (k = 0; k < P1.nship; ++k)
            {
                for (f = 0; f < P1.ships[k].ncell; ++f)
                {
                    if (P1.ships[k].shipPosition[f][0] == j && P1.ships[k].shipPosition[f][1] == i)
                    {
                        // now we found the ship
                        if (P1.ships[k].stats == 1)
                        {
                            P1.remainShip++;
                            P1.ships[k].stats = 0;
                            P1.ships[k].remainCell++;
                        }
                    }
                }
            }
        }
        else if (playerNum == 2)
        {
            P2.remainRepair--;
            for (k = 0; k < P2.nship; ++k)
            {
                for (f = 0; f < P2.ships[k].ncell; ++f)
                {
                    if (P2.ships[k].shipPosition[f][0] == j && P2.ships[k].shipPosition[f][1] == i)
                    {
                        // now we found the ship
                        if (P2.ships[k].stats == 1)
                        {
                            P2.remainShip++;
                            P2.ships[k].stats = 0;
                            P2.ships[k].remainCell++;
                        }
                    }
                }
            }
        }
        map[i][j] = -2;
        clearScreen();
        if (playerTurn == 1)
        {
            printInfo(P1.remainShip, P1.remainRepair, P1.namePlayer, P1.namePlayer);
        }
        else
            printInfo(P2.remainShip, P2.remainRepair, P2.namePlayer, P2.namePlayer);
        printf("  Repair Mode\n\n");
        printMaps(map);
        Green(1);
        printf("\n  You repaired a ship");
        Reset();
        sleep(4000);
        return 1;
    }
}
#endif
