/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:54:17 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/11 21:45:52 by dcaetano         ###   ########.fr       */
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
	if (!n_lines)
		cub_error_file(cub, ERROR_EMPTY, false);
	close(fd);
	fd = open(cub->config.filename, O_RDONLY);
	content = cub_check_contents(fd, n_lines);
	return (content);
}

void	cub_check_file_content(t_cub *cub)
{
	cub->config.fd = open(cub->config.filename, O_RDONLY);
	if (cub->config.fd == -1)
		cub_error_file(cub, cub->config.filename, true);
	cub->config.content = cub_read_file(cub, cub->config.fd);
	if (!cub->config.content)
		cub_error_file(cub, ERROR_FILE, false);
	if (!*cub->config.content)
		cub_error_file(cub, ERROR_FILE, false);
	cub_check_maps(cub->config.content, 0, &cub->map_info);
	cub_check_config(cub->config.content, 0, &cub->config_info);
	printf("map_info->pos: %d\n", cub->map_info.pos);
	printf("config_info->pos: %d\n", cub->config_info.pos);
}
