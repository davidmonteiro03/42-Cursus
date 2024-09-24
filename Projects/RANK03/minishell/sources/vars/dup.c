/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:12:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:29:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_vars	*vars_dup(t_vars *source)
{
	t_vars	*dest;

	dest = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (dest == NULL)
		return (NULL);
	dest->key = NULL;
	dest->value = NULL;
	if (source->key != NULL)
		dest->key = ft_strdup(source->key);
	if (source->value != NULL)
		dest->value = ft_strdup(source->value);
	dest->prev = NULL;
	dest->next = NULL;
	return (dest);
}
