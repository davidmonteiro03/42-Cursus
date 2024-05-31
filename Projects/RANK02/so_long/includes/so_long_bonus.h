/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:46:24 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/10 08:06:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <time.h>
# include <sys/time.h>
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
	EXT,
	PLAY
};

enum
{
	COL,
	SEN,
	MEN,
	FRB
};

enum
{
	FRM,
	ENE,
	SPL
};

enum
{
	START,
	END
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

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		height;
	int		width;
	t_pos	true_pos[2];
	char	**content;
}	t_map;

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

typedef struct s_frame
{
	int		size;
	char	*path;
}	t_frame;

typedef struct s_textures
{
	t_image	empty;
	t_image	wall;
	t_image	*collectible;
	t_image	*enemy_static;
	t_image	*enemy_moving;
	t_image	*fireball;
	t_image	exit;
}	t_textures;

typedef struct s_player
{
	t_pos			pos;
	t_image			*frames;
	t_image			*current;
	unsigned int	moves;
	bool			locked;
}	t_player;

typedef struct s_enemy
{
	t_pos	pos;
}	t_enemy;

typedef struct s_fireball
{
	t_pos	pos;
	int		direction;
}	t_fireball;

typedef struct s_time
{
	struct timeval	start;
	struct timeval	end;
}	t_time;

typedef struct s_sprites
{
	t_time	time[3];
	int		frames[4];
	double	elapsed_time[3];
}	t_sprites;

typedef struct s_message
{
	char	*text;
	t_pos	pos;
}	t_message;

typedef struct s_game
{
	t_file		file;
	t_map		map;
	t_comp		comp;
	t_mlx		mlx;
	t_textures	textures;
	t_player	player;
	t_pos		exit;
	t_list		*static_enemies;
	t_list		*moving_enemies;
	t_list		*ptrs_collect;
	t_list		*fireballs;
	t_sprites	sprites;
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
# define LOSE_REASON_1 "You were killed by the fire!"
# define LOSE_REASON_2 "You were killed by the wolf!"

# define EMPTY '0'
# define WALL '1'
# define COLLECT 'C'
# define PLAYER 'P'
# define EXIT 'E'
# define STATIC_ENEMY 'S'
# define MOVING_ENEMY 'K'
# define FIREBALL 'F'
# define VISIT 'V'

# define PATH_EMPTY "./textures/bonus/empty.xpm"
# define PATH_WALL "./textures/bonus/wall.xpm"
# define PATH_EXIT "./textures/bonus/exit.xpm"
# define PATH_PLAYER_UP "./textures/bonus/player/up.xpm"
# define PATH_PLAYER_LEFT "./textures/bonus/player/left.xpm"
# define PATH_PLAYER_DOWN "./textures/bonus/player/down.xpm"
# define PATH_PLAYER_RIGHT "./textures/bonus/player/right.xpm"
# define PATH_COLLECT "./textures/bonus/collectible/"
# define PATH_ENEMY_STATIC "./textures/bonus/enemy/static/"
# define PATH_ENEMY_MOVING "./textures/bonus/enemy/moving/"
# define PATH_FIREBALL "./textures/bonus/spell/"
# define MAX_FRAMES 9
# define COLLECT_FRAMES 9
# define ENEMY_STATIC_FRAMES 5
# define ENEMY_MOVING_FRAMES 8
# define FIREBALL_FRAMES 4
# define PLAYER_FRAMES 4
# define TEXTURE_SIZE 32
# define ENEMY_SPEED 5
# define SPELL_SPEED 10
# define MENU 5
# define RANGE 2
# define BACK_COLOR 0x00000000
# define TEXT_COLOR 0x00FFFFFF
# define MARGIN 4
# define NUM_MSGS 3

# define DEBUG false

// ------- Errors ------- //
void			so_long_error(char *msg, bool usage, \
	bool isfile); // so_long_error

// -------- Parse ------- //
void			so_long_parse(t_game *game, char *arg); // so_long_parse
void			so_long_parse_content(t_game *game); // so_long_parse_content
t_pos			so_long_getpos(char **map, char c); // so_long_getpos
void			so_long_parse_path(t_game *game); // so_long_parse_path

// -------- Exit -------- //
void			so_long_exit(t_game *game, char *error, bool iserror, \
	bool isfile); // so_long_exit

// -------- Free -------- //
void			so_long_free_file(t_file *file); // so_long_free_file
void			so_long_free_mlx(t_mlx *mlx); // so_long_free_mlx
void			so_long_free_image(t_image *image, \
	t_mlx mlx); // so_long_free_image
void			so_long_free_textures(t_textures *textures, \
	t_mlx mlx); // so_long_free_textures
void			so_long_free_player(t_player *player, \
	t_mlx mlx); // so_long_free_player
void			so_long_free_frames(t_image **frames, \
	t_mlx mlx, int size); // so_long_free_frames
void			so_long_free(t_game *game); // so_long_free

// -------- Utils ------- //
void			ft_free(void **ptr); // ft_free
void			ft_freeptrs(void ***ptrs); // ft_freeptrs
int				ft_strcmp(const char *s1, const char *s2); // ft_strcmp
char			**ft_readfile(int fd); // ft_readfile
t_map			ft_mapdup(t_map map); // ft_mapdup
int				ft_minvalue(int value_a, int value_b); // ft_minvalue
int				ft_maxvalue(int value_a, int value_b); // ft_maxvalue
char			*ft_joinfree(char *s1, char *s2); // ft_joinfree
t_enemy			*ft_newenemy(t_pos pos); // ft_newenemy
void			ft_showenemies(t_list *enemies); // ft_showenemies
t_pos			ft_generateposition(void); // ft_generateposition
t_pos			ft_generateposition2(t_map map, \
	t_pos player); // ft_generateposition2
void			ft_removenode(t_list **list, t_list *node, \
	void (*del)(void *)); // ft_removenode
t_list			*ft_findnodeptr(t_list *list, char *ptr); // ft_findnodeptr
t_list			*ft_findnodepos(t_list *list, t_pos pos); // ft_findnodepos
t_list			*ft_findnodeposfb(t_list *list, t_pos pos); // ft_findnodeposfb
void			ft_wrongfree(void *content); // ft_wrongfree
bool			ft_ptrinptrs(t_list *set, char *target); // ft_ptrinptrs
t_fireball		*ft_newfireball(t_pos pos, int direction); // ft_newfireball
bool			ft_istransp(unsigned int color); // ft_istransp

// -------- Init -------- //
void			so_long_init_file(t_file *file, \
	const char *name); // so_long_init_file
void			so_long_init_map(t_map *map, \
	char **content); // so_long_init_map
void			so_long_init_comp(t_comp *comp, \
	t_comp src); // so_long_init_comp
void			so_long_init_mlx(t_mlx *mlx, \
	t_map map, bool init); // so_long_init_mlx
void			so_long_init_textures(t_textures *textures, \
	t_mlx mlx, bool init); // so_long_init_textures
void			so_long_init_player(t_player *player, \
	t_mlx mlx, t_map map, bool init); // so_long_init_player
void			so_long_init_ptrs(t_list **ptrs, \
	t_game game, char c); // so_long_init_ptrs
void			so_long_init_img_background(t_image *image, \
	t_mlx mlx); // so_long_init_img_background
void			so_long_init_sprites(t_sprites \
	*sprites); // so_long_init_sprites
void			so_long_init(t_game *game); // so_long_init

// ------- Display ------ //
void			so_long_display_file(t_file file, \
	bool debug); // so_long_display_file
void			so_long_display_map(t_map map, \
	bool debug); // so_long_display_map

// -------- Game -------- //
int				so_long_close(t_game *game); // so_long_close
void			so_long_show_img(t_image image, t_mlx mlx, \
	t_pos pos, bool transp); // so_long_display_img
void			so_long_play(t_game *game); // so_long_play
int				so_long_keypress(int keycode, t_game *game); // so_long_keypress
int				so_long_keyrelease(int keycode, \
	t_game *game); // so_long_keyrelease
void			so_long_show_map(t_game *game); // so_long_show_map
void			so_long_show_map_case1(t_game *game); // so_long_show_map_case1
void			so_long_show_map_case2(t_game *game); // so_long_show_map_case2
void			so_long_show_map_case3(t_game *game); // so_long_show_map_case3
void			so_long_find_nearest_collect(t_game \
	*game); // so_long_find_nearest_collect
void			so_long_lose(t_game *game, char c); // so_long_lose
void			so_long_born_enemies(t_game *game, \
	char *ptr); // so_long_born_enemies
void			so_long_born_enemy(t_list **enemies, t_map *map, \
	char type, t_pos player); // so_long_born_enemy
void			so_long_move_enemy(t_game *game, \
	t_enemy *enemy, t_pos new); // so_long_move_enemy
void			so_long_move_enemies(t_game *game); // so_long_move_enemies
void			so_long_kill_enemy(t_list **enemies, \
	t_game *game, t_pos pos); // so_long_kill_enemy
void			so_long_hit_moving(t_game *game); // so_long_hit_moving
void			so_long_hit_static(t_game *game); // so_long_hit_static
void			so_long_fix_map_sizes(t_map *map); // so_long_fix_map_sizes
void			so_long_move_fireballs(t_game *game); // so_long_move_fireballs
void			so_long_update_times(t_game *game); // so_long_update_times
void			so_long_check_frames(t_game *game); // so_long_check_frames
void			so_long_put_block(t_game *game, \
	t_image *image, t_pos pos, char *c); // so_long_put_block
int				so_long_get_best_frame(char **map, \
	t_pos player, t_pos target); // so_long_get_best_frame
void			so_long_update_info(t_game *game, \
	unsigned int color, bool moves); // so_long_update_info
void			so_long_clear_spell(t_game *game, \
	t_pos pos, char *block); // so_long_clear_spell

#endif
