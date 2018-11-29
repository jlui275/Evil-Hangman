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

    //**************************************
    // Description: Get word
    // Pre-Condition: game instance exists
    // Post-Condition: word from i stream is got
    // Return: void
    //**************************************
    void getword(istream& in);

    //**************************************
    // Description: Checks to see if the process is finished
    // Pre-Condition: game instance exists
    // Post-Condition: check if process is finished.
    // Return: bool
    //**************************************
    bool checkfinished();

    //**************************************
    // Description: Sets difficulty
    // Pre-Condition: Game instance exists
    // Post-Condition: difficulty is changed
    // Return: void
    //**************************************
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
