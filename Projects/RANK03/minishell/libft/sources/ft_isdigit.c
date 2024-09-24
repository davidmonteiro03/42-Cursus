/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:00:14 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/25 00:43:35 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_isdigit --- Checks for a digit (0 through 9)
**
**SYNOPSIS: int	ft_isdigit(int i)
**
**DESCRIPTION: This function checks if 'i' is a digit (0 through 9).
**
**PARAMETERS:	i: digit to be checked 
**
**RETURN VALUE: Returns 1 if is a digit and return 0 if not.
**
**ERRORS: \NA
**
**FUNCTION: \NA */
int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}
/*
int	main( int argc, char **argv)
{
	if (argc == 2)
	{
		return (ft_isdigit(argv[1][0]));
	}
	else
	{
		return (0);
	}
}
*/
