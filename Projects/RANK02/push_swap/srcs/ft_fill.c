/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:50:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 07:58:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*new_element(int number)
{
	t_element	*element;

	element = (t_element *)malloc(sizeof(t_element));
	if (element == NULL)
		return (NULL);
	element->number = number;
	element->target = 0;
	return (element);
}

void	ft_fill(t_list **list, char **args)
{
	char		**tmp;
	int			i;
	t_element	*tmp_element;
	t_list		*tmp_node;

	if (list == NULL)
		return ;
	tmp = ft_acumulate(args);
	if (tmp == NULL)
		return ;
	i = -1;
	while (tmp[++i] != NULL)
	{
		tmp_element = new_element(ft_atoi(tmp[i]));
		tmp_node = ft_lstnew(tmp_element);
		ft_lstadd_back(list, tmp_node);
	}
	free_strs(tmp);
}
