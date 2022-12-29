#ifndef data
#define data

int n, nship;
int mapPlayer1[100][100];
int mapPlayer2[100][100];
char namePlayer1[20];
char namePlayer2[20];
int shipPlayer1, shipPlayer2;
struct shipPosition
{
    int shipPosition[3][2];
    int sw[3]={1,1,1};
}shipPosP1[15],shipPosP2[15];


#endif