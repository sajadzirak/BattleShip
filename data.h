#ifndef data
#define data

int n, nship;
int mapPlayer1[100][100];
int mapPlayer2[100][100];
char namePlayer1[20] = "Player 1";
char namePlayer2[20] = "Player 2";
int shipPlayer1, shipPlayer2;
int saveHits[13][13] = {0};
int around[4];
int hitsw = 0; // 0 = didn't hit && 1 = hit
int hitPos[2]; // contains location
int prevHit[2]; // contains location

struct ships
{
    int lengh;
    int width;
    int shipPosition[3][2];
    int sw[3] = {1, 1, 1};
} shipP1[15], shipP2[15];

#endif