#ifndef gameData
#define gameData

#include <stdio.h>
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
ALLEGRO_SAMPLE *repairSound;
ALLEGRO_SAMPLE *backgroundMusic;
int soundEffectSw = 1;
int musicSw = 1;
FILE *input;
struct ships
{
    int length=3;
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

void saveGame() {
    FILE* saveGameData = fopen("gameData.dat", "wb");
    fwrite(&n, sizeof(int), 1, saveGameData);
    fwrite(&nship, sizeof(int), 1, saveGameData);
    fwrite(&ncell, sizeof(int), 1, saveGameData);
    fwrite(&gameType, sizeof(int), 1, saveGameData);
    fwrite(&playerTurn, sizeof(int), 1, saveGameData);
    fwrite(mapPlayer1, sizeof(int), 144, saveGameData);
    fwrite(mapPlayer2, sizeof(int), 144, saveGameData);
    fwrite(namePlayer1, sizeof(char), 20, saveGameData);
    fwrite(namePlayer2, sizeof(char), 20, saveGameData);
    fwrite(&shipPlayer1, sizeof(int), 1, saveGameData);
    fwrite(&shipPlayer2, sizeof(int), 1, saveGameData);
    fwrite(saveHits, sizeof(int), 169, saveGameData);
    fwrite(around, sizeof(int), 4, saveGameData);
    fwrite(&hitsw, sizeof(int), 1, saveGameData);
    fwrite(hitPos, sizeof(int), 2, saveGameData);
    fwrite(prevHit, sizeof(int), 2, saveGameData);
    fwrite(&soundEffectSw, sizeof(int), 1, saveGameData);
    fwrite(shipP1, sizeof(ships), 15, saveGameData);
    fwrite(shipP2, sizeof(ships), 15, saveGameData);
    fwrite(&P1, sizeof(player), 1, saveGameData);
    fwrite(&P2, sizeof(player), 1, saveGameData);
    fclose(saveGameData);
}
//-------------------------------------------------------------------

void loadGameData() {
    FILE* saveGameData = fopen("gameData.dat", "rb");
    fread(&n, sizeof(int), 1, saveGameData);
    fread(&nship, sizeof(int), 1, saveGameData);
    fread(&ncell, sizeof(int), 1, saveGameData);
    fread(&gameType, sizeof(int), 1, saveGameData);
    fread(&playerTurn, sizeof(int), 1, saveGameData);
    fread(mapPlayer1, sizeof(int), 144, saveGameData);
    fread(mapPlayer2, sizeof(int), 144, saveGameData);
    fread(namePlayer1, sizeof(char), 20, saveGameData);
    fread(namePlayer2, sizeof(char), 20, saveGameData);
    fread(&shipPlayer1, sizeof(int), 1, saveGameData);
    fread(&shipPlayer2, sizeof(int), 1, saveGameData);
    fread(saveHits, sizeof(int), 169, saveGameData);
    fread(around, sizeof(int), 4, saveGameData);
    fread(&hitsw, sizeof(int), 1, saveGameData);
    fread(hitPos, sizeof(int), 2, saveGameData);
    fread(prevHit, sizeof(int), 2, saveGameData);
    fread(&soundEffectSw, sizeof(int), 1, saveGameData);
    fread(shipP1, sizeof(ships), 15, saveGameData);
    fread(shipP2, sizeof(ships), 15, saveGameData);
    fread(&P1, sizeof(player), 1, saveGameData);
    fread(&P2, sizeof(player), 1, saveGameData);
    fclose(saveGameData);
}
//-------------------------------------------------------------------

#endif