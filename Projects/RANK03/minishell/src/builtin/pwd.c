/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:28:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_pwd(t_input *input)
{
	char	*pwd;

	get_exit_code(0, 1);
	if (input->command->args && check_options(input->command->args, "pwd"))
		return (1);
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		ft_fprintf(2, "pwd: error retrieving current directory: getcwd: ");
		ft_fprintf(2, "cannot access parent directories: ");
		ft_fprintf(2, "No such file or directory\n");
		return (get_exit_code(2, 1));
	}
	ft_fprintf(1, "%s\n", pwd);
	free(pwd);
	return (0);
}
