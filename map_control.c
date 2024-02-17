#include "so_long.h"

void map_verify_2(t_solong *map_check,int y,int x)
{
	while(map_check->map[y])
	{
		x = 0;
		while(map_check->map[y][x])
		{
			if(map_check->map[y][x] == 'P')
				{
					map_check->p_count += 1;
					map_check->chrx = x;
					map_check->chry = y;
				}
			if(map_check->map[y][x] == 'C')
				map_check->c_count += 1;
			if(map_check->map[y][x] == 'E')
				map_check->e_count += 1;
			x++;
		}
		y++;
	}
	if(map_check->p_count != 1 || map_check->e_count != 1)
		errorm(map_check,'w');
}
void map_verify_1(t_solong *map_check,int a,int i)
{
	while(map_check->mapy > i)
	{
		if(ft_strlen(map_check->map[a]) != map_check->mapx)
			errorm(map_check,'e');
		if(map_check->map[a][0] != '1' || map_check->map[a][map_check->mapx - 1] != '1')
			errorm(map_check,'s');
		a++;
		i++;
	}
	map_verify_2(map_check,0,0);
}

void map_verify(t_solong *map_check,char *ber,int j,int i)
{
	map_check->map = get_map(ber,map_check);
	while (map_check->map[i])
	{
		j = 0;
		while (map_check->map[i][j]) // BU KISIM İÇERİDE 01PEC DIŞINDA BİR ŞEY OLMAMASI İÇİN
		{
			if (!ft_strchr("01PEC",map_check->map[i][j]))
				errorm(map_check,'a');
			if (ft_strchr("0PEC",map_check->map[0][j]) || \
			ft_strchr("0PEC",map_check->map[map_check->mapy - 1][j]))
				errorm(map_check,'m');
			j++;
		}
		i++;
	}
	map_verify_1(map_check,0,0);
}
