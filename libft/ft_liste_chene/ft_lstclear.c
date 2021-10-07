/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:41:07 by mbonnet           #+#    #+#             */
/*   Updated: 2021/09/30 16:56:59 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (del)
	{
		while (*lst)
		{
			del((*lst)->content);
			tmp = *lst;
			(*lst) = tmp->next;
			free(tmp);
		}
		*lst = NULL;
	}
}
