/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:43:22 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 14:43:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_check_multiple_maps(t_cub *cub, int start, int end)
{
	bool	flag;

	flag = false;
	while (start <= end)
	{
		if (!*cub->config.content[start] || \
			cub_dif_char_in(cub->config.content[start], " \t"))
		{
			flag = true;
			start++;
			continue ;
		}
		if (flag)
			cub_error_file(cub, ERROR_MAP, false);
		start++;
	}
}
