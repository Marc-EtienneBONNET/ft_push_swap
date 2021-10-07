/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:26 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 10:06:27 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_mem *mem, int tele)
{
	t_lst	*tmp_der;
	t_lst	*tmp_pre;
	t_lst	*tmp_av_der;
	t_lst	*tmp_av_av_der;

	if (mem->a.size > 2)
	{
		tmp_pre = mem->a.lst;
		tmp_der = mem->a.lst->previous;
		tmp_av_der = mem->a.lst->previous->previous;
		tmp_av_av_der = mem->a.lst->previous->previous->previous;
		tmp_pre->previous = tmp_av_der;
		tmp_av_av_der->next = tmp_der;
		tmp_der->next = tmp_av_der;
		tmp_der->previous = tmp_av_av_der;
		tmp_av_der->next = tmp_pre;
		tmp_av_der->previous = tmp_der;
	}
	else if (mem->a.size == 2)
		mem->a.lst = mem->a.lst->next;
	if (tele == 1)
		mem->trie = ft_ajoute_trie(&(mem->trie), 8);
}

void	ft_sb(t_mem *mem, int tele)
{
	t_lst	*tmp_der;
	t_lst	*tmp_pre;
	t_lst	*tmp_av_der;
	t_lst	*tmp_av_av_der;

	if (mem->b.size > 2)
	{
		tmp_pre = mem->b.lst;
		tmp_der = mem->b.lst->previous;
		tmp_av_der = mem->b.lst->previous->previous;
		tmp_av_av_der = mem->b.lst->previous->previous->previous;
		tmp_pre->previous = tmp_av_der;
		tmp_av_av_der->next = tmp_der;
		tmp_der->next = tmp_av_der;
		tmp_der->previous = tmp_av_av_der;
		tmp_av_der->next = tmp_pre;
		tmp_av_der->previous = tmp_der;
	}
	else if (mem->b.size == 2)
		mem->b.lst = mem->b.lst->next;
	if (tele == 1)
		mem->trie = ft_ajoute_trie(&(mem->trie), 9);
}

void	ft_ss(t_mem *mem, int tele)
{
	ft_sa(mem, 0);
	ft_sb(mem, 0);
	if (tele == 1)
		mem->trie = ft_ajoute_trie(&(mem->trie), 10);
}
