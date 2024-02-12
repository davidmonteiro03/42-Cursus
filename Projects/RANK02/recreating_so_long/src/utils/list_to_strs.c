/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:07:59 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 21:09:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**so_long_list_to_strs(t_list *list)
{
	t_list	*tmp;
	size_t	i;
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	tmp = list;
	while (tmp)
	{
		ret[i++] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
	}
	ret[i] = NULL;
	return (ret);
}
