/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib_3.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 14:25:38 by dcaetano         ###   ########.fr       */
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

# define BCYN "\033[1;36m"
# define BRED "\033[1;31m"
# define BGRN "\033[1;32m"
# define BBLK "\033[1;30m"
# define RESET "\033[0m"

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
	pid_t			pd;
	int				ss;
}t_gb;

// Exec utils
void	wild_get(t_gb *gb);

// Free
char	*buildfree(char *s1, char *s2, char *(*f)(const char *, const char *));
void	multiple_free(const char *format, ...);

// Utils
int		dsp_sz(char **strs, int i, int print);
char	**strs_rng(char **strs, int bgn, int end, int i);
char	*get_arg(t_gb *gb, char *first, char *last);
void	dsp_err(char *err);

// Wildcard
int		wildcmp(char *path, char *ptrn);

#endif
