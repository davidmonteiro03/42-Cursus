/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:53:30 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 20:46:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	temp_init(t_temp *temp)
{
	if (temp == NULL)
		return ;
	temp->pid = -1;
	temp->pipefd[0] = -1;
	temp->pipefd[1] = -1;
	temp->redirfd[0] = -1;
	temp->redirfd[1] = -1;
	temp->word = NULL;
}
