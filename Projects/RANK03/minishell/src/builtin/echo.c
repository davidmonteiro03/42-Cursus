/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:48:46 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo_option_helper(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != c)
			return (0);
	return (1);
}

int	ft_echo(t_command *cmd)
{
	int	i;
	int	nl;

	get_exit_code(0, 1);
	i = 0;
	nl = 1;
	if (!cmd->args)
		return (ft_fprintf(1, "\n"), 0);
	while (cmd->args[i] && cmd->args[i][0] == '-')
	{
		if (echo_option_helper(&cmd->args[i][1], 'n'))
			nl = 0;
		if (!echo_option_helper(&cmd->args[i][1], 'n'))
			break ;
		i++;
	}
	while (cmd->args[i])
	{
		ft_fprintf(1, "%s", cmd->args[i++]);
		if (cmd->args[i])
			ft_fprintf(1, " ");
	}
	if (nl)
		ft_fprintf(1, "\n");
	return (0);
}
