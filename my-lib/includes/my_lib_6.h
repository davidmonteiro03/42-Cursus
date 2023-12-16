/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib_6.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:35:47 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/16 11:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_6_H
# define MY_LIB_6_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <dirent.h>
# include <sys/stat.h>

// wildcard
int	wild_question_mark(char *path, char *pattern);
int	wild_asterisk(char *path, char *pattern);
int	wild_brakets(char *path, char **pattern, int match, int invert);
int	wild_match(char *path, char *pattern);

#endif
