/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:48:24 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/12 19:49:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
