#include "push_swap.h"

int	ft_compte_rb(t_mem *mem, t_lst *lst)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->b.lst;
	while (mem->b.size > ++x && mem->b.lst->previous->nb != lst->nb)
		ft_rb(mem, 0);
	mem->b.lst = tmp;
	return (x);
}

int	ft_compte_rrb(t_mem *mem, t_lst *lst)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->b.lst;
	while (mem->b.size > ++x && mem->b.lst->previous->nb != lst->nb)
		ft_rrb(mem, 0);
	mem->b.lst = tmp;
	return (x);
}

int	ft_compte_rb_rrb(t_mem *mem, t_lst *lst)
{
	int	rb;
	int	rrb;

	rb = ft_compte_rb(mem, lst);
	rrb = ft_compte_rrb(mem, lst);
	if (rb > rrb)
		return (rrb * -1);
	return (rb);
}
