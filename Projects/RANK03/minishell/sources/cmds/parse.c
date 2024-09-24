/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:37:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 16:11:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	skippipes(t_tokens **iter)
{
	if (iter == NULL || *iter == NULL || (*iter)->type != PIPE_TYPE)
		return ;
	while (*iter != NULL && (*iter)->type == PIPE_TYPE)
		*iter = (*iter)->next;
}

static int	handleredir(t_shell *shell, t_cmds *node, t_tokens *const token)
{
	if (shell == NULL || node == NULL || token == NULL)
		return (EXIT_FAILURE);
	if (token->type == HEREDOC_TYPE)
		return (cmds_heredoc(shell, node, token->next->value));
	if (token->type == REDIN_TYPE)
		return (cmds_redin(shell, node, token->next->value));
	if (token->type == REDOUT_TYPE)
		return (cmds_redout(shell, node, token->next->value));
	return (cmds_append(shell, node, token->next->value));
}

static int	parsecmd(t_shell *shell, t_tokens **iter)
{
	t_cmds	*node;

	if (shell == NULL || iter == NULL || *iter == NULL
		|| (*iter)->type == PIPE_TYPE)
		return (EXIT_FAILURE);
	node = cmds_new();
	cmds_pushback(&shell->cmds, node);
	while (*iter != NULL && (*iter)->type != PIPE_TYPE)
	{
		if ((*iter)->type >= REDIN_TYPE && (*iter)->type <= APPEND_TYPE)
		{
			*iter = (*iter)->next;
			if (handleredir(shell, node, (*iter)->prev) != EXIT_SUCCESS)
				return (EXIT_FAILURE);
			if (*iter != NULL)
				*iter = (*iter)->next;
			continue ;
		}
		tokens_pushback(&node->tokens, tokens_new((*iter)->value, TEXT_TYPE,
				false));
		*iter = (*iter)->next;
	}
	node->args = cmds_args(&shell->env, node->tokens);
	return (EXIT_SUCCESS);
}

int	cmds_parse(t_shell *shell)
{
	t_tokens	*iter;

	if (shell == NULL || shell->tokens == NULL)
		return (EXIT_FAILURE);
	iter = tokens_first(shell->tokens);
	while (iter != NULL)
	{
		skippipes(&iter);
		if (parsecmd(shell, &iter) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		skippipes(&iter);
	}
	return (EXIT_SUCCESS);
}
