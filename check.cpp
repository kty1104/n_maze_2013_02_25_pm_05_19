#include "n_maze.h"
#include "check.h"
#include "maze.h"
#include "cell.h"
COORD Check::check(Maze* m,int x, int y)
{
	int width,height;
	width = m->get_width()-x;
	height = m->get_height()-y;
	COORD size;
	for(int h = height;h>=MIN_CHECK_HEIGHT;h--)
	{
		for(int w=width;w>=MIN_CHECK_WIDTH;w--)
		{
			if(check_empty(m,x,y,w,h)==false)
			{
				size.X = w;
				size.Y = h;
				return size;
			}
		}
	}
	//x,y로 시작하는 사각형모양의 뭉친 벽이 없음
	size.X =0;
	size.Y =0;
	return size;
}
bool Check::check_empty(Maze* m,int x, int y,int w, int h)
{
	for(int cy=y;cy<h;cy++)
	{
		for(int cx=x;cx<w;cx++)
		{
			if(m->get_arr(cx,cy)->get()==0)
			{
				return true;
			}
		}
	}
	return false;
}
