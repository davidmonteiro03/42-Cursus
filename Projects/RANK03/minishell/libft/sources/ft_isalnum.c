/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:38:24 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/26 02:13:32 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_isalnum --- Check for an alphanumeric character
**
**SYNOPSIS: int	ft_isalnum(int i);
**
**DESCRIPTION: Check for an alphanumeric character; equivalent to 
**	(ft_isalpha || ft_isdigit);
**
**PARAMETERS:	i: character to be checked.
**
**RETURN VALUE: Returns 1 if is alphanumeric or 0 if not.
**
**ERRORS:
**
**FUNCTION: */
int	ft_isalnum(int i)
{
	return (ft_isalpha(i) || ft_isdigit(i));
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		return (ft_isalnum(argv[1][0]));
	}
	return (0);
}
*/
