/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:46:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

static int	ft_exitcode(char *str)
{
	unsigned int	code;

	code = (unsigned int)ft_atoi(str);
	while (code > 255)
		code -= 256;
	return (code);
}

static void	exit_num(t_mini *mini)
{
	ft_fprintf(2, "bash: exit: %s: numeric argument required\n",
		mini->input->command->args[0]);
	get_exit_code(2, 1);
	s_exit_minishell();
}

static void	exit_n_num(t_mini *mini)
{
	ft_fprintf(2, "bash: exit: %s: numeric argument required\n",
		mini->input->command->args[0]);
	get_exit_code(2, 1);
	s_exit_minishell();
}

int	ft_exit(void)
{
	t_mini	*mini;

	mini = get_mini(NULL);
	if (mini->input->command->args)
	{
		if (ft_strisdigit(mini->input->command->args[0]))
		{
			if (mini->input->command->args[1])
			{
				get_exit_code(1, 1);
				return (ft_fprintf(2,
						"exit\nbash: exit: too many arguments\n"), 1);
			}
			get_exit_code(ft_exitcode(mini->input->command->args[0]), 1);
		}
		else if (!mini->input->command->args[1]
			&& !ft_strisdigit(mini->input->command->args[0]))
			exit_num(mini);
		else
			exit_n_num(mini);
	}
	exit_minishell(mini);
	return (0);
}
