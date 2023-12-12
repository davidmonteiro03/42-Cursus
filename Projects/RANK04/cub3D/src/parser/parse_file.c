/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:54:17 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/12 19:54:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	cub_count_line(int fd)
{
	char	*line;
	int		count;

	line = get_next_line(fd);
	if (!line)
		return (0);
	count = 0;
	while (line)
	{
		++count;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

char	**cub_check_contents(int fd, int n_lines)
{
	char	**content;
	char	*line;
	int		count;

	content = (char **)malloc(sizeof(char *) * (n_lines + 1));
	if (!content)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (free(content), NULL);
	count = 0;
	while (line)
	{
		content[count++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	content[count] = NULL;
	return (content);
}

char	**cub_read_file(t_cub *cub, int fd)
{
	char	**content;
	int		n_lines;

	n_lines = cub_count_line(fd);
	if (n_lines == 0)
		return (NULL);
	close(fd);
	fd = open(cub->config.filename, O_RDONLY);
	content = cub_check_contents(fd, n_lines);
	if (!content)
		return (NULL);
	return (content);
}

void	cub_check_file_content(t_cub *cub)
{
	cub->config.fd = open(cub->config.filename, O_RDONLY);
	if (cub->config.fd == -1)
		cub_error_file(cub, cub->config.filename, true);
	cub->config.content = cub_read_file(cub, cub->config.fd);
	if (!cub->config.content)
	{
		close(cub->config.fd);
		cub_error_file(cub, ERROR_FILE, false);
	}
	close(cub->config.fd);
}
