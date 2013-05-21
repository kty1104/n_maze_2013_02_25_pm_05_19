#ifndef DRILL_H
#define DRILL_H
#include "n_maze.h"
class Drill
{
	Maze* maze;
	int x;
	int y;
	int to_x;
	int to_y;
public:
	Maze* get_maze();
	void set_maze(Maze* m);
	int get_x();
	int get_y();
	int get_to_x();
	int get_to_y();
	int set_xy(int in_x, int in_y,COORD wall_left_top, COORD wall_right_bottom);
	int set_to_xy(int in_x, int in_y,COORD wall_left_top, COORD wall_right_bottom);
	int around(int x, int y);
	bool drill(int from_x,int from_y, int to_x, int to_y,COORD wall_left_top, COORD wall_right_bottom, int max_n,int around_max);
	Drill(Maze* m);
	~Drill();
};
#endif
