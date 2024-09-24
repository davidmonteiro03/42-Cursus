/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:43:44 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	files_pushback(t_files **files, t_files *node)
{
	t_files	*last;

	if (files == NULL || node == NULL)
		return ;
	if (*files == NULL)
		return (*files = node, (void)0);
	last = files_last(*files);
	last->next = node;
	node->prev = last;
}
