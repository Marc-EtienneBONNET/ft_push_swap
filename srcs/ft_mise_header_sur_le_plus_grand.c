/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mise_header_sur_le_plus_grand.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:21:27 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/08 08:22:11 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_compte_ra_2(t_mem *mem, t_lst *lst)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->a.lst;
	while (mem->a.size > ++x && mem->a.lst->nb != lst->nb)
		ft_ra(mem, 0);
	mem->a.lst = tmp;
	return (x);
}

int	ft_compte_rra_2(t_mem *mem, t_lst *lst)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->a.lst;
	while (mem->a.size > ++x && mem->a.lst->nb != lst->nb)
		ft_rra(mem, 0);
	mem->a.lst = tmp;
	return (x);
}

t_lst	*ft_trouve_nb_max(t_mem *mem)
{
	t_lst	*res;
	t_lst	*tmp;
	int		x;

	x = -1;
	tmp = mem->a.lst;
	res = tmp;
	while (mem->a.size > ++x)
	{
		if (tmp->nb > res->nb)
			res = tmp;
		tmp = tmp->next;
	}
	return (res);
}

int	ft_mise_header_sur_le_plus_grand(t_mem *mem)
{
	t_lst	*tmp_max;
	t_lst	*tmp;
	int		ra;
	int		rra;

	tmp = mem->a.lst;
	tmp_max = ft_trouve_nb_max(mem);
	ra = ft_compte_ra_2(mem, tmp_max);
	rra = ft_compte_rra_2(mem, tmp_max);
	if (ra < rra)
	{
		while (ra-- > 0)
			if (ft_ra(mem, 1) == -1)
				return (-1);
	}
	else
	{
		while (rra-- > 0)
			if (ft_rra(mem, 1) == -1)
				return (-1);
	}
	return (1);
}
