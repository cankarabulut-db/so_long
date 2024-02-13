#include "so_long.h"

int ft_strchr(char *str,char c)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return (1);
		i++;
	}
		return (0);
}


int ft_strstrchr(char *str,char *search)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while(str[i])
	{
		i = 0;
		if(search[a])
		{
			if(search[a] == str[i])
			{
				
			}
		}
		i++;
	}
		return (0);
}
