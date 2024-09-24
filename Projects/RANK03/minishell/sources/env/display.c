/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:24:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/23 09:01:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	writevar(char *const key, char *const sep, char *const value)
{
	char	*output;

	if (key == NULL || sep == NULL)
		return ;
	output = ft_strjoin(key, sep);
	if (value != NULL)
		output = utils_joinfree(output, ft_strdup(value));
	output = utils_joinfree(output, ft_strdup("\n"));
	if (output != NULL)
	{
		write(STDOUT_FILENO, output, ft_strlen(output));
		free(output);
	}
}

static void	writevar2(char *const key, char *const sep, char *const value)
{
	char	*output;

	if (key == NULL || sep == NULL)
		return ;
	output = ft_strjoin("declare -x ", key);
	if (value != NULL)
	{
		output = utils_joinfree(output, ft_strdup(sep));
		output = utils_joinfree(output, ft_strdup("\""));
		output = utils_joinfree(output, ft_strdup(value));
		output = utils_joinfree(output, ft_strdup("\""));
	}
	output = utils_joinfree(output, ft_strdup("\n"));
	if (output != NULL)
	{
		write(STDOUT_FILENO, output, ft_strlen(output));
		free(output);
	}
}

static void	envs_display(t_vars *envs, char *const sep)
{
	t_vars	*iter;

	if (envs == NULL || sep == NULL)
		return ;
	iter = vars_first(envs);
	while (iter != NULL)
	{
		writevar(iter->key, sep, iter->value);
		iter = iter->next;
	}
}

static void	exps_display(t_vars *exps, char *const sep)
{
	t_vars	*iter;

	if (exps == NULL || sep == NULL)
		return ;
	iter = vars_first(exps);
	vars_sort(iter);
	while (iter != NULL)
	{
		writevar2(iter->key, sep, iter->value);
		iter = iter->next;
	}
}

void	env_display(t_env *env, char *const sep, bool printenvs, bool printexps)
{
	if (env == NULL || sep == NULL || (printenvs == false
			&& printexps == false))
		return ;
	if (printenvs == true && printexps == false)
		return (envs_display(env->envs, sep));
	if (printenvs == false && printexps == true)
		return (exps_display(env->exps, sep));
}
