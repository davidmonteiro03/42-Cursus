/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:51:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/07 16:08:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

t_list	*ft_findnodeptr(t_list *list, char *ptr)
{
	char	*tmp;

	if (list == NULL || ptr == NULL)
		return (NULL);
	while (list != NULL)
	{
		tmp = (char *)list->content;
		if (tmp == ptr)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_list	*ft_findnodepos(t_list *list, t_pos pos)
{
	t_enemy	*tmp;

	if (list == NULL)
		return (NULL);
	while (list != NULL)
	{
		tmp = (t_enemy *)list->content;
		if (tmp->pos.x == pos.x && tmp->pos.y == pos.y)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_list	*ft_findnodeposfb(t_list *list, t_pos pos)
{
	t_fireball	*tmp;

	if (list == NULL)
		return (NULL);
	while (list != NULL)
	{
		tmp = (t_fireball *)list->content;
		if (tmp->pos.x == pos.x && tmp->pos.y == pos.y)
			return (list);
		list = list->next;
	}
	return (NULL);
}
