/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:58:03 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 07:53:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	longlongintrange(long long int const sign, long long int const nbr,
		char const c)
{
	if (nbr * sign > LLONG_MAX / 10 || nbr * sign < LLONG_MIN / 10)
		return (false);
	if ((nbr * sign == LLONG_MAX / 10 && c - '0' > LLONG_MAX % 10) || (nbr
			* sign == LLONG_MIN / 10 && c - '0' > -(LLONG_MIN % 10)))
		return (false);
	return (true);
}

static bool	longlongintvalid(char *const str, size_t i, long long int sign,
		long long int nbr)
{
	if (str == NULL)
		return (false);
	while (str[i] != '\0' && utils_isspace(str[i]) == true)
		i++;
	if (str[i] == '\0')
		return (false);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0' && ft_isdigit(str[i]) == true)
	{
		if (longlongintrange(sign, nbr, str[i]) == false)
			return (false);
		nbr = nbr * 10 + str[i++] - '0';
	}
	while (str[i] != '\0' && utils_isspace(str[i]) == true)
		i++;
	return (str[i] == '\0');
}

static void	numericerror(char *const arg, t_shell *shell)
{
	char	*output;

	if (arg == NULL || shell == NULL)
		return ;
	output = ft_strjoin(NAME ": exit: ", arg);
	output = utils_joinfree(output, ft_strdup(": numeric argument required\n"));
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
	g_exit_status = 2;
	return (shell_hardreset(shell), exit(g_exit_status));
}

static void	argserror(void)
{
	char	*output;

	output = ft_strdup(NAME ": exit: too many arguments\n");
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
	g_exit_status = 1;
}

void	builtins_exit(t_cmds *cmd, t_shell *shell)
{
	if (cmd == NULL || cmd->args == NULL || shell == NULL)
		return ;
	if (cmd->prev == NULL && cmd->next == NULL)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (cmd->args[1] == NULL)
		return (shell_hardreset(shell), exit(g_exit_status));
	if (longlongintvalid(cmd->args[1], 0, 1, 0) == false)
		return (numericerror(cmd->args[1], shell));
	if (cmd->args[2] != NULL)
		return (argserror());
	g_exit_status = ft_atoi(cmd->args[1]);
	shell_hardreset(shell);
	exit(g_exit_status);
}
