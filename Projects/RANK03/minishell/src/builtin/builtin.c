/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:28:38 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 13:23:18 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec2(t_input *input)
{
	t_mini	*mini;
	int		fd[2];
	int		i;

	mini = get_mini(NULL);
	if (input->heardoc)
	{
		pipe(fd);
		ft_fprintf(fd[1], "%s", input->heardoc);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	if (!*input->line)
		return (0);
	input->args = split_args(input->line, 0);
	i = 0;
	while (input->args[i] && !*input->args[i])
		i++;
	if (!input->args[i])
		return (get_exit_code(0, 1), 0);
	input->command->cmd = ft_strdup(input->args[i++]);
	input->command->args = trim_args(input->args + i);
	input->command->args = wild_args(input->command->args);
	return (exec_builtin(mini, input));
}

int	exec_builtin(t_mini	*mini, t_input *input)
{
	char	*cmd;

	cmd = input->command->cmd;
	if (!ft_strcmp(cmd, "cd\0"))
		return (ft_cd());
	else if (!ft_strcmp(cmd, "echo\0"))
		return (ft_echo(input->command));
	else if (ft_strnstr(cmd, "env\0", 4))
		return (ft_env(input));
	else if (!ft_strcmp(cmd, "export\0"))
		return (ft_export(mini, input));
	else if (!ft_strcmp(cmd, "pwd\0"))
		return (ft_pwd(input));
	else if (!ft_strcmp(cmd, "unset\0"))
		return (ft_unset(mini->input->command->args,
				&mini->env, &mini->exp));
	else if (!ft_strcmp(cmd, "exit\0"))
		return (ft_exit());
	else
		return (ft_execve(mini, input));
	return (1);
}
