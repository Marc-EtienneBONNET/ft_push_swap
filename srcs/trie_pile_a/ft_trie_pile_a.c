#include "push_swap.h"

int		ft_if_b(t_lst *lst, int size)
{
	while (size != 0)
	{
		if (lst->pile == 'B')
			return (-1);
		lst = lst->next;
		size--;
	}
	return (1);
}

int		ft_if_dans_l_ordre(t_lst *lst, int size)
{
	int	next;

	next = lst->nb;
	while (size > 0)
	{
		if (lst->nb > next)
			return (-1);
		else
			next = lst->nb;
		lst = lst->next;
		size--;
	}
	return (1);
}

void	ft_choix_ra_rra_2(t_mem *mem)
{
	int	tmp;
	int	tmp2;

	ft_ra(mem, 0);
	tmp = mem->a.lst->previous->nb;
	ft_rra(mem, 0);
	ft_rra(mem, 0);
	tmp2 = mem->a.lst->previous->nb;
	ft_ra(mem, 0);
	if (tmp < tmp2)
		ft_ra(mem, 1);
	else
		ft_rra(mem, 1);
}

void	ft_ex_trie_pile_a_2(t_mem *mem)
{
	int	len_balisage;
	ft_best_balisage(mem, 1);
	ft_affichage_lst(mem->a,"debut");
	while (ft_if_b(mem->a.lst, mem->a.size) == -1
		&& ft_if_dans_l_ordre(mem->a.lst, mem->a.size) == -1)
	{
		len_balisage = ft_absolut(ft_best_balisage(mem, 0));
		ft_sa(mem, 0);
		printf("len_balisage : %d\t, balisage : %d\n", len_balisage, ft_absolut(ft_best_balisage(mem, 0)));
		if (ft_absolut(ft_best_balisage(mem, 0)) > len_balisage)
		{
			ft_best_balisage(mem, 1);
			ft_sa(mem, 1);
		}
		ft_sa(mem, 0);
				ft_affichage_lst(mem->a,"apres sa");
		if (mem->a.lst->previous->pile == 'B')
			ft_pb(mem, 1);
		else if (ft_if_dans_l_ordre(mem->a.lst, mem->a.size) == -1)
			ft_choix_ra_rra_2(mem);
		ft_affichage_lst(mem->a,"apres pb ra");
	}
}

int	ft_choix_ra_rra(t_mem *mem, int len_balisage)
{
	int	len_ra;
	int	len_rra;
	int	ra;
	int	rra;
	mem->a.lst = mem->a.lst->previous;
	ra = mem->a.lst->nb;
	len_ra = ft_absolut(ft_best_balisage(mem, 0));
	mem->a.lst = mem->a.lst->next->next;
	rra = mem->a.lst->nb;
	len_rra = ft_absolut(ft_best_balisage(mem, 0));
	mem->a.lst = mem->a.lst->previous;
	if (len_rra > len_balisage || len_rra > len_balisage)
	{
		if (len_ra > len_rra)
			ft_ra(mem, 1);
		else if (len_ra <= len_rra)
			ft_rra(mem, 1);
	}
	else
		return (-1);
	return (1);
}

int ft_ex_sa(t_mem *mem)
{
	int retour;

	ft_sa(mem,0);
	retour = ft_absolut(ft_best_balisage(mem, 0));
	ft_sa(mem,0);
	return (retour);
}

int ft_ex_ra(t_mem *mem)
{
	int retour;

	ft_ra(mem, 0);
	retour = ft_absolut(ft_best_balisage(mem, 0));
	ft_rra(mem, 0);
	return (retour);
}

int ft_ex_rra(t_mem *mem)
{
	int retour;

	ft_rra(mem, 0);
	retour = ft_absolut(ft_best_balisage(mem, 0));
	ft_ra(mem, 0);
	return (retour);
}

int	ft_ex_ra_rra(t_mem *mem, int len_balisage)
{
	int	res_ra;
	int	res_rra;
	int	res_sa;

	res_ra = ft_ex_ra(mem);
	res_rra = ft_ex_rra(mem);
	res_sa = ft_ex_sa(mem);
	if (res_sa >= res_ra && res_sa >= res_rra && res_sa > len_balisage)
		ft_sa(mem, 1);
	else if (res_rra >= res_sa && res_rra >= res_ra && res_rra > len_balisage)
	{
		if (res_ra == res_rra
			&& mem->a.lst->nb > mem->a.lst->previous->previous->nb)
			ft_ra(mem, 1);
		else
			ft_rra(mem, 1);
	}
	else if (res_ra >= res_sa && res_ra >= res_rra && res_ra > len_balisage)
		ft_ra(mem, 1);
	else
		return (-1);
	return (1);
}

void	ft_ex_trie_pile_a(t_mem *mem)
{
	int	len_balisage;

	ft_absolut(ft_best_balisage(mem, 1));
	while (ft_if_b(mem->a.lst, mem->a.size) == -1
		|| ft_if_dans_l_ordre(mem->a.lst, mem->a.size) == -1)
	{
		len_balisage = ft_absolut(ft_best_balisage(mem, 1));
		if (ft_ex_ra_rra(mem, len_balisage) != 1)
			ft_pb(mem, 1);
		len_balisage = ft_absolut(ft_best_balisage(mem, 1));
	}
}
