/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:28:33 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 11:53:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_unset(t_env *env, char *const key)
{
	if (env == NULL || key == NULL)
		return ;
	vars_unset(&env->envs, key);
	vars_unset(&env->exps, key);
	utils_freestrs(env->envp);
	env->envp = utils_listtoarray(env->envs);
}
