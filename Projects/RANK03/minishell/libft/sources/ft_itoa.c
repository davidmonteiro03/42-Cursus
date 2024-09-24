/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:45:38 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/04 06:28:35 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_itoa --- convert an int to a string
**
**SYNOPSIS: char	*ft_itoa(int n);
**
**DESCRIPTION: Allocates with malloc() and returns a string representing the
**	integer received as an argument. Negative numbers must be handled.
**
**PARAMETERS:	n: th integer to convert
**
**RETURN VALUE: The string representing the integer. 
**		NULL if the allocation fails.
**
**ERRORS: \NA
**
**FUNCTIONS: malloc() */
static size_t	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	len = ft_len(n);
	num = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (num)
	{
		str[len] = num % 10 + '0';
		len--;
		num = num / 10;
	}
	return (str);
}
/*
int main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(235475444));
	printf("%s\n", ft_itoa(-12236789));
}
*/
