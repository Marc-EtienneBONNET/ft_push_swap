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
