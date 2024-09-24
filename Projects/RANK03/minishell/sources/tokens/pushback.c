/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:22:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokens_pushback(t_tokens **tokens, t_tokens *node)
{
	t_tokens	*last;

	if (tokens == NULL || node == NULL)
		return ;
	if (*tokens == NULL)
		return (*tokens = node, (void)0);
	last = tokens_last(*tokens);
	last->next = node;
	node->prev = last;
}
