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
	int fd;
	int b;

	fd = open(str,O_RDONLY);
	if(fd == -1)
	{
		printf("That file is not openable.");
		exit(1);
	}
	solong->mapy = countline(fd);
	ret = malloc(sizeof(char *) * (solong->mapy + 1));
	if (!ret)
		return (NULL);
	close(fd);
	fd = open(str,O_RDONLY);
	b = -1;
	while (++b < solong->mapy)
		ret[b] = get_next_line(fd);
	ret[b] = NULL;
	solong->mapx = ft_strlen(ret[0]);
	solong->c_count = 0;
	solong->e_count = 0;
	solong->e_count = 0;
	solong->p_count = 0;
	return (ret);
}