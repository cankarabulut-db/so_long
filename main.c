#include "so_long.h"
void map_name_checker(char *str,int i)
{
	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' \
	|| str[i - 3] != '.')
	{
		printf("Map name Error!");
		exit(1);
	}
}

int main(int ac,char **av)
{
	t_solong so_long;

	if(ac != 2)
	{
		printf("Argument Error.\nTry this : ./a.out <mapLocation> ");
		exit(1);
	}
	so_long.mapname = av[1];
	map_name_checker(so_long.mapname,0);
	map_verify(&so_long,so_long.mapname,0,0);
	flood_fill(&so_long,0,-1);
	for (size_t i = 0; i < so_long.mapy; i++)
		printf("%s\n", so_long.mapcopy[i]);
	

}