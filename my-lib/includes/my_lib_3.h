/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib_3.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 11:33:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_3_H
# define MY_LIB_3_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0

typedef struct s_gb
{
	char			*in;
	char			*ln;
	DIR				*dr;
	struct dirent	*pt;
	struct stat		st;
	char			*cm;
	char			**as;
	int				ai;
	char			**ag;
	int				fg;
	int				*tb;
	char			**tp;
}t_gb;

// Exec utils
void	wild_get(t_gb *gb);

// Free
char	*buildfree(char *s1, char *s2, char *(*f)(const char *, const char *));
void	multiple_free(const char *format, ...);

// Utils
int		get_strs_size(char **strs, int i);
void	print_strs(char **strs, int i);
char	**strs_rng(char **strs, int bgn, int end, int i);
char	*get_arg(t_gb *gb, char *first, char *last);

// Wildcard
int		wildcmp(char *path, char *ptrn);

#endif
