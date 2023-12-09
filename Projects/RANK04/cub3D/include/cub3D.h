/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:28:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/09 22:27:30 by dcaetano         ###   ########.fr       */
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
# define ERROR_TEXTURES "Error parsing given textures"

typedef struct s_paths
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}t_paths;

typedef struct s_textures
{
	char	*filename;
	char	**file_content;
	char	***textures;
	t_paths	paths;
}t_textures;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}t_mlx;

typedef struct s_cub
{
	t_textures	textures;
	t_mlx		mlx;
}t_cub;

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

// simple error
void	cub_error(char *error, bool perror_flag);

// error parsing
void	cub_error_parsing(t_cub *cub, char *error);

/* ************************************************************************** */
/*                                   PARSER                                   */
/* ************************************************************************** */

// check textures
bool	cub_check_textures(char ***strs, int i);

// get textures
void	cub_get_textures(t_cub *cub, char **strs, int i);

// parse file
void	cub_check_file_content(char *filename, t_cub *cub);

// parse input
char	*cub_check_input(int argc, char **argv);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

// multiple free
void	multiple_free(const char *format, ...);

// sort_strs
void	cub_strs_sort(char ***strs_ptr, int i);

// strcmp
int		cub_strcmp(const char *s1, const char *s2);

#endif
