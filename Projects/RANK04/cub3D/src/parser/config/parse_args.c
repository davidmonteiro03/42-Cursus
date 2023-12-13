/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:36:23 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 12:28:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_check_config_arg(t_cub *cub, char *str)
{
	char	**tmp;
	int		size;

	tmp = cub_get_args(str);
	size = cub_strs_size(tmp);
	multiple_free("%b", tmp);
	if (size < 2)
		cub_error_file(cub, ERROR_CONFIG, false);
}

void	cub_check_config_args(t_cub *cub, int start, int end)
{
	while (start <= end)
	{
		if (!*cub->config.content[start] || \
			cub_dif_char_in(cub->config.content[start], " \t"))
		{
			start++;
			continue ;
		}
		cub_check_config_arg(cub, cub->config.content[start++]);
	}
}
