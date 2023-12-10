/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:11:41 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 09:47:53 by dcaetano         ###   ########.fr       */
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
		file_content[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	file_content[i] = NULL;
	return (free(filename), close(fd), file_content);
}

int	cub_count(char **strs, int i, int count, char *(*f)(char *str, int i))
{
	char	*tmp;

	while (strs[++i])
	{
		tmp = f(strs[i], 0);
		if (!tmp)
			continue ;
		count++;
		free(tmp);
	}
	return (count);
}

void	cub_check_file_content(char *filename, t_cub *cub)
{
	int	count_config;
	int	count_map;

	cub->config.data.file_content = cub_read_file(filename, 0);
	count_config = cub_count(cub->config.data.file_content, -1, 0, \
		&cub_get_config);
	count_map = cub_count(cub->config.data.file_content, -1, 0, \
		&cub_get_map);
	if (count_config != 6)
		return (multiple_free("%b", cub->config.data.file_content), \
			cub_error_parsing(cub, ERROR_CONFIG));
	if (count_map <= 0)
		return (multiple_free("%b", cub->config.data.file_content), \
			cub_error_parsing(cub, ERROR_MAP));
	cub_check_config(cub, cub->config.data.file_content, -1);
	cub_set_config(cub, cub->config.data.file_content, -1, 0);
	cub_check_data(cub, cub->config.data.data, -1);
}
