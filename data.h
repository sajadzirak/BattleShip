#ifndef data
#define data

int n, nship;
int mapPlayer1[100][100];
int mapPlayer2[100][100];
char namePlayer1[20]="Player 1";
char namePlayer2[20]="Player 2";
int shipPlayer1, shipPlayer2;
int saveHits[13][13] = {0};
int around[4] = {0};
int hitsw = 0; // 0 = didn't hit && 1 = hit
int previousPos[2];  // previousPos[0] = i && previousPos[1] = j

struct shipPosition
{
    int shipPosition[3][2];
    int sw[3]={1,1,1};
}shipPosP1[15],shipPosP2[15];



#endif