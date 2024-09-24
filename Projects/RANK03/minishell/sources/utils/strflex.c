/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strflex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:45:54 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:29:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*utils_strflex(char *const line, size_t *i)
{
	char	c;

	if (line == NULL || i == NULL || line[*i] == '\0')
		return (NULL);
	c = line[(*i)++];
	if (line[*i] != '\0' && line[*i] == c)
		return (++(*i), utils_strconstruct(c, 2));
	return (utils_strconstruct(c, 1));
}
