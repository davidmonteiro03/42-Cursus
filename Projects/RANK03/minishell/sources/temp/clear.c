/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:53:30 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 20:46:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	temp_clear(t_temp *temp)
{
	if (temp == NULL)
		return ;
	if (temp->pipefd[0] != -1)
		close(temp->pipefd[0]);
	if (temp->pipefd[1] != -1)
		close(temp->pipefd[1]);
	if (temp->redirfd[0] != -1)
		close(temp->redirfd[0]);
	if (temp->redirfd[1] != -1)
		close(temp->redirfd[1]);
	if (temp->word != NULL)
		free(temp->word);
	temp_init(temp);
}
