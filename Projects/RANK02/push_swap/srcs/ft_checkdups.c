/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:21:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/27 18:37:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_checkdups(t_list *list)
{
	t_list	*tmp;
	t_list	*head;
	bool	flag;

	flag = true;
	head = list;
	while (list != NULL)
	{
		tmp = list->next;
		while (tmp != NULL)
		{
			if (ft_equal(list->content, tmp->content, 0) == true)
			{
				flag = false;
				break ;
			}
			tmp = tmp->next;
		}
		list = list->next;
	}
	if (flag == false)
		return (ft_lstclear(&head, &free_content), ft_error());
}
