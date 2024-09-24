/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:29:34 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/29 08:23:10 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_toupper --- Convert lowercase letters to uppercase
**
**SYNOPSIS: int ft_toupper(int i) 
**
**DESCRIPTION: This function convert lowercase letters to uppercase. If it is a
**	lowercase, ft_toupper() returns its uppercase equivalent, if an uppercase
**	exists in the current locale, otherwise it returns 'i'.
**
**RETURN VALUE: The value returned is that of the converted letter, or 'i' if the
**	conversion was not possible.
**
**PARAMETERS:	i: character to convert
**
**ERRORS: \NA
**
**FUNCTION: \NA */
int	ft_toupper(int i)
{
	if (i >= 'a' && i <= 'z')
		return (i - 32);
	return (i);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%c", ft_toupper(argv[1][0]));
	}
}
*/
