/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:36:03 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/05 08:55:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t		result;
	const char	*tmp;

	result = 0;
	while (*s)
	{
		tmp = reject;
		while (*tmp)
		{
			if (*s == *tmp)
				return (result);
			tmp++;
		}
		s++;
		result++;
	}
	return (result);
}
