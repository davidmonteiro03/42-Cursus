/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushfront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:22:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokens_pushfront(t_tokens **tokens, t_tokens *node)
{
	t_tokens	*first;

	if (tokens == NULL || node == NULL)
		return ;
	if (*tokens == NULL)
		return (*tokens = node, (void)0);
	first = tokens_first(*tokens);
	first->prev = node;
	node->next = first;
	*tokens = node;
}
