/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:06:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/03 10:59:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_intdup(int start, int end, int flag)
{
	int		*result;
	int		len;
	size_t	i;

	if (flag == 0)
		len = end - start + 1;
	else
		len = start - end + 1;
	result = (int *)malloc(sizeof(int) * len);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (flag == 0)
		while (start <= end)
			result[i++] = start++;
	else
		while (start >= end)
			result[i++] = start--;
	return (result);
}

int	*ft_range(int start, int end)
{
	if (start != end)
		return (ft_intdup(start, end, start > end));
	return (ft_intdup(0, 0, 1));
}
