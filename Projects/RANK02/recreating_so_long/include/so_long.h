/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:06:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 20:40:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_ARG "Invalid argument"
# define ERROR_CONTENT "File content is invalid"
# define ERROR_EMPTY "File is empty"
# define ERROR_MALLOC "Memory allocation failed"

/* ************************************************************************** */
/*                                    ERRORS                                  */
/* ************************************************************************** */

void	so_long_error_file(char *file);
void	so_long_error(char *error);
void	so_long_usage(void);

/* ************************************************************************** */
/*                                    FREE                                    */
/* ************************************************************************** */

void	free_strs(char **strs, int i);

/* ************************************************************************** */
/*                                 PARSE_ARGS                                 */
/* ************************************************************************** */

void	so_long_check_args(int argc, char **argv);

/* ************************************************************************** */
/*                                    UTILS                                   */
/* ************************************************************************** */

bool	so_long_check_extension(char *filename, char *extension);
char	*so_long_last_str(char **strs);
bool	so_long_open_file(char *arg);

#endif
