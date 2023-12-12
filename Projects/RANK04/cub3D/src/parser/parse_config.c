/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:30:20 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/12 23:37:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_check_config_args(t_cub *cub, char *str)
{
	char	**tmp;
	int		size;

	(void)cub;
	tmp = ft_split(str, ' ');
	size = cub_strs_size(tmp);
	multiple_free("%b", tmp);
	if (size < 2)
		cub_error_file(cub, ERROR_CONFIG, false);
}

void	cub_check_config_info(t_cub *cub, t_info config_info)
{
	int	i;

	i = config_info.pos_start;
	while (i <= config_info.pos_end)
	{
		if (!*cub->config.content[i] || cub_dif_char_in(cub->config.content[i], " \t"))
		{
			i++;
			continue ;
		}
		cub_check_config_line(cub, cub->config.content[i++]);
	}
}
