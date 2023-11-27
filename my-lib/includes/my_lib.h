/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:38:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 19:26:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_H
# define MY_LIB_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <readline/readline.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/stat.h>

# define TRUE 1
# define FALSE 0

typedef struct s_g
{
	char			*l;
	DIR				*d;
	struct dirent	*e;
	struct stat		st;
	char			**v;
	char			**a;
	int				len;
}t_g;

char	*buildfree(char *s1, char *s2, char *(*f)(const char *, const char *));
void	multiple_free(const char *format, ...);

#endif
