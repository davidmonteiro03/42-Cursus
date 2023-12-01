/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib_4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 13:55:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_4_H
# define MY_LIB_4_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <sys/stat.h>

# define TRUE 1
# define FALSE 0

typedef struct s_global
{
	char	*line;
	char	**input_args;
	char	***old_args;
	char	***new_args;
	char	**exec_args;
	char	*command;
	int		total;
}t_global;

// Free
char	*buildfree(char *s1, char *s2, char *(*f)(const char *, const char *));
void	multiple_free(const char *format, ...);

// Parse dir
int		read_dir(char *pattern, int count);
int		construct_args(char *pattern, int count, char ***temp);
char	**new_args(char **src, int size);
void	olg_args_to_exec_args(t_global *global, char ***strs, int i, int k);

// Utils
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strlow(char *str);
void	sort_strs(char ***old, char **new, int i);
int		count_print_strs(char **strs, int i, int count);
char	*new_args_util(const char *src);

// Wildcard
int		wildcmp(char *path, char *pattern);

#endif
