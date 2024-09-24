/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:44:03 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/07 08:05:35 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_putchar_fd --- write character c on a specified file descriptor
**
**SYNOPSIS: void ft_putchar_fd(char c, int fd);
**
**DESCRIPTION: Outputs the character ’c’ to the given filei descriptor.
**
**PARAMETERS:	c: The character to output.
**		fd: The file descriptor on which to write.
**
**RETURN VALUE: \NA
**
**ERRORS: \NA
**
**FUNCTION: write() */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*

int main()
{
ft_putchar_fd('c', 1);
ft_putchar_fd('e', 55555);

ft_putchar_fd('p', -1);
}
*/
