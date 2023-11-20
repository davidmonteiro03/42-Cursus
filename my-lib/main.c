/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:17:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 19:39:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_lib.h"
#include <readline/readline.h>

void	parse_quotes(char *line)
{
	int		i;
	int		status;
	char	c;

	i = -1;
	status = 0;
	c = 0;
	line = ft_strtrim(line, " ");
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
		if (line[i - 1] == ' ' && line[i] != ' ' && status == 0)
			printf("\n");
		printf("%c", line[i]);
		if (line[i + 1] == c)
			printf("\n");
	}
	printf("\n");
}

int	main(void)
{
	char	*line;

	line = readline("minishell$ ");
	parse_quotes(line);
	return (0);
}
