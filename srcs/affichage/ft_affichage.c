/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:07:17 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 10:07:18 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_affichage_trie(t_mem mem)
{
	int	x;

	x = -1;
	if (mem.trie != NULL)
		while (mem.trie[++x] != -1)
			if (mem.trie[x] != -2)
				ft_printf("%s\n", mem.tab_trie[mem.trie[x]]);
}

void	ft_affichage_lst(t_stack pile, char *str)
{
	int	x;

	x = 0;
	if (pile.size <= 0)
	{
		printf("PILE VIDE : %s\n", str);
		return ;
	}
	printf("\n\tEN NEXT : %s\n", str);
	printf("size : %d\n", pile.size);
	while (pile.size > x)
	{
		printf("lst : nb = %d\tindex : %d\tpile : %c\n", pile.lst->nb,
			pile.lst->index, pile.lst->pile);
		pile.lst = pile.lst->next;
		x++;
	}
}

void	ft_affichage_lst_previous(t_stack pile, char *str)
{
	int	x;

	x = 0;
	if (pile.size <= 0)
	{
		printf("PILE VIDE : %s\n", str);
		return ;
	}
	printf("\n\tEN PREVIOUS : %s\n", str);
	printf("size : %d\n", pile.size);
	while (pile.size > x - 1)
	{
		printf("lst : nb = %d\tindex : %d\tpile : %c\n", pile.lst->nb,
			pile.lst->index, pile.lst->pile);
		pile.lst = pile.lst->previous;
		x++;
	}
	printf("\n");
}
