/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:40:06 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_files	*files_new(t_type const type, char *const name)
{
	t_files	*node;

	node = (t_files *)ft_calloc(1, sizeof(t_files));
	if (node == NULL)
		return (NULL);
	node->fd = -1;
	node->type = type;
	node->name = NULL;
	node->prev = NULL;
	node->next = NULL;
	if (name != NULL)
		node->name = ft_strdup(name);
	return (node);
}
