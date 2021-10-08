/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_pile_b_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:05:50 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/08 08:27:42 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (espace < res && espace > 0 && res > 0)
		{
			tmp_res = tmp;
			res = espace;
		}
		tmp = tmp->next;
	}
	if (tmp_res == 0)
		tmp_res = ft_defini_position_de_b_dans_a_2(nb, mem);
	return (tmp_res);
}
