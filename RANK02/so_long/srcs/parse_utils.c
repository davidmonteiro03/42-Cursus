/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:21:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 11:06:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*parse_extension(char *arg, char *ext)
{
	char	*tmp;
	char	*tmp_ext;
	size_t	len_ext;

	tmp = specialtrim(arg, ext);
	len_ext = ft_strlen(ext);
	tmp_ext = ft_substr(tmp, ft_strlen(tmp) - len_ext, len_ext);
	if (ft_strncmp(tmp_ext, ext, len_ext) != 0)
	{
		multiple_free("%a%a", tmp_ext, tmp);
		simperror(EXTENSION_ERROR);
	}
	multiple_free("%a", tmp_ext);
	return (tmp);
}

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

void	parse_length_lines(char **lines)
{
	int	i;

	i = -1;
	while (lines[++i])
	{
		if (i > 0 && ft_strlen(lines[i]) != ft_strlen(lines[i - 1]))
		{
			multiple_free("%b", lines);
			simperror("All the lines must have the same length");
		}
	}
}

void	parse_contents(char **lines)
{
	parse_length_lines(lines);
	display_strs(lines);
}
