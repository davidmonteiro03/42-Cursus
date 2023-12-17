/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:48:24 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/17 19:15:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	**cub_get_args(char *str)
{
	char	**tmp;
	char	*buf;
	int		i;

	tmp = ft_split(str, ' ');
	buf = ft_strdup("");
	i = -1;
	while (tmp[++i])
	{
		buf = cub_buildfree(buf, ft_strdup(tmp[i]), &ft_strjoin);
		buf = cub_buildfree(buf, ft_strdup("\t"), &ft_strjoin);
	}
	multiple_free("%b", tmp);
	tmp = ft_split(buf, '\t');
	free(buf);
	return (tmp);
}

char	**cub_copy(char **map, int i, int max_len)
{
	char	**save;
	int		j;

	save = (char **)malloc(sizeof(char *) * (cub_strs_size(map) + 1));
	while (map[++i])
	{
		save[i] = (char *)malloc(sizeof(char) * (max_len + 1));
		j = -1;
		while (++j < max_len)
		{
			if (j < (int)ft_strlen(map[i]))
				save[i][j] = map[i][j];
			else
				save[i][j] = ' ';
		}
		save[i][j] = '\0';
	}
	save[i] = NULL;
	return (save);
}

char	**cub_get_lines(char **content, int start, int end)
{
	char	**lines;
	int		i;

	lines = (char **)malloc(sizeof(char *) * (end - start + 2));
	if (!lines)
		return (NULL);
	i = 0;
	while (start <= end)
		lines[i++] = ft_strdup(content[start++]);
	lines[i] = NULL;
	return (lines);
}

int	cub_get_angle(char c)
{
	if (c == 'N')
		return (270);
	if (c == 'S')
		return (90);
	if (c == 'E')
		return (0);
	return (180);
}
