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
#include "answers.h"
#include "sizeArray.h"
using namespace std;
//function used for get pattern of the word
void drawRightPart(SDL_Plotter* g, int guess);
void redrawBase(SDL_Plotter* g);
int main(int argv, char** args)
{

   SDL_Plotter *g;
    ifstream in;
    //input word
    in.open("WordsList.txt");
    g = new SDL_Plotter(750,1000);
    game *newgame = new game;
    char length;
    char guess;
    void startScreen(SDL_Plotter *g);
    g->initSound("background.wav");
    g->initSound("excellent.wav");
    g->initSound("error.wav");
    g->initSound("end.wav");
    while (!g->getQuit()){

        //start screen
         bool start = true;
        g->clear();
        drawRightPart(g,0);
        drawMessage(g,"start game ",50,300,255,0,0);
        drawMessage(g,"hit enter ",50,350,255,0,0);
       // g->quitSound("end.wav");
        g->initSound("background.wav");
        g->playSound("background.wav");
        while(start){
        if(g->kbhit()){
            if(g->getKey() ==SDL_SCANCODE_RETURN){
                g->clear();
                start = false;
                g->playSound("error.wav");
            }
            }
        }
        //plot main part of the game
        redrawBase(g);
        newgame->gamereset();
        //read in and partion word based on length
       newgame->getword(in);
       drawRightPart(g,newgame->remainguess);
        bool findlength = false;
        while (!findlength){
            clearMessage(g);
            drawMessage(g,"choose the length of the word",50,30,255,0,0);
            clearWord(g);
        //get the word length and change the current list to word with that size
        //convert read length  in char to int
        string length = "";
        bool lengthCorrect = false;
        while(!lengthCorrect){
            if (g->kbhit()){
                clearMessage(g);
                switch(g->getKey()){
			    case '1': length+='1';
                        cout <<'1';
                         plotLine(g,getCorrectSize(1));
			              break;
			    case '2': length+='2';
			              cout <<'2';
			               plotLine(g,getCorrectSize(2));
			              break;
			    case '3': length+='3';
			              cout <<'3';
			               plotLine(g,getCorrectSize(3));
			              break;
			    case '4': length+='4';
			              cout <<'4';
			               plotLine(g,getCorrectSize(4));
			              break;
			    case '5': length+='5';
                        cout <<'5';
                         plotLine(g,getCorrectSize(5));
			              break;
			    case '6': length+='6';
                        cout <<'6';
                         plotLine(g,getCorrectSize(6));
			              break;
			    case '7': length+='7';
                          cout <<'7';
                           plotLine(g,getCorrectSize(7));
			              break;
			    case '8': length+='8';
			              cout <<'8';
			               plotLine(g,getCorrectSize(8));
			              break;
			    case '9': length+='9';
			              cout <<'9';
			               plotLine(g,getCorrectSize(9));
			              break;
			    case '0':length+='0';
			              cout <<'0';
			             //  plotLine(g,getCorrectSize(0));
			              break;
                case SDL_SCANCODE_RETURN:lengthCorrect = true;
			              break;

                 }
                 if(length != ""){
                    plotLine(g,getCorrectSize(stoi(length)));

                 }
                drawMessage(g,"hit enter",50,30,255,0,0);

            }
        }

        cout << endl;
        if(length!=""){
            newgame->wordlength = stoi(length);
        }
         for (int j = 0; j < newgame->totalword.size();j++){
            if (  newgame->wordlength ==  newgame->totalword[j].length){
                newgame->wordlist = newgame->totalword[j].list;
                findlength = true;
            }
        }
        if (length == ""){
                findlength = false;
            }
        newgame->solution = "";
        for (int i =0;i < newgame->wordlength;i++){
        newgame->solution += '-';
        }
         if (!findlength){
            clearMessage(g);
            drawMessage(g," invalid word length hit enter",50,30,255,0,0);
           bool wait = true;
            while (wait)
            if(g->kbhit()){
                if(g->getKey() == SDL_SCANCODE_RETURN){
                    wait = false;
                }
            }

        }
        plotLine(g,getCorrectSize(newgame->wordlength));
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
        clearMessage(g);
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
           clearWord(g);
           plotLine(g,getCorrectSize(newgame->wordlength));
            cout << "current Solution is " << newgame->solution << endl;
              plotLetters(g,getCorrectSize(newgame->wordlength),newgame->solution);
            if (!guesscorrect) {
                clearMessage(g);
                newgame->remainguess--;
                drawMessage(g,"wrong",50,30,255,0,0);
                drawRightPart(g,newgame->remainguess);
            }else{
                clearMessage(g);
                drawMessage(g,"right",50,30,255,0,0);
                g->playSound("excellent.wav");
            }

        cout << "remaining guess is " << newgame->remainguess << endl;

     }
       if (newgame->checkfinished() == true) {
             clearMessage(g);
            drawMessage(g,"you successfully find the word" ,50,30,255,0,0);
        } else {
            clearMessage(g);
            drawMessage(g,"you failed to guess the word" ,50,30,255,0,0);
             plotLetters(g,getCorrectSize(newgame->wordlength),newgame->getresult());
             clearWord(g);


            cout << "the actual word  we have is " << newgame->getresult()<<endl;
            cout <<endl;
            cout <<endl;
            cout <<endl;
            cout <<endl;
        }
        //g->quitSound("background.wav");
        g->initSound("end.wav");
        g->playSound("end.wav");
        bool gameContinue = false;
        drawMessage(g,"hit enter to continue" ,50,60,255,0,0);
        drawMessage(g,"hit q to quit" ,50,90,255,0,0);
        while(!gameContinue){
            if (g->kbhit()){
                if(g->getKey() == SDL_SCANCODE_RETURN){
                    gameContinue = true;
                    g->playSound("erro.wav");

                }
                else if (g->getKey() == 'Q'){
                    g->setQuit(true);
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
          plotBase(g);
        plotGallow(g);
        plotGallow1(g);
        plotGallow2(g);
    }else if (guess == 3){
         plotHead(g);
         plotSadness(g);
          plotBase(g);
        plotGallow(g);
        plotGallow1(g);
        plotGallow2(g);
        plotBody(g);
         plotLeftArm(g);
    }else if (guess == 2){
        plotHead(g);
         plotSadness(g);
          plotBase(g);
        plotGallow(g);
        plotGallow1(g);
        plotGallow2(g);
        plotBody(g);
         plotLeftArm(g);
         plotRightArm(g);
    }else if (guess == 1){
         plotHead(g);
         plotSadness(g);
          plotBase(g);
        plotGallow(g);
        plotGallow1(g);
        plotGallow2(g);
        plotBody(g);
         plotLeftArm(g);
         plotRightArm(g);
         plotLeftLeg(g);
    }else if (guess == 0){
         plotHead(g);
         plotSadness(g);
          plotBase(g);
        plotGallow(g);
        plotGallow1(g);
        plotGallow2(g);
        plotBody(g);
         plotLeftArm(g);
         plotRightArm(g);
         plotLeftLeg(g);
        plotRightLeg(g);
         plotDeath(g);
    }else if (guess == 4){
          plotHead(g);
         plotSadness(g);
          plotBase(g);
        plotGallow(g);
        plotGallow1(g);
        plotGallow2(g);
        plotBody(g);
    }
    g->update();
}
void redrawBase(SDL_Plotter *g){
    g->clear();
    plotAlphabet(g);
    plotBase(g);
        plotGallow(g);
        plotGallow1(g);
        plotGallow2(g);
}


