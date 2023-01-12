#ifndef gamesetting
#define gamesetting

#include "gameColor.h"
#include "general.h"
#include <conio.h>
#include "music.h"
//-------------------------------------------------------------------
void printSetting1() {
    printf("  ");
    printf("Music");
    printf("            ");
    WhiteBack();
    Black(1);
    if (musicSw == 1)
        printf("On");
    else
        printf("Off");
    Reset();
    printf("\n");
    printf("  ");
    printf("Sound Effects    ");
    if (soundEffectSw == 1)
        printf("On\n");
    else
        printf("Off\n");
    printf("           ");
    printf("Exit");
    printf("\n");
}
//-------------------------------------------------------------------

void printSetting2() {
    printf("  ");
    printf("Music");
    printf("            ");
    if (musicSw == 1)
        printf("On");
    else
        printf("Off");
    printf("\n");
    printf("  ");
    printf("Sound Effects    ");
    WhiteBack();
    Black(1);
    if (soundEffectSw == 1)
        printf("On\n");
    else
        printf("Off\n");
    Reset();
    printf("           ");
    printf("Exit");
    printf("\n");
}
//-------------------------------------------------------------------

void printSetting3() {
    printf("  ");
    printf("Music");
    printf("            ");
    if (musicSw == 1)
        printf("On");
    else
        printf("Off");
    printf("\n");
    printf("  ");
    printf("Sound Effects    ");
    if (soundEffectSw == 1)
        printf("On\n");
    else
        printf("Off\n");
    printf("           ");
    WhiteBack();
    Black(1);
    printf("Exit");
    Reset();
    printf("\n");
}
//-------------------------------------------------------------------

void settingAction(int i,int *exit) {
    if (i == 0 && musicSw == 1)
    {
        musicSw = 0;
        destroyBackgroundMusic();
    }
    else if (i == 0 && musicSw == 0)
    {
        musicSw = 1;
        playbackgroundMusic();
    }
    else if (i == 1 && soundEffectSw == 1)
        soundEffectSw = 0;
    else if (i == 1 && soundEffectSw == 0)
        soundEffectSw = 1;
    else if (i == 2)
        *exit = 1;
}
//-------------------------------------------------------------------
int setting()
{
    int x, i = 0;
    int exit = 0;
    clearScreen();
    printSetting1();
    x = _getch();
    while (x != 27 && exit == 0)
    {
        while (x != 224 && x != 27 && x != 13)
        {
            x = _getch();
        }
        if (x == 224)
            x = _getch();
        if (x == 13)
        {
            settingAction(i, &exit);
        }
        switch (x)
        {
        case 80:
            if (i < 2)
            {
                i++;
            }
            break;
        case 72:
            if (i > 0)
            {
                i--;
            }
            break;
        case 77:
            settingAction(i, &exit);
            break;
        case 75:
            settingAction(i, &exit);
            break;
        }
        clearScreen();
        switch (i)
        {
        case 0:
            printSetting1();
            break;
        case 1:
            printSetting2();
            break;
        case 2:
            printSetting3();
            break;
        }
        if (x == 13 && exit == 0)
        {
            x = _getch();
        }
    }
    return 0;
}

#endif