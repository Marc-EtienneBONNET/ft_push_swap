/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajoute_trie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:49 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 10:06:50 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_ajoute_trie(int **trie, int num_trie)
{
	int	x;
	int	*new_tab;

	x = 0;
	errno = 0;
	if (*trie == NULL)
		new_tab = malloc(sizeof(int) * 2);
	else
	{
		while ((*trie)[x] != -1)
			x++;
		new_tab = malloc(sizeof(int) * (x + 2));
		x = -1;
		while ((*trie)[++x] != -1)
			new_tab[x] = (*trie)[x];
		free(*trie);
	}
	if (errno != 0)
		return (NULL);
	new_tab[x++] = num_trie;
	new_tab[x] = -1;
	return (new_tab);
}
