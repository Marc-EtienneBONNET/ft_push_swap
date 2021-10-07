/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:07:03 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/07 16:26:05 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_malloc_maillon(void)
{
	t_lst	*lst;

	errno = 0;
	lst = malloc(sizeof(t_lst));
	if (errno != 0)
		return (NULL);
	lst->next = NULL;
	return (lst);
}

int	ft_ajoute_fin_lst(t_lst **lst, t_lst *new)
{
	if (!new)
		return (-1);
	if (!(*lst))
		*lst = new;
	else
	{
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		(*lst)->next = new;
	}
	return (1);
}

t_lst	*ft_remplie_stack_a(int *tab, int ac, int *size)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	t_lst	*res;
	int		x;

	x = ac - 2;
	tmp2 = NULL;
	res = NULL;
	while (x >= 0)
	{
		tmp = ft_malloc_maillon();
		if (tmp == NULL)
			return (NULL);
		tmp->nb = tab[x];
		tmp->index = -1;
		tmp->pile = ' ';
		ft_ajoute_fin_lst(&(res), tmp);
		if (*size == 0)
			tmp2 = res;
		(*size)++;
		x--;
	}
	res = tmp2;
	return (res);
}

void	ft_ajoute_previous(t_mem *mem)
{
	int		x;
	t_lst	*tmp;
	t_lst	*tmp2;

	if (mem->a.size == 1)
	{
		mem->a.lst->previous = mem->a.lst;
		mem->a.lst->next = mem->a.lst;
		return ;
	}
	x = 0;
	tmp = mem->a.lst;
	tmp2 = mem->a.lst;
	mem->a.lst = mem->a.lst->next;
	while (mem->a.size - 1 > x)
	{
		mem->a.lst->previous = tmp;
		tmp = mem->a.lst;
		if (x != mem->a.size - 2)
			mem->a.lst = mem->a.lst->next;
		x++;
	}
	mem->a.lst->next = tmp2;
	tmp2->previous = mem->a.lst;
	mem->a.lst = tmp2;
}

t_mem	ft_init_mem(int **tab, int ac)
{
	t_mem	mem;

	mem.a.lst = NULL;
	mem.a.size = 0;
	mem.b.lst = NULL;
	mem.b.size = 0;
	mem.trie = NULL;
	mem.a.lst = ft_remplie_stack_a(*tab, ac, &(mem.a.size));
	free(*tab);
	ft_ajoute_previous(&mem);
	return (mem);
}
