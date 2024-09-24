/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 05:35:27 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/04 06:47:51 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_strrchr --- locate character in LAST occurence in string.
**
**SYNOPSIS: char	*ft_strrchr(const char *ptr, int i);
**
**DESCRIPTION: The ft_strchr() function returns a pointer to the LAST occurence
**	of the character i in the string ptr.
**
**PARAMETERS:
**RETURN VALUE: Returns  a pointer to the matched character or NULL if the
**	character is not found. The terminating null byte is considered part
**	of the string, so that if 'i' is specified as '\0', these functions return
**	a pointer to the terminator.
**
**ERRORS: Here "character" means "byte"; these functions do not work with
**	wide or multibyte characters.
**
**FUNCTION: \NA */
char	*ft_strrchr(const char *ptr, int i)
{
	int	len;

	len = ft_strlen(ptr) + 1;
	while (len--)
		if (ptr[len] == (char)i)
			return ((char *)&ptr[len]);
	return (0);
}
/*
#include <string.h>
int	main(void)
{
	char	arr[]= "coisaipois";
	char	i = 'i';
	char	v = ' ';

	printf("%s\n", ft_strrchr(arr,i));
	printf("%s\n", ft_strrchr(arr,v));
	printf("%s\n", strrchr(arr,i));
	printf("%s", strrchr(arr,v));
	
}
*/
