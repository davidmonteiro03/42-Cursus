/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:59:14 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 12:00:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

bool	cub_config_type(char *type)
{
	if (!cub_strcmp(type, "NO"))
		return (true);
	if (!cub_strcmp(type, "SO"))
		return (true);
	if (!cub_strcmp(type, "WE"))
		return (true);
	if (!cub_strcmp(type, "EA"))
		return (true);
	if (!cub_strcmp(type, "F"))
		return (true);
	if (!cub_strcmp(type, "C"))
		return (true);
	return (false);
}

void	cub_check_config_type(t_cub *cub, char *str)
{
	char	**tmp;
	char	*type;

	tmp = cub_get_args(str);
	type = ft_strdup(tmp[0]);
	multiple_free("%b", tmp);
	if (!cub_config_type(type))
		return (free(type), cub_error_file(cub, ERROR_FILE, false));
	free(type);
}

void	cub_check_config_content(t_cub *cub, int start, int end)
{
	while (start <= end)
	{
		if (!*cub->config.content[start] || \
			cub_dif_char_in(cub->config.content[start], " \t"))
		{
			start++;
			continue ;
		}
		cub_check_config_type(cub, cub->config.content[start++]);
	}
}
