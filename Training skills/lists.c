/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:13:27 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/12 18:12:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

typedef struct s_data
{
	int	number;
}t_data;

t_list	*create_node(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_data	*data_init(int number)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->number = number;
	return (data);
}

void	add_node_end(t_list **list, t_list *node)
{
	t_list	*tmp;

	if (!*list)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

t_list	*last_node(t_list *list)
{
	t_list	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	swap_nodes(t_list **list)
{
	t_list	*tmp;

	if (!*list || !(*list)->next)
		return ;
	tmp = (*list)->next;
	(*list)->next = tmp->next;
	tmp->next = *list;
	*list = tmp;
}

void	push_node(t_list **list_from, t_list **list_to)
{
	t_list	*tmp;

	if (!*list_from)
		return ;
	tmp = *list_from;
	*list_from = (*list_from)->next;
	tmp->next = *list_to;
	*list_to = tmp;
}

void	rotate_list(t_list **list)
{
	t_list	*tmp;
	t_list	*last;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	last = last_node(*list);
	*list = (*list)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rev_rotate_list(t_list **list)
{
	t_list	*tmp;
	t_list	*last;

	if (!*list || !(*list)->next)
		return ;
	tmp = *list;
	last = last_node(*list);
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *list;
	*list = last;
}

void	display_content(void *content)
{
	t_data	*data;

	data = (t_data *)content;
	printf("%d", data->number);
}

void	display_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		display_content(tmp->content);
		if (tmp->next)
			printf(" => ");
		tmp = tmp->next;
	}
	printf("\n");
}

void	free_content(void *content)
{
	t_data	*data;

	data = (t_data *)content;
	free(data);
}

void	clear_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free_content((*list)->content);
		free(*list);
		*list = tmp;
	}
}

void	reverse_list(t_list **list_a, t_list **list_b)
{
	while (*list_a)
	{
		rev_rotate_list(list_a);
		push_node(list_a, list_b);
	}
	while (*list_b)
		push_node(list_b, list_a);
}

int	ascending(int a, int b)
{
	return (a < b);
}

int	descending(int a, int b)
{
	return (a > b);
}

void	sort_list(t_list **list_a, t_list **list_b, int (*f)(int, int))
{
	t_list	*max_node;
	t_list	*tmp;

	while (*list_a)
	{
		max_node = *list_a;
		tmp = (*list_a)->next;
		while (tmp)
		{
			if (f(((t_data *)tmp->content)->number, ((t_data *)max_node->content)->number))
				max_node = tmp;
			tmp = tmp->next;
		}
		while (*list_a != max_node)
		{
			if (max_node == (*list_a)->next)
				swap_nodes(list_a);
			else if (max_node == last_node(*list_a))
				rev_rotate_list(list_a);
			else
				rotate_list(list_a);
		}
		push_node(list_a, list_b);
	}
	while (*list_b)
		push_node(list_b, list_a);
}

int	main(void)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*node;
	t_data	*data;
	int		num[10];
	int		i;
	int		j;

	srand(time(NULL));
	i = -1;
	while (++i < 10)
	{
		num[i] = rand() % 10 + 1;
		j = -1;
		while (++j < i)
		{
			if (num[i] == num[j])
			{
				num[i] = rand() % 10 + 1;
				j = -1;
			}
		}
	}
	list_a = NULL;
	list_b = NULL;
	i = -1;
	while (++i < 10)
	{
		data = data_init(num[i]);
		node = create_node(data);
		add_node_end(&list_a, node);
	}
	display_list(list_a);
	sort_list(&list_a, &list_b, ascending);
	display_list(list_a);
	sort_list(&list_a, &list_b, descending);
	display_list(list_a);
	clear_list(&list_a);
	clear_list(&list_b);
	return (0);
}
