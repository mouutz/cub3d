/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:24:50 by msahli            #+#    #+#             */
/*   Updated: 2021/03/26 12:24:51 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit_prog(t_storage *storage)
{
	int		y;

	y = 0;
	while (storage->info->map[y])
	{
		free(storage->info->map[y]);
		y++;
	}
	free(storage->info->map[y]);
	free(storage->info->map);
	mlx_clear_window(storage->mlx->ptr, storage->mlx->win);
	mlx_destroy_window(storage->mlx->ptr, storage->mlx->win);
	exit(0);
	return (1);
}
