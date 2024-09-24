/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:51:49 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/08 04:38:02 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_lstlast --- get the last element of the list
**
**SYNOPSIS: t_list *ft_lstlast(t_list *lst);
**
**DESCRIPTION: Returns the last node of the list.
**
**PARAMETERS:	lst: The beginning of the list.
**
**RETURN VALUE: Last node of the list
**
**ERRORS: \NA
**
**FUNCTION: \NA */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*list;
	t_list	*node;
	t_list	*temp;
	int	i;
	int	*num;

	list = NULL;
	i = 0;
	while (i < 100)
	{
		num = (int *)malloc(sizeof(int));
		*num = i + 1;
		node = ft_lstnew(num);
		ft_lstadd_back(&list, node);
		i++;
	}
	printf("last value of list: %d\n", *(int *)(ft_lstlast(list)->content));
	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
	return (0);

}
*/
