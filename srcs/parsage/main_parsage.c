#include "push_swap.h"

int	*ft_init_arg(int ac, char **av)
{
	int		x;
	int		*tab;
	int		verif;

	x = 0;
	verif = 1;
	errno = 0;
	tab = malloc(sizeof(int) * ac);
	if (errno != 0)
		return (NULL);
	while (ac - 1 > x)
	{
		tab[x] = ft_copie_sans_whitespace(av[x + 1], &verif);
		if (verif == -1)
		{
			free(tab);
			return (NULL);
		}
		x++;
	}
	tab[x] = 0;
	return (tab);
}

int	ft_verif_doublon(int *tab, int ac)
{
	int	x;
	int	y;

	x = 0;
	while (ac - 1 > x)
	{
		y = x + 1;
		while (ac - 1 > y)
		{
			if (tab[x] == tab[y])
				return (-1);
			y++;
		}
		x++;
	}
	return (1);
}

int	*ft_init_parsage(int ac, char **av)
{
	int	*tab;
	int	x;

	x = 0;
	tab = NULL;
	if (ac < 2)
		return (NULL);
	tab = ft_init_arg(ac, av);
	if (tab == NULL)
		return (NULL);
	if (ft_verif_doublon(tab, ac) == -1)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
