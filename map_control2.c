#include "so_long.h"
void flood_fill_check(t_solong *solong,int y,int x)
{
	while(solong->mapcopy[y])
	{
		x = 0;
		while(solong->mapcopy[y][x])
		{
			if(solong->mapcopy[y][x] == 'E' || solong->mapcopy[y][x] == 'P' || \
			solong->mapcopy[y][x] == 'C')
				errorm(solong,'f');
			x++;
		}
		y++;
	}
}

void flood_fill(t_solong *solong,int fd,int i)
{
	t_point map;
	t_point character;

	map.x = solong->mapx;
	map.y = solong->mapy;
	character.x = solong->chrx;
	character.y = solong->chry;
	fd = open(solong->mapname,O_RDONLY);
	solong->mapcopy = malloc(sizeof(char *) * solong->mapy + 1);
	while(solong->mapy > ++i)
		solong->mapcopy[i] = get_next_line(fd);
	solong->mapcopy[i] = NULL;
	f_fill(solong->mapcopy,map,character.y,character.x);
	flood_fill_check(solong,0,0);
}
