/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:53:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 16:32:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	argspush(t_tokens **tokens, t_env *env, t_tokens *const iter)
{
	char	**tmp;
	size_t	i;

	if (tokens == NULL || iter == NULL)
		return ;
	tmp = parse_expand(env, iter->value);
	if (tmp == NULL || *tmp == NULL)
		return ;
	i = 0;
	while (tmp[i] != NULL)
		tokens_pushback(tokens, tokens_new(tmp[i++], TEXT_TYPE, false));
	utils_freestrs(tmp);
}

char	**cmds_args(t_env *env, t_tokens *const tokens)
{
	t_tokens	*iter;
	t_tokens	*buff;
	char		**ret;

	if (env == NULL || tokens == NULL)
		return (NULL);
	buff = NULL;
	iter = tokens_first(tokens);
	while (iter != NULL)
	{
		argspush(&buff, env, iter);
		iter = iter->next;
	}
	ret = utils_tokenstostrs(buff);
	return (tokens_clear(&buff), ret);
}
