#ifndef introduction
#define introduction

#include"color.h"
#include"general.h"
#include<conio.h>

int hitButton(int *i,int min,int max)
{
    int x;
    if (kbhit())
    {
        x = getch();
        if (x == 224)
        {
            x = getch();
        }
        switch (x)
        {
        case 77: // right

            break;
        case 75: // left

            break;
        case 72: // up
            if (*i >  min)
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

void intro(){
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
    printf("     -#=(  )=#-               \033[1;30mcontinue\033[0m               \n");
    printf("       _:||_                  \e[47m\033[1;30mstart new game\033[0m         \n");
    printf("     /       \\                setting                \n");
    printf("     \\=======/                exit                   \n");
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
//-----------------------------------------------------------------------

void printShip2()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               \033[1;30mcontinue\033[0m               \n");
    printf("       _:||_                  start new game         \n");
    printf("     /       \\                \e[47m\033[1;30msetting\033[0m                \n");
    printf("     \\=======/                exit                   \n");
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
//-----------------------------------------------------------------------

void printShip3()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               \033[1;30mcontinue\033[0m               \n");
    printf("       _:||_                  start new game         \n");
    printf("     /       \\                setting                \n");
    printf("     \\=======/                \e[47m\033[1;30mexit\033[0m                   \n");
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

void printShipStartNewGame1()
{
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-               \e[47m\033[1;30mSingle Player\033[0m          \n");
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
    printf("       _:||_                  \e[47m\033[1;30mMulti Player\033[0m           \n");
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
    printf("     /       \\                \e[47m\033[1;30mExit\033[0m                       \n");
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

int animate()
{
    int i = 1;
    while (hitButton(&i,1,3) == -1)
    {
        clearScreen();
        switch (i)
        {
        case 1:
            printShip1();
            break;
        case 2:
            printShip2();
            break;
        case 3:
            printShip3();
            break;
        }
        printf("\n");
        wave1();
        sleep(500);
        if (hitButton(&i,1,3) != -1)
            break;
        clearScreen();
        switch (i)
        {
        case 1:
            printShip1();
            break;
        case 2:
            printShip2();
            break;
        case 3:
            printShip3();
            break;
        }
        printf("\n");
        wave2();
        sleep(500);
        if (hitButton(&i,1,3) != -1)
            break;
        clearScreen();
        switch (i)
        {
        case 1:
            printShip1();
            break;
        case 2:
            printShip2();
            break;
        case 3:
            printShip3();
            break;
        }
        printf("\n");
        wave3();
        sleep(500);
        if (hitButton(&i,1,3) != -1)
            break;
    }
    return i;
}

//--------------------------------------------------------------

int startNewGameMenu(){
    int i = 0;
    while (hitButton(&i,0,2) == -1)
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
        if (hitButton(&i,0,2) != -1)
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
        if (hitButton(&i,0,2) != -1)
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
        if (hitButton(&i,0,2) != -1)
            break;
    }
    return i;
    
}

#endif
