/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:11:41 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/09 20:46:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	cub_count_lines(int fd, int count)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (line[0] != '\n')
			count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

char	**cub_read_file(char *filename, int i)
{
	char	*line;
	char	**file_content;
	int		num_lines;

	auto int fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (cub_error(filename, true), NULL);
	num_lines = cub_count_lines(fd, 0);
	if (num_lines == 0)
		cub_error(ft_strdup(ERROR_EMPTY), false);
	file_content = (char **)malloc(sizeof(char *) * (num_lines + 1));
	if (!file_content)
		return (close(fd), NULL);
	close(fd);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
			file_content[i++] = ft_strtrim(line, "\n\t ");
		free(line);
		line = get_next_line(fd);
	}
	file_content[i] = NULL;
	return (free(filename), close(fd), file_content);
}

void	cub_check_file_content(char *filename, t_cub *cub)
{
	cub->textures.file_content = cub_read_file(filename, 0);
	cub_strs_sort(&cub->textures.file_content, -1);
}
