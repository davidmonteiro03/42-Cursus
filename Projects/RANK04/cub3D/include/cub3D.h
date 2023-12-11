/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:28:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/11 21:46:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

// ERRORS
# define ERROR_INPUT "Invalid input"
# define ERROR_EXTENSION "Invalid extension"
# define ERROR_LENGTH "Invalid length in given argument"
# define ERROR_EMPTY "Empty file"
# define ERROR_FILE "Error in file content"

typedef struct s_info
{
	int	pos;
	int	count;
}t_info;

typedef struct s_file
{
	int		fd;
	char	*filename;
	char	**content;
}t_file;

typedef struct s_cub
{
	t_file	config;
	t_info	map_info;
	t_info	config_info;
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
void			free_file(t_file file);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

// init
t_info			cub_info_init(void);
t_file			cub_file_init(void);
t_cub			*cub_init(void);

/* ************************************************************************** */
/*                                   PARSER                                   */
/* ************************************************************************** */

// parse file
void			cub_check_file_content(t_cub *cub);

// parse info
int				cub_check_mapline(char *line, char *charset, int i);
void			cub_check_maps(char **file_content, int i, t_info *map_info);
void			cub_check_config(char **file_content, int i, \
	t_info *config_info);

// parse input
char			*cub_check_extension(t_cub *cub, char *arg, char *extension);
void			cub_check_input(t_cub *cub, int argc, char **argv);

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

// get num
int				cub_get_num_chars(char *str, char c);
int				cub_strs_size(char **strs);

// multiple free
void			multiple_free(const char *format, ...);

// rgb to hex
unsigned long	cub_rgb_to_hex(int red, int green, int blue);

// strcmp
int				cub_strcmp(const char *s1, const char *s2);

#endif
