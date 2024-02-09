/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:09:25 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/09 22:09:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ltoa_bonus(t_list *list)
{
	t_list	*tmp;
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_lstsize(list) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	tmp = list;
	while (tmp)
	{
		ret[i++] = ft_vtoc_bonus(tmp->content);
		tmp = tmp->next;
	}
	ret[i] = '\0';
	return (ret);
}
