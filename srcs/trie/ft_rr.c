/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:18 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/08 07:21:33 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_mem *mem, int tele)
{
	mem->a.lst = mem->a.lst->previous;
	return (ft_retour_fonction_trie(mem, tele, 2));
}

int	ft_rb(t_mem *mem, int tele)
{
	mem->b.lst = mem->b.lst->previous;
	return (ft_retour_fonction_trie(mem, tele, 3));
}

int	ft_rr(t_mem *mem, int tele)
{
	ft_ra(mem, 0);
	ft_rb(mem, 0);
	return (ft_retour_fonction_trie(mem, tele, 4));
}

int	ft_retour_fonction_trie(t_mem *mem, int tele, int trie)
{
	if (tele == 1)
	{
		mem->trie = ft_ajoute_trie(&(mem->trie), trie);
		if (mem->trie == NULL)
			return (-1);
	}
	return (1);
}
