/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:17:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/28 19:44:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_2.h"

int	check_quotes(char *line, char *c, int i, int s)
{
	while (line[++i])
	{
		if (s == 0 && (line[i] == '\'' || line[i] == '\"'))
		{
			s = 1;
			*c = line[i];
			continue ;
		}
		if (s == 1 && line[i] == *c)
		{
			s = 0;
			*c = '\0';
			continue ;
		}
	}
	return (s);
}

void	dspwhtspc(char c)
{
	if (c == '\a')
		ft_putstr("\\a");
	else if (c == '\b')
		ft_putstr("\\b");
	else if (c == '\t')
		ft_putstr("\\t");
	else if (c == '\n')
		ft_putstr("\\n");
	else if (c == '\v')
		ft_putstr("\\v");
	else if (c == '\f')
		ft_putstr("\\f");
	else
		ft_putstr("\\r");
}

void	check_char(char c)
{
	if (c >= 7 && c <= 13)
		dspwhtspc(c);
	else if (ft_isprint(c))
		write(1, &c, 1);
}

void	unprint_dsp(char *line, int i)
{
	while (line[++i])
	{
		if (line[i] == '\"')
		{
			while (line[++i] && line[i] != '\"')
				check_char(line[i]);
			continue ;
		}
		if (line[i] == '\'')
		{
			while (line[++i] && line[i] != '\'')
				check_char(line[i]);
			continue ;
		}
		check_char(line[i]);
	}
}

int	main(void)
{
	char	*line;
	char	c;
	char	*tmp;
	char	*tmp2;

	c = '\0';
	line = readline("quotes $ ");
	if (check_quotes(line, &c, -1, 0))
	{
		tmp = ft_strdup(line);
		while (1)
		{
			if (!check_quotes(tmp, &c, -1, 0))
				break ;
			tmp = buildfree(tmp, ft_strdup("\n"), &ft_strjoin);
			if (c == '\'')
				tmp = buildfree(tmp, readline("ups(')> "), &ft_strjoin);
			else if (c == '\"')
				tmp = buildfree(tmp, readline("ups(\")> "), &ft_strjoin);
		}
		tmp2 = line;
		line = buildfree(tmp, ft_strdup(""), &ft_strjoin);
		free(tmp2);
	}
	return (unprint_dsp(line, -1), free(line), 0);
}
