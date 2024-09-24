/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somefix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:10:06 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/24 12:50:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	expandpush(t_tokens **newt, char *const str, size_t start,
		size_t len)
{
	char	*tmp;

	if (newt == NULL || str == NULL)
		return ;
	tmp = ft_substr(str, start, len);
	if (tmp == NULL)
		return ;
	tokens_pushback(newt, tokens_new(tmp, TEXT_TYPE, true));
	free(tmp);
}

static void	splittokens(t_tokens **tokens, char *const str)
{
	size_t	i;
	size_t	k;

	if (tokens == NULL || str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		if (utils_isspace(str[i]) != 0)
		{
			i++;
			continue ;
		}
		k = i;
		while (str[i] != '\0' && utils_isspace(str[i]) == 0)
			i++;
		if (k > 0)
			tokens_pushback(tokens, tokens_new(" ", SPACE_TYPE, false));
		if (i > k)
			expandpush(tokens, str, k, i - k);
	}
}

t_tokens	*parse_somefix(t_tokens *tokens)
{
	t_tokens	*iter;
	t_tokens	*fixing;

	fixing = NULL;
	if (tokens == NULL)
		return (fixing);
	iter = tokens_first(tokens);
	while (iter != NULL)
	{
		if (iter->type != TEXT_TYPE)
			tokens_pushback(&fixing, tokens_new(iter->value, iter->type,
					false));
		else
			splittokens(&fixing, iter->value);
		iter = iter->next;
	}
	tokens_clear(&tokens);
	return (fixing);
}
