#include "../cub3d.h"

char	**ft_fill_map(t_info *info_map, char **new_map, int len_max)
{
	int		y;
	int		x;

	y = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x] != '\0')
		{
			new_map[y][x] = info_map->map[y][x];
			x++;
		}
		new_map[y][x] = '\0';
		if (x <= len_max)
		{
			while (x <= len_max)
			{
				new_map[y][x] = '1';
				x++;
			}
			new_map[y][x] = '\0';
		}
		y++;
	}
	return (new_map);
}

void	ft_malloc_new_map(t_info *info_map, int len_y, int len_max)
{
	int		y;
	char	**new_map;

	new_map = (char **)malloc(sizeof(char *) * (len_y + 1));
	if (!(new_map))
		return ;
	y = 0;
	while (y < len_y)
	{
		new_map[y] = (char *)malloc(sizeof(char) * (len_max + 1));
		if (!(new_map[y]))
			return ;
		y++;
	}
	new_map[y] = NULL;
	new_map = ft_fill_map(info_map, new_map, len_max);
	y = 0;
	while (info_map->map[y])
		free(info_map->map[y++]);
	free(info_map->map);
	info_map->map = new_map;
}

void	ft_check_len_map(t_info *info_map)
{
	int		y;
	int		x;
	int		len_max;

	y = 0;
	len_max = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (x > len_max)
				len_max = x;
			x++;
		}
		y++;
	}
	info_map->len_x = len_max;
	info_map->len_y = y;
	ft_malloc_new_map(info_map, y, len_max);
}
