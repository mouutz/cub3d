#include "../cub3d.h"

char	*ft_strdup_map(char *s)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			n++;
		i++;
	}
	if (!(dest = (char *)malloc(sizeof(char) * n + 1)))
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
