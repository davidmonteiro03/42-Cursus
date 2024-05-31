/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:30:52 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/26 13:49:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;
	size_t			i;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = -1;
	while (aux_s1[++i] || aux_s2[i])
		if (aux_s1[i] != aux_s2[i])
			return (aux_s1[i] - aux_s2[i]);
	return (0);
}

int	ft_max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

int	ft_min(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}

int	ft_countmoves(t_list *list, t_list *target)
{
	int	count;

	if (list == NULL || target == NULL)
		return (0);
	count = 0;
	while (list != NULL && list != target)
	{
		list = list->next;
		count++;
	}
	return (count);
}

int	ft_calc_optimize(int a, int b)
{
	int	ret;

	ret = 0;
	while (a-- > 0 && b-- > 0)
		ret++;
	return (ret);
}
