#include "libft.h"

void	ft_sans_whitespace(char *str, char **res)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (str[++x])
	{
		if (ft_whitespace(str[x]) == 0)
			(*res)[++y] = str[x];
	}
	(*res)[++y] = '\0';
}
