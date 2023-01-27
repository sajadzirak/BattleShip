#ifndef gameData
#define gameData

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

int n, nship, ncell;
int nrepair;
int gameType;
int playerTurn;
int mapPlayer1[12][12];
int mapPlayer2[12][12];
char namePlayer1[20] = "Player 1";
char namePlayer2[20] = "Player 2";
int shipPlayer1, shipPlayer2;
int saveHits[13][13] = {0};
int around[4] = { 0 };
int hitsw = 0; // 0 = didn't hit && 1 = hit
int hitPos[2]; // contains location
int prevHit[2]; // contains location

ALLEGRO_SAMPLE *fire;
ALLEGRO_SAMPLE *water;
ALLEGRO_SAMPLE *backgroundMusic;
int soundEffectSw = 1;
int musicSw = 1;
FILE *input;
struct ships
{
    int lengh=3;
    int width=1;
    char direction;
    int shipPosition[10][2] = {};
    int ncell;
    int remainCell;
    int stats = 0; // 0 means ship didn't destroy yet and 1 means ship completely destroyed
} shipP1[15], shipP2[15];

struct player
{
    char namePlayer[20] = "Player";
    struct ships ships[15];
    int nship = 0;
    int ncell = 0;
    int remainShip = 0;
    int remainRepair;
} P1, P2;

#endif