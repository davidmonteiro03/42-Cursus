/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 03:03:45 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/24 05:58:37 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME:ft_tolower --- convert character to lower case
**
**SYNOPSIS: int	ft_tolower(int i)
**
**DESCRIPTION: This function convert uppercase to lowercase. If i is an uppercase
**	letter, ft_tolower() returns its lowercase equivalent, if a lowercase 
**	representation exists in the current locale. 
**
**PARAMETERS:	i: character to be converted
**
**RETURN VALUE: The return value is that of the converted letter, or 'i' if the 
**	convertion was not possible.
**
**ERRORS: \NA
**
**FUNTION: \NA */
int	ft_tolower(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (i + 32);
	return (i);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%c", ft_tolower(argv[1][0]));
	}
}
*/
