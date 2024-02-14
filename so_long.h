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
	int mapy;
	int mapx;
	int chrx;
	int chry;
	void *mlx;
	void *mlx_win;

}				t_solong;



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "getnextline/get_next_line.h"

int ft_strchr(char *str,char c);
void errorm(t_solong *main,char x);



#endif