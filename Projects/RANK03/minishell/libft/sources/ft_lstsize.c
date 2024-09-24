/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:46:02 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/08 05:21:48 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_lstsize --- returns the number of elements in the list
**
**SYNOPSIS: int ft_lstsize(t_list *lst);
**
**DESCRIPTION: Counts the number of nodes in a list.
**
**PARAMETERS:	lst: The beginning of the list.
**
**RETURN VALUE: The length of the list
**
**ERRORS: \NA
**
**FUNCTION: \NA */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	int	i;
	t_list	*list;
	t_list	new0;
	t_list	new1;
	t_list	new2;
	
	int	num0 = 34;
	int	num1 = 12;
	int	num2 = 32;

	list = &new0;
	new0.next = &new1;
	new1.next = &new2;
	new2.next = 0;

	new0.content = &num1;
	new1.content = &num1;
	new2.content = &num2;


	i = ft_lstsize(list);;
	printf("%d\n", i);
	return (0);

}
*/
