/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:25:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 21:11:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

int	cub_check_mapline(char *line, char *charset, int i)
{
	if (!line || !*line)
		return (2);
	while (line[++i])
		if (!ft_strchr(charset, line[i]))
			return (0);
	return (1);
}

t_count	cub_check_map(char **file_content, int i, \
	int count_map, int count_config)
{
	t_count	count;

	while (file_content[i])
	{
		if (cub_check_mapline(file_content[i], " 012NSEW", -1) == 1)
		{
			while (file_content[i] && \
				cub_check_mapline(file_content[i], " 012NSEW", -1) != 2)
				i++;
			count_map++;
			continue ;
		}
		if (cub_check_mapline(file_content[i], " 012NSEW", -1) == 0)
		{
			while (file_content[i] && \
				cub_check_mapline(file_content[i], " 012NSEW", -1) != 1)
				i++;
			count_config++;
			continue ;
		}
		i++;
	}
	count.count_map = count_map;
	count.count_config = count_config;
	return (count);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = cub_init();
	if (!cub)
		return (1);
	cub_check_input(cub, argc, argv);
	cub_check_file_content(cub);
	printf("count_config: %d\n", \
		cub_check_map(cub->config.content, 0, 0, 0).count_config);
	printf("count_map: %d\n", \
		cub_check_map(cub->config.content, 0, 0, 0).count_map);
	cub_exit(cub);
	return (0);
}
