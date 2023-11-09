/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:21:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/26 17:33:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lstdisplay(t_node *stack, char *str, bool pro, bool first)
{
	t_node	*tmp;

	if (first == true)
		tmp = frstlastnode(stack, false);
	else
		tmp = stack;
	ft_printf("Stack values of %s\n", str);
	while (tmp)
	{
		ft_printf("MAIN: %d ", tmp->content);
		if (pro)
		{
			if (tmp->prev)
				ft_printf("PREV: %d ", tmp->prev->content);
			else
				ft_printf("PREV: NULL ");
			if (tmp->next)
				ft_printf("NEXT: %d\n", tmp->next->content);
			else
				ft_printf("NEXT: NULL\n");
		}
		tmp = tmp->next;
	}
	ft_printf("\n");
}

t_node	*createnode(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	lstfree(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return ;
	node = frstlastnode(node, false);
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}

t_node	*addnode(t_node *node, int content)
{
	t_node	*new;

	new = createnode(content);
	if (!new)
		return (NULL);
	if (!node)
		return (new);
	node->next = new;
	new->prev = node;
	return (new);
}

t_node	*frstlastnode(t_node *node, bool last)
{
	if (!node)
		return (NULL);
	if (!last)
	{
		while (node->prev)
			node = node->prev;
		return (node);
	}
	else
	{
		while (node->next)
			node = node->next;
		return (node);
	}
}
