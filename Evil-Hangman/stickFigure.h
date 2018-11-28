#include "SDL_Plotter.h"
#include <math.h>

void plotHead(SDL_Plotter *g);
void plotSadness(SDL_Plotter *g);
void plotBody(SDL_Plotter *g);
void plotLeftArm(SDL_Plotter *g);
void plotRightArm(SDL_Plotter *g);
void plotLeftLeg(SDL_Plotter *g);
void plotRightLeg(SDL_Plotter *g);

static const int xBodyLocation = 675;

void plotHead(SDL_Plotter *g)
{
    //position for body
    int x = xBodyLocation;
    int y = 250;
    int r = 100;

    static const double PI = 3.1415926535;
    double i, angle, x1, y1;

    for(i = 0; i < 360; i += 0.1)
    {
        angle = i;
        x1 = r * cos(angle * PI / 180);
        y1 = r * sin(angle * PI / 180);
        g->plotPixel(x + x1, y + y1, 0, 0, 0);
    }

    g->update();
}

void plotSadness(SDL_Plotter *g)
{
    //plotting left eye
    g-> plotPixel((xBodyLocation - 1)-50, 224, 0, 0, 0);
    g-> plotPixel(xBodyLocation - 50, 224, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 1) - 50, 224, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 1) - 50, 225, 0, 0, 0);
    g-> plotPixel(xBodyLocation - 50, 225, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 1) - 50, 225, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 1) - 50, 226, 0, 0, 0);
    g-> plotPixel(xBodyLocation - 50, 226, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 1) - 50, 226, 0, 0, 0);

    //plotting right eye
    g-> plotPixel((xBodyLocation - 1) + 50, 224, 0, 0, 0);
    g-> plotPixel(xBodyLocation + 50, 224, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 1) + 50, 224, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 1) + 50, 225, 0, 0, 0);
    g-> plotPixel(xBodyLocation + 50, 225, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 1) + 50, 225, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 1) + 50, 226, 0, 0, 0);
    g-> plotPixel(xBodyLocation + 50, 226, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 1) + 50, 226, 0, 0, 0);

    //plotting sadness
    static const double PI = 3.1415926535;
    double i, angle, x1, y1;
    int r = 10;

    for(i = 0; i < 180; i += 0.1)
    {
        angle = i;
        x1 = r * cos(angle * PI / 180);
        y1 = r * sin(angle * PI / 180);
        g->plotPixel(xBodyLocation - x1, 275 - y1, 0, 0, 0);
    }
    g->update();
}

void plotDeath(SDL_Plotter *g)
{
    //plotting dead left eye
    g-> plotPixel(xBodyLocation - 50, 225, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 50)+1, 226, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 50)+1, 224, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 50)-1, 226, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 50)-1, 224, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 50)+2, 227, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 50)+2, 223, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 50)-2, 227, 0, 0, 0);
    g-> plotPixel((xBodyLocation - 50)-2, 223, 0, 0, 0);

    //plotting dead right eye
    g-> plotPixel(xBodyLocation + 50, 225, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 50)+1, 226, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 50)+1, 224, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 50)-1, 226, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 50)-1, 224, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 50)+2, 227, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 50)+2, 223, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 50)-2, 227, 0, 0, 0);
    g-> plotPixel((xBodyLocation + 50)-2, 223, 0, 0, 0);

    //plotting dead
    static const double PI = 3.1415926535;
    double i, angle, x1, y1;
    int r = 10;

    for(i = 0; i < 360; i += 0.1)
    {
        angle = i;
        x1 = r * cos(angle * PI / 180);
        y1 = r * sin(angle * PI / 180);
        g->plotPixel(xBodyLocation + x1, 275 + y1, 0, 0, 0);
    }
    g->update();
}

void plotBody(SDL_Plotter *g)
{
    //position for body
    int x = xBodyLocation;
    int y = 350;

    for(int i = 0; i < 250; i++)
    {
        g->plotPixel(x, y+i, 0, 0, 0);
        g->plotPixel(x+1, y+i, 0, 0, 0);
    }

    g->update();
}

void plotRightLeg(SDL_Plotter *g)
{
    //position for body
    int x = xBodyLocation;
    int y = 600;
    int y1;

    for(int i = 0; i < 100; i++)
    {
        y1 = i;
        g-> plotPixel(x + i, y + y1, 0, 0, 0);
        g-> plotPixel((x + i) + 1, y + y1, 0, 0, 0);
    }

    g->update();
}

void plotLeftLeg(SDL_Plotter *g)
{
    //position for body
    int x = xBodyLocation;
    int y = 600;
    int y1;

    for(int i = 0; i < 100; i++)
    {
        y1 = i;
        g-> plotPixel(x - i, y + y1, 0, 0, 0);
        g-> plotPixel((x - i)+1, y + y1, 0, 0, 0);
    }

    g->update();
}

void plotLeftArm(SDL_Plotter *g)
{
    //position for body
    int x = xBodyLocation;
    int y = 450;
    int y1;

    for(int i = 0; i < 100; i++)
    {
        y1 = -i;
        g-> plotPixel(x - i, y + y1, 0, 0, 0);
        g-> plotPixel((x - i)+1, y + y1, 0, 0, 0);
    }

    g->update();
}

void plotRightArm(SDL_Plotter *g)
{
    //position for body
    int x = xBodyLocation;
    int y = 450;
    int y1;

    for(int i = 0; i < 100; i++)
    {
        y1 = -i;
        g-> plotPixel(x + i, y + y1, 0, 0, 0);
        g-> plotPixel((x + i)+1, y + y1, 0, 0, 0);
    }

    g->update();
}
