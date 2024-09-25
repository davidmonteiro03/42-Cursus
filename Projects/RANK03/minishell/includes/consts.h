/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:05:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 09:54:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTS_H
# define CONSTS_H

# define PROMPT "minishell$ "
# define NAME "minishell"

# define ECHO_STR "echo"
# define CD_STR "cd"
# define PWD_STR "pwd"
# define EXPORT_STR "export"
# define UNSET_STR "unset"
# define ENV_STR "env"
# define EXIT_STR "exit"

# define DOUBLECHARSET_STR "<>"
# define SINGLECHARSET_STR "|"

# define PIPE_STR "|"
# define REDIN_STR "<"
# define REDOUT_STR ">"
# define HEREDOC_STR "<<"
# define APPEND_STR ">>"

# define SHLVL_MAX 1000

typedef enum e_type
{
	NONE_TYPE = 0,
	TEXT_TYPE = 1,
	PIPE_TYPE = 2,
	REDIN_TYPE = 3,
	REDOUT_TYPE = 4,
	HEREDOC_TYPE = 5,
	APPEND_TYPE = 6,
	SPACE_TYPE = 7,
	SQUOTE_TYPE = 8,
	DQUOTE_TYPE = 9
}	t_type;

typedef enum e_error
{
	TOKEN_ERROR = 0,
	EOF_ERROR = 1
}	t_error;

typedef enum e_mode
{
	DEFAULT_MODE = 0,
	FORK_MODE = 1,
	HEREDOC_MODE = 2,
	CONTINUE_MODE = 3,
	IGNORE_MODE = 4
}	t_mode;

#endif // !CONSTS_H
