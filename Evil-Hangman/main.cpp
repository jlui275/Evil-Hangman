#include "SDL_Plotter.h"
#include "alphabet.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

SDL_Plotter *g;
int *data;
const int SPEED = 0;
bool TRACE = false;

void plotData();
bool init();
bool loadMedia();


int main(int argc, char **argv) {
	g = new SDL_Plotter(750,1000);
/*    data = new int[g->getCol()];


    for(int i =0; i < g->getCol(); i++){
		data[i] = rand()%g->getCol();
	}

	while(!g->getQuit()){

		if(g->kbhit()){
			switch(g->getKey()){
			    case 'B': BubbleSort();
			              break;
			    case 'R': RandomizeData();
			              break;
			    case 'S': SelectionSort();
			              break;
			    case 'I': InsertionSort();;
			              break;
			    case 'H': HeapSort();
			              break;
			    case 'Q': QuickSort(0, g->getCol());
			              break;
			    case 'M': MergeSort(0, g->getCol());
			              break;
			    case 'T': TRACE = !TRACE;
			              break;
			    case 'C': g->clear();
			              break;
			    case 'X': g->setQuit(true);
			              break;
			}
		}
		plotData();
	}

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

    while(!g->getQuit()){

        plotA(g);

        if(g->kbhit()){
			switch(g->getKey()){
			    case 'Q': g->setQuit(true);
                            break;
			}
        }
    }
    return 0;
}

// main draw function, gets called over and over, as fast as possible
void plotData(){
	  if(!TRACE) g->clear();
	  for(int i = 0; i < g->getCol();i++){
		  g->plotPixel(i,data[i],0,0,0);

		  if(i + 1 < g->getCol()) g->plotPixel(i+1,data[i],0,0,0);
		  if(i - 1 >= 0) g->plotPixel(i-1,data[i],0,0,0);
		  if(data[i] + 1 < g->getCol()) g->plotPixel(i,data[i]+1,0,0,0);
		  if(data[i] - 1 >= 0)g->plotPixel(i,data[i]-1,0,0,0);
	  }
	  g->update();
	  g->Sleep(SPEED);
}

/*
void plotA(){
    if(!TRACE) g-> clear();
    for(int i = 1; i <= 25; i++)
    {
        g->plotPixel(i, ((g->getRow() - 2*i) - 1), 255, 0, 0);
        g->plotPixel(i, (g->getRow() - 2*i), 255, 0, 0);
        g->plotPixel(i, ((g->getRow() - 2*i) + 1), 255, 0, 0);
    }

    int j = 0;
    for(int i = 25; i >= 1; i--)
    {
        g->plotPixel(i+j, (g->getRow() - 2*i) - 1, 255, 0, 0);
        g->plotPixel(i+j, g->getRow() - 2*i, 255, 0, 0);
        g->plotPixel(i+j, (g->getRow() - 2*i) + 1, 255, 0, 0);
        j += 2;
    }

    for(int i = 10; i < 40; i++)
    {
        g->plotPixel(i, (g->getRow() - 16) - 1, 255, 0, 0);
        g->plotPixel(i, g->getRow() - 16, 255, 0, 0);
        g->plotPixel(i, (g->getRow() - 16) + 1, 255, 0, 0);
    }

    g->update();
    g->Sleep(SPEED);
}

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
