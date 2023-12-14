/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:28:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/14 15:03:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

// MACROS
# define MAP_CHARSET "01NSEW"

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

typedef struct s_info
{
	int		pos_start;
	int		pos_end;
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

typedef struct s_cub
{
	t_file			config;
	t_info			map_info;
	t_info			config_info;
	t_mlx			mlx;
	t_directions	directions;
	t_color			floor;
	t_color			ceiling;
}t_cub;

/* ************************************************************************** */
/*                                    EXIT                                    */
/* ************************************************************************** */

// cub exit
void			cub_exit(t_cub *cub);

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
void			free_img(t_img img);
void			free_file(t_file file);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

// init
t_img			cub_img_init(char *path);
t_count			cub_count_init(void);
t_info			cub_info_init(void);
t_file			cub_file_init(void);
t_cub			*cub_init(void);

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
// // parse border
void			cub_check_border(t_cub *cub, int start, int end);

// // parse dups
void			cub_check_multiple_maps(t_cub *cub, int start, int end);

// // parse map
void			cub_check_map_info(t_cub *cub, t_info map_info);

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

// config
void			cub_set_config(t_cub *cub);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

// atol
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
size_t			cub_get_max_len(char **map, int i);
bool			cub_dif_char_in(char *str, char *charset);
int				cub_get_num_chars(char *str, char c);
int				cub_strs_size(char **strs);

// multiple free
void			multiple_free(const char *format, ...);

// strcmp
int				cub_strcmp(const char *s1, const char *s2);

#endif
