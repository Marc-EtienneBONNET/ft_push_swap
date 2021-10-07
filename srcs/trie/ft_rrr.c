/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:22 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 16:46:17 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra(t_mem *mem, int tele)
{
	mem->a.lst = mem->a.lst->next;
	if (tele == 1)
	{
		mem->trie = ft_ajoute_trie(&(mem->trie), 5);
		if (mem->trie == NULL)
		{
			return (-1);
		}
	}
	return (1);
}

int	ft_rrb(t_mem *mem, int tele)
{
	mem->b.lst = mem->b.lst->next;
	if (tele == 1)
	{
		mem->trie = ft_ajoute_trie(&(mem->trie), 6);
		if (mem->trie == NULL)
		{
			return (-1);
		}
	}
	return (1);
}

int	ft_rrr(t_mem *mem, int tele)
{
	ft_rra(mem, 0);
	ft_rrb(mem, 0);
	if (tele == 1)
	{
		mem->trie = ft_ajoute_trie(&(mem->trie), 7);
		if (mem->trie == NULL)
		{
			return (-1);
		}
	}
	return (1);
}
