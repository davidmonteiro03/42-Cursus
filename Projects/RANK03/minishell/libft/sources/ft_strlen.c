/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:52:27 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/25 07:52:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*NAME: ft_strlen	--- Calculates the lenght of a string
**
**SYNOPSIS: size_t	ft_strlen(const char *ptr)
**
**DESCRIPTION: This functions calculates the length of the string pointed to
**	by ptr, excluding the terminating null byte ('\0').
**
**PARAMETERS:	*ptr: pointer to a string
**
**RETURN VALUE: returns the lengh of a string
**
**ERRORS: \NA
**
**FUCNTION: \NA*/
size_t	ft_strlen(const char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		i++;
	return (i);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		return (ft_strlen(argv[1]));
	}
	else
	{
		return (0);
	}
}
*/
