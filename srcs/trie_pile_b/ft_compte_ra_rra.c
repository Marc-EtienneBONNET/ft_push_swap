/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compte_ra_rra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:05:41 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 10:05:42 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
