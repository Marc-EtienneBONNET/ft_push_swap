/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:18 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 17:38:42 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_mem *mem, int tele)
{
	mem->a.lst = mem->a.lst->previous;
	if (tele == 1)
	{
		mem->trie = ft_ajoute_trie(&(mem->trie), 2);
		if (mem->trie == NULL)
		{
			return (-1);
		}
	}
	return (1);
}

int	ft_rb(t_mem *mem, int tele)
{
	mem->b.lst = mem->b.lst->previous;
	if (tele == 1)
	{
		mem->trie = ft_ajoute_trie(&(mem->trie), 3);
		if (mem->trie == NULL)
		{
			return (-1);
		}
	}
	return (1);
}

int	ft_rr(t_mem *mem, int tele)
{
	ft_ra(mem, 0);
	ft_rb(mem, 0);
	if (tele == 1)
	{
		mem->trie = ft_ajoute_trie(&(mem->trie), 4);
		if (mem->trie == NULL)
		{
			return (-1);
		}
	}
	return (1);
}
