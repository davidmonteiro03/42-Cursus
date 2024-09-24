/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:14:25 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 15:16:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exp_print(int fd, t_exp *exp)
{
	if (exp == NULL || fd == -1)
		return ;
	display_fprintf(fd, "===== <%p> =====\n", exp);
	display_fprintf(fd, "<%p>->key  : %s\n", exp, exp->key);
	display_fprintf(fd, "<%p>->op   : %s\n", exp, exp->op);
	display_fprintf(fd, "<%p>->value: %s\n", exp, exp->value);
}
