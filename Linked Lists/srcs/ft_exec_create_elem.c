/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:19:38 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/01 21:24:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_exec_create_elem(t_list *(*create_elem)(void *))
{
	t_list	*list;
	int		*num;

	num = (int *)malloc(sizeof(int));
	if (!num)
		return ;
	*num = 42;
	list = create_elem(num);
	if (!list)
		return ;
	printf("\n => %d\n\n", *(int *)list->data);
	free(list->data);
	free(list);
}
