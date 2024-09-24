/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:59:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 20:13:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	ft_skip_quotes(char **ret, char *const line, size_t *i)
{
	char	*sub;
	char	*tmp;
	size_t	k;
	char	quote;

	if (line == NULL || i == NULL || line[*i] == '\0')
		return (0);
	quote = line[(*i)++];
	k = *i;
	while (line[*i] != '\0' && line[*i] != quote)
		(*i)++;
	if (line[*i] != '\0')
		(*i)++;
	if (ret != NULL && *ret != NULL && *i > k)
	{
		tmp = *ret;
		sub = ft_substr(line, k, *i - k - 1);
		if (sub != NULL)
		{
			*ret = ft_strjoin(*ret, sub);
			free(tmp);
			free(sub);
		}
	}
	return (*i - k - 1);
}

static size_t	ft_skip_normal(char **ret, char *const line, size_t *i)
{
	char	*sub;
	char	*tmp;
	size_t	k;

	if (line == NULL || i == NULL || line[*i] == '\0')
		return (0);
	k = *i;
	while (line[*i] != '\0' && line[*i] != '\"' && line[*i] != '\'')
		(*i)++;
	if (ret != NULL && *ret != NULL && *i > k)
	{
		tmp = *ret;
		sub = ft_substr(line, k, *i - k);
		if (sub != NULL)
		{
			*ret = ft_strjoin(*ret, sub);
			free(tmp);
			free(sub);
		}
	}
	return (*i - k);
}

static void	ft_skip(char **ret, char *const line, size_t i)
{
	if (line == NULL || *line == '\0')
		return ;
	while (line[i] != '\0')
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			ft_skip_quotes(ret, line, &i);
			continue ;
		}
		ft_skip_normal(ret, line, &i);
	}
}

char	*parse_quotes(char *const str)
{
	char	*ret;

	if (str == NULL || *str == '\0')
		return (NULL);
	ret = ft_strdup("");
	ft_skip(&ret, str, 0);
	return (ret);
}
