/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:28:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 19:52:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
/* # include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h> */

// ERRORS
# define ERROR_INPUT "Invalid input"
# define ERROR_EXTENSION "Invalid extension"
# define ERROR_LENGTH "Invalid length in given argument"
# define ERROR_EMPTY "Empty file"

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

// errors
void	cub_error(char *error, bool perror_flag);

/* ************************************************************************** */
/*                                   PARSER                                   */
/* ************************************************************************** */

// parse file
void	cub_check_file_content(char *filename, int i);

// parse input
char	*cub_check_input(int argc, char **argv);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

// multiple free
void	multiple_free(const char *format, ...);

// strcmp
int		cub_strcmp(const char *s1, const char *s2);

#endif
