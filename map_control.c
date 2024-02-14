#include "so_long.h"

int countline(int fd)
{
	char *str;
	int i;

	i = 0;
	str = get_next_line(fd);
	if (str != NULL)
	{
		i++;
		i += countline(fd);
	}
	free(str);
	return (i);
}

char **get_map(char *str, t_solong *solong)
{
	char **ret;
	int a;
	int b;

	a = open(str,O_RDONLY);
	solong->mapy = countline(a);
	ret = malloc(sizeof(char *) * (solong->mapy + 1));
	if (!ret)
		return (NULL);
	close(a);
	a = open(str,O_RDONLY);
	b = -1;
	while (++b < solong->mapy)
		ret[b] = get_next_line(a);
	ret[b] = NULL;
	solong->mapx = ft_strlen(ret[0]);
	solong->chrx = 0;
	solong->chry = 0;
	return (ret);
}
void map_verify_1(t_solong *map_check)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while(map_check->mapy > i)
	{
		if(ft_strlen(map_check->map[a]) != map_check->mapx)
			errorm(map_check,'e');
		if(map_check->map[a][0] != '1' || map_check->map[a][map_check->mapx - 1] != '1')
			errorm(map_check,'s');
		a++;
		i++;
	}
}

void map_verify(t_solong *map_check,char *ber)
{
	int j;
	int i;

	map_check->map = get_map(ber,map_check);
	i = 0;
	while(map_check->map[i])
	{
		j = 0;
		while(map_check->map[i][j]) // BU KISIM İÇERİDE 01PEC DIŞINDA BİR ŞEY OLMAMASI İÇİN
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
	map_verify_1(map_check);
}


int main()
{
	t_solong *solong;

	solong = malloc(sizeof(t_solong));
	if(!solong)
		return (0);
	map_verify(solong,"a.ber");
}