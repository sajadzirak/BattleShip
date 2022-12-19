#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>

int n, nship;
int mapPlayer1[100][100];
int mapPlayer2[100][100];
char namePlayer1[20];
char namePlayer2[20];

int scanBasicInf();
int initializeMap(int[][100], int);
int scanPlayerInf(int[][100], char[], int);
int checkOverlap(int, int, char, int[][100]);
int checkRange(int, int, char);
int putShips(int[][100], int, int, char);
int scanSign();
void clearScreen();
int printInf(int, int);
int printMaps(int[][100], int[][100], int);
void Black(int);
void Red(int);
void Green(int);
void Yellow(int);
void Blue(int);
void Purple(int);
void Cyan(int);
void White(int);
void Reset();
void WhiteBack();
void sleep(unsigned int mseconds);
void intro();
void printShip();
void wave1();
void wave2();
void wave3();
void animate();

int main()
{
    intro();
    animate();
    clearScreen();
    scanBasicInf();
    initializeMap(mapPlayer1, n);
    initializeMap(mapPlayer2, n);
    scanPlayerInf(mapPlayer1, namePlayer1, 1);
    if (scanSign()==1){
        clearScreen();
    }
    scanPlayerInf(mapPlayer2, namePlayer2, 2);
    clearScreen();
    printInf(nship, n);
    printMaps(mapPlayer1, mapPlayer2, n);
    return 0;
}

//-------------------------------------------------------------------

int scanBasicInf()
{
    White(1);
    printf("Give the map's size: ");
    Green(0);
    scanf("%d", &n);
    White(1);
    printf("How many ships are there?: ");
    Green(0);
    scanf("%d", &nship);
    Reset();
    return 0;
}

//-------------------------------------------------------------------

int initializeMap(int map[][100], int n)
{
    int i, j;
    for (i = 0, j = 0; j < n; j++)
    {
        map[i][j] = j + 1;
    }
    for (i = 1; i <= n; i++)
    {
        map[i][0] = i;
        for (j = 1; j < n; j++)
        {
            map[i][j] = 0;
        }
    }
    return 0;
}

//-------------------------------------------------------------------

int scanPlayerInf(int map[][100], char name[], int playerNum)
{
    int i, j, k;
    char direction;
    White(1);
    printf("Name and locations for player %d: \n", playerNum);
    Blue(1);
    scanf("%s", name);
    for (k = 0; k < nship; k++)
    {
        Red(1);
        scanf("%d %d %c", &j, &i,&direction);
        if (checkOverlap(i, j, direction, map) == 1 && checkRange(i, j, direction) == 1)
        {
            putShips(map, i, j, direction);
        }
        else
            k--;
    }
    White(1);
    printf("Name and locations received for player %d.\n",playerNum);
    Reset();
    return 0;
}

//-------------------------------------------------------------------

int checkOverlap(int i, int j, char direction, int map[][100])
{
    int sw = 1, p;
    if (direction == 'v')
    {
        for (p = 0; p < 3 && sw == 1; p++, i++)
        {
            if (map[i][j] == -2)
            {
                White(1);
                printf("Ships overlap with each other. Please input another location.\n");
                Reset();
                sw = 0;
            }
        }
    }
    else if (direction == 'h')
    {
        for (int p = 0; p < 3 && sw == 1; ++p, j++)
        {
            if (map[i][j] == -2)
            {
                White(1);
                printf("Ships overlap with each other. Please input another location.\n");
                Reset();
                sw = 0;
            }
        }
    }
    else
    {
        White(1);
        printf("Direction is not valid. Please input the correct direction (v/h)\n");
        Reset();
        sw = 0;
    }
    return sw;
}
//-------------------------------------------------------------------
int checkRange(int i, int j, char direction)
{
    int sw = 1;
    if ((i + 2 > n && direction == 'v') || (j + 2 > n && direction == 'h'))
    {
        White(1);
        printf("Ships are out of range. Please input another location.\n");
        Reset();
        sw = 0;
    }
    return sw;
}
//-------------------------------------------------------------------

int putShips(int map[][100], int i, int j, char direction)
{
    int k = 0;
    for (k = 0; k < 3; k++)
    {
        map[i][j] = -2;
        if (direction == 'v')
            i++;
        else
            j++;
    }
    return 0;
}

//-------------------------------------------------------------------

int scanSign()
{
    int i;
    char sign[5];
    White(1);
    printf("input the sign( < --- > for pass to player 2)\n");
    scanf("%s", sign); // scanf for '---'
    Reset();
    for (i = 0; i < 3 && sign[i] == '-'; i++);
    if (i == 3)
    {
        return 1;
    }else scanSign();
    // May be used for phase 6
    // for ( i = 0; i < 3 && sign[i]=='$'; i++)
    // {
    //     return 2;
    // }
    return 0;
}

//-------------------------------------------------------------------
void clearScreen(){
    system("cls");
}
//-------------------------------------------------------------------
int printInf(int ships, int n)
{
    int i;
    Blue(1);
    printf(" %s",namePlayer1);
    for (i = 0; i < 2 * n + 19-strlen(namePlayer1); i++)
    {
        printf(" ");
    }
    printf(" %s\n\n",namePlayer2);
    White(1);
    printf(" remaining ships: %d", ships);
    for (i = 0; i <= 2 * n; i++)
    {
        printf(" ");
    }
    printf(" remaining ships: %d\n\n", ships);
    Reset();
    return 0;
}

//-------------------------------------------------------------------

int printMaps(int map1[][100], int map2[][100], int n)
{
    int i, j;
    for (i = n; i > 0; i--)
    {
        // p1 map
        for (j = 0; j <= n; j++)
        {
            switch (map1[i][j])
            {
            case 0:
                Cyan(1);
                WhiteBack();
                printf("~ ");
                Reset();
                break;
            case -1:
                printf("* ");
                break;
            case -2:
                Red(1);
                WhiteBack();
                printf("> ");
                Reset();
                break;
            default:
                if (n > 9)
                {
                    if (i > 9)
                    {
                        Yellow(1);
                        printf("%d ", map1[i][j]);
                        Reset();
                    }
                    else
                    {
                        Yellow(1);
                        printf("%d  ", map1[i][j]);
                        Reset();
                    }
                }
                else
                {
                    Yellow(1);
                    printf("%d ", map1[i][j]);
                    Reset();
                }

                break;
            }
        }
        // space between p1 and p2
        for (j = 0; j < 18; j++)
            printf(" ");
        // p2 map
        for (j = 0; j <= n; j++)
        {
            switch (map2[i][j])
            {
            case 0:
                Cyan(1);
                WhiteBack();
                printf("~ ");
                Reset();
                break;
            case -1:
                printf("* ");
                break;
            case -2:
                Red(1);
                WhiteBack();
                printf("> ");
                Reset();
                break;
            default:
                if (n > 9)
                {
                    if (i > 9)
                    {
                        Yellow(1);
                        printf("%d ", map2[i][j]);
                        Reset();
                    }
                    else
                    {
                        Yellow(1);
                        printf("%d  ", map2[i][j]);
                        Reset();
                    }
                }
                else
                {
                    Yellow(1);
                    printf("%d ", map2[i][j]);
                    Reset();
                }
                break;
            }
        }
        printf("\n");
    }
    if (n > 9)
    {
        printf("  ");
    }
    else
    {
        printf(" ");
    }

    // numbers at the bottom of the graph p1
    for (i = 0, j = 0; j < n; j++)
    {
        Yellow(1);
        printf(" %d", map1[i][j]);
        Reset();
    }
    // space between p1 and p2
    if (n > 9)
    {
        for (i = 0; i < 20; i++)
            printf(" ");
    }
    else
    {
        for (i = 0; i < 20; i++)
            printf(" ");
    }
    // numbers at the bottom of the graph p2
    for (i = 0, j = 0; j < n; j++)
    {
        Yellow(1);
        printf(" %d", map2[i][j]);
        Reset();
    }
    return 0;
}
//-----------------------------------------------------
void Black(int x){
    if (x == 0)
        printf("\033[0;30m");
    else
        printf("\033[1;30m");
}
void Red(int x){
    if (x == 0)
        printf("\033[0;31m");
    else
        printf("\033[1;31m");
}
void Green(int x){
    if (x == 0)
        printf("\033[0;32m");
    else
        printf("\033[1;32m");
}
void Yellow(int x){
    if (x == 0)
        printf("\033[0;33m");
    else
        printf("\033[1;33m");
}
void Blue(int x){
    if (x == 0)
        printf("\033[0;34m");
    else
        printf("\033[1;34m");
}
void Purple(int x){
    if (x == 0)
        printf("\033[0;35m");
    else
        printf("\033[1;35m");
}
void Cyan(int x){
    if (x == 0)
        printf("\033[0;36m");
    else
        printf("\033[1;36m");
}
void White(int x){
    if (x == 0)
        printf("\033[0;37m");
    else
        printf("\033[1;37m");
}
void Reset(){
    printf("\033[0m");
}
//----------------------------------------------------------------
void WhiteBack(){
    printf("\e[47m");
}
//----------------------------------------------------------------
void sleep(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while(goal > clock());
}
//----------------------------------------------------------------
void intro(){
    printf("______       _   _   _        _____ _     _  \n");
    printf("| ___ \\     | | | | | |      /  ___| |   (_) \n");
    printf("| |_/ / __ _| |_| |_| | ___  \\ `--.| |__  _ _ __  \n");
    printf("| ___ \\/ _` | __| __| |/ _ \\  `--. \\ '_ \\| | '_ \\ \n");
    printf("| |_/ / (_| | |_| |_| |  __/ /\\__/ / | | | | |_) | \n");
    printf("\\____/ \\__,_|\\__|\\__|_|\\___| \\____/|_| |_|_| .__/ \n");
    printf("                                           | | \n");
    printf("                                           |_| \n");
    printf("\n");
    printf("Developed by Reza Mansouri && Sajad Zirak");
    sleep(5000);
}
//----------------------------------------------------------------
void printShip(){
    printf("         ,|                                          \n");
    printf("     -#=(  )=#-                                      \n");
    printf("       _:||_                                         \n");
    printf("     /       \\                                      \n");
    printf("     \\=======/                                      \n");
    printf("      |     |                                        \n");
    printf("      |     |                                        \n");
    printf("      |_____|__________________________________      \n");
    printf("     |__                                     __|     \n");
    printf("        \\                                   /       \n");
    printf("         \\                                 /        \n");
    printf("          \\__                           __/         \n");
    printf("             \\                         /            \n");
}
//-------------------------------------------------------------------
void wave1(){
    system("cls");
    printf("Press any key to start the game.\n\n");
    printShip();
    printf("     .~  .~~._                    __  \n");
    printf("   .'  .'     '~.              .-'  '-.    \n");
    printf("                 __                     \n");
    printf("            ..-~'  '~-..         _.-~'~-._             \n");
    printf("                              .-'         '-.           \n");
}
//-------------------------------------------------------------------
void wave2(){
    system("cls");
    printf("Press any key to start the game.\n\n");
    printShip();
    printf("                    __                 .~  .~~._                \n");
    printf("                 .-'  '-.            .'  .'     '~.                     \n");
    printf("                                              __           \n");
    printf("                   _.-~'~-._             ..-~'  '~-..               \n");
    printf("                .-'         '-.                         \n");
}
//-------------------------------------------------------------------
void wave3(){
    system("cls");
    printf("Press any key to start the game.\n\n");
    printShip();
    printf("     __                    .~  .~~._                            \n");
    printf("  .-'  '-.               .'  .'     '~.                                 \n");
    printf("                                  __                       \n");
    printf("     _.-~'~-._               ..-~'  '~-..                           \n");
    printf("  .-'         '-.                                       \n");
}
//-------------------------------------------------------------------
void animate(){
    while(_kbhit() == 0){
        wave1();
        sleep(500);
        wave2();
        sleep(500);
        wave3();
        sleep(500);
  }
}
