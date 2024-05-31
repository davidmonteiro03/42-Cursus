/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:46:24 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 12:10:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

enum
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

enum
{
	OLD,
	NEW,
	EXT
};

// ----- Game struct ---- //
typedef struct s_file
{
	int			fd;
	const char	*name;
	char		**content;
}	t_file;

typedef struct s_comp
{
	int	collectible;
	int	map_exit;
	int	start_position;
	int	unknown;
}	t_comp;

typedef struct s_map
{
	int		height;
	int		width;
	char	**content;
}	t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
}	t_mlx;

typedef struct s_image
{
	void	*img;
	int		bpp;
	int		size_line;
	char	*addr;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_textures
{
	t_image	empty;
	t_image	wall;
	t_image	collectible;
	t_image	exit;
}	t_textures;

typedef struct s_player
{
	t_pos			pos;
	t_image			*frames;
	t_image			*current;
	unsigned int	moves;
}	t_player;

typedef struct s_game
{
	t_file		file;
	t_map		map;
	t_comp		comp;
	t_mlx		mlx;
	t_textures	textures;
	t_player	player;
	t_pos		exit;
}	t_game;

// ------- MACROS ------- //
# define ERROR "Error"
# define USAGE "Usage: ./so_long <map>"
# define EMPTY_ARGUMENT "Empty argument"
# define ARGUMENT_TO_SHORT "Argument too short"
# define WRONG_EXTENSION "Wrong extension"
# define EMPTY_FILE "Empty file"
# define ERROR_SHAPE "The map must be rectangular."
# define ERROR_WALLS "The map must be closed/surrounded by walls."
# define ERROR_UNKNOWN_CHAR "The map must be composed of only \
'0', '1', 'C', 'E' and 'P'"
# define ERROR_COLLECT "The map must contain at least 1 collectible"
# define ERROR_PLAYER_POSITION "The map must contain 1 starting position"
# define ERROR_MAP_EXIT "The map must contain 1 exit"
# define MAIN_CHARSET "01CEP"
# define ERROR_FINISH_COLLECT "The map doesn't let the \
player collect everything"
# define ERROR_FINISH_GAME "The map doesn't let the player finish the game"

# define GAME_TITLE "SO_LONG"
# define MAP_EXTENSION ".ber"

# define EMPTY '0'
# define WALL '1'
# define COLLECT 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define VISIT 'V'

# define PATH_EMPTY "./textures/mandatory/empty.xpm"
# define PATH_WALL "./textures/mandatory/wall.xpm"
# define PATH_COLLECT "./textures/mandatory/collectible.xpm"
# define PATH_EXIT "./textures/mandatory/exit.xpm"
# define PLAYER_UP "./textures/mandatory/player_up.xpm"
# define PLAYER_LEFT "./textures/mandatory/player_left.xpm"
# define PLAYER_DOWN "./textures/mandatory/player_down.xpm"
# define PLAYER_RIGHT "./textures/mandatory/player_right.xpm"
# define PLAYER_FRAMES 4
# define TEXTURE_SIZE 32
# define MARGIN 4

# define DEBUG false

// ------- Errors ------- //
void	so_long_error(char *msg, bool usage, bool isfile); // so_long_error

// -------- Parse ------- //
void	so_long_parse(t_game *game, char *arg); // so_long_parse
void	so_long_parse_content(t_game *game); // so_long_parse_content
t_pos	so_long_getpos(char **map, char c); // so_long_getpos
void	so_long_parse_path(t_game *game); // so_long_parse_path

// -------- Exit -------- //
void	so_long_exit(t_game *game, char *error, bool iserror, \
	bool isfile); // so_long_exit

// -------- Free -------- //
void	so_long_free_file(t_file *file); // so_long_free_file
void	so_long_free_mlx(t_mlx *mlx); // so_long_free_mlx
void	so_long_free_image(t_image *image, t_mlx mlx); // so_long_free_image
void	so_long_free_textures(t_textures *textures, \
	t_mlx mlx); // so_long_free_textures
void	so_long_free_player(t_player *player, t_mlx mlx); // so_long_free_player
void	so_long_free(t_game *game); // so_long_free

// -------- Utils ------- //
void	ft_free(void **ptr); // ft_free
void	ft_freeptrs(void ***ptrs); // ft_freeptrs
int		ft_strcmp(const char *s1, const char *s2); // ft_strcmp
char	**ft_readfile(int fd); // ft_readfile
t_map	ft_mapdup(t_map map); // ft_mapdup
int		ft_minvalue(int value_a, int value_b); // ft_minvalue
int		ft_maxvalue(int value_a, int value_b); // ft_maxvalue
bool	ft_istransp(unsigned int color); // ft_istransp

// -------- Init -------- //
void	so_long_init_file(t_file *file, \
	const char *name); // so_long_init_file
void	so_long_init_map(t_map *map, char **content); // so_long_init_map
void	so_long_init_comp(t_comp *comp, t_comp src); // so_long_init_comp
void	so_long_init_mlx(t_mlx *mlx, t_map map, bool init); // so_long_init_mlx
void	so_long_init_textures(t_textures *textures, \
	t_mlx mlx, bool init); // so_long_init_textures
void	so_long_init_player(t_player *player, \
	t_mlx mlx, t_map map, bool init); // so_long_init_player
void	so_long_init_img_background(t_image *image, \
	t_mlx mlx); // so_long_init_img_background
void	so_long_init(t_game *game); // so_long_init

// ------- Display ------ //
void	so_long_display_file(t_file file, bool debug); // so_long_display_file
void	so_long_display_map(t_map map, bool debug); // so_long_display_map

// -------- Game -------- //
int		so_long_close(t_game *game); // so_long_close
void	so_long_show_img(t_image image, t_mlx mlx, \
	t_pos pos, bool transp); // so_long_display_img
void	so_long_put_block(t_game *game, \
	t_image *image, t_pos pos, char c); // so_long_put_block
void	so_long_play(t_game *game); // so_long_play
int		so_long_keypress(int keycode, t_game *game); // so_long_keypress
int		so_long_keyrelease(int keycode, t_game *game); // so_long_keyrelease
void	so_long_show_map(t_game *game); // so_long_show_map
void	so_long_show_map_case1(t_game *game); // so_long_show_map_case1
void	so_long_show_map_case2(t_game *game); // so_long_show_map_case2
void	so_long_show_map_case3(t_game *game); // so_long_show_map_case3
void	so_long_find_nearest_collect(t_game \
	*game); // so_long_find_nearest_collect
int		so_long_get_best_frame(char **map, \
	t_pos player, t_pos target); // so_long_get_best_frame

#endif
