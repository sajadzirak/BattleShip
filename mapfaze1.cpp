
#include "match.h"
#include "gamesetting.h"

int main()
{

    switch (menu())
    {
    case 1:
        if (startNewGame() == 0)
            main();
        break;
    case 2:
        if (setting() == 0)
            main();
        break;
    case 3:
        return 0;
        break;
    }
}