/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:06:41 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/10 05:53:10 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_lstclear --- removes the element passed as parameter and all the
**	following elements
**
**SYNOPSIS: void ft_lstclear(t_list **lst, void (*del)(void*));
**
**DESCRIPTION: Deletes and frees the given node and every successor of that node,
**	using the function ’del’ and free(). Finally, the pointer to the list
**	must be set to NULL.
**
**PARAMETERS:	lst: The address of a pointer to a node.
**		del: The address of the function used to delete the content of
**	the node.
**
**RETURN VALUE: \NA
**
**ERRORS: \NA
**
**FUNCTION: free */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*(*lst)).next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
	*lst = 0;
}
/*
void ft_del(void *ptr)
{
	free(ptr);
}

int main(void)
{
	t_list *head;
	t_list *node;
	t_list *node1;
	t_list *tmp;

	head = ft_lstnew(ft_strdup("que"));
	node = ft_lstnew(ft_strdup("cena"));
	(*head).next = node;
	node1 = ft_lstnew(ft_strdup("marada"));
	(*head).next = node1;
	ft_lstclear(&node, ft_del);
	tmp = head;
	while (tmp)
	{
		printf("%s\n", (char *)(*tmp).content);
	tmp = (*tmp).next;
	}
}
*/
