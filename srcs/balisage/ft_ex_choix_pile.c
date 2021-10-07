#include "push_swap.h"

int	ft_absolut(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void	ft_ex_choix_pile_par_nb(t_mem *mem, t_lst *fin, t_lst *ref)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->a.lst;
	while (tmp->nb != ref->nb)
	{
		tmp->pile = 'B';
		tmp = tmp->next;
	}
	while (mem->a.size > ++x)
	{
		if (tmp->nb <= ref->nb)
		{
			tmp->pile = 'A';
			ref = tmp;
		}
		else
			tmp->pile = 'B';
		if (tmp->nb == fin->nb)
			return ;
		tmp = tmp->next;
	}
	printf("\n\n");
}

void	ft_ex_choix_pile_par_index(t_mem *mem, t_lst *fin, t_lst *ref)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->a.lst;
	while (tmp->index != ref->index)
	{
		tmp->pile = 'B';
		tmp = tmp->next;
	}
	while (mem->a.size > ++x)
	{
		if (tmp->index == ref->index + 1
			|| ref->index == tmp->index)
		{
			tmp->pile = 'A';
			ref = tmp;
		}
		else
			tmp->pile = 'B';
		if (tmp->nb == fin->nb)
			return ;
		tmp = tmp->next;
	}

}

int	ft_best_balisage(t_mem *mem, int tele)
{
	int		x;
	t_lst	*ref;
	int		len_balisage;
	t_lst	*tmp;

	x = -1;
	ref = mem->a.lst;
	len_balisage = ft_absolut(ft_res_ou_ex_choix_pile(
				mem, mem->a.lst->previous, 0, ref));
	tmp = mem->a.lst;
	while (mem->a.size - 1 > ++x)
	{
		ref = ref->next;
		if (ft_absolut(ft_res_ou_ex_choix_pile(
					mem, mem->a.lst->previous, 0, ref)) > len_balisage)
		{
			tmp = ref;
			len_balisage = ft_absolut(ft_res_ou_ex_choix_pile(mem,
						mem->a.lst->previous, 0, ref));
		}
	}
	if (tele == 1)
		ft_res_ou_ex_choix_pile(mem, mem->a.lst->previous, 1, tmp);
	return (len_balisage);
}
