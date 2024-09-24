/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:32:48 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/10 07:06:11 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_lstmap --- creates a new list resulting from the application of f to
**	each element
**
**SYNOPSIS: t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
**		void (*del)(void *));
**
**DESCRIPTION: Iterates the list ’lst’ and applies the function ’f’ on the 
**	content of each node. Creates a new list resulting of the successive
**	applications of the function ’f’. The ’del’ function is used to delete
**	the content of a node if needed.
**
**PARAMETERS:	lst: The address of a pointer to a node.
**		f: The address of the function used to iterate on the list.
**		del: The address of the function used to delete the content of a
**		node if needed.
**
**RETURN VALUE: The new list. NULL if the allocation fails
**
**ERRORS: NULL if allocation fails
**
**FUNCTION: malloc(), free() */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*node;
	void	*set;

	if (!lst || !f || !del)
		return (0);
	list = 0;
	while (lst)
	{
		set = f((*lst).content);
		node = ft_lstnew(set);
		if (!node)
		{
			del(set);
			ft_lstclear(&list, (*del));
			return (list);
		}
		ft_lstadd_back(&list, node);
		lst = (*lst).next;
	}
	return (list);
}
/*
static void	*ft_str(void *se)
{
	int i = 0;
	char *str;
	char *s;

	s = (char *)se;
	str = malloc(ft_strlen((char *)s + 1));
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			str[i] = s[i] + 32;
		else
			str[i] = s[i];
		i++;

	}
	return (str);
}

static void	ft_del(void *ptr)
{
	free(ptr);
}

int main(void)
{
	t_list *head;
	t_list *node1;
	t_list *result;
	t_list *tmp;
	int	num;
	num = 5;

	head = ft_lstnew(ft_strdup("TONE"));

	node1 = ft_lstnew(ft_strdup("o BINO ..."));
	head->next = node1;
	node1 = ft_lstnew(ft_strdup("Morreu"));
	head->next->next = node1;

 	result = ft_lstmap(head, *ft_str, ft_del);
	tmp = head;
	while (tmp)
	{
	printf("%s\n", (char *)tmp->content);
	tmp = tmp ->next;
	}
	tmp = result;
	while (tmp)
	{
	printf("%s\n", (char *)tmp->content);
	tmp = tmp ->next;
	}
}
*/
