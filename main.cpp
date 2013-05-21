#include "n_maze.h"
#include "maze.h"
#include "cell.h"
#include "check.h"
#include "drill.h"
int main(int argc, char *argv[])
{
	int size_w;
	int size_h;
	if(argc<2)
	{
		printf("가로 세로 숫자가 공백구분으로 적혀있는 파일을 넘기면 그 파일에 미로를 프린트 합니다\n");
		printf("give me a txt file as a parameter. which include width and height seperated by space\n");
		printf("파일을 지정하지 않았기 때문에 가로 30, 세로 80크기로 출력합니다.\n");
		printf("since you didn't give me a txt file, I will print out with default size width 30, height 80\n");
		size_w = 30;
		size_h = 80;
	}
	else
	{
		FILE* fp;
		fp = fopen(argv[1],"r");
		fscanf(fp,"%d %d",&size_w,&size_h);
		fclose(fp);
	}
	
	
	int fake_route = 30;
	int max_n = 4096;
	int dest_x = size_w-2;//dest는 index이므로 -1에 또 -1
	int dest_y = size_h-2;//dest는 index이므로 -1에 또 -1
	Maze* m = new Maze(size_w,size_h);
	Drill* d = new Drill(m);
	Check* c = new Check();
	COORD wall_left_top = {0,0};
	COORD wall_right_bottom = {size_w-1,size_h-1};//wall은 index이므로 -1


	srand (time(NULL));
	d->drill(1,1,dest_x,dest_y,wall_left_top,wall_right_bottom,max_n,AROUND_MAX);
	while(fake_route--)
	{
		dest_x = rand()%(size_w-2);
		dest_y = rand()%(size_h-2);
		int from_x = rand()%(size_w-2);
		int from_y = rand()%(size_h-2);

		d->drill(from_x,from_y,dest_x,dest_y,wall_left_top,wall_right_bottom,max_n,AROUND_MAX);
	}
	
	
	print_maze(stdout,m,"  ","■");
	
	int rnd = rand()%10000;
	if(argc<2)
	{
		FILE* fp;
		char name[128];

		sprintf(name,"maze_%d.txt",rnd);
		fp = fopen(name,"w");
		print_maze(fp,m,"  ","■");
		fclose(fp);

		sprintf(name,"maze_num_%d.txt",rnd);
		fp = fopen(name,"w");
		print_maze(fp,m,"0","1");
		fclose(fp);
	}
	else
	{
		FILE* fp;
		char name[128];
		sprintf(name,"%s_%d.txt",argv[1],rnd);
		fp = fopen(name,"w");
		print_maze(fp,m,"  ","■");
		fclose(fp);

		sprintf(name,"%s_num_%d.txt",argv[1],rnd);
		fp = fopen(name,"w");
		print_maze(fp,m,"0","1");
		fclose(fp);
	}
	

	getchar();
}