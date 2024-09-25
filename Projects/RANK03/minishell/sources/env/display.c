/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:24:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 12:37:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	writevar(char *const key, char *const sep, char *const value)
{
	if (key == NULL || sep == NULL)
		return ;
	display_fprintf(STDOUT_FILENO, "%s%s", key, sep);
	if (value != NULL)
		ft_putstr_fd(value, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	writevar2(char *const key, char *const sep, char *const value)
{
	if (key == NULL || sep == NULL)
		return ;
	display_fprintf(STDOUT_FILENO, "declare -x %s", key);
	if (value != NULL)
		display_fprintf(STDOUT_FILENO, "%s\"%s\"", sep, value);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	envs_display(t_vars *envs, char *const underscore, char *const sep)
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
	writevar("_", sep, underscore);
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
		return (envs_display(env->envs, env->underscore, sep));
	if (printenvs == false && printexps == true)
		return (exps_display(env->exps, sep));
}
