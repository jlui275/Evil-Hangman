//
// Created by Xiang_Gao on 11/18/2018.
//
#include "pattern.h"
using namespace std;
string getPattern(string Word,char key){

    string pattern = "";
    for(int i = 0;i< Word.length() ;i++){
        if (Word[i] == key){
            pattern = pattern+key;
        }
        else{
            pattern = pattern+'_';
        }
        pattern = pattern+' ';
    }
    return pattern;
}
//function for compare patternword class
bool compare(patternWord p1,patternWord p2){
    return(p1.count > p2.count);
}
void pattern::readword(vector<string> word){
    wordlist = word;
}
void pattern::getPatterns(char key){
    for (int i = 0; i < wordlist.size(); i++ ){
        patternWord newpattern;
        newpattern.pat = getPattern(wordlist[i],key);
        bool addnewpattern = true;
        for (int j = 0; j < patterns.size();j++){
            if (newpattern.pat ==  patterns[j].pat){
                addnewpattern = false;
                patterns[j].list.push_back(wordlist[i]);
                patterns[j].updateCounter();

            }
        }
        if (addnewpattern){
            patterns.push_back(newpattern);
            patterns.back().list.push_back(wordlist[i]);
            patterns.back().updateCounter();
        }
    }

}
void pattern::printpattern() {
    for (int j = 0; j < patterns.size();j++){
        patterns[j].printword();
        cout << endl;
    }
}
void patternWord::printword() {
    cout << pat << " : ";
    for (int j = 0; j < list.size();j++){
        cout << list[j] << " ";
    }
}

void pattern::updatepattern() {
    sort(patterns.begin(),patterns.end(),compare);
}
patternWord pattern::Maxset() {
    this->updatepattern();
    //check if their multiple max set randomly choose one
    int Maxcount = patterns[0].count;
    int Maxindex = 0;
    for(int i =1;i < patterns.size();i++){
        if (patterns[i].count == Maxcount){
            Maxindex++;
        }
    }
    srand(time(NULL));
    int randnum = rand()%(Maxindex+1);
    swap(patterns[0],patterns[randnum]);
    return patterns[0];
}
