/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:54:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_input *input)
{
	t_mini	*mini;
	char	*tmp;

	mini = get_mini(NULL);
	if (input->command->args)
	{
		get_exit_code(127, 1);
		return (ft_fprintf(2, "env: ‘%s’: No such file or directory\n",
				input->command->args[0]), 1);
	}
	get_exit_code(0, 1);
	if (access(input->command->cmd, F_OK))
	{
		tmp = input->command->cmd;
		input->command->cmd = verify_access(tmp);
		free(tmp);
	}
	if (access(input->command->cmd, F_OK))
		return (no_path_err(input->command->cmd), 1);
	print_env(mini);
	return (0);
}
