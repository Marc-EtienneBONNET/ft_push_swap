#include "push_swap.h"

t_lst	*ft_defini_position_de_b_dans_a_2(int nb, t_mem *mem)
{
	int		x;
	int		espace;
	int		res;
	t_lst	*tmp;
	t_lst	*tmp_res;

	tmp = mem->a.lst;
	tmp_res = NULL;
	x = -1;
	res = 0;
	while (mem->a.size > ++x)
	{
		espace = nb - tmp->nb;
		if (espace > 0)
		{
			if (espace > res)
			{
				tmp_res = tmp;
				res = espace;
			}
		}
		tmp = tmp->next;
	}
	return (tmp_res);
}

t_lst	*ft_defini_position_de_b_dans_a(int nb, t_mem *mem)
{
	int		x;
	int		espace;
	int		res;
	t_lst	*tmp;
	t_lst	*tmp_res;

	tmp = mem->a.lst;
	tmp_res = NULL;
	x = -1;
	res = 2147483647;
	while (mem->a.size > ++x)
	{
		espace = tmp->nb - nb;
		if (espace > 0)
		{
			if (espace < res)
			{
				tmp_res = tmp;
				res = espace;
			}
		}
		tmp = tmp->next;
	}
	if (tmp_res == 0)
		tmp_res = ft_defini_position_de_b_dans_a_2(nb,mem);
	return (tmp_res);
}

t_lst	*ft_choix_nb_dans_pile(t_mem *mem)
{
	t_lst	*tmp;
	t_lst	*tmp_mem;
	int		x;
	int		total;
	int		res;

	x = -1;
	total = 0;
	tmp = mem->b.lst;
	res = 2147483647;
	while (mem->b.size > ++x)
	{
		total = ft_absolut(ft_compte_rb_rrb(mem, tmp));
		total += ft_absolut(ft_compte_ra_rra(mem,
					ft_defini_position_de_b_dans_a(tmp->nb, mem)));
		if (total < res)
		{
			tmp_mem = tmp;
			res = total;
		}
		tmp = tmp->next;
	}
	return (tmp_mem);
}

void	ft_ex_trie_pile(t_mem *mem, t_lst *lst)
{
	int	r_b;
	int	r_a;

	r_b = ft_compte_rb_rrb(mem, lst);
	r_a = ft_compte_ra_rra(mem, ft_defini_position_de_b_dans_a(lst->nb, mem));
	while (r_a > 0)
	{
		ft_ra(mem, 1);
		r_a--;
	}
	while (r_a < 0)
	{
		ft_rra(mem, 1);
		r_a++;
	}
	while (r_b > 0)
	{
		ft_rb(mem, 1);
		r_b--;
	}
	while (r_b < 0)
	{
		ft_rrb(mem, 1);
		r_b++;
	}
}

void	ft_ex_trie_pile_b(t_mem *mem)
{
	while (mem->b.size != 0)
	{
		if (mem->b.lst->previous->nb < mem->b.lst->previous->previous->nb)
			ft_sb(mem, 1);
		ft_ex_trie_pile(mem, ft_choix_nb_dans_pile(mem));
		ft_pa(mem, 1);
	}
}
