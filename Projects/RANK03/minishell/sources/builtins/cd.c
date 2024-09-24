/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:19:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/23 15:04:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	argserror(void)
{
	char	*output;

	output = ft_strdup(NAME ": cd: too many arguments\n");
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
	g_exit_status = 1;
}

void	builtins_cd(t_cmds *cmd, t_shell *shell)
{
	if (cmd == NULL || cmd->args == NULL || shell == NULL)
		return ;
	g_exit_status = 0;
	if (cmd->args[1] == NULL)
		return (builtins_cdspecific("HOME", &shell->env));
	if (cmd->args[2] != NULL)
		return (argserror());
	if (utils_strcmp(cmd->args[1], "-") == 0)
		return (builtins_cdspecific("OLDPWD", &shell->env));
	builtins_changedir(cmd->args[1], &shell->env);
}
