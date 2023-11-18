/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_training.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:54:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/18 19:52:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <readline/readline.h>

char	*buildfree(char *s1, char *s2, char *(*f)(const char *, const char *))
{
	char	*str;

	str = f(s1, s2);
	free(s1);
	return (str);
}

char	*build_cmd(char *line)
{
	int		i;
	int		j;
	char	*cmd;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	j = i;
	while (line[j] && line[j] != ' ')
		j++;
	cmd = ft_substr(line, i, j - i);
	if (cmd[0] == '\"')
		cmd = buildfree(cmd, "\"", &ft_strtrim);
	else if (cmd[0] == '\'')
		cmd = buildfree(cmd, "\'", &ft_strtrim);
	return (cmd);
}

char	*build_opt(char *line)
{
	int		i;
	int		j;
	char	*opt;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	j = i;
	while (line[j] && line[j] != ' ')
		j++;
	opt = ft_substr(line, i, j - i);
	if (opt)
		return (NULL);
	if (opt[0] == '\"')
		opt = buildfree(opt, "\"", &ft_strtrim);
	else if (opt[0] == '\'')
		opt = buildfree(opt, "\'", &ft_strtrim);
	return (opt);
}

char	*build_str(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	return (&line[i]);
}

void	check_quotes(char *str)
{
	int		i;
	int		status;
	char	c;

	i = -1;
	status = 0;
	while (str[++i])
	{
		if (status == 0 && (str[i] == '\'' || str[i] == '\"'))
		{
			status = 1;
			c = str[i];
			continue ;
		}
		if (status == 1 && str[i] == c)
		{
			status = 0;
			c = 0;
			continue ;
		}
		printf("%c", str[i]);
	}
}

void	echo(char *line)
{
	char	*cmd;
	char	*opt;
	char	*str;
	int		n;

	cmd = build_cmd(line);
	opt = build_opt(line);
	str = build_str(line);
	if (opt && ft_strncmp(opt, "-n", 2) == 0 || \
		ft_strncmp(opt, "\'-n\'", 4) == 0 || \
		ft_strncmp(opt, "\"-n\"", 4) == 0)
		n = 1;
	if (n == 0)
		printf("%s", opt);
	check_quotes(str);
	else
		printf("\n");
	free(cmd);
	free(opt);
	free(str);
}

int	main(int ac, char **av)
{
	char	*line;

	(void)ac;
	line = readline("echo$ ");
	echo(line);
	free(line);
	return (0);
}
