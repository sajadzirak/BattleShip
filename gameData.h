#ifndef gameData
#define gameData

int n, nship;
int mapPlayer1[100][100];
int mapPlayer2[100][100];
char namePlayer1[20] = "Player 1";
char namePlayer2[20] = "Player 2";
int shipPlayer1, shipPlayer2;
int saveHits[11][11] = {0};
int soundEffectSw = 1;
int musicSw = 1;
FILE *input;
struct ships
{
    int lengh=3;
    int width=1;
    int shipPosition[3][2] = {};
    int sw[3] = {1, 1, 1};
} shipP1[15], shipP2[15];

#endif