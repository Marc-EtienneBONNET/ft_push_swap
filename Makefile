# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 15:14:49 by mbonnet           #+#    #+#              #
#    Updated: 2021/10/07 18:11:23 by mbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS			=	main.c\
					parsage/main_parsage.c\
					parsage/aide_parsage.c\
					mem/ft_init_mem.c\
					mem/ft_init_index.c\
					netoyage/ft_netoyage.c\
					trie/ft_s.c\
					trie/ft_rr.c\
					trie/ft_rrr.c\
					trie/ft_p.c\
					memoire_trie/ft_ajoute_trie.c\
					memoire_trie/ft_init_cara_trie.c\
					affichage/ft_affichage.c\
					balisage/ft_res_choix_pile.c\
					balisage/ft_ex_choix_pile.c\
					trie_pile_a/ft_trie_pile_a.c\
					trie_pile_a/ft_mise_pointeur_sur_le_plus_grand.c\
					trie_pile_a/ft_trie_pile_a_2.c\
					trie_pile_b/ft_trie_pile_b_2.c\
					trie_pile_b/ft_trie_pile_b.c\
					trie_pile_b/ft_compte_rb_rrb.c\
					trie_pile_b/ft_compte_ra_rra.c\
					traitement_tab_trie/ft_traitement_tab_trie.c\


OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

HEAD			=	-I includes -I libft/includes

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g

LIBFT_DIR		=	libft

LDFLAGS			=	-L ${LIBFT_DIR} -lft

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C ${LIBFT_DIR}
					${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}


all				:	${NAME}

clean			:
					make clean -C ${LIBFT_DIR}
					rm -rf ${OBJS}

fclean			:	clean
					make fclean -C ${LIBFT_DIR}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
