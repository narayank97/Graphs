#include <iostream>
#include "coordinate.h"
#include <stdlib.h> 

using namespace std;

int main(){
    int length = 7;
    int width = 7;

    int numBlocks = length*width/5;

    int startRow = 5;
    int startCol = 1;

    int endRow = 0;
    int endCol = 6;
    
    char Maze[length][width];

    for(int i = 0; i < length; i++){
        for(int  j = 0; j < width; j++){
            Maze[i][j] = 'O';
        }
    }

    while(numBlocks != 0){
        int rowVal = rand()%length;
        int colVal = rand()%length;

        Maze[rowVal][colVal] = 'X';
        numBlocks--;
    }

    Maze[startRow][startCol] = 'S';
    Maze[endRow][endCol] = 'E';

    for(int i = 0; i < length; i++){
        for(int  j = 0; j < width; j++){
            cout << Maze[i][j];
        }
        cout << endl;
    }



    return 0;
}
