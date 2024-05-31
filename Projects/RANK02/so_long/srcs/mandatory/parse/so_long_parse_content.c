/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:47:45 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/03 19:07:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	so_long_parse_lines_len(t_game *game)
{
	int		i;
	size_t	mainlen;
	size_t	currlen;

	mainlen = ft_strlen(game->file.content[0]);
	i = -1;
	while (game->file.content[++i] != NULL)
	{
		currlen = ft_strlen(game->file.content[i]);
		if (currlen != mainlen)
			return (so_long_exit(game, ERROR_SHAPE, true, false));
	}
}

static void	so_long_parse_walls(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map.content[++i] != NULL)
	{
		j = -1;
		while (game->map.content[i][++j] != '\0')
		{
			if ((i == 0 || i == game->map.height - 1 || \
				j == 0 || j == game->map.width - 1) && \
				game->map.content[i][j] != WALL)
				return (so_long_exit(game, ERROR_WALLS, true, false));
		}
	}
}

static void	so_long_parse_data(t_game *game, t_comp comp)
{
	if (comp.unknown > 0)
		return (so_long_exit(game, ERROR_UNKNOWN_CHAR, true, false));
	if (comp.start_position != 1)
		return (so_long_exit(game, ERROR_PLAYER_POSITION, true, false));
	if (comp.map_exit != 1)
		return (so_long_exit(game, ERROR_MAP_EXIT, true, false));
	if (comp.collectible < 1)
		return (so_long_exit(game, ERROR_COLLECT, true, false));
}

static void	so_long_parse_components(t_game *game)
{
	int		i;
	int		j;
	t_comp	tmp;

	tmp = (t_comp){0};
	i = -1;
	while (game->map.content[++i] != NULL)
	{
		j = -1;
		while (game->map.content[i][++j] != '\0')
		{
			if (ft_strchr(MAIN_CHARSET, game->map.content[i][j]) == NULL)
				tmp.unknown++;
			else if (game->map.content[i][j] == PLAYER)
				tmp.start_position++;
			else if (game->map.content[i][j] == COLLECT)
				tmp.collectible++;
			else if (game->map.content[i][j] == EXIT)
				tmp.map_exit++;
		}
	}
	so_long_parse_data(game, tmp);
	so_long_init_comp(&game->comp, tmp);
}

void	so_long_parse_content(t_game *game)
{
	so_long_parse_lines_len(game);
	so_long_parse_walls(game);
	so_long_parse_components(game);
	so_long_parse_path(game);
}
