/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:24:40 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/15 18:44:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <readline/readline.h>
#include <sys/wait.h>

char	*joinfree(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**args;
	char	*input;
	char	cwd[1024];
	pid_t	pid;
	int		i;

	(void)ac;
	(void)av;
	while (1)
	{
		input = ft_strdup("");
		input = joinfree(input, "╭─ ");
		input = joinfree(input, getcwd(cwd, sizeof(cwd)));
		input = joinfree(input, "\n╰─❯ ");
		line = readline(input);
		if (!line)
			break ;
		if (*line)
		{
			if (ft_strncmp(line, "ls", 2) == 0)
			{
				pid = fork();
				args = (char **)malloc(sizeof(char *) * 2);
				args[0] = "ls";
				args[1] = NULL;
				if (pid == 0)
					execve("/bin/ls", args, env);
				else
					wait(NULL);
				free(args);
			}
			else if (ft_strncmp(line, "cd", 2) == 0)
			{
				args = ft_split(line, ' ');
				i = 0;
				while (args[i])
					i++;
				if (i == 1)
					chdir(getenv("HOME"));
				else if (i == 2)
					chdir(args[1]);
				if (i > 0)
				{
					i = -1;
					while (args[++i])
						free(args[i]);
					free(args);
				}
			}
			else if (ft_strncmp(line, "clear", 2) == 0)
			{
				pid = fork();
				args = (char **)malloc(sizeof(char *) * 2);
				args[0] = "clear";
				args[1] = NULL;
				if (pid == 0)
					execve("/bin/clear", args, env);
				else
					wait(NULL);
				free(args);
			}
		}
		free(line);
		free(input);
	}
	return (0);
}
