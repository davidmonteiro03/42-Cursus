/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 19:43:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check(t_mini *mini)
{
	mini->args = ft_split(mini->command, ' ');
	mini->size = 0;
	while (mini->args[mini->size])
		mini->size++;
	if (mini->size <= 2 && ft_strncmp(mini->args[0], EXIT, 4) == 0)
	{
		if (mini->size == 1)
			return (exit_mini(mini, 0));
		return (exit_mini(mini, ft_atoi(mini->args[1])));
	}
	multiple_free("%b", mini->args);
}

int	exec_mini(t_mini *mini)
{
	mini->input = ft_strjoin(" => ", mini->dir->name);
	mini->input = ft_jointfree(mini->input, " ");
	mini->command = readline(mini->input);
	if (mini->command && *mini->command)
	{
		add_history(mini->command);
		check(mini);
		free(mini->input);
		free(mini->command);
	}
	return (0);
}
