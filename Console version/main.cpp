#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include "game.h"
using namespace std;
//function used for get pattern of the word



int main()
{
   ifstream in;
   in.open("WordsList.txt");
   game newgame;
  newgame.gamerun(in);
    return 0;
}

