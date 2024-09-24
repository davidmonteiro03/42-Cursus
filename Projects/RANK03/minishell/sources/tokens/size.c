/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:00:45 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	tokens_size(t_tokens *const tokens)
{
	size_t		size;
	t_tokens	*iter;

	if (tokens == NULL)
		return (0);
	size = 0;
	iter = tokens_first(tokens);
	while (iter != NULL)
	{
		size++;
		iter = iter->next;
	}
	return (size);
}
