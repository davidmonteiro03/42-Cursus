/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:51:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	files_clear(t_files **files)
{
	t_files	*iter;
	t_files	*temp;

	if (files == NULL || *files == NULL)
		return ;
	iter = files_first(*files);
	while (iter != NULL)
	{
		temp = iter->next;
		if (iter->fd != -1)
			close(iter->fd);
		if (iter->name != NULL)
			free(iter->name);
		free(iter);
		iter = temp;
	}
	*files = NULL;
}
