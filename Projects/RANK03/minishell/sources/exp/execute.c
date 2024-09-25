/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:24:15 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 10:02:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	experror(char *const arg)
{
	char	*output;

	if (arg == NULL)
		return ;
	output = ft_strjoin(NAME ": export: `", arg);
	output = utils_joinfree(output, ft_strdup("': not a valid identifier\n"));
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
}

void	exp_execute(t_env *env, t_exp exp, char *const arg,
		void (*insert)(t_vars **, t_vars *))
{
	if (env == NULL)
		return ;
	if (exp.key == NULL)
		return (g_exit_status = 1, experror(arg));
	vars_export(&env->exps, exp, insert);
	if (exp.op != NULL)
		vars_export(&env->envs, exp, insert);
	utils_freestrs(env->envp);
	env->envp = utils_listtoarray(env->envs);
}
