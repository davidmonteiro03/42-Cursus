/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:56:54 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/06 07:38:58 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/* NAME: ft_strmapi --- apply a function to each character of a string
**
**SYNOPSIS: char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
**
**DESCRIPTION: Applies the function 'f' to each character of the string 's, and
**	passing its index as first argument to create a new string, with malloc()
**	resultinf from successive applications of 'f'.
**
**PARAMETERS:	s: The string on which to iterate.
**		f: The function to apply to each character.
**
**RETURN VALUE: The string created from successsive applications of 'f'. Returns
**	NULL if the allocation fails.
**
**ERRORS: \NA
**
**FUNCTIONS: malloc()\ */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*res;

	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
/*
int add(int a, int b)
{
	return a + b;
}

int main()
{
	int(*fp)(int, int);

	f = add;
	printf("%d\n", f(10, 20)); //30
}
*/
