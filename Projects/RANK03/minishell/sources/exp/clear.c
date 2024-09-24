/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:11:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 15:12:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exp_clear(t_exp *exp)
{
	if (exp == NULL)
		return ;
	if (exp->key != NULL)
		free(exp->key);
	if (exp->op != NULL)
		free(exp->op);
	if (exp->value != NULL)
		free(exp->value);
	exp->key = NULL;
	exp->op = NULL;
	exp->value = NULL;
}
