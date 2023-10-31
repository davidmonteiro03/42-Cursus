/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:49:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 19:35:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}t_vars;

int	key_hook(int keycode)
{
	ft_printf("Key pressed: %d => %c\n", keycode, (char)keycode);
	return (keycode);
}

void	start_game(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 300, "so_long");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **av)
{
	t_mapinfo	mapinfo;
	char		**map;

	if (ac != 2)
		simperror("Try this: ./so_long {arg} [ex: map1.ber]");
	mapinfo = mapinfo_init();
	map = NULL;
	parse_arg(av[1], &mapinfo, &map);
	start_game();
	multiple_free("%b", map);
	return (EXIT_SUCCESS);
}
