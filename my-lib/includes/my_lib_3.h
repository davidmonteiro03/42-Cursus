/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib_3.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 10:08:02 by dcaetano         ###   ########.fr       */
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
}t_gb;

// Exec utils
void	wild_get(t_gb *gb);

// Free
char	*buildfree(char *s1, char *s2, char *(*f)(const char *, const char *));
void	multiple_free(const char *format, ...);

/* BASH IS SO DUMB */
char	*get_arg(t_gb *gb, char **strs, int i, char *last_file);

// Wildcard
int		wildcmp(char *path, char *ptrn);

#endif
