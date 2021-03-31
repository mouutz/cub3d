/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msahli <msahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:21:00 by msahli            #+#    #+#             */
/*   Updated: 2021/03/31 15:37:41 by msahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strdup_c(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char)*(ft_strlen_c(str, c) + 1));
	if (!new)
		return (NULL);
	while (str && str[i] && str[i] != c)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strcut_c(char *str, char c)
{
	int		i;

	i = 0;
	if (!(str))
		return (NULL);
	if (ft_is_c(str, c) == 0)
		return (NULL);
	while (str[i] != c)
		i++;
	i++;
	return (ft_strdup_c(&str[i], '\0'));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char)
			*((ft_strlen_c(s1, '\0') + ft_strlen_c(s2, '\0') + 1)));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}
