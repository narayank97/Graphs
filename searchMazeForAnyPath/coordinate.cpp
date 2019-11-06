#include "coordinate.h"
#include <iostream>

using namespace std;

coordinate::coordinate(int a, int b){
    x = a;
    y = b;
}

bool coordinate::isEqualTo(coordinate myPoint){
    if(myPoint.x == this->x && myPoint.y == this->y){
        return true;
    }
    return false;
}

void coordinate::printCoord(){
    cout << "("<<this->x <<" , "<<this->y << ")"<< endl;
}