/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:17:37 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_type	gettype(char *const str)
{
	if (str == NULL || *str == '\0')
		return (NONE_TYPE);
	if (utils_strcmp(str, PIPE_STR) == 0)
		return (PIPE_TYPE);
	if (utils_strcmp(str, REDIN_STR) == 0)
		return (REDIN_TYPE);
	if (utils_strcmp(str, REDOUT_STR) == 0)
		return (REDOUT_TYPE);
	if (utils_strcmp(str, HEREDOC_STR) == 0)
		return (HEREDOC_TYPE);
	if (utils_strcmp(str, APPEND_STR) == 0)
		return (APPEND_TYPE);
	return (TEXT_TYPE);
}

static bool	handle_input(t_tokens **tokens, char *const token,
		t_type (*tokencode)(char *const))
{
	t_tokens	*node;

	if (tokens == NULL || token == NULL || *token == '\0')
	{
		if (token != NULL)
			free(token);
		return (true);
	}
	if (tokencode == NULL)
		node = tokens_new(token, TEXT_TYPE, false);
	else
		node = tokens_new(token, tokencode(token), false);
	free(token);
	if (node == NULL)
		return (false);
	return (tokens_pushback(tokens, node), true);
}

t_tokens	*tokens_parse(char *const line, size_t i)
{
	t_tokens	*tokens;
	char		*oper;
	char		*text;
	bool		status;

	if (line == NULL)
		return (NULL);
	tokens = NULL;
	status = true;
	while (line[i] != '\0' && line[i] != '#')
	{
		oper = tokens_getoper(line, &i);
		status = handle_input(&tokens, oper, gettype);
		if (status == false)
			return (tokens_clear(&tokens), NULL);
		text = tokens_gettext(line, &i);
		status = handle_input(&tokens, text, NULL);
		if (status == false)
			return (tokens_clear(&tokens), NULL);
	}
	if (tokens == NULL)
		return (NULL);
	return (tokens);
}
