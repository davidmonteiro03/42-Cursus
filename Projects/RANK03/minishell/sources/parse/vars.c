/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:51:33 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*expanddollar(char *const str, t_env *env, size_t *i)
{
	size_t	k;
	char	*key;
	char	*value;

	if (str[++(*i)] == '?')
		return ((*i)++, ft_itoa(g_exit_status));
	k = *i;
	while (str[*i] != '\0' && (ft_isalnum(str[*i]) != 0 || str[*i] == '_'))
		(*i)++;
	if (*i == k)
		return (ft_strdup("$"));
	key = ft_substr(str, k, *i - k);
	if (key == NULL)
		return (NULL);
	value = vars_getvalue(env, key);
	free(key);
	if (value == NULL)
		return (NULL);
	return (ft_strdup(value));
}

static char	*expanded(char *const str, t_env *env)
{
	size_t	i;
	size_t	k;
	char	*value;
	char	*buffer;

	buffer = NULL;
	if (str == NULL)
		return (buffer);
	buffer = ft_strdup("");
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			value = expanddollar(str, env, &i);
			if (value != NULL)
				buffer = utils_joinfree(buffer, value);
			continue ;
		}
		k = i;
		while (str[i] != '\0' && str[i] != '$')
			i++;
		buffer = utils_joinfree(buffer, ft_substr(str, k, i - k));
	}
	return (buffer);
}

static void	expandpush(t_tokens **newt, t_tokens *const iter, t_env *env,
		bool restricted)
{
	char	*expand;

	if (newt == NULL || iter == NULL || env == NULL)
		return ;
	expand = expanded(iter->value, env);
	if (expand == NULL)
		return ;
	tokens_pushback(newt, tokens_new(expand, iter->type, restricted));
	free(expand);
}

t_tokens	*parse_vars(t_tokens *tokens, t_env *env)
{
	t_tokens	*iter;
	t_tokens	*newt;

	if (tokens == NULL || env == NULL)
		return (NULL);
	newt = NULL;
	iter = tokens_first(tokens);
	while (iter != NULL)
	{
		if (iter->type == SQUOTE_TYPE)
			tokens_pushback(&newt, tokens_new(iter->value, iter->type, false));
		else if (iter->type == DQUOTE_TYPE)
			expandpush(&newt, iter, env, false);
		else
			expandpush(&newt, iter, env, true);
		iter = iter->next;
	}
	tokens_clear(&tokens);
	return (newt);
}
