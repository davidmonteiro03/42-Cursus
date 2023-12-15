/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:24:45 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 15:25:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

size_t	cub_strlen(char *str, char c)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c)
			len = i + 1;
		i++;
	}
	return (len);
}

size_t	cub_get_max_len(char **map, char c, int i)
{
	size_t	max_len;

	max_len = 0;
	while (map[++i])
		if (cub_strlen(map[i], c) > max_len)
			max_len = cub_strlen(map[i], c);
	return (max_len);
}

bool	cub_dif_char_in(char *str, char *charset)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_strchr(charset, str[i]))
			return (false);
	return (true);
}

int	cub_get_num_chars(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == c)
			count++;
	return (count);
}

int	cub_strs_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
