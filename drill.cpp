#include "n_maze.h"
#include "drill.h"
#include "maze.h"
#include "cell.h"
Maze* Drill::get_maze()
{
	return maze;
}
void Drill::set_maze(Maze* m)
{
	maze = m;
}
int Drill::get_x()
{
	return x;
}
int Drill::get_y()
{
	return y;
}
int Drill::get_to_x()
{
	return to_x;
}
int Drill::get_to_y()
{
	return to_y;
}
int Drill::set_xy(int in_x, int in_y,COORD wall_left_top, COORD wall_right_bottom)
{
	if((in_x<=wall_left_top.X)||(in_x>=wall_right_bottom.X)||(in_y<=wall_left_top.Y)||(in_y>=wall_right_bottom.Y))
	{
		return false;
	}
	else
	{
		x = in_x;
		y = in_y;
	}
	return true;
	
}
int Drill::set_to_xy(int in_x, int in_y,COORD wall_left_top, COORD wall_right_bottom)
{
	if((in_x<=wall_left_top.X)||(in_x>=wall_right_bottom.X)||(in_y<=wall_left_top.Y)||(in_y>=wall_right_bottom.Y))
	{
		return false;
	}
	else
	{
		to_x = in_x;
		to_y = in_y;
	}
	return true;
	
}

int Drill::around(int in_x, int in_y)//return around number of occupied cells
{
	int rtn=0;
	for(int y=-1;y<=1;y++)
	{
		for(int x=-1;x<=1;x++)
		{
			Cell *c;
			c = maze->get_arr(x+in_x,y+in_y);
			if(c!=0)
			{
				rtn = rtn + c->get();
			}
		}
	}
	return rtn;
}


bool Drill::drill(int from_x,int from_y, int to_x, int to_y,COORD wall_left_top, COORD wall_right_bottom, int max_n,int around_max)
{
	int direction;
	int max_step;
	max_step=STEP_MAX;
	int step;
	int ret = set_xy(from_x,from_y,wall_left_top,wall_right_bottom);
	if(ret==false)
	{
		return false;
	}
	while(max_n--)
	{
		step = rand()%max_step;
		direction = rand()%4; //0 left, 1 right, 2 up, 3 down
		while(step--)
		{
			if(direction==0)
			{
				Cell *c = maze->get_arr(x-1,y);
				if((around(x-1,y) >= around_max) || (c->get()==0))
				{
					set_xy(x-1,y,wall_left_top,wall_right_bottom);
					maze->set_arr(x,y,0);
				}
			}
			else if(direction==1)
			{
				Cell *c = maze->get_arr(x+1,y);
				if((around(x+1,y) >= around_max) || (c->get()==0))
				{
					set_xy(x+1,y,wall_left_top,wall_right_bottom);
					maze->set_arr(x,y,0);
				}
			}
			else if(direction==2)
			{
				Cell *c = maze->get_arr(x,y-1);
				if((around(x,y-1) >= around_max) || (c->get()==0))
				{
					set_xy(x,y-1,wall_left_top,wall_right_bottom);
					maze->set_arr(x,y,0);
				}
			}
			else if(direction==3)
			{
				Cell *c = maze->get_arr(x,y+1);
				if((around(x,y+1) >= around_max) || (c->get()==0))
				{
					set_xy(x,y+1,wall_left_top,wall_right_bottom);
					maze->set_arr(x,y,0);
				}
			}
			if((get_x()==to_x) && (get_y() == to_y))
			{
				return true;
			}

		}
	}
	return false;
}
Drill::Drill(Maze* m)
{
	maze = m;
}
Drill::~Drill()
{

}