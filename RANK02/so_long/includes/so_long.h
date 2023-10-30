/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 19:38:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BCYN "\e[1;36m"
# define BRST "\e[1;0m"

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <strings.h>

////////////////////////////////////////////////////////////////////////////////
//                                   ERRORS                                   //
////////////////////////////////////////////////////////////////////////////////

void	simperror(char *error);

////////////////////////////////////////////////////////////////////////////////
//                               PARSE ARGUMENTS                              //
////////////////////////////////////////////////////////////////////////////////

char	*parse_extension(char *arg, char *extension);
void	parse_arg(char *arg);

////////////////////////////////////////////////////////////////////////////////
//                                    FREE                                    //
////////////////////////////////////////////////////////////////////////////////

void	free_strings(void **pnts);
void	type_free(va_list args, const char format);
void	multiple_free(const char *format, ...);

#endif
