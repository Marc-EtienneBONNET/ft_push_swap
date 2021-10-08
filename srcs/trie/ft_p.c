/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:15 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/08 07:25:24 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pousse_dans_b(t_mem *mem, t_lst *new)
{
	t_lst	*tmp;

	tmp = mem->b.lst->previous;
	tmp->next = new;
	new->next = mem->b.lst;
	new->previous = mem->b.lst->previous;
	mem->b.lst->previous = new;
}

int	ft_pb(t_mem *mem, int tele)
{
	t_lst	*new;
	t_lst	*tmp_av_der;
	t_lst	*tmp_deb;

	if (mem->a.size <= 1)
		return (1);
	new = mem->a.lst->previous;
	tmp_deb = mem->a.lst;
	tmp_av_der = mem->a.lst->previous->previous;
	tmp_deb->previous = tmp_av_der;
	tmp_av_der->next = tmp_deb;
	mem->a.lst = tmp_deb;
	if (mem->b.size == 0)
	{
		mem->b.lst = new;
		mem->b.lst->next = mem->b.lst;
		mem->b.lst->previous = mem->b.lst;
	}
	else
		ft_pousse_dans_b(mem, new);
	mem->b.size++;
	mem->a.size--;
	return (ft_retour_fonction_trie(mem, tele, 1));
}

void	ft_pousse_dans_a(t_mem *mem, t_lst *new)
{
	int		x;
	t_lst	*tmp;

	if (mem->a.size == 0)
	{
		mem->a.lst = new;
		mem->a.lst->next = mem->b.lst;
		mem->a.lst->previous = mem->b.lst;
	}
	else
	{
		tmp = mem->a.lst;
		x = 0;
		while (mem->a.size > ++x)
			mem->a.lst = mem->a.lst->next;
		mem->a.lst->next = new;
		mem->a.lst->next->next = tmp;
		mem->a.lst->next->previous = mem->a.lst;
		tmp->previous = new;
		mem->a.lst = tmp;
	}
}

int	ft_pa(t_mem *mem, int tele)
{
	t_lst	*new;
	t_lst	*tmp_av_der;
	t_lst	*tmp_deb;

	if (mem->b.size == 0)
		return (1);
	new = mem->b.lst->previous;
	if (mem->b.size != 1)
	{
		tmp_deb = mem->b.lst;
		tmp_av_der = mem->b.lst->previous->previous;
		tmp_deb->previous = tmp_av_der;
		tmp_av_der->next = tmp_deb;
		mem->b.lst = tmp_deb;
	}
	else
		mem->b.lst = NULL;
	ft_pousse_dans_a(mem, new);
	mem->a.size++;
	mem->b.size--;
	return (ft_retour_fonction_trie(mem, tele, 0));
}
