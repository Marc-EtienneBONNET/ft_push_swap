#include "push_swap.h"


void	ft_free_lst(t_lst **lst, int size)
{
	t_lst	*tmp;
	int		x;

	x = 0;
	tmp = NULL;
	while (size > x)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
		x++;
	}
}
