/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:17:08 by preis-ne          #+#    #+#             */
/*   Updated: 2023/11/24 04:29:43 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_striteri --- apply a function to each character of a string
**	specifying the index
**
**SYNOPSIS: void ft_striteri(char *s, void (*f)(unsigned int, char*)); 
**
**DESCRIPTION: Applies the function ’f’ on each character of the string passed as
**	argument, passing its index as first argument. Each character is passed
**	by address to ’f’ to be modified if necessary.
**
**PARAMETERS:	s: The string on which to iterate
**		f: The function to apply to each character.
**
**RETURN VALUE: \NA
**
**ERRORS: \NA
**
**FUNTIONS: \NA
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void ft_small(unsigned int i, char *c)
{
	if (*c >= 'A' && *c <= 'Z' && i >= 0)
		*c += 32;
}

int  main(void)
{
	char str[] = "COisa pa";

	ft_striteri(str, ft_small);
	printf("%s\n", str);
}
*/
