#include "peli.h"

int main()
{
    srand(time(NULL));

    Peli peli;
    peli.initGame();

    while (peli.getPlaying())
    {
        peli.mainMenu();
    }

    return 0;
}
