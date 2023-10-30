/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 17:02:25 by dcaetano         ###   ########.fr       */
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

t_map	init_map(void)
{
	t_map	map;

	map.lines = NULL;
	map.cont_lines = 0;
	map.length_lines = NULL;
	return (map);
}

char	*ft_jointfree(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (tmp);
}

void	valid_extension(char *file, char *extension)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(file) < ft_strlen(extension) + 1)
		ft_simple_error("Argument to low!");
	j = 0;
	i = ft_strlen(file);
	while (i-- > ft_strlen(file) - ft_strlen(extension))
		if (file[i] != extension[ft_strlen(extension) - ++j])
			ft_simple_error("Wrong extension!");
}

void	print_chars(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (strs[++i])
		ft_printf("%s\n", strs[i]);
}

void	freechars(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

char	**valid_contents(char *file)
{
	int		fd;
	char	*line;
	char	**lines;
	char	*buff;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_perror(file);
	buff = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		buff = ft_jointfree(buff, line);
		line = get_next_line(fd);
	}
	close(fd);
	lines = ft_split(buff, '\n');
	free(buff);
	return (lines);
}

void	valid_file(char *file, t_map map)
{
	valid_extension(file, ".ber");
	map.lines = NULL;
	map.lines = valid_contents(file);
	print_chars(map.lines);
	freechars(map.lines);
}

int	main(int ac, char **av)
{
	t_chars	chars;
	t_map	map;

	if (ac != 2)
		exit(EXIT_SUCCESS);
	chars = init_chars();
	map = init_map();
	valid_file(av[1], map);
	return (EXIT_SUCCESS);
}
