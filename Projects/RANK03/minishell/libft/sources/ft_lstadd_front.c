/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:41:07 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/07 04:12:11 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_lstad_front --- Adds a new element ar the front of the list
**
**SYNOPSIS: void ft_lstadd_front(t_list **lst, t_list *new);
**
**DESCRIPTION: Adds the node ’new’ at the beginning of the list.
**
**PARAMETERS:	lst: The address of a pointer to the first link of a list.
**		new: The address of a pointer to the node to be added to
**	the list.
**
**RETURN VALUE: \NA
**
**ERRORS: \NA
**
**FUNCTION: \NA */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	(*new).next = *lst;
	*lst = new;
}

/*
int main() {
    t_list *list = NULL;
    t_list *new = ft_lstnew("Hello, world!");

    ft_lstadd_front(&list, new);

    printf("Content: %s\n", (char *)list->content);
    printf("Next: %p\n", list->next);

    return 0;
}
*/
/*

int	main(void)
{
	t_list	*list;
	t_list	new0;
	t_list	new1;
	t_list	new2;
	t_list	new3;

	int	num0 = 34;
	int	num1 = 12;
	int	num2 = 32;
	int	num3 = 54;

	list = &new1;
	new1.next = &new2;
	new2.next = &new3;
	new3.next = 0;

	new0.content = &num1;
	new1.content = &num1;
	new2.content = &num2;
	new3.content = &num3;

	printf("First new0: %d\n",*(int *)new0.content);

	ft_lstadd_front(&list, &new0);
	if (list)
		list = &new0;
		list = &new1;
		list = &new2;
		list = &new3;
	printf("%d\n",*(int *)new0.content);
	printf("%d\n",*(int *)new1.content);
	return (0);

}
*/
