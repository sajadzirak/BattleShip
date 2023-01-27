
#include "match.h"
#include "gamesetting.h"

int continueMultiPlayerGame() {
    if (playerTurn==1)
    {
        while (1)
        {
            playerTurn = 1;
            if (bombing(mapPlayer2, &shipPlayer2, 2) == 0)
                return 0;
            if (shipPlayer2 == 0)
            {
                break;
            }
            playerTurn = 2;
            if (bombing(mapPlayer1, &shipPlayer1, 1) == 0)
                return 0;
            if (shipPlayer1 == 0)
            {
                break;
            }
        }
    }
    else
    {
        while (1)
        {
            playerTurn = 2;
            if (bombing(mapPlayer1, &shipPlayer1, 1) == 0)
                return 0;
            if (shipPlayer1 == 0)
            {
                break;
            }
            playerTurn = 1;
            if (bombing(mapPlayer2, &shipPlayer2, 2) == 0)
                return 0;
            if (shipPlayer2 == 0)
            {
                break;
            }
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
int continueSinglePlayerGame() {
    while (1)
    {
        playerTurn = 1;
        if (bombing(mapPlayer2, &shipPlayer2, 2) == 0)
            return 0;
        if (shipPlayer2 == 0)
        {
            break;
        }
        //computerBombing(); //*****   // temporary
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
int loadGame() {
    if (gameType==1)
    {
        return continueSinglePlayerGame();
    }
    else
    {
        return continueMultiPlayerGame();
    }
    return 0;
}
int menu() {
    switch (printMenu())
    {
    case 0:
        loadGameData();
        if (loadGame() == 0) {
            menu();
        }
        break;
    case 1:
        if (startNewGame() == 0)
            menu();
        break;
    case 2:
        if (setting() == 0)
            menu();
        break;
    case 3:
        return 0;
        break;
    }
}
//---------------------------------------------------------------

int main()
{
    intro();
    initializeMusic();
    playbackgroundMusic();
    menu();
    destroyMusic();
    destroyBackgroundMusic();
}
