/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:55:50 by msahli            #+#    #+#             */
/*   Updated: 2021/03/26 12:55:51 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_get_pos_player(t_info *info_map, int i, int x)
{
	if (info_map->player_start == '0')
	{
		info_map->player_x = x;
		info_map->player_y = i;
		info_map->player_start = info_map->map[i][x];
		info_map->map[i][x] = '0';
	}
	else
		return (ft_management_error(7, ""));
	return (1);
}

void	ft_get_sprite_nb(t_info *info_map)
{
	int		y;
	int		x;

	y = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (info_map->map[y][x] == '2')
				info_map->sprite_nb++;
			x++;
		}
		y++;
	}
}

void	ft_get_pos_sprite(t_info *info_map, t_storage *storage)
{
	int			y;
	int			x;
	int			n;

	y = 0;
	n = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (info_map->map[y][x] == '2')
			{
				storage->sprite[n].x = (double)x + 0.5;
				storage->sprite[n].y = (double)y + 0.5;
				n++;
			}
			x++;
		}
		y++;
	}
}
