#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include "game.h"
#include "SDL_Plotter.h"
#include "alphabet.h"
#include "stickFigure.h"
#include "gallows.h"
using namespace std;
//function used for get pattern of the word
void drawRightPart(SDL_Plotter* g, int guess);
void clearBody(SDL_Plotter* g);
int main(int argv, char** args)
{
    ifstream in;
    //input word
    in.open("WordsList.txt");
    SDL_Plotter *g;
    g = new SDL_Plotter(750,1000);
    game *newgame = new game;
    char length;
    char guess;

    while (!g->getQuit()){
        //plot main part of the game
        clearBody(g);
        newgame->gamereset();
        //read in and partion word based on length
       newgame->getword(in);
       drawRightPart(g,newgame->remainguess);
        bool findlength = false;
        while (!findlength){
            cout <<"choose the length of the word"<< endl;
        //get the word length and change the current list to word with that size
        //convert read length  in char to int
        string length = "";
        bool lengthCorrect = false;
        while(!lengthCorrect){
            if (g->kbhit()){
                switch(g->getKey()){
			    case '1': length+='1';
                        cout <<'1';
			              break;
			    case '2': length+='2';
			              cout <<'2';
			              break;
			    case '3': length+='3';
			              cout <<'3';
			              break;
			    case '4': length+='4';
			              cout <<'4';
			              break;
			    case '5': length+='5';
                        cout <<'5';
			              break;
			    case '6': length+='6';
                        cout <<'6';
			              break;
			    case '7': length+='7';
                          cout <<'7';
			              break;
			    case '8': length+='8';
			              cout <<'8';
			              break;
			    case '9': length+='9';
			              cout <<'9';
			              break;
			    case '0':length+='0';
			              cout <<'0';
			              break;
                case SDL_SCANCODE_RETURN:lengthCorrect = true;
			              break;
                 }

            }
        }
        cout << endl;
        newgame->wordlength = stoi(length);
         for (int j = 0; j < newgame->totalword.size();j++){
            if (  newgame->wordlength ==  newgame->totalword[j].length){
                newgame->wordlist = newgame->totalword[j].list;
                findlength = true;
            }
        }
        newgame->solution = "";
        for (int i =0;i < newgame->wordlength;i++){
        newgame->solution += '-';
        }
         if (!findlength){
            cout << " we dont have word this length" << endl;
        }
    }

        //convert guess chance
      /*  cout <<"choose how many guess you want have" << endl;
        string guess = "";
        bool guessTest = false;
        while(!guessTest){
            if (g->kbhit()){
                switch(g->getKey()){
			    case '1': guess+='1';
                        cout <<'1';
			              break;
			    case '2': guess+='2';
			              cout <<'2';
			              break;
			    case '3': guess+='3';
			              cout <<'3';
			              break;
			    case '4': guess+='4';
			              cout <<'4';
			              break;
			    case '5': guess+='5';
                        cout <<'5';
			              break;
			    case '6': guess+='6';
                        cout <<'6';
			              break;
			    case '7': guess+='7';
                          cout <<'7';
			              break;
			    case '8': guess+='8';
			              cout <<'8';
			              break;
			    case '9': guess+='9';
			              cout <<'9';
			              break;
			    case '0':guess+='0';
			              cout <<'0';
			              break;
                case SDL_SCANCODE_RETURN:guessTest = true;
			              break;
                 }
            }
        }
        cout << endl;
        newgame->remainguess = stoi(guess);*/
        newgame->calulateDiffculty();
        //print solution and remaining guess
        //---replace---//
        cout << "current Solution is " << newgame->solution << endl;
        cout << "remaining guess is " << newgame->remainguess << endl;

       while (!newgame->checkfinished() && newgame->remainguess > 0) {
           char key;
            bool guesscorrect = false;
             bool alreadydone = false;
             while (!alreadydone){
                if (g->kbhit()){
                key = g->getKey();
                 alreadydone = newgame->inputchar(key);
                }
            }
           updateAlphabe(g,newgame->letterguessed);
           guesscorrect = newgame->updateSol();
            cout << "current Solution is " << newgame->solution << endl;
            if (!guesscorrect) {
                newgame->remainguess--;
                drawRightPart(g,newgame->remainguess);
            }

        cout << "remaining guess is " << newgame->remainguess << endl;

     }
       if (newgame->checkfinished() == true) {
            cout << "you successfully find the word" << endl;
        } else {
            cout << "you failed guess the word" << endl;
            cout << "the actual word  we have is " << newgame->getresult()<<endl;
            cout <<endl;
            cout <<endl;
            cout <<endl;
            cout <<endl;
        }
        bool gameContinue = false;
        cout <<"do you want to try again" << endl;
        while(!gameContinue){
            if (g->kbhit()){
                if(g->getKey() == SDL_SCANCODE_RETURN){
                    gameContinue = true;
                }
            }
        }
    }
    return 0;
}
void drawRightPart(SDL_Plotter *g,int guess){
    if (guess == 6){
        plotBase(g);
        plotGallow(g);
        plotGallow1(g);
        plotGallow2(g);
    }else if (guess == 5){
         plotHead(g);
         plotSadness(g);
    }else if (guess == 3){
         plotLeftArm(g);
    }else if (guess == 2){
         plotRightArm(g);
    }else if (guess == 1){
         plotLeftLeg(g);
    }else if (guess == 0){
        plotRightLeg(g);
         plotDeath(g);
    }else if (guess == 4){
        plotBody(g);
    }
    g->update();
}
void clearBody(SDL_Plotter *g){
    g->clear();
    plotAlphabet(g);
}
