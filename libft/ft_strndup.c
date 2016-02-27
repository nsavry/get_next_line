#include <stdlib.h>

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[n] = 0;
	return (new);
}
