/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atott.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:48:37 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	quotes_text(t_tokens **tokens, char *const str, size_t *i)
{
	size_t	k;
	char	quote;
	char	*sub;

	if (tokens == NULL || str == NULL || i == NULL || str[*i] == '\0'
		|| ft_strchr("\'\"", str[*i]) == NULL)
		return ;
	quote = str[(*i)++];
	k = *i;
	while (str[*i] != '\0' && str[*i] != quote)
		(*i)++;
	sub = ft_substr(str, k, *i - k);
	if (str[*i] != '\0')
		(*i)++;
	if (sub != NULL)
	{
		tokens_pushback(tokens, tokens_new(sub, SQUOTE_TYPE + (quote == '\"'),
				false));
		free(sub);
	}
}

static void	normal_text(t_tokens **tokens, char *const str, size_t *i)
{
	size_t	k;
	char	*sub;

	if (tokens == NULL || str == NULL || i == NULL || str[*i] == '\0'
		|| ft_strchr("\'\"", str[*i]) != NULL)
		return ;
	k = *i;
	while (str[*i] != '\0' && ft_strchr("\'\"", str[*i]) == NULL)
		(*i)++;
	if (*i == k)
		return ;
	sub = ft_substr(str, k, *i - k);
	if (sub != NULL)
	{
		tokens_pushback(tokens, tokens_new(sub, TEXT_TYPE, true));
		free(sub);
	}
}

t_tokens	*utils_atott(char *const str)
{
	t_tokens	*tokens;
	size_t		i;

	tokens = NULL;
	if (str == NULL)
		return (tokens);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr("\'\"", str[i]) != NULL)
		{
			quotes_text(&tokens, str, &i);
			continue ;
		}
		normal_text(&tokens, str, &i);
	}
	return (tokens);
}
