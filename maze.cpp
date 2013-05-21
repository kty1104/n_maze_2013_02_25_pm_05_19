#include "n_maze.h"
#include "maze.h"
#include "cell.h"

int Maze::get_width()
{
	return width;
}
int Maze::get_height()
{
	return height;
}
void Maze::set_width(int w)
{
	width = w;
}
void Maze::set_height(int h)
{
	height = h;
}
Cell* Maze::get_arr(int x, int y)
{
	if((x<0)||(x>=width)||(y<0)||(y>=height))
	{
		return 0;
	}
	return arr[y*width+x];
}
void Maze::set_arr(int x,int y, int val)
{
	get_arr(x,y)->set(val);
}
Maze::Maze(int w, int h)
{
	width = w;
	height = h;
	arr = new Cell*[height*width];
	for(int y=0;y<height;y++)
	{
		for(int x=0;x<width;x++)
		{
			arr[y*width+x] = new Cell;
		}
	}
}
Maze::~Maze()
{
	for(int y=0;y<height;y++)
	{
		for(int x=0;x<width;x++)
		{
			delete arr[y*width+x];
		}
	}
	delete arr;
}
