/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:13:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 14:15:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_check_color_data(t_cub *cub, char **args)
{
	if (!cub_dif_char_in(args[0], "0123456789") || \
		!cub_dif_char_in(args[1], "0123456789") || \
		!cub_dif_char_in(args[2], "0123456789"))
		return (multiple_free("%b", args), \
			cub_error_file(cub, ERROR_COLOR, false));
	if (ft_atoi(args[0]) > 255 || ft_atoi(args[1]) > 255 || \
		ft_atoi(args[2]) > 255)
		return (multiple_free("%b", args), \
			cub_error_file(cub, ERROR_COLOR, false));
}

void	cub_check_color_args(t_cub *cub, char *type, char *line)
{
	char	**args;
	char	*buf;
	int		size;
	int		i;

	if (cub_strcmp(type, "F") && cub_strcmp(type, "C"))
		return (free(type));
	free(type);
	args = cub_get_args(line);
	buf = ft_strdup("");
	i = 0;
	while (args[++i])
		buf = cub_buildfree(buf, ft_strdup(args[i]), &ft_strjoin);
	multiple_free("%b", args);
	if (buf[0] == ',' || buf[ft_strlen(buf) - 1] == ',' || \
		cub_get_num_chars(buf, ',') != 2)
		return (free(buf), cub_error_file(cub, ERROR_COLOR, false));
	args = ft_split(buf, ',');
	free(buf);
	size = cub_strs_size(args);
	if (size != 3)
		return (multiple_free("%b", args), \
			cub_error_file(cub, ERROR_COLOR, false));
	cub_check_color_data(cub, args);
	multiple_free("%b", args);
}

void	cub_check_config_colors(t_cub *cub, int start, int end)
{
	char	*type;

	while (start <= end)
	{
		if (!*cub->config.content[start] || \
			cub_dif_char_in(cub->config.content[start], " \t"))
		{
			start++;
			continue ;
		}
		type = cub_get_config_type(cub->config.content[start]);
		cub_check_color_args(cub, type, cub->config.content[start++]);
	}
}
