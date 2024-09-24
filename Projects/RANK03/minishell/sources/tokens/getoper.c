/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getoper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:42:27 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:27:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*tokens_getoper(char *const line, size_t *i)
{
	if (line == NULL || i == NULL || line[*i] == '\0')
		return (NULL);
	if (ft_strchr(DOUBLECHARSET_STR, line[*i]) != NULL)
		return (utils_strflex(line, i));
	if (ft_strchr(SINGLECHARSET_STR, line[*i]) != NULL)
		return (++(*i), utils_strconstruct(line[*i - 1], 1));
	return (NULL);
}
