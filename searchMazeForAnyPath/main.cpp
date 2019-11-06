#include <iostream>
#include "coordinate.h"
#include <stdlib.h> 

using namespace std;

int main(){
    // establish size of maze
    int length = 7;
    int width = 7;

    // number of blocked squares in maze
    int numBlocks = length*width/5;

    // starting coordinate
    int startRow = 5;
    int startCol = 1;

    // ending coordinate
    int endRow = 0;
    int endCol = 6;
    
    char Maze[length][width];

    // initialize maze to all open spots
    for(int i = 0; i < length; i++){
        for(int  j = 0; j < width; j++){
            Maze[i][j] = 'O';
        }
    }

    // add random blocked spots
    while(numBlocks != 0){
        int rowVal = rand()%length;
        int colVal = rand()%length;

        Maze[rowVal][colVal] = 'X';
        numBlocks--;
    }

    // add my starting and ending point
    Maze[startRow][startCol] = 'S';
    Maze[endRow][endCol] = 'E';

    // print maze
    for(int i = 0; i < length; i++){
        for(int  j = 0; j < width; j++){
            cout << Maze[i][j];
        }
        cout << endl;
    }



    return 0;
}
