#include "n_maze.h"
#include "cell.h"
void Cell::set(int val)
{
	value = val;
}
int Cell::get()
{
	return value;
}
Cell::Cell()
{
	value = 1;
}