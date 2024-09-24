/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:19:30 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:29:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_vars	*vars_first(t_vars *const vars)
{
	if (vars == NULL)
		return (NULL);
	if (vars->prev == NULL)
		return (vars);
	return (vars_first(vars->prev));
}
