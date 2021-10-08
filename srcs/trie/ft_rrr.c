/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:22 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/08 07:22:07 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra(t_mem *mem, int tele)
{
	mem->a.lst = mem->a.lst->next;
	return (ft_retour_fonction_trie(mem, tele, 5));
}

int	ft_rrb(t_mem *mem, int tele)
{
	mem->b.lst = mem->b.lst->next;
	return (ft_retour_fonction_trie(mem, tele, 6));
}

int	ft_rrr(t_mem *mem, int tele)
{
	ft_rra(mem, 0);
	ft_rrb(mem, 0);
	return (ft_retour_fonction_trie(mem, tele, 7));
}
