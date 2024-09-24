/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:26:30 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/25 09:18:23 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_isascii --- Checks if the character falls into the ascii table
**
**SYNOPSIS: int	ft_isascii(int i);
**
**DESCRIPTION: Checks if is a 7-bit unsigned char value that fits into de 
**	ASCII character set.
**
**PARAMETERS:	i: character to be compare
**
**RETURN VALUE: Returns 1 if found in ascii table 0 if not.
**
**ERRORS: \NA
**
**FUNCTION: \NA */
int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	else
		return (0);
}
/*
int	main(int argc, unsigned char **argv)
{
	if (argc == 2)
	{
		return (ft_isascii(argv[1][0]));
	}
	else
	{
		return (0);
	}
}
*/
