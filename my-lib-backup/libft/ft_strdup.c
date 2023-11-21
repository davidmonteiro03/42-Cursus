/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:29:11 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/05 17:14:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s))
		dest[i] = (char)s[i];
	dest[i] = '\0';
	return (dest);
}
