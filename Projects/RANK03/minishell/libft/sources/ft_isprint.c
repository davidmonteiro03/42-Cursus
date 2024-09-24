/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:46:41 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/25 04:59:19 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_isprint --- checks if its printable from 'space' to 'tilde'
**
**SYNOPSIS: int	ft_isprint(int i);
**
**DESCRIPTION: Checks for any printable character including space.
**
**PARAMETERS:	i: character to be checked
**
**RETURN VALUE: Returns 1 if is a printable character and 0 if it's not.
**
**ERRORS: \NA
**
**FUNCTION: \NA*/
int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		return (ft_isprint(argv[1][0]));
	}
	else
	{
		return (0);
	}
}
*/
