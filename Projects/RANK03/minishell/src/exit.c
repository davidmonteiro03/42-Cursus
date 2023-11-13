/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:33:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 19:40:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exit_mini(t_mini *mini, int status)
{
	clear_history();
	multiple_free("%b%a%a%a%a%a",
		mini->args, \
		mini->input, \
		mini->command, \
		mini->dir->name, \
		mini->dir, \
		mini \
	);
	exit(status);
}
