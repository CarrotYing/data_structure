#pragma once
#include "stack.h"
#define MAX_ROW 6
#define MAX_COL 6
typedef struct maze{
    int map[MAX_ROW][MAX_COL];
}Maze;

/*
 * @brief 初始化迷宫
 *
 * @param maze
 * */
void MazeInit(Maze* maze);
/*
 * @brief 打印迷宫
 *
 * @param
 * */
void MazePrint(Maze* maze);
void _MazeShortPathWithCycle(Maze* maze,Point cur, Point pre,Point entry,
                             SeqStack* cur_path,SeqStack* short_path);

void MazeShortPathWithCycle(Maze* maze,Point entry);
int CanStay(Maze* maze,Point cur,Point pre);
int IsExit(Point cur,Point entry);
void Mark(Maze* maze,Point cur,Point pre);
