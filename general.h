#ifndef general
#define general

#include <time.h>
#include <stdlib.h>
#include "data.h"

void clearScreen()
{
	system("cls");
}
//------------------------------------------------
void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock())
		;
}
//------------------------------------------------
void randomSeed()
{
	time_t x;
	x = time(NULL);
	srand(x);
}
//------------------------------------------------
int random()
{
	// This function return a random int between 1 and n
	int i;
	i = rand() % n + 1;
	return i;
}

#endif