/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:59:44 by msahli            #+#    #+#             */
/*   Updated: 2021/03/31 14:46:11 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_read_map(t_info *info_map, int fd, char *line)
{
	int		i;
	char	*map_tmp;

	i = 1;
	map_tmp = (char *)malloc(sizeof(char));
	if (!(map_tmp))
		return (ft_management_error(9, "Error malloc"));
	map_tmp[0] = 0;
	line = ft_strdup_map(line);
	map_tmp = ft_strjoin_point(map_tmp, line);
	if (i == 0)
		free(line);
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		line = ft_strdup_map(line);
		map_tmp = ft_strjoin_point(map_tmp, line);
		free(line);
	}
	info_map->map = ft_split(map_tmp, '.');
	free(map_tmp);
	return (1);
}

int	ft_read_info(char *s, t_info *info_map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (ft_management_error(2, ""));
	while (((i = get_next_line(fd, &line)) != 0) && !ft_is_wall(line[0]))
	{
		if (!ft_get_info_map(line, info_map))
			return (0);
		free(line);
	}
	ft_read_map(info_map, fd, line);
	return (1);
}

int	ft_read_management(char *s, t_info *info_map)
{
	t_len_map	len;

	if (ft_check_extension(s) == 0)
	{
		ft_management_error(1, "");
		return (0);
	}
	else
	{
		if ((ft_read_info(s, info_map)) == 0)
			return (0);
		if (!ft_parse_management(info_map, &len))
			return (0);
	}
	return (1);
}
