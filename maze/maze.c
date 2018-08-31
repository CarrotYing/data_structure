#include <stdio.h>
#include "maze.h"


void MazeInit(Maze* maze){
    int map[MAX_ROW][MAX_COL]={
     {0,1,0,0,0,0},
     {0,1,1,1,0,0},
     {0,1,0,1,1,1},
     {1,1,1,0,0,0},
     {0,0,1,0,0,0},
     {0,0,1,0,0,0},
    };
    size_t i=0;
    for(;i<MAX_ROW;++i){
        size_t j=0;
        for(;j<MAX_COL;++j){
            maze->map[i][j]= map[i][j];
        }
    }
}

void MazePrint(Maze* maze){
    size_t i=0;
    for(;i<MAX_ROW;++i){
        size_t j=0;
        for(;j<MAX_COL;++j){
            printf("%d ",maze->map[i][j]);
        }
        printf("\n");
    }
}
void MazeShortPath(Maze* maze,Point entry){
    if(maze==NULL)
        return;
    if(!CanStay(maze,entry))
        return;
    SeqStack cur_path;
    SeqStack short_path;
    SeqStackInit(&cur_path);
    SeqStackInit(&short_path);
    _MazeShortPath(maze,entry,entry,&cur_path,&short_path);
    SeqStackPrint(short_path);
}

int CanStay(Maze* maze,Point cur){
    if(cur.row<0||cur.row>=MAX_ROW
       ||cur.col<0||cur.col>=MAX_COL)
        return 0;
    if(maze->map[cur.row][cur.col]==1)
        return 1;
    else return 0;
}
int IsExit(Point cur,Point entry){
    if(cur.row==entry.row&&cur.col==entry.col)
        return 0;
    if(cur.col==0||cur.col==MAX_COL-1
       ||cur.row==0||cur.row==MAX_ROW-1)
        return 1;
    else return 0;
}
void Mark(Maze* maze,Point cur){
    maze->map[cur.row][cur.col]=2;
}

void _MazeShortPath(Maze* maze,Point cur, Point entry,SeqStack* cur_path,SeqStack* short_path){
    if(maze==NULL)
        return;
    if(!CanStay(maze,cur))
        return ;
    printf("[%d,%d]\n",cur.row,cur.col);
    Mark(maze,cur);
    SeqStackPush(cur_path,cur);
    if(IsExit(cur,entry)){
        printf("找到一条路径\n");
        if(cur_path->size<short_path->size
           ||short_path->size==0){
            printf("找到一条更短的路径\n");
            SeqStackAssign(short_path,cur_path);
        }
        SeqStackPop(cur_path);
        return;
    }
    Point up=cur;
    up.row-=1;
    _MazeShortPath(maze,up,entry,cur_path,short_path);
    Point right=cur;
    right.col+=1;
    _MazeShortPath(maze,right,entry,cur_path,short_path);
    Point down=cur;
    down.row+=1;
    _MazeShortPath(maze,down,entry,cur_path,short_path);
    Point left=cur;
    left.col-=1;
    _MazeShortPath(maze,left,entry,cur_path,short_path);
    SeqStackPop(cur_path);
}
