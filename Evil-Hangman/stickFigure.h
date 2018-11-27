#include "SDL_Plotter.h"
#include <math.h>

void plotHead(SDL_Plotter *g);
void plotBody(SDL_Plotter *g);
void plotLeftArm(SDL_Plotter *g);
void plotRightArm(SDL_Plotter *g);
void plotLeftLeg(SDL_Plotter *g);
void plotRightLeg(SDL_Plotter *g);


void plotHead(SDL_Plotter *g)
{
    //position for body
    int x = 250;
    int y = 250;
    int r = 100;

    static const double PI = 3.1415926535;
    double i, angle, x1, y1;

    for(i = 0; i < 360; i += 0.1)
    {
        angle = i;
        x1 = r * cos(angle * PI / 180);
        y1 = r * sin(angle * PI / 180);
        g->plotPixel(x + x1, y + y1, 255, 0, 0);
    }

    g->update();
}

void plotBody(SDL_Plotter *g)
{
    //position for body
    int x = 250;
    int y = 350;

    for(int i = 0; i < 250; i++)
    {
        g->plotPixel(x, y+i, 255, 0, 0);
        g->plotPixel(x+1, y+i, 255, 0, 0);
    }

    g->update();
}

void plotRightLeg(SDL_Plotter *g)
{
    //position for body
    int x = 250;
    int y = 600;
    int x1, y1;

    for(int i = 0; i < 100; i++)
    {
        y1 = i;
        g-> plotPixel(x + i, y + y1, 255, 0 , 0);
        g-> plotPixel((x + i) + 1, y + y1, 255, 0 , 0);
    }

    g->update();
}

void plotLeftLeg(SDL_Plotter *g)
{
    //position for body
    int x = 250;
    int y = 600;
    int x1, y1;

    for(int i = 0; i < 100; i++)
    {
        y1 = i;
        g-> plotPixel(x - i, y + y1, 255, 0 , 0);
        g-> plotPixel((x - i)+1, y + y1, 255, 0 , 0);
    }

    g->update();
}

void plotLeftArm(SDL_Plotter *g)
{
    //position for body
    int x = 250;
    int y = 400;
    int x1, y1;

    for(int i = 0; i < 100; i++)
    {
        y1 = -i;
        g-> plotPixel(x - i, y + y1, 255, 0 , 0);
        g-> plotPixel((x - i)+1, y + y1, 255, 0 , 0);
    }

    g->update();
}

void plotRightArm(SDL_Plotter *g)
{
    //position for body
    int x = 250;
    int y = 400;
    int x1, y1;

    for(int i = 0; i < 100; i++)
    {
        y1 = -i;
        g-> plotPixel(x - i, y + y1, 255, 0 , 0);
        g-> plotPixel((x - i)+1, y + y1, 255, 0 , 0);
    }

    g->update();
}
