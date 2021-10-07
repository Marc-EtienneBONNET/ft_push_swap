/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:07:00 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 10:07:01 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_index(t_mem *mem)
{
	int		x;
	t_lst	*max;
	int		index;

	index = -1;
	max = mem->a.lst;
	while (++index < mem->a.size)
	{
		x = -1;
		while (max->index != -1)
			max = max->next;
		while (mem->a.size > ++x)
		{
			if (mem->a.lst->index == -1 && mem->a.lst->nb > max->nb)
				max = mem->a.lst;
			mem->a.lst = mem->a.lst->next;
		}
		max->index = index;
	}
}
