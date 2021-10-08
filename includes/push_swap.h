/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:03:15 by mbonnet           #+#    #+#             */
/*   Updated: 2021/10/08 08:27:58 by mbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include <errno.h>

typedef struct s_lst
{
	int				nb;
	int				index;
	char			pile;
	struct s_lst	*next;
	struct s_lst	*previous;
}	t_lst;

typedef struct s_stack
{
	t_lst	*lst;
	int		size;
}	t_stack;

typedef struct s_mem
{
	t_stack	a;
	t_stack	b;
	int		*trie;
	char	**tab_trie;
}	t_mem;

int		*ft_init_parsage(int ac, char **av);
int		ft_close_programme(int *tab, int retour);
int		ft_verif_str(char *tab);
long	ft_atoi_long(char *str);
int		ft_verif_int_max(char *tab);
int		ft_copie_sans_whitespace(char *str, int *res);
t_mem	ft_init_mem(int **tab, int ac);
void	ft_free_lst(t_lst **lst, int size);
int		ft_sa(t_mem *mem, int tele);
int		ft_sb(t_mem *mem, int tele);
int		ft_ss(t_mem *mem, int tele);
int		ft_ra(t_mem *mem, int tele);
int		ft_rb(t_mem *mem, int tele);
int		ft_rr(t_mem *mem, int tele);
int		ft_rra(t_mem *mem, int tele);
int		ft_rrb(t_mem *mem, int tele);
int		ft_rrr(t_mem *mem, int tele);
int		ft_pb(t_mem *mem, int tele);
int		ft_pa(t_mem *mem, int tele);
int		ft_retour_fonction_trie(t_mem *mem, int tele, int trie);
int		*ft_ajoute_trie(int **trie, int num_trie);
char	**ft_init_cara_trie(void);
void	ft_affichage_trie(t_mem mem);
void	ft_init_index(t_mem *mem);
void	ft_affichage_lst_previous(t_stack pile, char *str);
void	ft_affichage_lst(t_stack pile, char *str);
int		ft_res_ou_ex_choix_pile(t_mem *mem, t_lst *fin, int tele, t_lst *ref);
int		ft_res_choix_pile_par_index(t_mem *mem, t_lst *fin, t_lst *ref);
int		ft_res_choix_pile_par_nb(t_mem *mem, t_lst *fin, t_lst *ref);
int		ft_absolut(int x);
void	ft_ex_choix_pile_par_nb(t_mem *mem, t_lst *fin, t_lst *ref);
void	ft_ex_choix_pile_par_index(t_mem *mem, t_lst *fin, t_lst *ref);
int		ft_best_balisage(t_mem *mem, int tele);
int		ft_ex_trie_pile_a(t_mem *mem);
int		ft_ex_trie_pile_b(t_mem *mem);
int		ft_compte_rb_rrb(t_mem *mem, t_lst *lst);
int		ft_compte_ra_rra(t_mem *mem, t_lst *lst);
void	ft_traitement_tab_trie(t_mem *mem);
int		ft_ex_rra(t_mem *mem);
int		ft_ex_ra(t_mem *mem);
int		ft_ex_sa(t_mem *mem);
int		ft_if_dans_l_ordre(t_lst *lst, int size);
int		ft_if_b(t_lst *lst, int size);
int		ft_fin(t_mem *mem, int nb);
int		ft_mise_header_sur_le_plus_grand(t_mem *mem);
t_lst	*ft_defini_position_de_b_dans_a(int nb, t_mem *mem);

#endif
