/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:25:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/13 16:23:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = cub_init();
	if (!cub)
		return (1);
	cub_check_input(cub, argc, argv);
	cub_check_file_content(cub);
	cub_check_data(cub);
	cub_set_config(cub);
	cub_exit(cub);
	return (0);
}
