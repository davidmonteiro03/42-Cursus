/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:53:34 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 21:14:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	so_long_check_file_content(char *file)
{
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (so_long_error_file(file), exit(1));
	tmp = get_next_line(fd);
	if (!tmp)
		return (close(fd), so_long_error(ERROR_EMPTY), exit(1));
	while (tmp)
	{
		if (!ft_strchr(tmp, '\n'))
			return (free(tmp), close(fd), \
				so_long_error(ERROR_CONTENT), exit(1));
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
}

bool	so_long_check_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		i++;
	}
	return (true);
}

void	so_long_parse_file(char *file)
{
	t_list	*tmp;
	char	**parse;

	so_long_check_file_content(file);
	tmp = so_long_get_file_content(file);
	if (!tmp)
		return (so_long_error(ERROR_CONTENT), exit(1));
	parse = so_long_list_to_strs(tmp);
	ft_lstclear(&tmp, free);
	if (!parse)
		return (so_long_error(ERROR_MALLOC), exit(1));
	so_long_check_map(parse);
	free_strs(parse, -1);
}
