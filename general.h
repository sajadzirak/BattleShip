#ifndef general
#define general


#include<time.h>
#include<stdlib.h>

void clearScreen()
{
    system("cls");
}

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

#endif