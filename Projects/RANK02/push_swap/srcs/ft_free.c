/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:03:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/29 08:47:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(char **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

void	free_strs(char **strs)
{
	int	i;

	if (strs == NULL)
		return ;
	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

void	free_content(void *content)
{
	t_element	*tmp;

	tmp = (t_element *)content;
	free(tmp);
}
