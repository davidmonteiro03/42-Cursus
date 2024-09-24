/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:58:05 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 10:34:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	fillvariables(t_env *env, char *const *envp,
		void (*insert)(t_vars **, t_vars *))
{
	t_vars	*node;
	size_t	i;

	if (env == NULL || envp == NULL)
		return ;
	i = 0;
	while (envp[i] != NULL)
	{
		node = vars_new(envp[i]);
		if (node == NULL)
			return (vars_clear(&env->envs));
		if (utils_strcmp(node->key, "_") != 0)
			insert(&env->envs, node);
		else
			vars_clear(&node);
		++i;
	}
}

void	env_init(t_env *env, char *const *envp, void (*insert)(t_vars **,
			t_vars *))
{
	if (env == NULL)
		return ;
	env->envs = NULL;
	env->exps = NULL;
	env->envp = NULL;
	if (envp == NULL || insert == NULL)
		return ;
	fillvariables(env, envp, insert);
	if (env->envs == NULL)
		return ;
	env->exps = vars_copy(env->envs, insert);
	env->envp = utils_listtoarray(env->envs);
}
