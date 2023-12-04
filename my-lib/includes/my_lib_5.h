/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib_5.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 17:00:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_5_H
# define MY_LIB_5_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>

# define TRUE 1
# define FALSE 0

# define BCYN "\033[1;36m"
# define BGRN "\033[1;32m"
# define BRED "\033[1;31m"
# define RESET "\033[0m"

typedef struct s_global
{
	char	*line;
	char	c;
	char	*tmp;
	char	*tmp2;
	int		count;
	char	*buff;
	int		valid;
	char	**args;
	char	**args2;
}t_global;

// Free
char	*buildfree(char *s1, char *s2, char *(*f)(const char *, const char *));
void	multiple_free(const char *format, ...);

// Utils
void	valid_args(t_global *global, int k, int i, bool init);
void	print_strs(char **strs, int i);

#endif
