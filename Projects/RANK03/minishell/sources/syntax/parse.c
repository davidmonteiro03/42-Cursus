/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:11:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:27:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	parse_token_pipe(t_tokens *token)
{
	if (token == NULL)
		return (EXIT_SUCCESS);
	if (token->prev == NULL)
		return (syntax_error(TOKEN_ERROR, token->value));
	if (token->prev->type != TEXT_TYPE)
		return (syntax_error(TOKEN_ERROR, token->value));
	if (token->next == NULL)
		return (syntax_error(EOF_ERROR, NULL));
	if (token->next->type == PIPE_TYPE)
		return (syntax_error(TOKEN_ERROR, token->next->value));
	return (EXIT_SUCCESS);
}

static int	parse_token_redir(t_tokens *token)
{
	if (token == NULL)
		return (EXIT_SUCCESS);
	if (token->next == NULL)
		return (syntax_error(TOKEN_ERROR, "newline"));
	if (token->next->type != TEXT_TYPE)
		return (syntax_error(TOKEN_ERROR, token->next->value));
	return (EXIT_SUCCESS);
}

static int	parse_token_arg(t_tokens *token)
{
	char	quote;
	size_t	i;

	if (token == NULL)
		return (g_exit_status);
	i = 0;
	while (token->value[i] != '\0')
	{
		if (token->value[i] == '\"' || token->value[i] == '\'')
		{
			quote = token->value[i++];
			while (token->value[i] != '\0' && token->value[i] != quote)
				i++;
			if (token->value[i] == '\0')
				return (syntax_unexpected_eof_match(quote));
			++i;
			continue ;
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	syntax_parse(t_tokens *tokens)
{
	int			status;
	t_tokens	*iter;

	status = EXIT_SUCCESS;
	if (tokens == NULL)
		return (status);
	iter = tokens_first(tokens);
	while (iter != NULL)
	{
		if (iter->type == PIPE_TYPE)
			status = parse_token_pipe(iter);
		else if (iter->type >= REDIN_TYPE && iter->type <= APPEND_TYPE)
			status = parse_token_redir(iter);
		else
			status = parse_token_arg(iter);
		if (status != 0)
			return (status);
		iter = iter->next;
	}
	return (status);
}
