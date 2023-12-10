/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:32:15 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 16:46:19 by dcaetano         ###   ########.fr       */
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

void	cub_check_extension_texture(t_cub *cub, char *arg, char *extension)
{
	char	*input_extension;
	size_t	extension_len;

	extension_len = ft_strlen(extension);
	if (ft_strlen(arg) < extension_len + 1)
		return (cub_clear_error2(cub, ERROR_CONFIG));
	input_extension = ft_substr(arg, ft_strlen(arg) - \
		extension_len, extension_len);
	if (cub_strcmp(input_extension, extension))
		return (free(input_extension), cub_clear_error2(cub, ERROR_EXTENSION));
	free(input_extension);
}

void	cub_check_texture(t_cub *cub, char **strs)
{
	char	**buf;

	if (cub_strs_size(strs) != 2)
		cub_clear_error2(cub, ERROR_CONFIG);
	cub_check_extension_texture(cub, strs[1], ".xpm");
	buf = cub_read_file_texture(cub, strs[1], 0);
	multiple_free("%b", buf);
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
	i = -1;
	while (data[++i])
	{
		if (!cub_strcmp(data[i][0], "F") || !cub_strcmp(data[i][0], "C"))
			cub_check_color(cub, &data[i][1], -1);
		else
			cub_check_texture(cub, data[i]);
	}
}
