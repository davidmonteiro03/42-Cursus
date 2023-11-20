/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:17:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 22:23:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"
#include <readline/readline.h>

void	count_chars(char *line, int *count)
{
	int		i;
	int		status;
	char	c;

	i = -1;
	status = 0;
	c = 0;
	while (line[++i])
	{
		if (status == 0 && (line[i] == '\'' || line[i] == '\"'))
		{
			status = 1;
			c = line[i];
			continue ;
		}
		if (status == 1 && line[i] == c)
		{
			status = 0;
			c = 0;
			continue ;
		}
		if ((line[i] == ' ' && line[i - 1] != ' ' && status == 0) || \
			((line[i] != ' ' && status == 0) || status == 1))
			*count += 1;
	}
}

void	build_str(char *line, int j, char *buf)
{
	int		i;
	int		status;
	char	c;

	i = -1;
	status = 0;
	c = 0;
	while (line[++i])
	{
		if (status == 0 && (line[i] == '\'' || line[i] == '\"'))
		{
			status = 1;
			c = line[i];
			continue ;
		}
		if (status == 1 && line[i] == c)
		{
			status = 0;
			c = 0;
			continue ;
		}
		if ((line[i] == ' ' && line[i - 1] != ' ' && status == 0) || \
			((line[i] != ' ' && status == 0) || status == 1))
			buf[j++] = line[i];
	}
}

int	main(void)
{
	char	*line;
	char	*buf;
	int		count;

	line = readline("minishell$ ");
	line = buildfree(line, " ", &ft_strtrim);
	count = 0;
	count_chars(line, &count);
	buf = malloc(sizeof(char *) * (count + 1));
	build_str(line, 0, buf);
	free(line);
	buf[count] = '\0';
	printf("%s\n", buf);
	free(buf);
	return (0);
}
