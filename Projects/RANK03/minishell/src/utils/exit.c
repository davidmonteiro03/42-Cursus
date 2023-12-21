/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:40:00 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_exp(t_exp *exp)
{
	t_exp	*tmp;

	while (exp)
	{
		free(exp->key);
		tmp = exp;
		exp = exp->next;
		free(tmp);
	}
	free(exp);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env && env->key)
	{
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		tmp = env;
		env = env->next;
		free(tmp);
	}
	free(env);
}

static void	free_mini(t_mini *mini)
{
	free_input(mini->input);
	if (mini->env)
		free_env(mini->env);
	free_exp(mini->exp);
	free(mini->line);
	free(mini);
}

void	exit_minishell(t_mini *mini)
{
	free_mini(mini);
	ft_fprintf(1, "exit\n");
	rl_clear_history();
	exit(get_exit_code(0, 0));
}

void	s_exit_minishell(void)
{
	t_mini	*mini;

	mini = get_mini(NULL);
	free_mini(mini);
	rl_clear_history();
	exit(get_exit_code(0, 0));
}
