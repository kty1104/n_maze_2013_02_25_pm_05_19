#ifndef CHECK_H
#define CHECK_H
#include "n_maze.h"
#define MIN_CHECK_WIDTH 4
#define MIN_CHECK_HEIGHT 4

class Check
{
	bool Check::check_empty(Maze* m,int x, int y,int w, int h);
public:
	COORD check(Maze* m, int x, int y);
};
#endif
