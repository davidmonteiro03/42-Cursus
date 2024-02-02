/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:26:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/02 21:39:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int* ret = NULL;
	if (start == end)
	{
		ret = (int*)malloc(sizeof(int));
		*ret = 0;
	}
	else if (start > end)
	{
		ret = (int*)malloc(sizeof(int) * (start - end));
		int i = 0;
		while (start >= end)
			ret[i++] = start--;
	}
	else
	{
		ret = (int*)malloc(sizeof(int) * (end - start));
		int i = 0;
		while (end >= start)
			ret[i++] = end--;
	}
	return (ret);
}
