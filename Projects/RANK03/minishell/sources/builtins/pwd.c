/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:24:13 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 15:36:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	writeerror(char *const error)
{
	char	*output;

	if (error == NULL)
		return ;
	output = ft_strjoin(NAME, ": pwd: ");
	output = utils_joinfree(output, ft_strdup(error));
	output = utils_joinfree(output, ft_strdup("\n"));
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
}

void	builtins_pwd(void)
{
	char	*pwd;

	g_exit_status = 0;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		g_exit_status = 1;
		writeerror(strerror(errno));
		return ;
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	g_exit_status = 0;
}
