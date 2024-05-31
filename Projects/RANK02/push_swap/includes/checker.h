/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:34:23 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 09:31:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/push_swap.h"

typedef struct s_tmpdisp
{
	t_list	*tmp;
	bool	flag;
	int		nbr;
}	t_tmpdisp;

typedef struct s_check
{
	char	buf[BUFSIZ];
	char	*buffer;
	int		ret;
	char	*line;
	char	*tmp;
	int		original_size;
}	t_check;

// ----- Parse ----- //
void	ft_parse_bonus(char **argv, bool *has_flag); // ft_parse_bonus

// ---- Checker ---- //
void	ft_putstacks(t_list *list_a, t_list *list_b, \
	int original_size); // ft_putstacks
void	ft_checker_bonus(t_check *check, t_list **list_a, \
	t_list **list_b, bool has_flag); // ft_checker_bonus

// ----- Utils ----- //
void	ft_putnbr_ultimate(int nbr); // ft_putnbr_ultimate
void	ft_fill_bonus(t_list **list, char **args); // ft_fill_bonus
int		ft_getline(char **buff, char **line); // ft_getline
void	ft_check_stack(t_tmpdisp *tmpdisp, t_list *list, \
	int original_size); // ft_check_stack

#endif
