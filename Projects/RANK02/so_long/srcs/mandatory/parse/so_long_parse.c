/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:58:25 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/10 13:14:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	so_long_parse_ext(t_game *game, char *arg, char *ext)
{
	char	*rigth_pos;
	char	*what_pos;
	int		result;

	if (arg == NULL)
		return (so_long_exit(game, EMPTY_ARGUMENT, true, false));
	if (ft_strlen(arg) <= ft_strlen(ext))
		return (ft_free((void **)&arg), \
			so_long_exit(game, ARGUMENT_TO_SHORT, true, false));
	what_pos = ft_strnstr(arg, ext, ft_strlen(arg));
	if (what_pos == NULL)
		return (ft_free((void **)&arg), \
			so_long_exit(game, WRONG_EXTENSION, true, false));
	rigth_pos = arg + ft_strlen(arg) - ft_strlen(ext);
	result = ft_strcmp(what_pos, rigth_pos);
	ft_free((void **)&arg);
	if (result != 0)
		return (so_long_exit(game, WRONG_EXTENSION, true, false));
}

static void	so_long_parse_arg(t_game *game, char *arg)
{
	char	**tmp;
	char	**head;
	char	*last;

	tmp = ft_split(arg, '/');
	if (tmp == NULL || *tmp == NULL)
		return (ft_freeptrs((void ***)&tmp), \
			so_long_exit(game, EMPTY_ARGUMENT, true, false));
	head = tmp;
	while (*tmp != NULL && *(tmp + 1) != NULL)
		tmp++;
	last = ft_strdup(*tmp);
	ft_freeptrs((void ***)&head);
	so_long_parse_ext(game, last, MAP_EXTENSION);
}

static void	so_long_parse_file(t_game *game, char *name)
{
	so_long_init_file(&game->file, name);
	if (game->file.fd == -1)
		return (so_long_exit(game, name, true, true));
	if (game->file.content == NULL)
		return (so_long_exit(game, EMPTY_FILE, true, false));
	so_long_init_map(&game->map, game->file.content);
	so_long_parse_content(game);
}

void	so_long_parse(t_game *game, char *arg)
{
	so_long_parse_arg(game, arg);
	so_long_parse_file(game, arg);
}
