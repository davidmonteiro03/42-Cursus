/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:22:27 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 07:18:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_clear(t_env *env)
{
	if (env == NULL)
		return ;
	if (env->envs != NULL)
		vars_clear(&env->envs);
	if (env->exps != NULL)
		vars_clear(&env->exps);
	if (env->envp != NULL)
		utils_freestrs(env->envp);
	if (env->underscore != NULL)
		free(env->underscore);
}
