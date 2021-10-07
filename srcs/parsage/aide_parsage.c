#include "push_swap.h"

int	ft_close_programme(int *tab, int retour)
{
	int	x;

	x = -1;
	if (tab != NULL)
		free(tab);
	return (retour);
}

int	ft_verif_str(char *tab)
{
	int	y;

	y = 0;
	if (tab[y] == '-')
		y++;
	while (tab[y])
	{
		if (tab[y] < '0' || tab[y] > '9')
			return (-1);
		y++;
	}
	if (y == 0)
		return (-1);
	return (1);
}

long	ft_atoi_long(char *str)
{
	long	sign;
	long	res;

	res = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

int	ft_verif_int_max(char *tab)
{
	int	x;

	x = -1;
	if (ft_strlen(tab) > 11 || ft_atoi_long(tab) < -2147483648
		|| ft_atoi_long(tab) > 2147483647)
		return (-1);
	return (1);
}

int	ft_copie_sans_whitespace(char *str, int *res)
{
	char	*tmp;
	int		renvoie;

	errno = 0;
	tmp = malloc(sizeof(char) * (ft_strlen_moin_whitespace(str) + 1));
	if (errno != 0)
	{
		*res = -1;
		return (-1);
	}
	ft_sans_whitespace(str, &tmp);
	if (ft_verif_str(tmp) == -1 || ft_verif_int_max(tmp) == -1)
	{
		free(tmp);
		*res = -1;
		return (-1);
	}
	renvoie = ft_atoi(tmp);
	free(tmp);
	return (renvoie);
}
