/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:09:57 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 12:10:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

char	*cub_get_config_type(char *str)
{
	char	**tmp;
	char	*type;

	tmp = cub_get_args(str);
	type = ft_strdup(tmp[0]);
	multiple_free("%b", tmp);
	return (type);
}

void	cub_update_count(t_count *count, char *type)
{
	if (!cub_strcmp(type, "NO"))
		count->north++;
	else if (!cub_strcmp(type, "SO"))
		count->south++;
	else if (!cub_strcmp(type, "WE"))
		count->west++;
	else if (!cub_strcmp(type, "EA"))
		count->east++;
	else if (!cub_strcmp(type, "F"))
		count->floor++;
	else if (!cub_strcmp(type, "C"))
		count->ceiling++;
}

void	cub_check_config_duplicates(t_cub *cub, int start, int end)
{
	t_count	count;
	char	*type;

	count = cub_count_init();
	while (start <= end)
	{
		if (!*cub->config.content[start] || \
			cub_dif_char_in(cub->config.content[start], " \t"))
		{
			start++;
			continue ;
		}
		type = cub_get_config_type(cub->config.content[start++]);
		cub_update_count(&count, type);
		free(type);
	}
	if (!(count.north == 1 && count.south == 1 && count.west == 1 && \
		count.east == 1 && count.floor == 1 && count.ceiling == 1))
		cub_error_file(cub, ERROR_FILE, false);
}
