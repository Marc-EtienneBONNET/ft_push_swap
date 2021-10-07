/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_pile_b_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:11:57 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 18:11:58 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ex_trie_pile_2(t_mem *mem, int r_b)
{
	int	secu;

	secu = 1;
	while (r_b > 0 && secu != -1)
	{
		secu = ft_rb(mem, 1);
		r_b--;
	}
	while (r_b < 0 && secu != -1)
	{
		secu = ft_rrb(mem, 1);
		r_b++;
	}
	if (secu == -1)
		return (-1);
	return (1);
}
