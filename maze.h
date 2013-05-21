#ifndef MAZE_H
#define MAZE_H
#include "n_maze.h"
class Maze
{
	int width;
	int height;
	Cell** arr;//new로 할당해줘야함
public:
	int get_width();
	int get_height();
	void set_width(int w);
	void set_height(int h);
	Cell* get_arr(int x, int y);
	void set_arr(int x,int y, int val);
	Maze(int w, int h);
	~Maze();

};
#endif