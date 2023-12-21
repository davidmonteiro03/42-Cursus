/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:27:04 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_char(char c)
{
	if (!c)
		return (1);
	if (c == '\"' || c == '\'' || c == ' ' || c == '\t')
		return (1);
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

static int	count_args(char *line, int count)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			i += skip(&line[i + 1], line[i]) + 1;
		else if (line[i] == ' ' || line[i] == '\t')
		{
			i++;
			continue ;
		}
		else if (!check_char(line[i]))
		{
			while (!check_char(line[i]))
				i++;
			i--;
		}
		else if (line[i] == '>' || line[i] == '<')
			if (line[i + 1] == line[i])
				i++;
		i++;
		count++;
	}
	return (count);
}

static void	clean_quotes(char **arg)
{
	char	*head;
	char	*tmp;

	head = *arg;
	*arg = ft_strdup("");
	tmp = handle_quotes(head);
	*arg = ft_joint_free(*arg, tmp);
	free(head);
}

static char	*get_arg(char *line, int *i)
{
	int		j;
	char	*arg;

	j = *i;
	while (line[*i] && line[*i] != ' ' && line[*i] != '\t'
		&& line[*i] != '|' && line[*i] != '>' && line[*i] != '<')
	{
		if (line[*i] == '\"' || line[*i] == '\'')
			*i += skip(line + *i + 1, line[*i]) + 1;
		(*i)++;
	}
	if (*(line + j) == '|')
		return (ft_strdup("|"));
	if (*(line + j) == '>' || *(line + j) == '<')
	{
		if ((line + j)[1] == (line + j)[0])
			return (ft_substr((line + j), 0, 2));
		return (ft_substr((line + j), 0, 1));
	}
	arg = malloc(*i - j + 1);
	return (ft_strlcpy(arg, line + j, *i - j + 1),
		clean_quotes(&arg), arg);
}

char	**split_args(char *line, int i)
{
	char	**args;
	int		j;

	j = 0;
	args = malloc(sizeof(char *) * (count_args(line, 0) + 1));
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (line[i] == '\"' || line[i] == '\'')
		{
			args[j++] = handle_quotes(&line[i]);
			i += handle_quotes_count(&line[i]);
		}
		else
			args[j++] = get_arg(line, &i);
	}
	args[j] = NULL;
	return (args);
}
