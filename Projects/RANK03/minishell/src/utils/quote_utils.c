/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:27:54 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*expand_til(char *line, int *i)
{
	char	*tmp;

	if (*i == 0 || line[*i - 1] == ' '
		|| line[*i - 1] == '\t' || line[*i - 1] == '/')
	{
		if (line[*i + 1] == ' ' || line[*i + 1] == '\t'
			|| line[*i + 1] == '/' || line[*i + 1] == '\0')
		{
			*i += 1;
			tmp = expand(ft_strdup("$HOME"));
			if (*tmp)
				return (tmp);
			return (free(tmp), ft_strdup("~"));
		}
	}
	*i += 1;
	return (ft_strdup("~"));
}

static char	*helper(char *line, int *i)
{
	int		j;
	char	*tmp;

	j = skip(&line[*i + 1], line[*i]);
	tmp = ft_substr(line, *i + 1, j);
	if (line[*i] == '\'')
	{
		*i += j + 2;
		return (tmp);
	}
	*i += j + 2;
	return (expand_arg_adv(tmp, 0, 0));
}

char	*handle_quotes(char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			break ;
		if (line[i] == '\"' || line[i] == '\'')
			tmp = ft_joint_free(tmp, helper(line, &i));
		else if (line[i] == '~')
			tmp = ft_joint_free(tmp, expand_til(line, &i));
		else
		{
			j = i;
			while (line[i] != ' ' && line[i] != '\t' && line[i] != '\"'
				&& line[i] && line[i] != '\'')
				i++;
			tmp = ft_joint_free(tmp, expand_arg_adv
					(ft_substr(line, j, (i - j)), 0, 0));
		}
	}
	return (tmp);
}

int	handle_quotes_count(char *line)
{
	int		i;
	int		j;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			break ;
		if (line[i] == '\"' || line[i] == '\'')
		{
			j = skip(&line[i + 1], line[i]);
			i += j + 2;
		}
		else
			i++;
	}
	return (i);
}
