//
// Created by Xiang_Gao on 11/18/2018.
//
#include "game.h"
bool game::updateSol() {
    bool guessedcorrect = false;
    char key = letterguessed.back();
    cout <<"key you type is "<< key << endl;
    //partion and get the max set
    pattern newpattern;
    newpattern.readword(wordlist);
    newpattern.getPatterns(key);
    wordlist = newpattern.Maxset().list;
    //newpattern.printpattern();
    string check;
    //replace solution with our new word
    for (int i =0;i < wordlength ;i ++){
        if (wordlist[0][i] == key){
            solution[i] = key;
            guessedcorrect = true;
        }

    }
    return guessedcorrect;
}
//this method read in word list
void game::getword(istream &in) {
    string newword;
    while(in >> newword){
        wordLength newlength;
        newlength.length = newword.length();
        bool addnewlengh= true;
        for (int j = 0; j < totalword.size();j++){
            if ( newlength.length ==  totalword[j].length){
                addnewlengh= false;
                totalword[j].list.push_back(newword);

            }
        }
        if (addnewlengh){
            totalword.push_back(newlength);
            totalword.back().list.push_back(newword);
        }
    }
}
// this method read in current guess
void game::inputchar() {
    bool inputsuccess = false;
    char key;
    while(!inputsuccess){
        cin >> key;
        inputsuccess = true;
        for (int i = 0; i < letterguessed.size();i++){
            if (key == letterguessed[i]){
                inputsuccess = false;
                cout << "you already guessed this key" << endl;
            }
        }
    }
    if (inputsuccess){
        letterguessed.push_back(key);
    }
}
//check if there is - in solution
bool game::checkfinished() {
    for (int i =0;i < wordlength;i++){
        if(solution[i] == '-'){
            return false;
        }
    }
    return true;
}
void game::calulateDiffculty() {
    int diffculty = 0;
    if (wordlength < 5){
        diffculty+= 3;
    }else if (wordlength >= 5 &&wordlength <10){
        diffculty += 2;
    }else{
        diffculty += 1;
    }
    if(remainguess < 5){
        diffculty+= 3;
    }
    else if (wordlength >= 5 &&wordlength <10){
        diffculty+=2;
    }else{
        diffculty+=1;
    }

    if (diffculty > 5){
        cout <<"Difficulty: ultra evil" << endl;
    }else if (diffculty < 5 && diffculty >= 3){
        cout <<"Difficulty: evil "<< endl;
    }else{
        cout <<"Difficulty: easy ?" << endl;
    }

}
//get set of the word with specific length
void game::getset() {
    bool findlength = false;
    while(!findlength){
        cout <<"choose the length of the word"<< endl;
        cin >> wordlength;
        for (int j = 0; j < totalword.size();j++){
            if ( wordlength ==  totalword[j].length){
                wordlist = totalword[j].list;
                findlength = true;
            }
        }
        if (!findlength){
            cout << " we dont have word this length" << endl;
        }
    }
    cout <<"choose how many guess you want have" << endl;
    cin >> remainguess;
    solution = "";
    for (int i =0;i < wordlength;i++){
        solution += '-';
    }

}
//get the current result
string game::getresult() {
    srand(time(NULL));
    int randnum = rand()%(wordlist.size());
    cout <<"random numer" << randnum << endl;
    return wordlist[randnum];
}
//let the game run
void game::gamerun(istream &in) {
    //read in and partion word based on length
    this->getword(in);
    //get the word length and change the current list to word with that size
    this->getset();
    this->calulateDiffculty();
    cout << "current Solution is " << solution << endl;
    cout << "remaining guess is " << remainguess << endl;
    bool guesscorrect = false;
    while (!this->checkfinished() && remainguess > 0) {
        this->inputchar();
        guesscorrect = this->updateSol();
        //cout << "you guessed this"<< letterguessed.back() <<endl;
        cout << "current Solution is " << solution << endl;
        if (!guesscorrect) {
            remainguess--;
        }

        cout << "remaining guess is " << remainguess << endl;
    }
    if (this->checkfinished() == true) {
        cout << "you successfully find the word" << endl;
    } else {
        cout << "you failed guess the word" << endl;
        cout << "the actual word  we have is " << this->getresult()<<endl;
    }
}
