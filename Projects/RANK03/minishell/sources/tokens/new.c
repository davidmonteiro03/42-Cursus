/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:15:32 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokens	*tokens_new(char *const value, t_type const type,
		bool const restricted)
{
	t_tokens	*node;

	if (value == NULL || (restricted == true && *value == '\0'))
		return (NULL);
	node = (t_tokens *)ft_calloc(1, sizeof(t_tokens));
	if (node == NULL)
		return (NULL);
	node->value = ft_strdup(value);
	node->type = type;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
