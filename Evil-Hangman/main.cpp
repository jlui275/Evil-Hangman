#include "SDL_Plotter.h"
#include "alphabet.h"
#include "stickFigure.h"
#include "gallows.h"
<<<<<<< HEAD
#include "sizeArray.h"
=======
#include "answers.h"
>>>>>>> a4091ccf6518ecee3b4eca5148dccdd43300207f

#include <cstdlib>
#include <algorithm>

using namespace std;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

SDL_Plotter *g;

bool init();
bool loadMedia();


int main(int argc, char **argv) {
	g = new SDL_Plotter(750,1000);
/*
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else{

        if( !loadMedia() )
        {
            printf( "Failed to load media!\n");
        }
        else
        {
            while( !g->getQuit() )
            {
                SDL_BlitSurface ( gHelloWorld, NULL, gScreenSurface, NULL);
                SDL_UpdateWindowSurface( gWindow );

                if(g->kbhit())
                {
                    switch(g->getKey())
                    {
                        case 'ESC': g->setQuit(true);
			            break;
                    }
                }
            }
        }
    }
    */

    bool usedCharacters [26] = {0, 0, 0};

    while(!g->getQuit()){

        plotAlphabet(g, usedCharacters);

        plotHead(g);
        plotDeath(g);
        plotBody(g);
        plotLeftLeg(g);
        plotRightLeg(g);
        plotLeftArm(g);
        plotRightArm(g);

        plotBase(g);
        plotGallow(g);
        plotGallow1(g);
        plotGallow2(g);

        bool sizeArray [21] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
        plotLine(g, 21, sizeArray);

        if(g->kbhit()){
			switch(g->getKey()){
			    case 'ESC': g->setQuit(true);
                            break;
			}
        }
    }
    return 0;
}

/*

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_SHOWN );
        if( gWindow == NULL)
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return success;
}

//Loads images using SDL_LoadBMP
bool loadMedia()
{
    bool success = true;

    gHelloWorld = SDL_LoadBMP( "background.bmp" );
    if( gHelloWorld == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "background.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}
*/
