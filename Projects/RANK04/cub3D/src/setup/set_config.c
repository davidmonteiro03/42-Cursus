/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:26:58 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 17:04:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_set_textures(t_cub *cub, char **content, int i)
{
	char	**args;

	while (content[++i])
	{
		if (!*content[i] || cub_dif_char_in(content[i], "\t "))
			continue ;
		args = cub_get_args(content[i]);
		if (!cub_strcmp(args[0], "NO"))
			cub->directions.north = cub_img_init(args[1]);
		else if (!cub_strcmp(args[0], "SO"))
			cub->directions.south = cub_img_init(args[1]);
		else if (!cub_strcmp(args[0], "WE"))
			cub->directions.west = cub_img_init(args[1]);
		else if (!cub_strcmp(args[0], "EA"))
			cub->directions.east = cub_img_init(args[1]);
		multiple_free("%b", args);
	}
}

t_color	cub_set_color(char **strs)
{
	t_color	color;
	char	**args;
	char	*buf;
	int		i;

	buf = ft_strdup("");
	i = 0;
	while (strs[++i])
		buf = cub_buildfree(buf, ft_strdup(strs[i]), &ft_strjoin);
	args = ft_split(buf, ',');
	free(buf);
	color.red = ft_atoi(args[0]);
	color.green = ft_atoi(args[1]);
	color.blue = ft_atoi(args[2]);
	multiple_free("%b", args);
	color.hex = (color.red << 16) + (color.green << 8) + color.blue;
	return (color);
}

void	cub_set_colors(t_cub *cub, char **content, int i)
{
	char	**args;

	while (content[++i])
	{
		if (!*content[i] || cub_dif_char_in(content[i], "\t "))
			continue ;
		args = cub_get_args(content[i]);
		if (!cub_strcmp(args[0], "F"))
			cub->floor = cub_set_color(args);
		else if (!cub_strcmp(args[0], "C"))
			cub->ceiling = cub_set_color(args);
		multiple_free("%b", args);
	}
}

void	cub_set_config(t_cub *cub)
{
	char	**args;

	args = cub_get_lines(cub->config.content, cub->config_info.pos_start, \
		cub->config_info.pos_end);
	cub_set_textures(cub, args, -1);
	cub_set_colors(cub, args, -1);
	multiple_free("%b", args);
}
