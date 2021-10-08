/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_pile_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:05:50 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/08 08:36:34 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_ex_trie_pile_fin(t_mem *mem, int r_b)
{
	while (r_b > 0)
	{
		if (ft_rb(mem, 1) == -1)
			return (-1);
		r_b--;
	}
	while (r_b < 0)
	{
		if (ft_rrb(mem, 1) == -1)
			return (-1);
		r_b++;
	}
	return (1);
}

int	ft_ex_trie_pile(t_mem *mem, t_lst *lst)
{
	int	r_b;
	int	r_a;

	r_b = ft_compte_rb_rrb(mem, lst);
	r_a = ft_compte_ra_rra(mem, ft_defini_position_de_b_dans_a(lst->nb, mem));
	while (r_a > 0)
	{
		if (ft_ra(mem, 1) == -1)
			return (-1);
		r_a--;
	}
	while (r_a < 0)
	{
		if (ft_rra(mem, 1) == -1)
			return (-1);
		r_a++;
	}
	return (ft_ex_trie_pile_fin(mem, r_b));
}

int	ft_ex_trie_pile_b(t_mem *mem)
{
	while (mem->b.size != 0)
	{
		if (mem->b.lst->previous->nb < mem->b.lst->previous->previous->nb)
			if (ft_sb(mem, 1) == -1)
				return (-1);
		if (ft_ex_trie_pile(mem, ft_choix_nb_dans_pile(mem)) == -1
			|| ft_pa(mem, 1) == -1)
			return (-1);
	}
	return (1);
}
