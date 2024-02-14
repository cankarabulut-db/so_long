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
	open(str,O_RDONLY);
	b = -1;
	while (++b < solong->mapy)
		ret[b] = get_next_line(a);
	solong->mapx = ft_strlen(ret[0]);
	ret[b] = NULL;
	return (ret);
}
void map_verify_1(t_solong *map_check)
{
	int y_refer;
	int x;
	int i;

	i = 0;
	x = 0;
	y_refer = map_check->mapx - 1;
	while(y_refer > 0) // BU KISIM BAŞINI VE SONUNU KONTROL ETMEK İÇİN
	{
		
		x++;
		y_refer--;
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
			{
				printf("bozuk");
				return;
			}
			if (ft_strchr("0PEC",map_check->map[0][j]) || \
			ft_strchr("0PEC",map_check->map[map_check->mapy - 1][j]))
			{
				printf("bu diğer bozuk olan");
				return ;
			}
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