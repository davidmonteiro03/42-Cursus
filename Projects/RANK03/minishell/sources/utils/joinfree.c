/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:19:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*utils_joinfree(char *const s1, char *const s2)
{
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}
