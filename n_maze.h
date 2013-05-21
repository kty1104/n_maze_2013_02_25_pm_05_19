#ifndef N_MAZE_H
#define N_MAZE_H
#define AROUND_MAX 7
#define STEP_MAX 3
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>   
#include <Windows.h>

class Cell;
class Maze;
class Drill;
class Check;
void print_maze(FILE* fp,Maze * m,char* blank,char* block);


#endif