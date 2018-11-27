#ifndef PATTERN_H_INCLUDED
#define PATTERN_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>


using namespace std;
//single pattern of  word list
class patternWord{
public:
    vector<string> list;
    string pat;
    int count;
    void printword();
    void updateCounter(){
        count++;
    }
    patternWord(){
        count = 0;
    }
};

//partition
class pattern{
private:
    vector<string> wordlist;
public:
    vector<patternWord> patterns;
    void readword(vector<string> word);
    void getPatterns(char key);
    void printpattern();
    void updatepattern();
    patternWord Maxset();
};
class wordLength{
public:
    vector<string> list;
    int length;
    wordLength(){
        length = 0;
    }
};


#endif // PATTERN_H_INCLUDED
