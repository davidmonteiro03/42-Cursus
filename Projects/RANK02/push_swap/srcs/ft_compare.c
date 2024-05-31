/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:31:51 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/27 18:37:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_greater(void *cont1, void *cont2, int mode)
{
	t_element	*tmp1;
	t_element	*tmp2;

	if (cont1 == NULL || cont2 == NULL)
		return (false);
	tmp1 = (t_element *)cont1;
	tmp2 = (t_element *)cont2;
	if (mode == 0)
		return (tmp1->number > tmp2->number);
	if (mode == 1)
		return (tmp1->target > tmp2->target);
	if (mode == 2)
		return (tmp1->number > tmp2->target);
	return (tmp1->target > tmp2->number);
}

bool	ft_smaller(void *cont1, void *cont2, int mode)
{
	t_element	*tmp1;
	t_element	*tmp2;

	if (cont1 == NULL || cont2 == NULL)
		return (false);
	tmp1 = (t_element *)cont1;
	tmp2 = (t_element *)cont2;
	if (mode == 0)
		return (tmp1->number < tmp2->number);
	if (mode == 1)
		return (tmp1->target < tmp2->target);
	if (mode == 2)
		return (tmp1->number < tmp2->target);
	return (tmp1->target < tmp2->number);
}

bool	ft_equal(void *cont1, void *cont2, int mode)
{
	t_element	*tmp1;
	t_element	*tmp2;

	if (cont1 == NULL || cont2 == NULL)
		return (false);
	tmp1 = (t_element *)cont1;
	tmp2 = (t_element *)cont2;
	if (mode == 0)
		return (tmp1->number == tmp2->number);
	if (mode == 1)
		return (tmp1->target == tmp2->target);
	if (mode == 2)
		return (tmp1->number == tmp2->target);
	return (tmp1->target == tmp2->number);
}
