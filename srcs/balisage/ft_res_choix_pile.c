/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res_choix_pile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:07:12 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 10:19:49 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_res_choix_pile_par_nb(t_mem *mem, t_lst *fin, t_lst *ref)
{
	int		res;
	int		x;
	t_lst	*tmp;

	res = 0;
	x = -1;
	tmp = mem->a.lst;
	while (tmp->nb != ref->nb)
		tmp = tmp->next;
	while (mem->a.size > ++x)
	{
		if (tmp->nb <= ref->nb)
		{
			ref = tmp;
			res++;
		}
		if (tmp->nb == fin->nb)
			return (res);
		tmp = tmp->next;
	}
	return (res);
}

int	ft_res_choix_pile_par_index(t_mem *mem, t_lst *fin, t_lst *ref)
{
	int		res;
	int		x;
	t_lst	*tmp;

	res = 0;
	x = -1;
	tmp = mem->a.lst;
	while (tmp->index != ref->index)
		tmp = tmp->next;
	while (mem->a.size > ++x)
	{
		if (tmp->index == ref->index + 1
			|| tmp->index == ref->index)
		{
			ref = tmp;
			res++;
		}
		if (tmp->nb == fin->nb)
			return (res);
		tmp = tmp->next;
	}
	return (res);
}

int	ft_res_ou_ex_choix_pile(t_mem *mem, t_lst *fin, int tele, t_lst *ref)
{
	int		len_index;
	int		len_nb;
	int		res;
	t_lst	*tmp;

	tmp = mem->a.lst;
	len_index = ft_res_choix_pile_par_index(mem, fin, ref);
	len_nb = ft_res_choix_pile_par_nb(mem, fin, ref);
	if (len_index > len_nb)
		res = (len_index * -1);
	res = len_nb;
	if (tele == 1)
	{
		if (res < 0)
			ft_ex_choix_pile_par_index(mem, fin, ref);
		else
			ft_ex_choix_pile_par_nb(mem, fin, ref);
	}
	mem->a.lst = tmp;
	return (res);
}
