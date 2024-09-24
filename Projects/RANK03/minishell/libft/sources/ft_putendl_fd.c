/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 01:02:58 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/08 05:25:04 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_putendl_fd --- write a string on a file description follow by a 
**		new line
**
**SYNOPSIS: void ft_putendl_fd(char *s, int fd);
**
**DESCRIPTIONS: Outputs the string ’s’ to the given file descriptor followed by
**	a newline.
**
**PARAMETERS:	s: The string to output.
**		fd: The file descriptor on which to write.
**
**RETURN VALUE: \NA
**
**ERRORS: \NA
**
**FUNCTION: write */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
