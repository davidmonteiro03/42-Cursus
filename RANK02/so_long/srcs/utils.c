/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:05:42 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 15:52:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	find_invalid_char(char *str, t_chars chars)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != chars.empty && str[i] != chars.wall && \
			str[i] != chars.collect && str[i] != chars.exit && \
			str[i] != chars.start_pos)
			return (1);
	return (0);
}

char	*specialtrim(char *str, char *ext)
{
	char	*s;
	char	*t;

	s = ft_strtrim(str, " \n\t");
	if (ft_strchr(s, ' ') || ft_strchr(s, '\n') || ft_strchr(s, '\t'))
	{
		multiple_free("%a", s);
		simperror(ARGUMENT_ERROR);
	}
	t = ft_substr(s, 0, ft_strlen(s) - ft_strlen(ext));
	if (ft_strchr(t, '.'))
	{
		multiple_free("%a%a", s, t);
		simperror(ARGUMENT_ERROR);
	}
	multiple_free("%a", t);
	return (s);
}

char	*ft_jointfree2(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	multiple_free("%a%a", s1, s2);
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
