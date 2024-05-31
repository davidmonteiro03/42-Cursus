/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:13:06 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/05 17:09:05 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	srand(time(NULL));
	if (argc != 2)
		so_long_error(USAGE, true, false);
	so_long_init(&game);
	so_long_parse(&game, argv[1]);
	so_long_play(&game);
	so_long_exit(&game, NULL, false, false);
	return ((void)argc, (void)argv, EXIT_SUCCESS);
}
