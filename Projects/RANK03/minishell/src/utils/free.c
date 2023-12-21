/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:13:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_command(t_command *cmd)
{
	t_command	*tmp;

	while (cmd)
	{
		if (cmd->cmd)
			free(cmd->cmd);
		if (cmd->args)
			free_split(cmd->args);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
	free(cmd);
}

void	free_input(t_input *input)
{
	t_input	*tmp;

	while (input)
	{
		free(input->line);
		free_command(input->command);
		if (input->args)
			free_split(input->args);
		if (input->heardoc)
			free(input->heardoc);
		tmp = input;
		input = input->next;
		free(tmp);
	}
	free(input);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_arrays(char ***arrays)
{
	int	i;

	i = 0;
	while (arrays[i])
	{
		free_split(arrays[i]);
		i++;
	}
	free(arrays);
}
