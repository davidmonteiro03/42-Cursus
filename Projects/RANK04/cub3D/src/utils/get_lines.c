/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:48:24 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 11:44:04 by dcaetano         ###   ########.fr       */
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
