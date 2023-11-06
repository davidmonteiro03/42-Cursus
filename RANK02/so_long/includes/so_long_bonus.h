/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:44:27 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/05 15:44:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BRED "\e[1;91m"
# define BGRN "\e[1;92m"
# define BYLW "\e[1;93m"
# define BCYN "\e[1;96m"
# define BWHT "\e[1;97m"
# define RESET "\e[0m"

# define LEVEL_1 BRED
# define LEVEL_2 "\e[1;31m"
# define LEVEL_3 BYLW
# define LEVEL_4 "\e[1;32m"
# define LEVEL_5 BGRN

# define MEMORY_ERROR "Problem with memory allocation"
# define ARGUMENT_ERROR "Problem with given argument"
# define LENGTH_ERROR "Argument length must be greater than extension length"
# define EXTENSION_ERROR "Wrong extension"

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <strings.h>
# include <X11/X.h>
# include <X11/keysym.h>

////////////////////////////////////////////////////////////////////////////////
//                                 STRUCTURES                                 //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_chars
{
	char	empty;
	char	wall;
	char	collect;
	char	exit;
	char	start_pos;
}t_chars;

typedef struct s_mapinfo
{
	int	n_collect;
	int	n_exit;
	int	n_start_pos;
	int	n_lines;
	int	n_columns;
	int	start_x;
	int	start_y;
}t_mapinfo;

////////////////////////////////////////////////////////////////////////////////
//                                    GAME                                    //
////////////////////////////////////////////////////////////////////////////////

// game data
typedef struct s_data
{
	char	**m;
	int		c;
	int		sc;
	int		x;
	int		y;
	int		mv;
}t_data;

// game sizes
typedef struct s_size
{
	int	m_w;
	int	m_h;
	int	i_w;
	int	i_h;
}t_size;

// player directories
typedef struct s_play_d
{
	char	*play;
	char	*play_r;
	char	*play_l;
	char	*play_u;
	char	*play_d;
}t_play_d;

// std directories
typedef struct s_std_d
{
	char	*bck;
	char	*col;
	char	*ext;
	char	*wal;
}t_std_d;

// fire directories
typedef struct s_fire_d
{
	char	*fire_1;
	char	*fire_2;
	char	*fire_3;
	char	*fire_4;
	char	*fire_5;
}t_fire_d;

// player images
typedef struct s_play_i
{
	void	*play;
	void	*play_r;
	void	*play_l;
	void	*play_u;
	void	*play_d;
}t_play_i;

// std images
typedef struct s_std_i
{
	void	*bck;
	void	*col;
	void	*ext;
	void	*wal;
}t_std_i;

// fire images
typedef struct s_fire_i
{
	void	*fire_1;
	void	*fire_2;
	void	*fire_3;
	void	*fire_4;
	void	*fire_5;
}t_fire_i;

// directories
typedef struct s_dir
{
	t_play_d	play;
	t_std_d		std;
	t_fire_d	fire;
}t_dir;

// images
typedef struct s_img
{
	t_play_i	play;
	t_std_i		std;
	t_fire_i	fire;
}t_img;

// mlx
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}t_mlx;

// game
typedef struct s_game
{
	t_data	data;
	t_size	size;
	t_dir	dir;
	t_mlx	mlx;
	t_img	img;
}t_game;

//prepare_game_bonus.c
void		prepare_game_bonus(t_game *g, t_mapinfo info);

//dir_init_bonus.c
t_std_d		std_dir_init_bonus(void);
t_play_d	play_dir_init_bonus(void);
t_fire_d	fire_dir_init_bonus(void);
t_dir		dir_init_bonus(void);

//img_init_bonus.c
t_play_i	play_img_init_bonus(t_game *g);
t_std_i		std_img_init_bonus(t_game *g);
t_fire_i	fire_img_init_bonus(t_game *g);
t_img		img_init_bonus(t_game *g);

//init_game_bonus.c
void		put_image_bonus(t_game *g, void *img, int x, int y);
void		draw_game_bonus(t_game *g);
int			empty_around_bonus(int i, int j, t_game *g);
void		put_fire_bonus(t_game *g);
void		init_game_bonus(t_game *g);

//play_game_bonus.c
int			move_bonus(int k, t_game *g);
void		put_fire_onmap_bonus(t_game *g, void *img);
int			animate_bonus(t_game *g);
void		play_game_bonus(t_game *g);

//exit_game_bonus.c
void		clean_play_imgs_bonus(t_game *g);
void		clean_std_imgs_bonus(t_game *g);
void		clean_fire_imgs_bonus(t_game *g);
void		clean_imgs_bonus(t_game *g);
int			exit_game_bonus(t_game *g);

//close_game_bonus.c
int			close_game_bonus(t_game *g);
int			lose_game_bonus(t_game *g);

//moves_bonus.c
void		right_bonus(t_game *g);
void		left_bonus(t_game *g);
void		up_bonus(t_game *g);
void		down_bonus(t_game *g);

//display_bonus.c
void		print_exit_msg(void);
void		print_score_bonus(t_game *g);
void		print_game_info(t_game *g);
void		print_lose_msg(void);

//fire_utils_bonus.c
void		check_clear_fire_bonus(t_game *g);
void		clear_fire_bonus(t_game *g, int i, int j);
void		put_fire_pos_bonus(t_game *g, int i, int j);

//display_utils_bonus.c
void		print_level1_bonus(int c, int t, int p);
void		print_level2_bonus(int c, int t, int p);
void		print_level3_bonus(int c, int t, int p);
void		print_level4_bonus(int c, int t, int p);
void		print_level5_bonus(int c, int t, int p);

////////////////////////////////////////////////////////////////////////////////
//                                   ERRORS                                   //
////////////////////////////////////////////////////////////////////////////////

void		simperror(char *error);
void		fileerror(char *file);

////////////////////////////////////////////////////////////////////////////////
//                                    FREE                                    //
////////////////////////////////////////////////////////////////////////////////

void		simplefree(void *pnt);
void		free_pnts(void **pnts);
void		free_ppnts(void ***ppnts);
void		type_free(va_list args, const char format);
void		multiple_free(const char *format, ...);

////////////////////////////////////////////////////////////////////////////////
//                               INITIALIZATION                               //
////////////////////////////////////////////////////////////////////////////////

t_chars		chars_init(void);
t_mapinfo	mapinfo_init(void);
void		mapinfo_update(char c, t_mapinfo *mapinfo, t_chars chars);

////////////////////////////////////////////////////////////////////////////////
//                               PARSE ARGUMENTS                              //
////////////////////////////////////////////////////////////////////////////////

char		*parse_extension(char *arg, char *ext);
void		parse_arg(char *arg, t_mapinfo *mapinfo, char ***lines);

////////////////////////////////////////////////////////////////////////////////
//                                 PARSE UTILS                                //
////////////////////////////////////////////////////////////////////////////////

void		parse_length_lines(char **lines);
void		parse_chars(char **lines);
void		parse_info(char **lines, t_mapinfo *mapinfo);
void		parse_walls(char **lines, t_mapinfo *mapinfo);
void		parse_contents(char **lines, t_mapinfo *mapinfo);

////////////////////////////////////////////////////////////////////////////////
//                                    UTILS                                   //
////////////////////////////////////////////////////////////////////////////////

char		*specialtrim(char *str, char *ext);
char		*ft_jointfree2(char *s1, char *s2);
char		**read_file(char *file);
int			find_invalid_char(char *str, t_chars chars);

#endif
