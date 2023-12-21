/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:03:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_getenv(char *key)
{
	t_mini	*mini;
	t_env	*tmp;

	mini = get_mini(NULL);
	tmp = mini->env;
	while (tmp)
	{
		if (tmp->key && !ft_strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*expand(char *line)
{
	char	*value;

	if (line[0] == '$' && !line[1])
		return (free(line), ft_strdup("$"));
	if (line[0] == '$' && line[1] != '?')
	{
		value = ft_getenv(line + 1);
		if (value)
			return (free(line), ft_strdup(value));
		return (free(line), ft_strdup(""));
	}
	return (line);
}
