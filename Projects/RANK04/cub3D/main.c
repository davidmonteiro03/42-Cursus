/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:25:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 00:09:54 by dcaetano         ###   ########.fr       */
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
	multiple_free("%b%a", cub->textures.file_content, cub);
	return (0);
}
