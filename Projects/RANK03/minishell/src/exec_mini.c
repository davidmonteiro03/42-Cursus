/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:57:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 16:49:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	exec_mini(t_mini *mini)
{
	char	*line;

	ft_printf("%s ", mini->pwd);
	line = get_next_line(0);
	mini->command = ft_strtrim(line, "\n");
	free(line);
	if (ft_strncmp(mini->command, EXIT, ft_strlen(mini->command)) == 0)
		exit_mini(mini, 0);
	if (ft_strncmp(mini->command, PWD, ft_strlen(mini->command)) == 0)
		ft_printf("%s\n", mini->pwd);
	free(mini->command);
	return (0);
}
