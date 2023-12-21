/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:48:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:48:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	no_path_err(char *str)
{
	get_exit_code(127, 1);
	ft_fprintf(2, "%s: command not found\n", str);
}

void	cd_err(char *str)
{
	get_exit_code(1, 1);
	ft_fprintf(2, "bash: cd: %s: No such file or directory\n", str);
}
