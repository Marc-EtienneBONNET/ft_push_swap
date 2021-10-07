#include "push_swap.h"

int	ft_compte_ra_2(t_mem *mem, t_lst *lst)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->a.lst;
	while (mem->a.size > ++x && mem->a.lst->nb != lst->nb)
		ft_ra(mem, 0);
	mem->a.lst = tmp;
	return (x);
}

int	ft_compte_rra_2(t_mem *mem, t_lst *lst)
{
	int		x;
	t_lst	*tmp;

	x = -1;
	tmp = mem->a.lst;
	while (mem->a.size > ++x && mem->a.lst->nb != lst->nb)
		ft_rra(mem, 0);
	mem->a.lst = tmp;
	return (x);
}

t_lst	*ft_trouve_nb_max(t_mem *mem)
{
	t_lst	*res;
	t_lst	*tmp;
	int		x;

	x = -1;
	tmp = mem->a.lst;
	res = tmp;
	while (mem->a.size > ++x)
	{
		if (tmp->nb > res->nb)
			res = tmp;
		tmp = tmp->next;
	}
	return (res);
}

void	ft_mise_header_sur_le_plus_grand(t_mem *mem)
{
	t_lst	*tmp_max;
	t_lst	*tmp;
	int		ra;
	int		rra;

	tmp = mem->a.lst;
	tmp_max = ft_trouve_nb_max(mem);
	ra = ft_compte_ra_2(mem, tmp_max);
	rra = ft_compte_rra_2(mem, tmp_max);
	if (ra < rra)
		while (ra-- > 0)
			ft_ra(mem, 1);
	else
		while (rra-- > 0)
			ft_rra(mem, 1);
}

int	main(int ac, char **av)
{
	int		*tab;
	t_mem	mem;

	tab = ft_init_parsage(ac, av);
	if (tab == NULL)
		return (-1);
	mem = ft_init_mem(&tab, ac);
	if (mem.a.lst == NULL)
		return (-1);
	else if (mem.a.size == 1)
	{
		ft_free_lst(&(mem.a.lst), mem.a.size);
		return (1);
	}
	mem.tab_trie = ft_init_cara_trie();
	ft_init_index(&mem);
	ft_ex_trie_pile_a(&mem);
	ft_ex_trie_pile_b(&mem);
	ft_mise_header_sur_le_plus_grand(&mem);
	ft_traitement_tab_trie(&mem);
	ft_affichage_trie(mem);
	ft_free_lst(&(mem.a.lst), mem.a.size);
	free(mem.trie);
	free(mem.tab_trie);
	return (0);
}
