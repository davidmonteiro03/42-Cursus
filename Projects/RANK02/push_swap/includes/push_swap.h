/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:55:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 08:47:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

enum
{
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR,
};

typedef struct s_rotate
{
	int	ops[6];
}	t_rotate;

typedef struct s_element
{
	int	number;
	int	target;
}	t_element;

// ----- Parse ----- //
long int	ft_atol(const char *nptr); // ft_atol
char		*ft_joinfree(char *s1, char *s2); // ft_joinfree
char		**ft_acumulate(char **args); // ft_acumulate
void		ft_check(char *arg, bool *flag); // ft_check
void		ft_parse(char **argv); // ft_parse
void		ft_checkdups(t_list *list); // ft_checkdups
bool		ft_smaller(void *cont1, void *cont2, int mode); // ft_smaller
bool		ft_greater(void *cont1, void *cont2, int mode); // ft_greater
bool		ft_equal(void *cont1, void *cont2, int mode); // ft_equal

// ----- Free ------ //
void		ft_free(char **ptr); // ft_free
void		free_strs(char **strs); // free_strs
void		free_content(void *content); // free_content

// ----- Error ----- //
void		ft_error(void); // ft_error

// ----- Fill ------ //
void		ft_fill(t_list **list, char **args); // ft_fill

// ----- Init ------ //
t_element	*new_element(int number); // new_element

// ---- Display ---- //
void		ft_display_content(void *content); // ft_display_content
void		ft_display(t_list *list); // ft_display

// -- Operations --- //
bool		ft_swap(t_list **list); // ft_swap
bool		ft_push(t_list **list_from, t_list **list_to); // ft_push
bool		ft_rotate(t_list **list, int mode); // ft_rotate

// ---- Execute ---- //
bool		ft_execute(char *op, \
	t_list **list_a, t_list **list_b, bool print); // ft_execute
void		ft_multiexecute(t_list **list_a, \
	t_list **list_b, t_rotate *rot); // ft_multiexecute

// ---- Sortlist --- //
void		ft_sort3(t_list **list_a); // ft_sort3
void		ft_sort(t_list **list_a, t_list **list_b); // ft_sort
void		ft_sortlist(t_list **list_a, t_list **list_b); // ft_sortlist

// ---- Utils 1 ---- //
int			ft_strcmp(const char *s1, const char *s2); // ft_strcmp
int			ft_max(int a, int b); // ft_max
int			ft_min(int a, int b); // ft_min
int			ft_countmoves(t_list *list, t_list *target); // ft_countmoves

// ---- Utils 2 ---- //
t_list		*ft_gettarget(t_list *list, \
	bool (*compare)(void *, void *, int)); // ft_gettarget
void		ft_set_targets_b(t_list **list_a, \
	t_list **list_b); // ft_set_targets_b
void		ft_set_targets_a(t_list **list_a, \
	t_list **list_b); // ft_set_targets_a
void		ft_push_best_to_b(t_list **list_a, \
	t_list **list_b, t_rotate *rot); // ft_push_best_to_b
void		ft_push_best_to_a(t_list **list_a, \
	t_list **list_b, t_rotate *rot); // ft_push_best_to_a

// ---- Utils 3 ---- //
bool		ft_issorted(t_list *list); // ft_issorted
void		ft_optimize_moves_a(t_list **list_a, t_list **list_b, \
	t_rotate *rot, t_list *node); // ft_optimize_moves_a
void		ft_optimize_moves_b(t_list **list_a, t_list **list_b, \
	t_rotate *rot, t_list *node); // ft_optimize_moves_b
void		ft_optimize(t_list **list_a, t_list **list_b, \
	t_rotate *rot, bool pos); // ft_optimize

// ---- Utils 4 ---- //
void		ft_setmoves_ultimate(t_rotate *rot, \
	int *rotate); // ft_setmoves_ultimate
void		ft_setmoves(t_rotate *rot, \
	int *rotate, bool fill); // ft_setmoves
t_list		*ft_findsecmin(t_list *list); // ft_findsecmin

#endif
