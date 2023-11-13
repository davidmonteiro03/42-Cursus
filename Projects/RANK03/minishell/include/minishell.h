/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:39:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 19:33:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BRED "\e[1;91m"
# define BGRN "\e[1;92m"
# define BYLW "\e[1;93m"
# define BCYN "\e[1;96m"
# define BWHT "\e[1;97m"
# define RESET "\e[0m"

# include "../libs/libft/libft.h"
# include "../libs/libft/get_next_line.h"
# include <readline/readline.h>
# include <readline/history.h>

# define EXIT "exit"
# define LS "ls"

typedef struct s_dir
{
	bool	type;
	char	*name;
}t_dir;

typedef struct s_mini
{
	char	**env;
	int		size;
	char	**args;
	char	*command;
	char	*pwd;
	char	*home;
	char	*input;
	t_dir	*dir;
}t_mini;

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

void	usage(void);
void	error(void);

/* ************************************************************************** */
/*                                    EXEC                                    */
/* ************************************************************************** */

int		exec_mini(t_mini *mini);

/* ************************************************************************** */
/*                                    EXIT                                    */
/* ************************************************************************** */

void	exit_mini(t_mini *mini, int status);

/* ************************************************************************** */
/*                                    FREE                                    */
/* ************************************************************************** */

void	multiple_free(const char *format, ...);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

t_mini	*init_mini(char **env);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

char	*ft_jointfree2(char *s1, char *s2);
char	*ft_jointfree(char *s1, char *s2);

#endif
