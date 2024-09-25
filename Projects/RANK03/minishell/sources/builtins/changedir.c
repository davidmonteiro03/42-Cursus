/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changedir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:25:45 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 10:02:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cderror(char *const dir, char *const error)
{
	char	*output;

	if (dir == NULL || error == NULL)
		return ;
	output = ft_strjoin(NAME ": cd: ", dir);
	output = utils_joinfree(output, ft_strdup(": "));
	output = utils_joinfree(output, ft_strdup(error));
	output = utils_joinfree(output, ft_strdup("\n"));
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
}

static char	*handlepwdoldpwd(t_env *env)
{
	char	*oldpwd;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	oldpwd = ft_strdup(vars_getvalue(env, "PWD"));
	if (oldpwd == NULL)
	{
		vars_unset(&env->envs, "OLDPWD");
		vars_resetvalue(&env->exps, "OLDPWD");
	}
	if (pwd != NULL)
	{
		exp_execute(env, (t_exp){.key = "PWD", .op = "=", .value = pwd}, NULL,
			vars_pushback);
		if (oldpwd != NULL)
		{
			exp_execute(env, (t_exp){.key = "OLDPWD", .op = "=",
				.value = oldpwd}, NULL, vars_pushback);
			free(oldpwd);
		}
		free(pwd);
	}
	return (vars_getvalue(env, "PWD"));
}

char	*builtins_changedir(char *const dir, t_env *env)
{
	int	ret;

	if (dir == NULL || *dir == '\0' || env == NULL)
		return (NULL);
	ret = chdir(dir);
	if (ret != 0)
	{
		g_exit_status = 1;
		cderror(dir, strerror(errno));
		return (NULL);
	}
	return (handlepwdoldpwd(env));
}
