/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:02:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/27 07:30:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////
//                                  LIST DATA                                 //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_data
{
	int	*tab;
	int	size;
}t_data;

////////////////////////////////////////////////////////////////////////////////
//                               LIST STRUCTURE                               //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

////////////////////////////////////////////////////////////////////////////////
//                                  CALCULATE                                 //
////////////////////////////////////////////////////////////////////////////////

int		lcm(int pos[2], int size_a, int size_b, bool move);
int		calc(t_node *stack_a, t_node *stack_b, int size, bool pos_b);
int		execute_calc(t_node *stack_a, t_node *stack_b, int size, bool pos_b);
void	reverse_pos(t_node **stack_a, t_node **stack_b, int pos[2]);

////////////////////////////////////////////////////////////////////////////////
//                                   ERRORS                                   //
////////////////////////////////////////////////////////////////////////////////

void	errorargs(char **strs);
void	errorall(int *tab, char **strs);
void	errorlst(t_node *stack);

////////////////////////////////////////////////////////////////////////////////
//                                 OPERATIONS                                 //
////////////////////////////////////////////////////////////////////////////////

bool	swap(t_node **stack);
bool	push(t_node **stack_from, t_node **stack_to);
bool	rotate(t_node **stack, bool reverse);
bool	execute(t_node **stack_a, t_node **stack_b, char *line, bool display);
bool	multi_execute(t_node **stack_a, t_node **stack_b, char *line, int n);

////////////////////////////////////////////////////////////////////////////////
//                              PREPARE ARGUMENTS                             //
////////////////////////////////////////////////////////////////////////////////

char	*ft_jointfree(char *str, char *buff);
int		getlen(char **strs);
void	freechars(char **strs);
char	**jointsplit(int len, char **av);
void	validargs(char **strs);

////////////////////////////////////////////////////////////////////////////////
//                               PREPARE NUMBERS                              //
////////////////////////////////////////////////////////////////////////////////

long	ft_atol(const char *nptr);
int		findrep(int *tab, int len);
int		*validnums(char **strs);

////////////////////////////////////////////////////////////////////////////////
//                                  PUSH_SWAP                                 //
////////////////////////////////////////////////////////////////////////////////

void	execute_ps(t_node **stack_a, t_node **stack_b, int pos[2], int mode);
void	sort3(t_node *stack_a);
void	simple_sort(t_node *stack_a, t_node *stack_b, int size);
void	sort(t_node *stack_a, t_node *stack_b);
void	push_swap(t_node *stack_a, t_node *stack_b, int size);

////////////////////////////////////////////////////////////////////////////////
//                                    SORT                                    //
////////////////////////////////////////////////////////////////////////////////

int		find_target(t_node *stack_from, t_node *stack_to);
void	push_target(t_node *stack, int pos);
void	exec_smt(t_node **stack_a, t_node **stack_b, int pos[2], int mode);

////////////////////////////////////////////////////////////////////////////////
//                                 SORT UTILS                                 //
////////////////////////////////////////////////////////////////////////////////

bool	sorted(t_node *stack, bool reverse);
int		node_index(t_node *stack, int target);
int		posminmax(t_node *stack, bool max, bool pos);
void	pushminmax(t_node *stack, bool max);
int		find_min_index(t_node *stack_a, t_node *stack_b, int size);

////////////////////////////////////////////////////////////////////////////////
//                                 STACK UTILS                                //
////////////////////////////////////////////////////////////////////////////////

void	lstdisplay(t_node *stack, char *str, bool pro, bool first);
t_node	*createnode(int content);
void	lstfree(t_node *node);
t_node	*addnode(t_node *node, int content);
t_node	*frstlastnode(t_node *node, bool last);

////////////////////////////////////////////////////////////////////////////////
//                                    UTILS                                   //
////////////////////////////////////////////////////////////////////////////////

int		max(int a, int b);
int		min(int a, int b);
int		stacksize(t_node *stack);
int		ft_strcmp(const char *s1, const char *s2);

#endif
