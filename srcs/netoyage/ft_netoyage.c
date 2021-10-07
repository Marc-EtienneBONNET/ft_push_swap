/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_netoyage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:45 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 10:19:59 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_lst **lst, int size)
{
	t_lst	*tmp;
	int		x;

	x = 0;
	tmp = NULL;
	while (size > x)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
		x++;
	}
}
