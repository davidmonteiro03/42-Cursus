/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:19:30 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:27:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokens	*tokens_first(t_tokens *const tokens)
{
	if (tokens == NULL)
		return (NULL);
	if (tokens->prev == NULL)
		return (tokens);
	return (tokens_first(tokens->prev));
}
