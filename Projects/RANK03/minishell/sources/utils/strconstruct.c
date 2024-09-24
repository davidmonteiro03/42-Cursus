/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:48:24 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:29:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*utils_strconstruct(char const c, size_t len)
{
	char	*str;

	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memset(str, c, len);
	return (str);
}
