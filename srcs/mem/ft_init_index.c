#include "push_swap.h"

void	ft_init_index(t_mem *mem)
{
	int		x;
	t_lst	*max;
	int		index;

	index = -1;
	max = mem->a.lst;
	while (++index < mem->a.size)
	{
		x = -1;
		while (max->index != -1)
			max = max->next;
		while (mem->a.size > ++x)
		{
			if (mem->a.lst->index == -1 && mem->a.lst->nb > max->nb)
				max = mem->a.lst;
			mem->a.lst = mem->a.lst->next;
		}
		max->index = index;
	}
}
