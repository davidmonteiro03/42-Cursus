/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 11:19:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BCYN "\e[1;36m"
# define BRST "\e[1;0m"

# define MEMORY_ERROR "Problem with memory allocation"
# define ARGUMENT_ERROR "Problem with given argument"
# define LENGTH_ERROR "Argument length must be greater than extension length"
# define EXTENSION_ERROR "Wrong extension"

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <strings.h>

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

////////////////////////////////////////////////////////////////////////////////
//                                   DISPLAY                                  //
////////////////////////////////////////////////////////////////////////////////

void	display_strs(char **strs);
void	display_chars_struct(t_chars chars);

////////////////////////////////////////////////////////////////////////////////
//                                   ERRORS                                   //
////////////////////////////////////////////////////////////////////////////////

void	simperror(char *error);
void	fileerror(char *file);

////////////////////////////////////////////////////////////////////////////////
//                                    FREE                                    //
////////////////////////////////////////////////////////////////////////////////

void	simplefree(void *pnt);
void	free_pnts(void **pnts);
void	free_ppnts(void ***ppnts);
void	type_free(va_list args, const char format);
void	multiple_free(const char *format, ...);

////////////////////////////////////////////////////////////////////////////////
//                                 PARSE UTILS                                //
////////////////////////////////////////////////////////////////////////////////

char	*parse_extension(char *arg, char *ext);
char	**read_file(char *file);
void	parse_length_lines(char **lines);
void	parse_contents(char **lines);

////////////////////////////////////////////////////////////////////////////////
//                               PARSE ARGUMENTS                              //
////////////////////////////////////////////////////////////////////////////////

void	parse_arg(char *arg);

////////////////////////////////////////////////////////////////////////////////
//                          STRUCTURES INITIALIZATION                         //
////////////////////////////////////////////////////////////////////////////////

t_chars	chars_init(void);

////////////////////////////////////////////////////////////////////////////////
//                                    UTILS                                   //
////////////////////////////////////////////////////////////////////////////////

char	*specialtrim(char *str, char *ext);
char	*ft_jointfree2(char *s1, char *s2);

#endif
