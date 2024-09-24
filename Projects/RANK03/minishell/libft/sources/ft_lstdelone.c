/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:02:03 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/10 05:07:10 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_lstdelone --- removes one element from the list
**
**SYNOPSIS: void ft_lstdelone(t_list *lst, void (*del)(void*));
**
**DESCRIPTION: Takes as a parameter a node and frees the memory of the node’s
**	content using the function ’del’ given as a parameter and free the node.
**	The memory of ’next’ must not be freed.
**
**PARAMETERS:	lst: The node to free.
**		del: The address of the function used to delete the content.
**
**RETURN VALUE: \NA
**
**ERRORS: \NA
**
**FUNCTION: free() */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del((*lst).content);
	free(lst);
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
	head = ft_lstnew(ft_strdup("coisa"));
 	head->next = NULL;
	node = ft_lstnew(ft_strdup("tal"));
 	node->next = NULL;
 	head->next = node;
 	node = ft_lstnew(ft_strdup("e agora"));
 	node->next = NULL;
 	head->next->next = node;
	node = head;
	while (node)
	{
		printf("%s \n", (char *)node->content);
		node = node->next;
	}
	node = head->next;
	head->next = node->next;
 	ft_lstdelone(node, ft_del);
	node = head;
	while (node)
	{
		printf("%s\n", (char *)node->content);
		node = node->next;
	} 
}
*/
