/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:25:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/09 22:27:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (!cub)
		return (1);
	cub->textures.filename = cub_check_input(argc, argv);
	cub_check_file_content(cub->textures.filename, cub);
	cub_get_textures(cub, cub->textures.file_content, -1);
	if (!cub_check_textures(cub->textures.textures, -1))
		cub_error_parsing(cub, ERROR_TEXTURES);
	multiple_free("%c%a", cub->textures.textures, cub);
	return (0);
}
