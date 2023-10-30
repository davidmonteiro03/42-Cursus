/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 15:03:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_chars	init_chars(void)
{
	t_chars	chars;

	chars.empty = '0';
	chars.wall = '1';
	chars.collect = 'C';
	chars.exit = 'E';
	chars.start_pos = 'P';
	return (chars);
}

void	read_file(char *file)
{
	int		fd;
	char	*line;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(file);
	buf = "";
	line = get_next_line(fd);
	while (line)
	{
		ft_putstr(line);
		buf = ft_strjoin(line, buf);
		free(line);
		line = get_next_line(fd);
	}
	free(buf);
}

int	main(int ac, char **av)
{
	t_chars	chars;

	if (ac != 2)
		exit(EXIT_FAILURE);
	chars = init_chars();
	read_file(av[1]);
	return (EXIT_SUCCESS);
}
