/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:42:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:29:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	utils_strcmp(char *const s1, char *const s2)
{
	char	*iter_s1;
	char	*iter_s2;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	if (s1 == s2)
		return (0);
	iter_s1 = s1;
	iter_s2 = s2;
	while (*iter_s1 != '\0' || *iter_s2 != '\0')
	{
		if (*iter_s1 != *iter_s2)
			return (*iter_s1 - *iter_s2);
		iter_s1++;
		iter_s2++;
	}
	return (0);
}
