/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underscoreup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:03:27 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 08:09:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_underscoreup(t_env *env, char *const newstr)
{
	if (env == NULL || newstr == NULL)
		return ;
	if (env->underscore != NULL)
		free(env->underscore);
	env->underscore = ft_strdup(newstr);
}
