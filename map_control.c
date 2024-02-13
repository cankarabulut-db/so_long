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
	ret[b] = NULL;
	return (ret);
}
void map_verify_1(t_solong *map_check,int y_reference,int lineref)
{
	int y_refer;
	int x;

	x = 0;
	y_refer = y_reference;
	while(y_refer > 0)
	{
		if(map_check->map[x][0] != '1'  || map_check->map[x][lineref - 1] != '1')
			printf("Wrong map error , verify 1 fonksiyon \n");
		x++;
		y_refer--;
	}
}

void map_verify(t_solong *map_check,char *ber)
{
	int x;
	int lineref;
	int yref;

	map_check->map = get_map(ber,map_check);
	x = 0;
	yref = map_check->mapy;
	lineref = ft_strlen(map_check->map[0]) - 1;
	if(ft_strchr(map_check->map[0],'0') || ft_strchr(map_check->map[yref -1],'0'))
		printf("wrong map furkan abime sor , verify fonk\n ");
	map_verify_1(map_check,yref,lineref);
}


int main()
{
	t_solong *solong;

	solong = malloc(sizeof(t_solong));
	if(!solong)
		return (0);
	map_verify(solong,"a.ber");
}