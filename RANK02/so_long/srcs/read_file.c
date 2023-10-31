/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:24:09 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 12:08:05 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_file(char *file)
{
	int		fd;
	char	*line;
	char	*buff;
	char	**lines;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		fileerror(file);
	buff = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		buff = ft_jointfree2(buff, line);
		line = get_next_line(fd);
	}
	if (fd > 0)
		close(fd);
	if (!buff)
		return (NULL);
	lines = ft_split(buff, '\n');
	free(buff);
	if (!lines)
		return (NULL);
	return (lines);
}
