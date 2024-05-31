/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:52:46 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 13:19:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		so_long_error(USAGE, true, false);
	so_long_init(&game);
	so_long_parse(&game, argv[1]);
	so_long_play(&game);
	so_long_exit(&game, NULL, false, false);
	return ((void)argc, (void)argv, EXIT_SUCCESS);
}
