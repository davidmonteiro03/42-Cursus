/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listtoarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:33:28 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 10:34:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**utils_listtoarray(t_vars *const vars)
{
	t_vars	*iter;
	size_t	i;
	char	**envp;

	if (vars == NULL)
		return (NULL);
	envp = (char **)ft_calloc(vars_size(vars) + 1, sizeof(char *));
	if (envp == NULL)
		return (NULL);
	i = 0;
	iter = vars_first(vars);
	while (iter != NULL)
	{
		envp[i] = ft_strdup(iter->key);
		if (iter->value != NULL)
		{
			envp[i] = utils_joinfree(envp[i], ft_strdup("="));
			envp[i] = utils_joinfree(envp[i], ft_strdup(iter->value));
		}
		i++;
		iter = iter->next;
	}
	envp[i] = NULL;
	return (envp);
}
