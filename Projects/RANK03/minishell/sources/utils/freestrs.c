/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 08:05:56 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	utils_freestrs(char **strs)
{
	size_t	i;

	if (strs == NULL)
		return ;
	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}
