/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:41:48 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/25 09:16:03 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_isalpha --- Checks if exists a alphabetic character
**
**SYNOPSIS: int	isalpha(int i);
**
**DESCRIPTION: This function checks if 'i' is a alphabetic character,
**	wich must have the value of an unsigned char or EOF(End Of File),
**	because it can accept the value of -1 corresponding the end of a flux.
**	It's equivalent to (ft_isupper(int i) ||ft_islower(int i)).
**
**PARAMETERS:	i: character to be checked
**
**RETURN VALUE: The return value is 1 if is an alphabetic character and 0 if not.
**
**ERRORS: \NA
**
**FUNCTION: \NA */
static int	ft_isupper(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (1);
	else
		return (0);
}

static int	ft_islower(int i)
{
	if (i >= 'a' && i <= 'z')
		return (1);
	else
		return (0);
}

int	ft_isalpha(int i)
{
	return (ft_isupper(i) || ft_islower(i));
}
/*
int	main(int argc,char **argv)
{
	if (argc != 2)
	{
		return (0);
	}
	if (argc == 2)
	{
		return (ft_isalpha(argv[1][0]));
	}
}
*/
