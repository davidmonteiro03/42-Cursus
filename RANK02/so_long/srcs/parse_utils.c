/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:21:06 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 12:56:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	parse_chars(char **lines)
{
	t_chars	chars;
	int		i;

	chars = chars_init();
	i = -1;
	while (lines[++i])
	{
		if (find_invalid_char(lines[i], chars) == 1)
		{
			multiple_free("%b", lines);
			simperror("Found a invalid char in file!");
		}
	}
}

void	parse_info(char **lines, t_mapinfo *mapinfo)
{
	t_chars	chars;
	int		i;
	int		j;

	chars = chars_init();
	i = -1;
	while (lines[++i])
	{
		j = -1;
		while (lines[i][++j])
			mapinfo_update(lines[i][j], mapinfo, chars);
	}
	if (mapinfo->n_collect < 1 || mapinfo->n_exit != 1 || \
		mapinfo->n_start_pos != 1)
	{
		multiple_free("%b", lines);
		simperror("Invalid map");
	}
	mapinfo->n_lines = i;
	mapinfo->n_columns = j;
}

void	parse_walls(char **lines, t_mapinfo *mapinfo)
{
	t_chars	chars;
	int		i;
	int		j;

	chars = chars_init();
	i = -1;
	while (++i < mapinfo->n_lines)
	{
		j = -1;
		while (++j < mapinfo->n_columns)
		{
			if ((i == 0 || j == 0 || i == mapinfo->n_lines - 1 || \
				j == mapinfo->n_columns - 1) && lines[i][j] != chars.wall)
			{
				multiple_free("%b", lines);
				simperror("The border of the map must be a wall");
			}
		}
	}
}

void	parse_contents(char **lines)
{
	t_mapinfo	mapinfo;

	parse_length_lines(lines);
	parse_chars(lines);
	mapinfo = mapinfo_init();
	parse_info(lines, &mapinfo);
	parse_walls(lines, &mapinfo);
}
