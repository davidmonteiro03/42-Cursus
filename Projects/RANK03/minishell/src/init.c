/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:23:26 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 16:39:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_mini	*init_mini(char **env)
{
	t_mini	*mini;
	int		i;

	mini = (t_mini *)malloc(sizeof(t_mini));
	if (!mini)
		return (NULL);
	mini->env = env;
	i = 0;
	while (mini->env[i])
		i++;
	mini->vars = (char ***)malloc(sizeof(char **) * (i + 1));
	i = -1;
	while (mini->env[++i])
		mini->vars[i] = ft_split(mini->env[i], '=');
	mini->vars[i] = NULL;
	mini->pwd = get_value_of(mini->vars, "PWD");
	return (mini);
}
