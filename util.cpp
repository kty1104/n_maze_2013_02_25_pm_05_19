#include "n_maze.h"
#include "maze.h"
#include "cell.h"

void print_maze(FILE* fp,Maze * m,char* blank,char* block)
{
	int width = m->get_width();
	int height = m->get_height();
	for(int cy=0;cy<height;cy++)
	{
		for(int cx =0; cx<width;cx++)
		{
			if(m->get_arr(cx,cy)->get()==0)
			{
				fprintf(fp,blank);
			}
			else
			{
				fprintf(fp,block);
			}
		}
		fprintf(fp,"\n");
	}
}