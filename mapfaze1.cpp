
#include "match.h"
#include "gamesetting.h"

int menu() {
    switch (printMenu())
    {
    case 0:
        loadGameData();
        if (loadGame() == 0) {
            menu();
        }
        break;
    case 1:
        if (startNewGame() == 0)
            menu();
        break;
    case 2:
        if (setting() == 0)
            menu();
        break;
    case 3:
        if (loadReplay()==0)
            menu();
        break;
    case 4:
        return 0;
        break;
    }
}
//---------------------------------------------------------------

int main()
{
    intro();
    initializeMusic();
    playbackgroundMusic();
    menu();
    if (musicSw==1)
    {
        destroyBackgroundMusic();
    }
    destroyMusic();
}
