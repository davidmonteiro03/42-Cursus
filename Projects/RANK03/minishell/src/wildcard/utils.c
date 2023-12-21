/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:43:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/16 19:45:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_strscmp(const char *s1, const char *s2)
{
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;
	size_t			i;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = -1;
	while (aux_s1[++i] || aux_s2[i])
	{
		if (aux_s1[i] != aux_s2[i])
		{
			if (!ft_isalnum(aux_s1[i]) && ft_isalnum(aux_s2[i]))
				return (1);
			if (!ft_isalnum(aux_s2[i]) && ft_isalnum(aux_s1[i]))
				return (-1);
			return (aux_s1[i] - aux_s2[i]);
		}
	}
	return (0);
}

char	*ft_strlow(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}

int	strs_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
