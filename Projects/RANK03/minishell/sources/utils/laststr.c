/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laststr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 07:46:33 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/25 07:48:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*utils_laststr(char *const *strs)
{
	if (strs == NULL || *strs == NULL)
		return (NULL);
	if (*(strs + 1) == NULL)
		return (*strs);
	return (utils_laststr(strs + 1));
}
