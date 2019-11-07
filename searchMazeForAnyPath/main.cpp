#include <iostream>
#include "coordinate.h"
#include <stdlib.h> 
#include <vector>

using namespace std;

void searchMaze(vector<vector<char> >& maze, coordinate start, coordinate end, vector<coordinate>& path);
bool hasPathToEnd(vector<vector<char> >& maze,coordinate current, coordinate end, vector<coordinate> shifts,  vector<coordinate>& path);
bool canTraverse(coordinate point, vector<vector<char> >& maze);


int main(){
    // establish size of maze
    int length = 10;
    int width = 10;

    // number of blocked squares in maze
    int numBlocks = length*width/2;

    // starting coordinate
    int startRow = 8;
    int startCol = 1;

    // ending coordinate
    int endRow = 0;
    int endCol = 9;
    
    //char Maze[length][width];
    vector<vector<char> > Maze;
    vector<coordinate> myPath;

    // initialize maze to all open spots
    for(int i = 0; i < length; i++){
        vector<char> MazeRow;
        for(int  j = 0; j < width; j++){
            MazeRow.push_back('O');
        }
        Maze.push_back(MazeRow);
        MazeRow.clear();
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
    coordinate start = coordinate(startRow,startCol);
    Maze[endRow][endCol] = 'O';
    coordinate end = coordinate(endRow,endCol);

    // print maze BEFORE
    for(int i = 0; i < length; i++){
        for(int  j = 0; j < width; j++){
            cout << Maze[i][j];
        }
        cout << endl;
    }

    searchMaze(Maze,start,end,myPath);
    Maze[startRow][startCol] = 'S';
     Maze[endRow][endCol] = 'E';

    cout << endl << endl;

    // print maze AFTERS
    for(int i = 0; i < length; i++){
        for(int  j = 0; j < width; j++){
            cout << Maze[i][j];
        }
        cout << endl;
    }
    
    cout << endl;
    //cout << myPath.size() << endl;

    for(int i = 0; i < myPath.size(); i++){
        myPath[i].printCoord();
    }

    return 0;
}

// allows to easily pass 2D array to function
 
bool hasPathToEnd(vector<vector<char> >& maze,coordinate current, coordinate end, vector<coordinate> shifts,  vector<coordinate>& path){
    if(current.isEqualTo(end)){
        return true;
    }
    for(int i = 0; i < shifts.size(); i++){
        //have to check if it can traverse here
        
        current.row += shifts[i].row;
        current.col += shifts[i].col;
        
        if(canTraverse(current,maze)){
            maze[current.row][current.col] = '!';
            path.push_back(current);
            
            coordinate next = current;
            
            if(hasPathToEnd(maze,next,end,shifts,path)){
                return true;
            }
            path.pop_back();
        }
       
    }
    return false;
}


void searchMaze(vector<vector<char> >& maze, coordinate start, coordinate end, vector<coordinate>& path){
    vector<coordinate> shifts;
    
    // add shifts up,right,down,left
    shifts.push_back(coordinate(-1,0));
    shifts.push_back(coordinate(0,1));
    shifts.push_back(coordinate(1,0));
    shifts.push_back(coordinate(0,-1));

    // flipped this spot to discovered
    maze[start.row][start.col] = '!';
    path.push_back(coordinate(start.row,start.col));
    if(!hasPathToEnd(maze,start,end,shifts,path)){
        path.pop_back();
    }
}

bool canTraverse(coordinate point, vector<vector<char> >& maze){
    if(point.row < 0 || point.col < 0){
        return false;
    }
    if(point.row > maze.size() || point.col > maze.size()){
        return false;
    }
    
    if(maze[point.row][point.col] != 'O'){
        return false;
    }
    return true;
}



