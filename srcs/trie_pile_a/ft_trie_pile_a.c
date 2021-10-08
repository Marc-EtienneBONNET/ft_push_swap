/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_pile_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:05:56 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/08 07:42:20 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ex_ra_rra(t_mem *mem, int len_balisage)
{
	int	res_ra;
	int	res_rra;
	int	res_sa;
	int	x;

	res_ra = ft_ex_ra(mem);
	res_rra = ft_ex_rra(mem);
	res_sa = ft_ex_sa(mem);
	if (res_sa >= res_ra && res_sa >= res_rra && res_sa > len_balisage)
		x = ft_sa(mem, 1);
	else if (res_rra >= res_sa && res_rra >= res_ra && res_rra > len_balisage)
	{
		if (res_ra == res_rra
			&& mem->a.lst->nb > mem->a.lst->previous->previous->nb)
			x = ft_ra(mem, 1);
		else
			x = ft_rra(mem, 1);
	}
	else if (res_ra >= res_sa && res_ra >= res_rra && res_ra > len_balisage)
		x = ft_ra(mem, 1);
	else
		return (-1);
	if (x < 0)
		return (-2);
	return (1);
}

int	ft_ex_trie_pile_a(t_mem *mem)
{
	int	len_balisage;
	int	res;

	res = 0;
	ft_absolut(ft_best_balisage(mem, 1));
	while (ft_if_b(mem->a.lst, mem->a.size) == -1
		|| ft_if_dans_l_ordre(mem->a.lst, mem->a.size) == -1)
	{
		len_balisage = ft_absolut(ft_best_balisage(mem, 1));
		res = ft_ex_ra_rra(mem, len_balisage);
		if (res != 1)
		{
			if (res == -2)
				return (-1);
			else if (ft_pb(mem, 1) == -1)
				return (-1);
		}
		len_balisage = ft_absolut(ft_best_balisage(mem, 1));
	}
	return (1);
}
