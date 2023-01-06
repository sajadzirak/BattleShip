#ifndef music
#define music

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "general.h"

void must_init(bool test, const char* description)
{
    if (test) return;

    printf("couldn't initialize %s\n", description);
    sleep(3000);
    exit(1);
}

int fire()
{

    must_init(al_init(), "allegro");
    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codecs");
    must_init(al_reserve_samples(16), "reserve samples");

    ALLEGRO_SAMPLE* fire = al_load_sample("fire.mp3");
    must_init(fire, "fire");

    al_play_sample(fire, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    sleep(4000);

    al_destroy_sample(fire);
    return 0;
}
int water() {

    must_init(al_init(), "allegro");
    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codecs");
    must_init(al_reserve_samples(16), "reserve samples");

    ALLEGRO_SAMPLE* water = al_load_sample("water.mp3");
    must_init(water, "water");

    al_play_sample(water, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    sleep(2000);

    al_destroy_sample(water);
    return 0;
}

#endif