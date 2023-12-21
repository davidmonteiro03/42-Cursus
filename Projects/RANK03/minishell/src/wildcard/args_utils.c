/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:45:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/16 19:45:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*new_args_util(const char *src)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	i = -1;
	j = 0;
	while (src[++i])
		if (src[i] != '_')
			dest[j++] = src[i];
	dest[j] = '\0';
	return (dest);
}

char	**ft_new_args(char **src, int size)
{
	char	**dest;
	int		i;

	dest = malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < size)
		dest[i] = new_args_util(src[i]);
	dest[size] = NULL;
	return (dest);
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
			if (ft_strscmp(ft_strlow(new[i]), ft_strlow(new[j])) > 0)
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
