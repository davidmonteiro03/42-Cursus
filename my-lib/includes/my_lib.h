/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/22 16:27:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_H
# define MY_LIB_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <readline/readline.h>

# define TRUE 1
# define FALSE 0

typedef struct s_utils
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp_2;
	char	*tmp_3;
	int		tmp_i;
	int		tmp_j;
	int		new_line;
	size_t	len;
}t_utils;

typedef struct s_check
{
	int		status;
	char	c;
}t_check;

typedef struct t_test
{
	char	*line;
	char	*buf;
	char	**args;
	int		tmp_i;
	t_check	*check;
	t_utils	*utils;
}t_test;

char	*buildfree(char *s1, char *s2, char *(*f)(const char *, const char *));
void	multiple_free(const char *format, ...);
size_t	ft_mnstrlen(t_test *t);
void	ft_strbuild(t_test *t);

#endif