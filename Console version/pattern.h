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

    //**************************************
    // Description: Will print the word
    // Pre-Condition: Game instance exists
    // Post-Condition: Word is printed
    // Return: void
    //**************************************
    void printword();

    //**************************************
    // Description: Updates the Counter
    // Pre-Condition: Counter and game instance exists
    // Post-Condition: counter is updated
    // Return: void
    //**************************************
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

    //**************************************
    // Description: Read the word from the word vector
    // Pre-Condition: game instance exists
    // Post-Condition: word is read
    // Return: void
    //**************************************
    void readword(vector<string> word);

    //**************************************
    // Description: Read word and partition into patters
    // Pre-Condition: char must be entered
    // Post-Condition: game instance exists
    // Return: void
    //**************************************
    void getPatterns(char key);

    //**************************************
    // Description: Prints patterns
    // Pre-Condition: game instance exists
    // Post-Condition: pattern is printed
    // Return: void
    //**************************************
    void printpattern();

    //**************************************
    // Description: update current pattern
    // Pre-Condition: game instance exists
    // Post-Condition: current pattern is updated
    // Return: void
    //**************************************
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
