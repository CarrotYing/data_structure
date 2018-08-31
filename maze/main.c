#include <stdio.h>
#include "maze.h"
#include "stack.h"
#define __HEADER__ printf("\n_________%s_________\n",__FUNCTION__);

void TestMaze(){
    __HEADER__
    Maze maze;
    MazeInit(&maze);
    MazePrint(&maze);
    Point entry={0,1};
    MazeShortPath(&maze,entry);    
}
int main(){
    TestMaze();
    return 0;
}
