/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:11:41 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 06:52:27 by dcaetano         ###   ########.fr       */
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

char	*cub_find_config(char **file_content, int i)
{
	char	*tmp;

	while (file_content[++i])
	{
		tmp = file_content[i];
		while (*tmp)
		{
			while (*tmp && ft_strchr("\t ", *tmp))
				tmp++;
			if (ft_isalpha(*tmp))
				return (ft_strdup(file_content[i]));
			tmp++;
		}
	}
	return (NULL);
}

void	cub_check_file_content(char *filename, t_cub *cub)
{
	char	*tmp;
	int		i;

	cub->textures.file_content = cub_read_file(filename, 0);
	i = -1;
	while (cub->textures.file_content[++i])
	{
		tmp = cub_find_config(&cub->textures.file_content[i], -1);
		printf("%s\n", tmp);
		free(tmp);
	}
}
