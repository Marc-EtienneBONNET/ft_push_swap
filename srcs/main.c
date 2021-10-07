/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:05:32 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 18:40:07 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero_mem(t_mem *mem)
{
	mem->a.lst = NULL;
	mem->b.lst = NULL;
	mem->trie = NULL;
	mem->tab_trie = NULL;
}

int	main(int ac, char **av)
{
	int		*tab;
	t_mem	mem;

	ft_bzero_mem(&mem);
	tab = ft_init_parsage(ac, av);
	if (tab == NULL)
		return (ft_fin(&mem, -1));
	if (ac == 2)
	{
		free(tab);
		return (ft_fin(&mem, 0));
	}
	mem = ft_init_mem(&tab, ac);
	if (mem.a.lst == NULL)
		return (ft_fin(&mem, -1));
	else if (mem.a.size == 1)
		return (ft_fin(&mem, 0));
	mem.tab_trie = ft_init_cara_trie();
	if (mem.tab_trie == NULL)
		return (ft_fin(&mem, -1));
	ft_init_index(&mem);
	if (ft_ex_trie_pile_a(&mem) == -1 || ft_ex_trie_pile_b(&mem) == -1
		|| ft_mise_header_sur_le_plus_grand(&mem) == -1
		|| ft_mise_header_sur_le_plus_grand(&mem) == -1)
		return (ft_fin(&mem, -1));
	return (ft_fin(&mem, 0));
}
