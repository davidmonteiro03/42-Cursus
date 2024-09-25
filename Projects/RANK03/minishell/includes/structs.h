/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:00:42 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 07:17:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "consts.h"
# include "headers.h"

typedef struct s_cmds	t_cmds;
typedef struct s_env	t_env;
typedef struct s_exp	t_exp;
typedef struct s_files	t_files;
typedef struct s_shell	t_shell;
typedef struct s_tmp	t_tmp;
typedef struct s_tokens	t_tokens;
typedef struct s_vars	t_vars;

typedef struct s_cmds
{
	t_files				*files;
	t_tokens			*tokens;
	char				*path;
	char				**args;
	pid_t				pid;
	int					pipefd[2];
	struct s_cmds		*prev;
	struct s_cmds		*next;
}						t_cmds;

typedef struct s_env
{
	t_vars				*envs;
	t_vars				*exps;
	char				**envp;
	char				*underscore;
}						t_env;

typedef struct s_exp
{
	char				*key;
	char				*op;
	char				*value;
}						t_exp;

typedef struct s_files
{
	int					fd;
	t_type				type;
	char				*name;
	struct s_files		*prev;
	struct s_files		*next;
}						t_files;

typedef struct s_temp
{
	pid_t				pid;
	int					pipefd[2];
	int					redirfd[2];
	char				*word;
}						t_temp;

typedef struct s_tmp
{
	int					i;
	int					len;
	int					fd;
}						t_tmp;

typedef struct s_tokens
{
	char				*value;
	t_type				type;
	struct s_tokens		*prev;
	struct s_tokens		*next;
}						t_tokens;

typedef struct s_vars
{
	char				*key;
	char				*value;
	struct s_vars		*prev;
	struct s_vars		*next;
}						t_vars;
typedef struct s_shell
{
	char				*line;
	t_env				env;
	t_tokens			*tokens;
	t_cmds				*cmds;
	t_temp				temp;
}						t_shell;

#endif // !STRUCTS_H
