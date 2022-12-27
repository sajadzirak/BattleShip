#ifndef gamesetting
#define gamesetting
#include"color.h"
#include"general.h"
#include<conio.h>

int setting()
{
    clearScreen();
    int x, i = 0;
    int sw1 = 1, sw2 = 1;
    int exit = 0;
    printf("  ");
    printf("Music");
    printf("            ");
    WhiteBack();
    if (sw1 == 1)
        printf("On");
    else
        printf("Off");
    Reset();
    printf("\n");
    printf("  ");
    printf("Sound Effects    ");
    if (sw2 == 1)
        printf("On\n");
    else
        printf("Off\n");
    printf("           ");
    printf("Exit");
    printf("\n");
    x = getch();
    while (x != 27 && exit == 0)
    {
        while (x != 224 && x != 27 && x != 13)
        {
            x = getch();
        }
        if (x == 224)
            x = getch();
        if (x == 13)
        {
            if (i == 0 && sw1 == 1)
                sw1 = 0;
            else if (i == 0 && sw1 == 0)
                sw1 = 1;
            else if (i == 1 && sw2 == 1)
                sw2 = 0;
            else if (i == 1 && sw2 == 0)
                sw2 = 1;
            else if (i == 2)
            {
                exit = 1;
            }
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
            if (i == 0 && sw1 == 1)
                sw1 = 0;
            else if (i == 0 && sw1 == 0)
                sw1 = 1;
            else if (i == 1 && sw2 == 1)
                sw2 = 0;
            else if (i == 1 && sw2 == 0)
                sw2 = 1;
            break;
        case 75:
            if (i == 0 && sw1 == 1)
                sw1 = 0;
            else if (i == 0 && sw1 == 0)
                sw1 = 1;
            else if (i == 1 && sw2 == 1)
                sw2 = 0;
            else if (i == 1 && sw2 == 0)
                sw2 = 1;
            break;
        }
        clearScreen();
        switch (i)
        {
        case 0:
            printf("  ");
            printf("Music");
            printf("            ");
            if (sw1 == 1)
            {
                WhiteBack();
                printf("On");
            }
            else
            {
                WhiteBack();
                printf("Off");
            }
            Reset();
            printf("\n");
            printf("  ");
            printf("Sound Effects    ");
            if (sw2 == 1)
                printf("On\n");
            else
                printf("Off\n");
            printf("           ");
            printf("Exit");
            printf("\n");
            break;
        case 1:
            printf("  ");
            printf("Music");
            printf("            ");
            if (sw1 == 1)
                printf("On");
            else
                printf("Off");
            printf("\n");
            printf("  ");
            printf("Sound Effects    ");
            WhiteBack();
            if (sw2 == 1)
                printf("On\n");
            else
                printf("Off\n");
            Reset();
            printf("           ");
            printf("Exit");
            printf("\n");
            break;
        case 2:
            printf("  ");
            printf("Music");
            printf("            ");
            if (sw1 == 1)
                printf("On");
            else
                printf("Off");
            printf("\n");
            printf("  ");
            printf("Sound Effects    ");
            if (sw2 == 1)
                printf("On\n");
            else
                printf("Off\n");
            printf("           ");
            WhiteBack();
            printf("Exit");
            Reset();
            printf("\n");
            break;
        }
        if (x == 13 && exit == 0)
        {
            x = getch();
        }
    }
    return 0;
}

#endif