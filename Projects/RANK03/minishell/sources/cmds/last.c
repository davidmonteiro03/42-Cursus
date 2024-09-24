/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:44:24 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:22:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmds	*cmds_last(t_cmds *const cmds)
{
	if (cmds == NULL)
		return (NULL);
	if (cmds->next == NULL)
		return (cmds);
	return (cmds_last(cmds->next));
}
