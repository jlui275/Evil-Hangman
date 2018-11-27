#include "SDL_Plotter.h"
#include <math.h>

#define PI 3.1415926535

void plotHead(SDL_Plotter *g);
void plotBody(SDL_Plotter *g);
void plotLeftArm(SDL_Plotter *g);
void plotRightArm(SDL_Plotter *g);
void plotLeftLeg(SDL_Plotter *g);
void plotRightLeg(SDL_Plotter *g);


void plotHead(SDL_Plotter *g)
{
    int x = 500;
    int y = 500;
    int r = 100;

    //static const double PI = 3.1415926535;
    double i, angle, x1, y1;

    for(i = 0; i < 360; i += 0.1)
    {
        angle = i;
        x1 = r * cos(angle * PI / 180);
        y1 = r * sin(angle * PI / 180);
        g->plotPixel(x - x1, y + y1, 255, 0, 0);
    }
}
