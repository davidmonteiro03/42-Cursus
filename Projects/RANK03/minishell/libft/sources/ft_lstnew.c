/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:13:30 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/07 08:59:53 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_lstnew --- create a new list node element
**
**SYNOPSIS: t_list *ft_lstnew(void *content);
**
**DESCRIPTION: Allocates with malloc() and returns a new node.
**	The member variable ’content’ is initialized with the value of 
**	the parameter ’content’. 
**	The variable ’next’ is initialized to NULL.
**
**PARAMETERS:	content: The content to create the node with.
**		next: variable to inicialize with 0
**
**RETURN VALUE: The new node
**
**ERRORS: \NA
**
**FUNCTION: malloc() */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}
/*
int	main(void)
{
	t_list	*new;

	new = ft_lstnew("Pois e tal");
	printf("%s\n", (char *)new->content);
	printf("%s", (char *)new->next);
}
*/
