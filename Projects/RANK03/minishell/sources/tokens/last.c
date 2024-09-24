/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:19:30 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokens	*tokens_last(t_tokens *const tokens)
{
	if (tokens == NULL)
		return (NULL);
	if (tokens->next == NULL)
		return (tokens);
	return (tokens_last(tokens->next));
}
