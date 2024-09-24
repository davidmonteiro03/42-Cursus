/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 06:51:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 15:34:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	is_option_n(char *const str)
{
	size_t	i;

	if (str == NULL || *str != '-')
		return (false);
	i = 1;
	while (str[i] != '\0' && str[i] == 'n')
		i++;
	return (i > 1 && str[i] == '\0');
}

void	builtins_echo(t_cmds *cmd, t_shell *shell)
{
	bool	nl;
	size_t	i;
	size_t	tmp;

	if (cmd == NULL || cmd->args == NULL || shell == NULL)
		return ;
	g_exit_status = 0;
	nl = true;
	i = 1;
	while (cmd->args[i] != NULL && is_option_n(cmd->args[i]))
	{
		nl = false;
		i++;
	}
	tmp = 0;
	while (cmd->args[i] != NULL)
	{
		if (tmp++ > 0)
			ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putstr_fd(cmd->args[i++], STDOUT_FILENO);
	}
	if (nl == true)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
