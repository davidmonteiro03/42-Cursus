/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:28:05 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	init_env(char **envp)
{
	t_mini	*mini;
	char	*key;
	char	*value;

	mini = get_mini(NULL);
	mini->env = NULL;
	mini->exp = NULL;
	while (*envp)
	{
		key = retkey(*envp);
		value = retval(*envp);
		if (value)
			add_env(mini, key, value);
		else
			add_exp(mini, key);
		envp++;
	}
}

t_input	*init_input(void)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	input->line = NULL;
	input->args = NULL;
	input->heardoc = NULL;
	input->command = malloc(sizeof(t_command));
	input->command->cmd = NULL;
	input->command->args = NULL;
	input->command->next = NULL;
	input->next = NULL;
	return (input);
}

void	init_mini(char **envp)
{
	t_mini	*mini;

	mini = malloc(sizeof(t_mini));
	get_mini(mini);
	init_env(envp);
	get_env(mini->env);
	get_exp(mini->exp);
	mini->input = init_input();
	mini->envp = envp;
	mini->line = NULL;
}
