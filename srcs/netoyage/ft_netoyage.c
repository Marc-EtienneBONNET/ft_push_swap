/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_netoyage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:45 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 17:41:35 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_lst **lst, int size)
{
	t_lst	*tmp;
	int		x;

	x = 0;
	if (*lst == NULL)
		return ;
	tmp = NULL;
	while (size > x && (*lst)->next != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
		x++;
	}
}

int	ft_fin(t_mem *mem, int nb)
{
	if (nb == 0)
	{
		ft_traitement_tab_trie(mem);
		ft_affichage_trie(*mem);
	}
	if (mem->a.lst != NULL)
		ft_free_lst(&(mem->a.lst), mem->a.size);
	if (mem->b.lst != NULL)
		ft_free_lst(&(mem->b.lst), mem->b.size);
	if (mem->trie != NULL)
		free(mem->trie);
	if (mem->tab_trie != NULL)
		free(mem->tab_trie);
	if (nb == -1)
		ft_printf("erreur\n");
	return (nb);
}
