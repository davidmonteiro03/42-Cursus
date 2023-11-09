/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:03:46 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/09 19:08:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

// get_next_line_utils.c
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*gnl_strjoin(const char *s1, const char *s2);

// get_next_line.c
char	*get_next_line(int fd);

#endif
