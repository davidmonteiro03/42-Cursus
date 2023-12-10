/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:32:15 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 09:46:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	cub_check_each_config(char *str)
{
	if (!cub_strcmp(str, "NO"))
		return (true);
	if (!cub_strcmp(str, "SO"))
		return (true);
	if (!cub_strcmp(str, "WE"))
		return (true);
	if (!cub_strcmp(str, "EA"))
		return (true);
	if (!cub_strcmp(str, "F"))
		return (true);
	if (!cub_strcmp(str, "C"))
		return (true);
	return (false);
}

void	cub_check_config(t_cub *cub, char **strs, int i)
{
	char	*tmp;
	char	**tmp_strs;

	while (strs[++i])
	{
		tmp = cub_get_config(strs[i], 0);
		if (!tmp)
			continue ;
		tmp_strs = ft_split(tmp, ' ');
		free(tmp);
		if (!tmp_strs)
			return (cub_clear_error1(cub, ERROR_CONFIG));
		if (!*tmp_strs)
			return (free(tmp_strs), cub_clear_error1(cub, ERROR_CONFIG));
		if (!cub_check_each_config(tmp_strs[0]))
			return (multiple_free("%b", tmp_strs), \
				cub_clear_error1(cub, ERROR_CONFIG));
		multiple_free("%b", tmp_strs);
	}
}

void	cub_set_config(t_cub *cub, char **strs, int i, int count)
{
	char	*tmp;

	cub->config.data.data = (char ***)malloc(sizeof(char **) * 7);
	cub->config.data.data[6] = NULL;
	while (strs[++i])
	{
		tmp = cub_get_config(strs[i], 0);
		if (!tmp)
			continue ;
		cub->config.data.data[count++] = ft_split(tmp, ' ');
		free(tmp);
	}
}

void	cub_check_data(t_cub *cub, char ***data, int i)
{
	int	j;

	while (data[++i])
	{
		j = -1;
		while (data[++j])
			if (i != j && !cub_strcmp(data[i][0], data[j][0]))
				return (cub_clear_error2(cub, ERROR_CONFIG));
	}
}
