/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:59:03 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 17:01:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_vars	*vars_new2(t_exp const exp)
{
	t_vars	*node;

	if (exp.key == NULL)
		return (NULL);
	node = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (node == NULL)
		return (NULL);
	node->key = ft_strdup(exp.key);
	if (node->key == NULL)
		return (free(node), NULL);
	node->value = ft_strdup(exp.value);
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
