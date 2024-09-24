/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:50:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 11:51:05 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_delone(t_vars *node)
{
	if (node == NULL)
		return ;
	if (node->key != NULL)
		free(node->key);
	if (node->value != NULL)
		free(node->value);
	free(node);
}
