/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:49:03 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/15 09:37:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

bool	cub_check_texture(char *texture, char *extension)
{
	char	*input_extension;
	size_t	extension_len;
	t_mlx	tmp;

	extension_len = ft_strlen(extension);
	if (ft_strlen(texture) < extension_len + 1)
		return (false);
	input_extension = ft_substr(texture, ft_strlen(texture) - \
		extension_len, extension_len);
	if (cub_strcmp(input_extension, extension))
		return (free(input_extension), false);
	free(input_extension);
	tmp.mlx = mlx_init();
	tmp.img.img = mlx_xpm_file_to_image(tmp.mlx, texture, \
		&tmp.img.width, &tmp.img.height);
	if (!tmp.img.img)
		return (mlx_destroy_display(tmp.mlx), free(tmp.mlx), false);
	mlx_destroy_image(tmp.mlx, tmp.img.img);
	return (mlx_destroy_display(tmp.mlx), free(tmp.mlx), true);
}

void	cub_check_texture_args(t_cub *cub, char *type, char *line)
{
	char	**args;
	char	*texture;
	int		size;

	if (!cub_strcmp(type, "F") || !cub_strcmp(type, "C"))
		return (free(type));
	free(type);
	args = cub_get_args(line);
	size = cub_strs_size(args);
	if (size != 2)
		return (multiple_free("%b", args), \
			cub_error_file(cub, ERROR_TEXTURES, false));
	texture = ft_strdup(args[1]);
	multiple_free("%b", args);
	if (!cub_check_texture(texture, ".xpm"))
		return (free(texture), cub_error_file(cub, ERROR_XPM, false));
	free(texture);
}

void	cub_check_config_textures(t_cub *cub, int start, int end)
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
		cub_check_texture_args(cub, type, cub->config.content[start++]);
	}
}
