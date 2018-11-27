#include "SDL_Plotter.h"


void plotBase(SDL_Plotter *g);
void plotGallow(SDL_Plotter *g);
void plotGallow1(SDL_Plotter *g);
void plotGallow2(SDL_Plotter *g);


/*
 * description: Plots the base of the gallow
 * return: void
 * precondition: SDL Plotter object is valid
 * postcondition: The base of the gallow is plotted to the SDL window
 *
*/

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

/*
 * description: Plots the upright of the gallow
 * return: void
 * precondition: SDL Plotter object is valid
 * postcondition: The upright of the gallow is plotted to the SDL window
 *
*/

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

/*
 * description: Plots the overhang of the gallow
 * return: void
 * precondition: SDL Plotter object is valid
 * postcondition: The overhang of the gallow is plotted to the SDL window
 *
*/

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

/*
 * description: Plots the rope of the gallow
 * return: void
 * precondition: SDL Plotter object is valid
 * postcondition: The rope of the gallow is plotted to the SDL window
 *
*/

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
