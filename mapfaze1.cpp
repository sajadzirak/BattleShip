
#include "match.h"
#include "gamesetting.h"

int main()
{
    intro();
    switch (menu())
    {
    case 1:
        if (startNewGame() == 0)
            menu();
        break;
    case 2:
        if (setting() == 0)
            menu();
        break;
    case 3:
        return 0;
        break;
    }
}