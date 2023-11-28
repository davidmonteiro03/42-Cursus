/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:17:16 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/28 15:33:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_2.h"

int	check_quotes(char *line, char c, int i, int s)
{
	while (line[++i])
	{
		if (s == 0 && (line[i] == '\'' || line[i] == '\"'))
		{
			s = 1;
			c = line[i];
			continue ;
		}
		if (s == 1 && line[i] == c)
		{
			s = 0;
			c = '\0';
			continue ;
		}
	}
	return (s);
}

int	main(void)
{
	char	*line;
	char	c;
	char	*tmp;
	char	*tmp2;

	c = '\0';
	line = readline("prompt> ");
	if (check_quotes(line, c, -1, 0))
	{
		tmp = ft_strdup(line);
		while (1)
		{
			if (!check_quotes(tmp, c, -1, 0))
				break ;
			tmp = buildfree(tmp, ft_strdup("\n"), &ft_strjoin);
			tmp = buildfree(tmp, readline("heardoc> "), &ft_strjoin);
		}
		tmp2 = line;
		line = buildfree(tmp, ft_strdup(""), &ft_strjoin);
		free(tmp2);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
