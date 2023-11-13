/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:23:26 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 12:44:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_mini	*init_mini(char **env)
{
	t_mini	*mini;
	char	**tmp;
	int		i;

	mini = (t_mini *)malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->env = env;
	i = -1;
	while (mini->env[++i])
	{
		tmp = ft_split(mini->env[i], '=');
		printf("%s -> %s\n", tmp[0], tmp[1]);
	}
	mini->args = NULL;
	mini->command = NULL;
	return (mini);
}
