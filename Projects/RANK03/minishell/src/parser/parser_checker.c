/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 07:28:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_pipes(char *line, int i)
{
	while (line[i])
	{
		if (line[i] == '|')
			return (ft_fprintf(2, "bash: syntax error \
near unexpected token `|'\n"), 1);
		else if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			break ;
	}
	return (0);
}

int	check_redir(char *line, int i)
{
	while (line[i])
	{
		if (!ft_strcmp(&line[i], "<>")
			|| !ft_strcmp(&line[i], ">>"))
			return (ft_fprintf(2, "bash: syntax error \
near unexpected token `%c%c'\n", line[i], line[i + 1]), 1);
		if (line[i] == '|' || line[i] == '<' || line[i] == '>')
			return (ft_fprintf(2, "bash: syntax error \
near unexpected token `%c'\n", line[i]), 1);
		else if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			break ;
	}
	if (!line[i])
		return (ft_fprintf(2, "bash: syntax error \
near unexpected token `newline'\n"), 1);
	return (0);
}

int	check_redirdouble(char *line, int i)
{
	while (line[i])
	{
		if (!ft_strcmp(&line[i], "<>") || !ft_strcmp(&line[i], "<<")
			|| !ft_strcmp(&line[i], ">>"))
			return (ft_fprintf(2, "bash: syntax error \
near unexpected token `%c%c'\n", line[i], line[i + 1]), 1);
		else if (line[i] == '|' || line[i] == '<' || line[i] == '>')
			return (ft_fprintf(2, "bash: syntax error \
near unexpected token `%c'\n", line[i]), 1);
		else if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			break ;
	}
	if (!line[i])
		return (ft_fprintf(2, "bash: syntax error \
near unexpected token `newline'\n"), 1);
	return (0);
}

int	check_special(char *line)
{
	if (!ft_strncmp(line, ">>", 2))
		return (check_redirdouble(line, 2));
	else if (!ft_strncmp(line, "<<", 2))
		return (check_redirdouble(line, 2));
	else if (!ft_strncmp(line, "<>", 2))
		return (check_redirdouble(line, 2));
	else if (!ft_strncmp(line, ">", 1))
		return (check_redir(line, 1));
	else if (!ft_strncmp(line, "<", 1))
		return (check_redir(line, 1));
	else if (!ft_strncmp(line, "|", 1))
		return (check_pipes(line, 1));
	return (0);
}
