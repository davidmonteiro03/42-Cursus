/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:01:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:27:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokens_clear(t_tokens **tokens)
{
	t_tokens	*iter;
	t_tokens	*temp;

	if (tokens == NULL || *tokens == NULL)
		return ;
	iter = tokens_first(*tokens);
	while (iter != NULL)
	{
		temp = iter->next;
		if (iter->value != NULL)
			free(iter->value);
		free(iter);
		iter = temp;
	}
	*tokens = NULL;
}
