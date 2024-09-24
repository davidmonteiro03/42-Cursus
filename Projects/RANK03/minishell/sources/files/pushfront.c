/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushfront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:43:44 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	files_pushfront(t_files **files, t_files *node)
{
	t_files	*first;

	if (files == NULL || node == NULL)
		return ;
	if (*files == NULL)
		return (*files = node, (void)0);
	first = files_first(*files);
	first->prev = node;
	node->next = first;
	*files = node;
}
