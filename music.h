#ifndef music
#define music

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "gameData.h"

void must_init(bool test, const char* description)
{
    if (test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}
//------------------------------------------------------------------

void initializeMusic() {
    must_init(al_init(), "allegro");
    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codecs");
    must_init(al_reserve_samples(16), "reserve samples");
}
//------------------------------------------------------------------

void destroyMusic() {
    al_destroy_sample(fire);
    al_destroy_sample(water);
    al_destroy_sample(repairSound);
}
//-----------------------------------------------------------------

void destroyBackgroundMusic() {
    al_destroy_sample(backgroundMusic);
}
//-----------------------------------------------------------------

int playFire()
{

    fire = al_load_sample("fire.mp3");
    must_init(fire, "fire");

    al_play_sample(fire, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

    return 0;
}
//----------------------------------------------------------------------------

int playWater() {

    water = al_load_sample("water.mp3");
    must_init(water, "water");

    al_play_sample(water, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

    return 0;
}
//----------------------------------------------------------------------------
int playRepairSound() {

    repairSound = al_load_sample("repair.mp3");
    must_init(repairSound, "repair");

    al_play_sample(repairSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

    return 0;
}
//----------------------------------------------------------------------------
int playbackgroundMusic() {

    backgroundMusic = al_load_sample("backgroundMusic.mp3");
    must_init(backgroundMusic, "backgroundMusic");
    al_play_sample(backgroundMusic, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
}
#endif