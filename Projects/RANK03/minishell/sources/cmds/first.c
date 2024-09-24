/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:44:24 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:22:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmds	*cmds_first(t_cmds *const cmds)
{
	if (cmds == NULL)
		return (NULL);
	if (cmds->prev == NULL)
		return (cmds);
	return (cmds_first(cmds->prev));
}
