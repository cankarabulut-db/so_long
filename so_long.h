#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_map
{
	void *img_player;
	void *img_exit;
	void *img_;
}			t_map;


typedef struct s_solong{

	char **map;
	char **mapcopy;
	char *mapname;
	int mapy;
	int mapx;
	int chrx;
	int chry;
	int		p_count;
	int 	c_count;
	int 	e_count;
	int		w_count;
	void *mlx;
	void *mlx_win;
}				t_solong;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "getnextline/get_next_line.h"

int ft_strchr(char *str,char c);
void errorm(t_solong *main,char x);
void map_verify(t_solong *map_check,char *ber,int j,int i);
void map_verify_1(t_solong *map_check,int a,int i);
void map_verify_2(t_solong *map_check,int x,int i);
char **get_map(char *str, t_solong *solong);
int countline(int fd);
void flood_fill(t_solong *solong,int fd,int i);
void	f_fill(char **tab, t_point map_size, int y, int x);



#endif