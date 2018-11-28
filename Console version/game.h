#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include "pattern.h"
using namespace std;
class game{
public:
    vector<string> wordlist;
    vector<wordLength> totalword;
    bool updateSol();
    int wordlength;
    int remainguess;
    vector<char> letterguessed;
    void getword(istream& in);
    bool checkfinished();
    void calulateDiffculty();
    string solution;
    game(){
        solution = "----";
        wordlength = 4;
        remainguess = 6;
    }
    bool inputchar(char key);
    //void gamerun(istream& in);
    string getresult();
    void gamereset();
};


#endif // GAME_H_INCLUDED
