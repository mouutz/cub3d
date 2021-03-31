/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:14:25 by msahli            #+#    #+#             */
/*   Updated: 2021/03/31 15:13:44 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup_map(char *s)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = -1;
	while (s[++i])
	{
		if (s[i] != ' ')
			n++;
	}
	dest = (char *)malloc(sizeof(char) * n + 1);
	if (!dest)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			dest[n++] = s[i];
		i++;
	}
	dest[n] = '\0';
	free(s);
	return (dest);
}
