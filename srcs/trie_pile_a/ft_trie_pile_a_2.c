/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_pile_a_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:05:56 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 10:15:44 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_b(t_lst *lst, int size)
{
	while (size != 0)
	{
		if (lst->pile == 'B')
			return (-1);
		lst = lst->next;
		size--;
	}
	return (1);
}

int	ft_if_dans_l_ordre(t_lst *lst, int size)
{
	int	next;

	next = lst->nb;
	while (size > 0)
	{
		if (lst->nb > next)
			return (-1);
		else
			next = lst->nb;
		lst = lst->next;
		size--;
	}
	return (1);
}

int	ft_ex_sa(t_mem *mem)
{
	int	retour;

	ft_sa(mem, 0);
	retour = ft_absolut(ft_best_balisage(mem, 0));
	ft_sa(mem, 0);
	return (retour);
}

int	ft_ex_ra(t_mem *mem)
{
	int	retour;

	ft_ra(mem, 0);
	retour = ft_absolut(ft_best_balisage(mem, 0));
	ft_rra(mem, 0);
	return (retour);
}

int	ft_ex_rra(t_mem *mem)
{
	int	retour;

	ft_rra(mem, 0);
	retour = ft_absolut(ft_best_balisage(mem, 0));
	ft_ra(mem, 0);
	return (retour);
}
