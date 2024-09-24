/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:54:07 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/20 11:10:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*NAME: ft_atoi --- convert a string to an integer
**
**SYNOPSIS: int	atoi(const char *ptr);
**
**DESCRIPTION: The ft_atoi() function converts the initial portion of the string
**	pointed to by ptr to int. The string may begin with an arbitrary amount
**	of white space (space, \f,\n,\r,\t,\v) folowed by a single optional
**	+ or - sign.
**
**PARAMETERS:	ptr: String to convert in an integer
**
**RETURN VALUE: Returns the converted value.
**
**ERRORS: \NA;
**
**FUNCTION: \NA;
*/
static int	ft_isspace(int i, const char *ptr)
{
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == ' ')
		i++;
	return (i);
}

static int	ft_sign(int *i, const char *ptr)
{
	int	sign;

	sign = 1;
	if (ptr[*i] == '-' || ptr[*i] == '+')
	{
		if (ptr[*i] == '-')
			sign = -sign;
		*i += 1;
	}
	return (sign);
}

int	ft_atoi(const char *ptr)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	i = ft_isspace(i, ptr);
	sign = ft_sign(&i, ptr);
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + (ptr[i++] - '0');
	}
	return (sign * result);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", ft_atoi(argv[1]));
		printf("%d", atoi(argv[1]));
		return(0);
}
*/
