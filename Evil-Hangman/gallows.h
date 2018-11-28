#include "SDL_Plotter.h"


void plotBase(SDL_Plotter *g);
void plotGallow(SDL_Plotter *g);
void plotGallow1(SDL_Plotter *g);
void plotGallow2(SDL_Plotter *g);

void plotBase(SDL_Plotter *g)
{
    int x = 525;
    int y = 725;

    for(int i = 0; i < 450; i++)
    {
        g->plotPixel(x + i, y, 165, 42, 42);
        g->plotPixel(x + i, y + 1, 165, 42, 42);
    }

    g->update();
}

void plotGallow(SDL_Plotter *g)
{
    int x = 900;
    int y = 725;

    for(int i = 0; i < 650; i++)
    {
        g->plotPixel(x, y-i, 165, 42, 42);
        g->plotPixel(x + 1, y-i, 165, 42, 42);
    }

    g->update();
}

void plotGallow1(SDL_Plotter *g)
{
    int x = 900;
    int y = 75;

    for(int i = 0; i < 225; i++)
    {
        g->plotPixel(x - i, y, 165, 42, 42);
        g->plotPixel(x - i, y - 1, 165, 42, 42);
    }

    g->update();
}

void plotGallow2(SDL_Plotter *g)
{
    int x = 675;
    int y = 75;

    for(int i = 0; i < 75; i++)
    {
        g->plotPixel(x, y + i, 165, 42, 42);
        g->plotPixel(x + 1, y + i, 165, 42, 42);
    }

    g->update();
}
