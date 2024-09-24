/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:53:56 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/08 05:24:09 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_putstr_fd --- write a string on a file descriptor
**
**SYNOPSIS: void ft_putstr_fd(char *s, int fd);
**
**DESCRIPTION: Outputs the string ’s’ to the given file descriptor.
**
**PARAMETERS:	s: The sring to output.
**		fd: The file descriptor on wich to write.
**
**RETURN VALUE: \NA
**
**ERRORS: 'fd' cannot take negative values.
**
**FUNCTION: write */
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
/*
int main()
{
char str[] = "coisa\n";
ft_putstr_fd(str, 1);

char error[] = "erro\n";
ft_putstr_fd(error, 55555);

ft_putstr_fd("pois", -1);


}

*/
