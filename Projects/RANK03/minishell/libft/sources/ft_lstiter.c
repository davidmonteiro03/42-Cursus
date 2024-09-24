/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:17:27 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/10 06:10:07 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_lstiter --- apply a function to each element's content
**
**SYNOPSIS: void ft_lstiter(t_list *lst, void (*f)(void *));
**
**DESCRIPTION: Iterates the list ’lst’ and applies the function 'f’ on the 
**	content	of each node.
**
**PARAMETERS:	lst: The address of a pointer to a node.
**		f: The address of the function used to iterate on the list.
**
**RETURN VALUE: \NA
**
**ERRORS: \NA
**
**FUNCTION: \NA */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
/*
static void ft_str(void *s)
{
	char *str;

	str = (char *)s;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

int main(void)
{
	t_list *head;
	t_list *node;
	t_list *node1;
	t_list *tmp;

	head = ft_lstnew(ft_strdup("Ate parece COIsa linda"));
	node = ft_lstnew(ft_strdup("E ate eSPETAcular"));
	head->next = node;
	node1 = ft_lstnew(ft_strdup("MAS nao e"));
	head->next->next = node1;
	ft_lstiter(head, ft_str);
	tmp = head;
	while (tmp)
	{
		printf("%s\n", (char *)(*tmp).content);
		tmp = (*tmp).next;
	}
}
*/
