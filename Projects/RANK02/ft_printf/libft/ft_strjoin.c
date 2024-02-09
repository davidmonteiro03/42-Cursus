/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:28:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/05 18:03:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*final_str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	final_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!final_str)
		return (NULL);
	j = 0;
	i = -1;
	while (s1[++i])
		final_str[j++] = (char)s1[i];
	i = -1;
	while (s2[++i])
		final_str[j++] = (char)s2[i];
	final_str[j] = '\0';
	return (final_str);
}
