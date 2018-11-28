#include "SDL_Plotter.h"


bool* getCorrectSize(int x){
    
    bool *boolArray[21];
    
    static bool  a1[21] = {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};
    static bool  a2[21] = {0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0};
    static bool  a3[21] = {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0};
    static bool  a4[21] = {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0};
    static bool  a5[21] = {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0};
    static bool  a6[21] = {0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
    static bool  a7[21] = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0};
    static bool  a8[21] = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0};
    static bool  a9[21] = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0};
    static bool a10[21] = {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0};
    static bool a11[21] = {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0};
    static bool a12[21] = {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0};
    static bool a13[21] = {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0};
    static bool a14[21] = {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0};
    static bool a15[21] = {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0};
    static bool a16[21] = {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0};
    static bool a17[21] = {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0};
    static bool a18[21] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0};
    static bool a19[21] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
    static bool a20[21] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
    static bool a21[21] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    
    
    
    switch(x){
        case 1:
            return a1;
            break;
        case 2:
            return a2;
            break;
        case 3:
            return a3;
            break;
        case 4:
            return a4;
            break;
        case 5:
            return a5;
            break;
        case 6:
            return a6;
            break;
        case 7:
            return a7;
            break;
        case 8:
            return a8;
            break;
        case 9:
            return a9;
            break;
        case 10:
            return a10;
            break;
        case 11:
            return a11;
            break;
        case 12:
            return a12;
            break;
        case 13:
            return a13;
            break;
        case 14:
            return a14;
            break;
        case 15:
            return a15;
            break;
        case 16:
            return a16;
            break;
        case 17:
            return a17;
            break;
        case 18:
            return a18;
            break;
        case 19:
            return a19;
            break;
        case 20:
            return a20;
            break;
        case 21:
            return a21;
            break;
    }
    
    return boolArray[6];
}
