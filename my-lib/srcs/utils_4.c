/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:49:36 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 12:52:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_4.h"

int	ft_strcmp(const char *s1, const char *s2)
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

void	sort_strs(char ***old, char **new, int i)
{
	int		j;
	char	*tmp;

	while ((*old)[++i])
	{
		j = i;
		while ((*old)[++j])
		{
			if (ft_strcmp(ft_strlow(new[i]), ft_strlow(new[j])) > 0)
			{
				tmp = (*old)[i];
				(*old)[i] = (*old)[j];
				(*old)[j] = tmp;
				tmp = new[i];
				new[i] = new[j];
				new[j] = tmp;
			}
		}
	}
}
