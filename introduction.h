#ifndef introduction
#define introduction

#include "gameColor.h"
#include "general.h"
#include <conio.h>
//-------------------------------------------------------------------

int hitButton(int *i, int min, int max)
{
    int x;
    if (_kbhit())
    {
        x = _getch();
        if (x == 224)
        {
            x = _getch();
        }
        switch (x)
        {
        case 77: // right

            break;
        case 75: // left

            break;
        case 72: // up
            if (*i > min)
                *i = *i - 1;
            break;
        case 80: // down
            if (*i < max)
            {
                *i = *i + 1;
            }
            break;
        case 13:
            return *i;
        }
    }
    return -1;
}
//-------------------------------------------------------------------------

void intro()
{
    clearScreen();
    printf("\n");
    Green(0);
    printf("  ______       _   _   _        _____ _     _  \n");
    printf("  | ___ \\     | | | | | |      /  ___| |   (_) \n");
    printf("  | |_/ / __ _| |_| |_| | ___  \\ `--.| |__  _ _ __  \n");
    printf("  | ___ \\/ _` | __| __| |/ _ \\  `--. \\ '_ \\| | '_ \\ \n");
    printf("  | |_/ / (_| | |_| |_| |  __/ /\\__/ / | | | | |_) | \n");
    printf("  \\____/ \\__,_|\\__|\\__|_|\\___| \\____/|_| |_|_| .__/ \n");
    printf("                                           | | \n");
    printf("                                           |_| \n");
    Reset();
    printf("\n");
    Red(0);
    printf("    Developed by Reza Mansouri && Sajad Zirak");
    Reset();
    sleep(5000);
}
//----------------------------------------------------------------

void printShip1()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               \33[47m\033[1;30mContinue\033[0m               \n");
    printf("       _:||_                  Start New Game         \n");
    printf("     /       \\                Setting                \n");
    printf("     \\=======/                Replay                   \n");
    printf("      |     |                 Exit                       \n");
    printf("      |     |                                        \n");
    printf("      |_____|_________________________________      \n");
    printf("     |__                                    __|     \n");
    printf("        \\                                  /       \n");
    printf("         \\                                /        \n");
    printf("          \\__                          __/         \n");
    printf("             \\                        /            \n");
    Reset();
}
//----------------------------------------------------------------

void printShip2()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               \033[1;30mContinue\033[0m               \n");
    printf("       _:||_                  \33[47m\033[1;30mStart New Game\033[0m         \n");
    printf("     /       \\                Setting                \n");
    printf("     \\=======/                Replay                   \n");
    printf("      |     |                 Exit                       \n");
    printf("      |     |                                        \n");
    printf("      |_____|_________________________________      \n");
    printf("     |__                                    __|     \n");
    printf("        \\                                  /       \n");
    printf("         \\                                /        \n");
    printf("          \\__                          __/         \n");
    printf("             \\                        /            \n");
    Reset();
}
//-----------------------------------------------------------------------

void printShip3()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               \033[1;30mContinue\033[0m               \n");
    printf("       _:||_                  Start New Game         \n");
    printf("     /       \\                \33[47m\033[1;30mSetting\033[0m                \n");
    printf("     \\=======/                Replay                   \n");
    printf("      |     |                 Exit                      \n");
    printf("      |     |                                        \n");
    printf("      |_____|_________________________________      \n");
    printf("     |__                                    __|     \n");
    printf("        \\                                  /       \n");
    printf("         \\                                /        \n");
    printf("          \\__                          __/         \n");
    printf("             \\                        /            \n");
    Reset();
}
//-----------------------------------------------------------------------

void printShip4()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               \033[1;30mContinue\033[0m               \n");
    printf("       _:||_                  Start New Game         \n");
    printf("     /       \\                Setting                \n");
    printf("     \\=======/                \33[47m\033[1;30mReplay\033[0m                   \n");
    printf("      |     |                 Exit                      \n");
    printf("      |     |                                        \n");
    printf("      |_____|_________________________________      \n");
    printf("     |__                                    __|     \n");
    printf("        \\                                  /       \n");
    printf("         \\                                /        \n");
    printf("          \\__                          __/         \n");
    printf("             \\                        /            \n");
    Reset();
}
//-------------------------------------------------------------------

void printShip5()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               \033[1;30mContinue\033[0m               \n");
    printf("       _:||_                  Start New Game         \n");
    printf("     /       \\                Setting                \n");
    printf("     \\=======/                Replay                   \n");
    printf("      |     |                 \33[47m\033[1;30mExit\033[0m                      \n");
    printf("      |     |                                        \n");
    printf("      |_____|_________________________________      \n");
    printf("     |__                                    __|     \n");
    printf("        \\                                  /       \n");
    printf("         \\                                /        \n");
    printf("          \\__                          __/         \n");
    printf("             \\                        /            \n");
    Reset();
}
//-------------------------------------------------------------------
void printShipStartNewGame1()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               \33[47m\033[1;30mSingle Player\033[0m          \n");
    printf("       _:||_                  Multi Player           \n");
    printf("     /       \\                Exit                        \n");
    printf("     \\=======/                                       \n");
    printf("      |     |                                        \n");
    printf("      |     |                                        \n");
    printf("      |_____|_________________________________      \n");
    printf("     |__                                    __|     \n");
    printf("        \\                                  /       \n");
    printf("         \\                                /        \n");
    printf("          \\__                          __/         \n");
    printf("             \\                        /            \n");
    Reset();
}
//-------------------------------------------------------------------
void printShipStartNewGame2()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               Single Player          \n");
    printf("       _:||_                  \33[47m\033[1;30mMulti Player\033[0m           \n");
    printf("     /       \\                Exit                        \n");
    printf("     \\=======/                                       \n");
    printf("      |     |                                        \n");
    printf("      |     |                                        \n");
    printf("      |_____|_________________________________      \n");
    printf("     |__                                    __|     \n");
    printf("        \\                                  /       \n");
    printf("         \\                                /        \n");
    printf("          \\__                          __/         \n");
    printf("             \\                        /            \n");
    Reset();
}
//-------------------------------------------------------------------
void printShipStartNewGame3()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               Single Player          \n");
    printf("       _:||_                  Multi Player           \n");
    printf("     /       \\                \33[47m\033[1;30mExit\033[0m                       \n");
    printf("     \\=======/                                       \n");
    printf("      |     |                                        \n");
    printf("      |     |                                        \n");
    printf("      |_____|_________________________________      \n");
    printf("     |__                                    __|     \n");
    printf("        \\                                  /       \n");
    printf("         \\                                /        \n");
    printf("          \\__                          __/         \n");
    printf("             \\                        /            \n");
    Reset();
}
//-------------------------------------------------------------------

void wave1()
{

    Cyan(0);
    printf("     .~  .~~._                    __                           \n");
    printf("   .'  .'     '~.              .-'  '-.                        \n");
    printf("                 __                                            \n");
    printf("            ..-~'  '~-..         _.-~'~-._                     \n");
    printf("                              .-'         '-.                  \n");
    Reset();
}
//-------------------------------------------------------------------

void wave2()
{

    Cyan(0);
    printf("                    __                 .~  .~~._               \n");
    printf("                 .-'  '-.            .'  .'     '~.            \n");
    printf("                                              __               \n");
    printf("                   _.-~'~-._             ..-~'  '~-..          \n");
    printf("                .-'         '-.                                \n");
    Reset();
}
//-------------------------------------------------------------------

void wave3()
{

    Cyan(0);
    printf("     __                    .~  .~~._                           \n");
    printf("  .-'  '-.               .'  .'     '~.                        \n");
    printf("                                  __                           \n");
    printf("     _.-~'~-._               ..-~'  '~-..                      \n");
    printf("  .-'         '-.                                              \n");
    Reset();
}
//-------------------------------------------------------------------

int printMenu()
{
    int i = 1, min, max=4;
    if (fileCheck()==1)
    {
        min = 0;
    }
    else
    {
        min = 1;
    }
    while (hitButton(&i, min, max) == -1)
    {
        clearScreen();
        switch (i)
        {
        case 0:
            printShip1();
            break;
        case 1:
            printShip2();
            break;
        case 2:
            printShip3();
            break;
        case 3:
            printShip4();
            break;
        case 4:
            printShip5();
            break;
        }
        printf("\n");
        wave1();
        sleep(500);
        if (hitButton(&i, min, max) != -1)
            break;
        clearScreen();
        switch (i)
        {
        case 0:
            printShip1();
            break;
        case 1:
            printShip2();
            break;
        case 2:
            printShip3();
            break;
        case 3:
            printShip4();
            break;
        case 4:
            printShip5();
            break;
        }
        printf("\n");
        wave2();
        sleep(500);
        if (hitButton(&i, min, max) != -1)
            break;
        clearScreen();
        switch (i)
        {
        case 0:
            printShip1();
            break;
        case 1:
            printShip2();
            break;
        case 2:
            printShip3();
            break;
        case 3:
            printShip4();
            break;
        case 4:
            printShip5();
            break;
        }
        printf("\n");
        wave3();
        sleep(500);
        if (hitButton(&i, min, max) != -1)
            break;
    }
    return i;
}

//--------------------------------------------------------------

int startNewGameMenu()
{
    int i = 0;
    while (hitButton(&i, 0, 2) == -1)
    {
        clearScreen();
        switch (i)
        {
        case 0:
            printShipStartNewGame1();
            break;
        case 1:
            printShipStartNewGame2();
            break;
        case 2:
            printShipStartNewGame3();
        }
        printf("\n");
        wave1();
        sleep(500);
        if (hitButton(&i, 0, 2) != -1)
            break;
        clearScreen();
        switch (i)
        {
        case 0:
            printShipStartNewGame1();
            break;
        case 1:
            printShipStartNewGame2();
            break;
        case 2:
            printShipStartNewGame3();
        }
        printf("\n");
        wave2();
        sleep(500);
        if (hitButton(&i, 0, 2) != -1)
            break;
        clearScreen();
        switch (i)
        {
        case 0:
            printShipStartNewGame1();
            break;
        case 1:
            printShipStartNewGame2();
            break;
        case 2:
            printShipStartNewGame3();
        }
        printf("\n");
        wave3();
        sleep(500);
        if (hitButton(&i, 0, 2) != -1)
            break;
    }
    return i;
}
//-------------------------------------------------------------------
void printMidGameMenu1() {
    printf("  ");
    WhiteBack();
    Black(1);
    printf("Continue");
    Reset();
    printf("\n  ");
    White(1);
    printf("Save Game");
    Reset();
    printf("\n  ");
    White(1);
    printf("Setting");
    Reset();
    printf("\n  ");
    White(1);
    printf("Exit");
    Reset();
    printf("\n");
}
//-------------------------------------------------------------------
void printMidGameMenu2() {
    printf("  ");
    White(1);
    printf("Continue");
    Reset();
    printf("\n  ");
    WhiteBack();
    Black(1);
    printf("Save Game");
    Reset();
    printf("\n  ");
    White(1);
    printf("Setting");
    Reset();
    printf("\n  ");
    White(1);
    printf("Exit");
    Reset();
    printf("\n");
}
//-------------------------------------------------------------------
void printMidGameMenu3() {
    printf("  ");
    White(1);
    printf("Continue");
    Reset();
    printf("\n  ");
    White(1);
    printf("Save Game");
    Reset();
    printf("\n  ");
    WhiteBack();
    Black(1);
    printf("Setting");
    Reset();
    printf("\n  ");
    White(1);
    printf("Exit");
    Reset();
    printf("\n");
}
//-------------------------------------------------------------------
void printMidGameMenu4() {
    printf("  ");
    White(1);
    printf("Continue");
    Reset();
    printf("\n  ");
    White(1);
    printf("Save Game");
    Reset();
    printf("\n  ");
    White(1);
    printf("Setting");
    Reset();
    printf("\n  ");
    WhiteBack();
    Black(1);
    printf("Exit");
    Reset();
    printf("\n");
}
//-------------------------------------------------------------------

int midGameMenu()
{
    clearScreen();
    printMidGameMenu1();
    int x, i = 0;
    x = _getch();
    while (x != 13)
    {
        while (x != 224 && x != 13)
        {
            x = _getch();
        }
        if (x == 224)
        {
            x = _getch();
        }
        switch (x)
        {
        case 72: // up
            if (i>0)
            {
                i--;
            }
            break;
        case 80: // down
            if (i<3)
            {
                i++;
            }
            break;
        }
        switch (i)
        {
        case 0:
            clearScreen();
            printMidGameMenu1();
            break;
        case 1:
            clearScreen();
            printMidGameMenu2();
            break;
        case 2:
            clearScreen();
            printMidGameMenu3();
            break;
        case 3:
            clearScreen();
            printMidGameMenu4();
            break;
        }
    }
    return i;
}
//-------------------------------------------------------------------


#endif
