#ifndef color
#define color

#include <stdio.h>

void Black(int x)
{
    if (x == 0)
        printf("\033[0;30m");
    else
        printf("\033[1;30m");
}
void Red(int x)
{
    if (x == 0)
        printf("\033[0;31m");
    else
        printf("\033[1;31m");
}
void Green(int x)
{
    if (x == 0)
        printf("\033[0;32m");
    else
        printf("\033[1;32m");
}
void Yellow(int x)
{
    if (x == 0)
        printf("\033[0;33m");
    else
        printf("\033[1;33m");
}
void Blue(int x)
{
    if (x == 0)
        printf("\033[0;34m");
    else
        printf("\033[1;34m");
}
void Purple(int x)
{
    if (x == 0)
        printf("\033[0;35m");
    else
        printf("\033[1;35m");
}
void Cyan(int x)
{
    if (x == 0)
        printf("\033[0;36m");
    else
        printf("\033[1;36m");
}
void White(int x)
{
    if (x == 0)
        printf("\033[0;37m");
    else
        printf("\033[1;37m");
}
void Reset()
{
    printf("\033[0m");
}
//----------------------------------------------------------------
void WhiteBack()
{
    printf("\e[47m");
}

#endif