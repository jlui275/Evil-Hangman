//
// Created by Xiang_Gao on 11/18/2018.
//

#ifndef GROUPROJECT_GAME_H
#define GROUPROJECT_GAME_H

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
private:
    vector<string> wordlist;
    vector<wordLength> totalword;
    bool updateSol();
    int wordlength;
    int remainguess;
    vector<char> letterguessed;
    void getword(istream& in);
    bool checkfinished();
    void getset();
    void calulateDiffculty();
public:
    string solution;
    game(){
        solution = "----";
        wordlength = 4;
        remainguess = 10;
    }
    void inputchar();
    void gamerun(istream& in);
    string getresult();
};
#endif //GROUPROJECT_GAME_H
