#include "push_swap.h"

int	ft_trouve_trie_a_remplace(t_mem *mem)
{
	int	x;

	x = -1;
	while (mem->trie[++x + 1] != -1)
	{
		if ((mem->trie[x] == 8 && mem->trie[x + 1] == 9)
			|| (mem->trie[x] == 9 && mem->trie[x + 1] == 8))
			return (x);
		else if ((mem->trie[x] == 2 && mem->trie[x + 1] == 3)
			|| (mem->trie[x] == 3 && mem->trie[x + 1] == 2))
			return (x);
		else if ((mem->trie[x] == 5 && mem->trie[x + 1] == 6)
			|| (mem->trie[x] == 6 && mem->trie[x + 1] == 5))
			return (x);
	}
	return (-1);
}

void	ft_traitement_tab_trie(t_mem *mem)
{
	int	index;
	int	x;

	x = -1;
	while ((mem->trie != NULL && mem->trie[1] != -1)
		&& mem->trie[++x + 1] != -1)
	{
		index = ft_trouve_trie_a_remplace(mem);
		if (index == -1)
			return ;
		if (mem->trie[index] == 8 || mem->trie[index] == 9)
			mem->trie[index] = 10;
		if (mem->trie[index] == 2 || mem->trie[index] == 3)
			mem->trie[index] = 4;
		if (mem->trie[index] == 5 || mem->trie[index] == 6)
			mem->trie[index] = 7;
		mem->trie[index + 1] = -2;
	}
}
