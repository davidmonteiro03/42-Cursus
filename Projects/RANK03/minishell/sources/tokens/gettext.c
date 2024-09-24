/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:59:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_join_quotes_text(char **ret, char *const line, size_t *i)
{
	char	*sub;
	char	*tmp;
	size_t	k;
	char	quote;

	if (line == NULL || i == NULL || line[*i] == '\0')
		return ;
	k = *i;
	quote = line[(*i)++];
	while (line[*i] != '\0' && line[*i] != quote)
		(*i)++;
	if (line[*i] != '\0')
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
}

static void	ft_join_normal_text(char **ret, char *const line, size_t *i)
{
	char	*sub;
	char	*tmp;
	size_t	k;

	if (line == NULL || i == NULL || line[*i] == '\0')
		return ;
	k = *i;
	while (line[*i] != '\0' && utils_isspace(line[*i]) == false
		&& tokens_isoper(line[*i]) == false && line[*i] != '\"'
		&& line[*i] != '\'' && !(line[*i] == '$' && (line[*i + 1] == '\"'
				|| line[*i + 1] == '\'')))
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
}

static void	ft_join_dollar_text(char **ret, char *const line, size_t *i)
{
	char	*tmp;

	if (line == NULL || i == NULL || line[*i] == '\0')
		return ;
	if (line[*i + 1] == '\"' || line[*i + 1] == '\'')
	{
		(*i)++;
		return ;
	}
	if (line[*i + 1] == '$')
	{
		tmp = *ret;
		*ret = ft_strjoin(*ret, "$$");
		free(tmp);
		*i += 2;
		return ;
	}
	tmp = *ret;
	*ret = ft_strjoin(*ret, "$");
	free(tmp);
	(*i)++;
}

static void	ft_join_text(char **ret, char *const line, size_t *i)
{
	if (line == NULL || i == NULL || line[*i] == '\0')
		return ;
	while (line[*i] != '\0' && utils_isspace(line[*i]) == true)
		(*i)++;
	while (line[*i] != '\0' && utils_isspace(line[*i]) == false
		&& tokens_isoper(line[*i]) == false)
	{
		if (line[*i] == '$')
		{
			ft_join_dollar_text(ret, line, i);
			continue ;
		}
		if (line[*i] == '\"' || line[*i] == '\'')
		{
			ft_join_quotes_text(ret, line, i);
			continue ;
		}
		ft_join_normal_text(ret, line, i);
	}
	while (line[*i] != '\0' && utils_isspace(line[*i]) == true)
		(*i)++;
}

char	*tokens_gettext(char *const line, size_t *i)
{
	char	*ret;

	if (line == NULL || i == NULL || line[*i] == '\0')
		return (NULL);
	ret = ft_strdup("");
	ft_join_text(&ret, line, i);
	return (ret);
}
