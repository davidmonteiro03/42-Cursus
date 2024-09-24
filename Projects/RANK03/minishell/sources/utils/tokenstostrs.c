/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenstostrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:43:05 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:29:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**utils_tokenstostrs(t_tokens *const tokens)
{
	size_t		i;
	size_t		count;
	t_tokens	*iter;
	char		**strs;

	if (tokens == NULL)
		return (NULL);
	count = tokens_size(tokens);
	if (count == 0)
		return (NULL);
	strs = (char **)ft_calloc(count + 1, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i = 0;
	iter = tokens_first(tokens);
	while (iter != NULL)
	{
		strs[i++] = ft_strdup(iter->value);
		iter = iter->next;
	}
	strs[i] = NULL;
	return (strs);
}
