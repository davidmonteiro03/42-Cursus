/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:28:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 16:06:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

// MACROS
# define MAP_CHARSET "01NSEW"
# define MMAP_SZ 10
# define STEP MMAP_SZ / 32 * 2
# define PLAYER_SZ MMAP_SZ / 3
# define M_PI 3.14159265358979323846

// ERRORS
# define ERROR_INPUT "Invalid input"
# define ERROR_EXTENSION "Invalid extension"
# define ERROR_LENGTH "Invalid length in given argument"
# define ERROR_FILE "Invalid file content"
# define ERROR_MAP "Invalid map"
# define ERROR_CONFIG "Invalid configuration"
# define ERROR_TEXTURES "Invalid textures configuration"
# define ERROR_XPM "XPM file not found or invalid format"
# define ERROR_COLOR "Invalid color configuration"
# define ERROR_WALLS "Map must be surrounded by walls"
# define ERROR_PLAYER_NONE "Map must contain a player"
# define ERROR_PLAYER_MULTIPLE "Map must contain only one player"

typedef struct s_parse
{
	int	up;
	int	left;
	int	right;
	int	down;
	int	spc_up;
	int	spc_left;
	int	spc_right;
	int	spc_down;
}t_parse;

typedef struct s_adj
{
	char	up;
	char	left;
	char	center;
	char	right;
	char	down;
}t_adj;

typedef struct s_info
{
	int	pos_start;
	int	pos_end;
}t_info;

typedef struct s_file
{
	int		fd;
	char	*filename;
	char	**content;
}t_file;

typedef struct s_coord
{
	int	x;
	int	y;
}t_coord;

typedef struct s_count
{
	int	north;
	int	south;
	int	west;
	int	east;
	int	floor;
	int	ceiling;
}t_count;

typedef struct s_img
{
	char	*path;
	void	*img;
	int		width;
	int		height;
}t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_size;
	t_img	img;
}t_mlx;

typedef struct s_directions
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
}t_directions;

typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
	unsigned long	hex;
}t_color;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}t_map;

typedef struct s_player
{
	double	x;
	double	y;
	char	c;
	int		angle;
}t_player;

typedef struct s_cub
{
	t_file			config;
	t_info			map_info;
	t_info			config_info;
	t_mlx			mlx;
	t_directions	directions;
	t_color			floor;
	t_color			ceiling;
	t_map			map;
	t_player		player;
}t_cub;

/* ************************************************************************** */
/*                                    EXIT                                    */
/* ************************************************************************** */

// cub exit
int				cub_exit(t_cub *cub);

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

// simple error
void			cub_error(char *error);

// file error
void			cub_error_file(t_cub *cub, char *file, bool perror_flag);

/* ************************************************************************** */
/*                                    FREE                                    */
/* ************************************************************************** */

// free_file
void			free_mlx_imgs(t_cub *cub);
void			free_img(t_img img);
void			free_map(t_map map);
void			free_file(t_file file);
void			free_mlx(t_mlx mlx);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

// init
t_img			cub_img_init(char *path);
t_count			cub_count_init(void);
t_info			cub_info_init(void);
t_file			cub_file_init(void);
t_cub			*cub_init(void);

// init 2
t_map			cub_map_init(void);
t_color			cub_color_init(void);
t_mlx			cub_mlx_init(void);
t_player		cub_player_init(void);
void			*cub_new_image(void *mlx, t_img *img);

/* ************************************************************************** */
/*                                    MLX                                     */
/* ************************************************************************** */

// draw utils
void			cub_draw_circle(t_cub *cub, int x, int y, int i);
void			cub_clear_circle(t_cub *cub, int x, int y, int i);

// draw
void			cub_draw_shape(t_mlx mlx, int x, int y, int color);
void			cub_draw_map(t_cub *cub, char **map, int y);
void			cub_mlx(t_cub *cub);

// key handler
int				cub_key_handler(int keycode, t_cub *cub);
int				cub_render(t_cub *cub);

/* ************************************************************************** */
/*                                   PARSER                                   */
/* ************************************************************************** */

// config
// // parse args
void			cub_check_config_arg(t_cub *cub, char *str);
void			cub_check_config_args(t_cub *cub, int start, int end);

// // parse colors
void			cub_check_color_args(t_cub *cub, char *type, char *line);
void			cub_check_config_colors(t_cub *cub, int start, int end);

// // parse config
void			cub_check_config_info(t_cub *cub, t_info config_info);

// // parse duplicates
char			*cub_get_config_type(char *str);
void			cub_update_count(t_count *count, char *type);
void			cub_check_config_duplicates(t_cub *cub, int start, int end);

// // parse type
bool			cub_config_type(char *type);
void			cub_check_config_type(t_cub *cub, char *str);
void			cub_check_config_content(t_cub *cub, int start, int end);

// // parse textures
bool			cub_check_texture(char *texture, char *extension);
void			cub_check_texture_args(t_cub *cub, char *type, char *line);
void			cub_check_config_textures(t_cub *cub, int start, int end);

// map
// // parse border utils
void			cub_update_parse_up(t_parse *parse, char **strs, \
	int k, int l);
void			cub_update_parse_left(t_parse *parse, char **strs, \
	int k, int l);
void			cub_update_parse_right(t_parse *parse, char **strs, \
	int k, int l);
void			cub_update_parse_down(t_parse *parse, char **strs, \
	int k, int l);
void			cub_little_update(char **strs);

// // parse border utils2
t_parse			cub_init_parse(void);
bool			cub_check_space(t_parse parse, char **strs, int i, int j);
void			cub_check_char(char **strs, int i, int j);
void			cub_prepare_copy(char **strs, int i);

// // parse border utils3
bool			cub_check_char_util(t_adj adj);
bool			cub_check_char_border(char **map, int i, int j);
bool			cub_check_walls(char **map, int i);
void			cub_check_border_pro(t_cub *cub, int start, int end);

// // parse border utils4
void			cub_check_1(t_adj *adj, char **map, int i, int j);
void			cub_check_2(t_adj *adj, char **map, int i, int j);
void			cub_check_3(t_adj *adj, char **map, int i, int j);

// // parse border utils5
void			cub_update_1(t_adj *adj, char **map, int i, int j);
void			cub_update_2(t_adj *adj, char **map, int i, int j);
void			cub_update_3(t_adj *adj, char **map, int i, int j);

// // parse border utils6
void			cub_update_4(t_adj *adj, char **map, int i, int j);
void			cub_update_5(t_adj *adj, char **map, int i, int j);
void			cub_update_6(t_adj *adj, char **map, int i, int j);

// // parse border utils7
void			cub_update_7(t_adj *adj, char **map, int i, int j);
void			cub_update_8(t_adj *adj, char **map, int i, int j);
void			cub_update_9(t_adj *adj, char **map, int i, int j);

// // parse border
t_coord			cub_get_coord(char **map, int i);
void			cub_flood_fill(t_cub *cub, char **map, int x, int y);
bool			cub_fix_check(char **copy, int *i, int *j);
void			cub_fix_copy(char **copy);
void			cub_check_border(t_cub *cub, int start, int end);

// // parse dups
void			cub_check_player(t_cub *cub, int start, int end);
void			cub_check_multiple_maps(t_cub *cub, int start, int end);

// // parse map
void			cub_check_map_info(t_cub *cub, t_info map_info);

// // parse player
void			cub_check_player(t_cub *cub, int start, int end);

// parse file
void			cub_check_file_content(t_cub *cub);

// parse info
void			cub_check_mixes(t_cub *cub, int start, int end, bool flag);
int				cub_check_mapline(char *line, char *charset, int i);
void			cub_check_maps(char **file_content, int i, t_info *map_info);
void			cub_check_config(char **file_content, int i, \
	t_info *config_info);
void			cub_check_data(t_cub *cub);

// parse input
char			*cub_check_extension(t_cub *cub, char *arg, char *extension);
void			cub_check_input(t_cub *cub, int argc, char **argv);

/* ************************************************************************** */
/*                                    SETUP                                   */
/* ************************************************************************** */

// map
t_player		cub_get_player_pos(char **map);
void			cub_set_map(t_cub *cub);

// config
void			cub_set_config(t_cub *cub);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

// utils1
int				cub_get_angle(t_cub *cub, char c);
unsigned long	ft_min(unsigned long a, unsigned long b);
unsigned long	ft_max(unsigned long a, unsigned long b);
unsigned long	cub_contrast_color(unsigned long color, \
	unsigned long dark, unsigned long light);
long int		cub_atol(const char *nptr);

// build free
char			*cub_buildfree(char *s1, char *s2, \
	char *(*f)(const char *, const char *));

// display file content
void			cub_display_strs(char **file_content, int start, int end);

// get lines
char			**cub_get_args(char *str);
char			**cub_copy(char **map, int i, int max_len);
char			**cub_get_lines(char **content, int start, int end);

// get size
size_t			cub_strlen(char *str, char c);
size_t			cub_get_max_len(char **map, char c, int i);
bool			cub_dif_char_in(char *str, char *charset);
int				cub_get_num_chars(char *str, char c);
int				cub_strs_size(char **strs);

// multiple free
void			multiple_free(const char *format, ...);

// strcmp
int				cub_strcmp(const char *s1, const char *s2);

#endif
