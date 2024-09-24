/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:11:44 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	expandpush(t_tokens **buff, t_tokens **iter)
{
	char	*tmp;

	if (buff == NULL || iter == NULL || *iter == NULL)
		return ;
	tmp = ft_strdup("");
	while (*iter != NULL && (*iter)->type != SPACE_TYPE)
	{
		tmp = utils_joinfree(tmp, ft_strdup((*iter)->value));
		*iter = (*iter)->next;
	}
	tokens_pushback(buff, tokens_new(tmp, TEXT_TYPE, false));
	free(tmp);
}

static t_tokens	*splitall(t_tokens *tokens)
{
	t_tokens	*finalbuf;
	t_tokens	*iter;

	finalbuf = NULL;
	if (tokens == NULL)
		return (finalbuf);
	iter = tokens_first(tokens);
	while (iter != NULL)
	{
		if (iter->type == SPACE_TYPE)
		{
			iter = iter->next;
			continue ;
		}
		expandpush(&finalbuf, &iter);
	}
	return (tokens_clear(&tokens), finalbuf);
}

char	**parse_expand(t_env *env, char *const str)
{
	t_tokens	*tokens;
	char		**expand;

	expand = NULL;
	tokens = NULL;
	if (str == NULL)
		return (expand);
	tokens = utils_atott(str);
	tokens = parse_vars(tokens, env);
	tokens = parse_somefix(tokens);
	tokens = splitall(tokens);
	expand = utils_tokenstostrs(tokens);
	tokens_clear(&tokens);
	return (expand);
}
