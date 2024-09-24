/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdspecific.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:24:18 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 20:35:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cdkeyerror(char *const key)
{
	char	*output;

	if (key == NULL)
		return ;
	output = ft_strjoin(NAME ": cd: ", key);
	output = utils_joinfree(output, ft_strdup(" not set\n"));
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
		return ;
	}
}

void	builtins_cdspecific(char *const key, t_env *env)
{
	char	*dir;
	char	*pwd;

	if (key == NULL || env == NULL)
		return ;
	dir = vars_getvalue(env, key);
	if (dir == NULL)
	{
		g_exit_status = 1;
		cdkeyerror(key);
		return ;
	}
	pwd = builtins_changedir(dir, env);
	if (utils_strcmp(key, "OLDPWD") == 0 && pwd != NULL)
		ft_putendl_fd(pwd, STDOUT_FILENO);
}
