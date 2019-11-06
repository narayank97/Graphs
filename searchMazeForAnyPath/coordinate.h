# pragma once
class coordinate{
   
    public:
        int row;
        int col;
        
        coordinate();
        coordinate(int, int);
        void printCoord();
        bool isEqualTo(coordinate myPoint);
};