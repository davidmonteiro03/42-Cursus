/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wild_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:10:14 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/01 09:30:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_3.h"

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

void	sort_strs(t_gb *gb, char **aux)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	i = -1;
	if (stat(gb->ag[0], &gb->st))
		i = 0;
	while (gb->ag[++i])
	{
		j = i;
		while (gb->ag[++j])
		{
			if (ft_strcmp(ft_strlow(aux[i]), ft_strlow(aux[j])) > 0)
			{
				tmp = gb->ag[i];
				gb->ag[i] = gb->ag[j];
				gb->ag[j] = tmp;
				tmp2 = aux[i];
				aux[i] = aux[j];
				aux[j] = tmp2;
			}
		}
	}
}

char	**new_args(char **src, int size)
{
	char	**dest;
	int		i;

	dest = malloc((size + 1) * sizeof(char *));
	i = -1;
	while (++i < size)
		dest[i] = new_args_util(src[i]);
	dest[size] = NULL;
	return (dest);
}
