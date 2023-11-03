/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/03 11:16:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYLW "\e[1;33m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"
# define RESET "\e[0m"

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
	int		n_collect;
	int		n_exit;
	int		n_start_pos;
	int		n_lines;
	int		n_columns;
	int		start_x;
	int		start_y;
}t_mapinfo;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**m;
	void	*wall;
	void	*bck;
	void	*play;
	void	*ext;
	void	*col;
	int		i_w;
	int		i_h;
	int		m_w;
	int		m_h;
	int		c;
	int		x;
	int		y;
	int		mv;
	int		end;
}t_game;

////////////////////////////////////////////////////////////////////////////////
//                                   DISPLAY                                  //
////////////////////////////////////////////////////////////////////////////////

void		display_strs(char **strs);
void		display_chars_struct(t_chars chars);

////////////////////////////////////////////////////////////////////////////////
//                                    DRAW                                    //
////////////////////////////////////////////////////////////////////////////////

void		init_game(t_game *g);
void		draw(t_game *g);

////////////////////////////////////////////////////////////////////////////////
//                                   ERRORS                                   //
////////////////////////////////////////////////////////////////////////////////

void		simperror(char *error);
void		fileerror(char *file);

////////////////////////////////////////////////////////////////////////////////
//                                    FIND                                    //
////////////////////////////////////////////////////////////////////////////////

int			find_invalid_char(char *str, t_chars chars);

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

void		prepare_game(t_game *g, t_mapinfo info);
t_chars		chars_init(void);
t_mapinfo	mapinfo_init(void);

////////////////////////////////////////////////////////////////////////////////
//                                     MAP                                    //
////////////////////////////////////////////////////////////////////////////////

void		mapinfo_update(char c, t_mapinfo *mapinfo, t_chars chars);

////////////////////////////////////////////////////////////////////////////////
//                                    MOVES                                   //
////////////////////////////////////////////////////////////////////////////////

void		right(t_game *g);
void		left(t_game *g);
void		up(t_game *g);
void		down(t_game *g);

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
//                                    PLAY                                    //
////////////////////////////////////////////////////////////////////////////////

void		play(t_game *g);
void		exit_game(t_game *g);

////////////////////////////////////////////////////////////////////////////////
//                                  READ FILE                                 //
////////////////////////////////////////////////////////////////////////////////

char		**read_file(char *file);

////////////////////////////////////////////////////////////////////////////////
//                                    UTILS                                   //
////////////////////////////////////////////////////////////////////////////////

char		*specialtrim(char *str, char *ext);
char		*ft_jointfree2(char *s1, char *s2);

#endif
