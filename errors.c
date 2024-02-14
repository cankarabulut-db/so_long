#include "so_long.h"
void errorm(t_solong *main,char x)
{
	if(x == 'm')
		printf("Something is wrong between the first and last line!");
	else if(x == 'a')
		printf("Unwanted Character on the map!");
	else if(x == 'e')
		printf("The lines are not equal!");
	else if(x == 's')
		printf("Something is wrong on the wall!");
	exit(1);
}