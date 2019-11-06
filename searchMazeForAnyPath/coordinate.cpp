#include "coordinate.h"
#include <iostream>

using namespace std;

coordinate::coordinate(){
    row = 0;
    col = 0;
}

coordinate::coordinate(int a, int b){
    row = a;
    col = b;
}

bool coordinate::isEqualTo(coordinate mcolPoint){
    if(mcolPoint.row == this->row && mcolPoint.col == this->col){
        return true;
    }
    return false;
}

void coordinate::printCoord(){
    cout << "("<<this->row <<" , "<<this->col << ")"<< endl;
}