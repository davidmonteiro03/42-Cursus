/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:46:57 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 14:19:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	cub_check_color_range(char *red, char *green, char *blue)
{
	if (cub_atol(red) < 0 || cub_atol(red) > 255)
		return (false);
	if (cub_atol(green) < 0 || cub_atol(green) > 255)
		return (false);
	if (cub_atol(blue) < 0 || cub_atol(blue) > 255)
		return (false);
	return (true);
}

void	cub_check_color(t_cub *cub, char **strs, int i)
{
	char	*buf;
	char	**tmp;

	buf = ft_strdup("");
	while (strs[++i])
		buf = cub_buildfree(buf, ft_strdup(strs[i]), &ft_strjoin);
	if (cub_get_num_chars(buf, ',') != 2)
		return (free(buf), cub_clear_error2(cub, ERROR_CONFIG));
	tmp = ft_split(buf, ',');
	free(buf);
	if (!tmp)
		return (cub_clear_error2(cub, ERROR_CONFIG));
	if (!*tmp)
		return (free(tmp), cub_clear_error2(cub, ERROR_CONFIG));
	if (cub_strs_size(tmp) != 3)
		return (multiple_free("%b", tmp), cub_clear_error2(cub, ERROR_CONFIG));
	if (!cub_check_color_range(tmp[0], tmp[1], tmp[2]))
		return (multiple_free("%b", tmp), cub_clear_error2(cub, ERROR_CONFIG));
	multiple_free("%b", tmp);
}
