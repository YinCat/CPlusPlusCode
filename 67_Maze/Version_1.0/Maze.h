#pragma once

#include "Stack.h"
#define N 6 
static int maze[N][N] ={
{ 0,0,0,0,0,0 },
{ 0,0,1,1,1,0 },
{ 0,0,1,0,1,0 },
{ 0,0,1,1,1,1 },
{ 0,0,1,0,1,0 },
{ 0,0,1,0,0,0 },
};

void MazePrint();
int MazeGetPath(Pos entry, Pos exit);
//void MazeGetPathR(Pos entry);
int MazeCheckIsAccess(Pos pos);
Stack shortPath;
void MazeGetShortPath(Pos entry, Stack* path);
int CheckAccess(Pos next);