/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:54:01 by preis-ne          #+#    #+#             */
/*   Updated: 2023/12/08 05:03:49 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/*NAME: ft_lstadd_back --- adds a new node at the end of the list
**
**SYNOPSIS: void ft_lstadd_back(t_list **lst, t_list *new);
**
**DESCRIPTION: Adds the node ’new’ at the end of the list.
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
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}
/*
 int main()
{
  t_list *begin = NULL;
  t_list elem1;
  t_list elem2;
  t_list elem3;
  t_list elem4;
  int	num1;
  int	num2;
  int	num3;
  int 	num4;

	num1 = 1;
	num2 = 2;
	num3 = 3;
	num4 = 4;

  begin = &elem1;
  elem1.next = &elem2;
  elem2.next = &elem3;
  elem3.next = NULL;

  elem1.content = &num1;
  elem2.content = &num2;
  elem3.content = &num3;
  elem4.content = &num4;
  elem4.next = NULL;
  
  ft_lstadd_back(&begin, &elem4);
  int i;

  i = -1;
  //while (++i < 3)
  	begin = begin->next->next->next;
 // while (begin != NULL)
 // {
    printf("%d\n", *(int *)begin->content);
   // begin = begin->next;
  //}

  return 0;
}
*/
