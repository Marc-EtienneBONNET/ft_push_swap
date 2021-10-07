#include "push_swap.h"

int	ft_compte_ra(t_mem *mem, t_lst *lst)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->a.lst;
	while (mem->a.size > ++x && mem->a.lst->previous->nb != lst->nb)
		ft_ra(mem, 0);
	mem->a.lst = tmp;
	return (x);
}

int	ft_compte_rra(t_mem *mem, t_lst *lst)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->a.lst;
	while (mem->a.size > ++x && mem->a.lst->previous->nb != lst->nb)
		ft_rra(mem, 0);
	mem->a.lst = tmp;
	return (x);
}

int	ft_compte_ra_rra(t_mem *mem, t_lst *lst)
{
	int	ra;
	int	rra;

	ra = ft_compte_ra(mem, lst);
	rra = ft_compte_rra(mem, lst);
	if (ra > rra)
		return (rra * -1);
	return (ra);
}
