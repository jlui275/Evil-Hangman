#include "SDL_Plotter.h"

void plotLine(SDL_Plotter *g, int length);

void plotLine(SDL_Plotter *g, int length, bool *sizeArray)
{

    int y = 500;
    int newChar = 5;

    for(int j = 0; j <= 21; j++)
    {
        if(sizeArray[j] == 1)
        {
            for(int i = 0; i <= 25; i++)
            {
                g->plotPixel(i+newChar, y, 0, 0, 0);
            }
        }
        newChar += 30;
    }

    g->update();
}
