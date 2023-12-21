/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:15:35 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_access(char *file)
{
	if (access(file, F_OK))
	{
		get_exit_code(1, 1);
		return (ft_fprintf(2, "bash: %s: \
No such file or directory\n", file), 1);
	}
	if (access(file, R_OK))
	{
		get_exit_code(1, 1);
		return (ft_fprintf(2, "bash: %s: Permission denied\n", file), 1);
	}
	return (0);
}

int	exec_red1(char **args, t_input *input)
{
	int		fd;
	char	*tmp;

	tmp = ft_strdup("");
	if (args[0][0] == '<')
	{
		if (args[0][1] == '<')
		{
			if (call_heardoc(&tmp, args, input))
				return (free(tmp), free_split(args), 1);
		}
		else
		{
			if (check_access(args[1]))
				return (free(tmp), free_split(args), 1);
			fd = open(args[1], O_RDONLY);
			if (fd < 0)
				return (free(tmp), get_exit_code(1, 1), free_split(args), 1);
			dup2(fd, 0);
			close(fd);
		}
	}
	return (free(tmp), free_split(args), 0);
}

int	exec_red2(char **args)
{
	int		fd;

	if (args[0][0] == '>')
	{
		if (!access(args[1], F_OK) && check_access(args[1]))
			return (free_split(args), 1);
		if (args[0][1] == '>')
			fd = open(args[1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			fd = open(args[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (get_exit_code(1, 1), free_split(args), 1);
		dup2(fd, 1);
		close(fd);
	}
	return (free_split(args), 0);
}

void	helper(int *i, char *tmp)
{
	while (tmp[*i] && tmp[*i] != ' ' && tmp[*i] != '\t' \
		&& tmp[*i] != '>' && tmp[*i] != '<'
		&& tmp[*i] != '|')
	{
		if (tmp[*i] == '\'' || tmp[*i] == '\"')
			*i += skip(tmp + *i + 1, tmp[*i]) + 1;
		*i += 1;
	}
}

int	handle_redirect(t_input *input, int i)
{
	char	**args;
	int		j;
	char	*tmp;
	char	*tmp2;

	tmp = input->line + i;
	i = 0;
	while (tmp[i] && (tmp[i] == '>' || tmp[i] == '<'))
		i++;
	if (!tmp[i])
		return (1);
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_substr(tmp, 0, i);
	skip_space(tmp, &i);
	j = i;
	helper(&i, tmp);
	args[1] = ft_substr(tmp, j, i - j);
	tmp2 = args[1];
	args[1] = handle_quotes(args[1]);
	free(tmp2);
	args[2] = NULL;
	if (args[0][0] == '<')
		return (ft_memset(tmp, ' ', i), exec_red1(args, input));
	return (ft_memset(tmp, ' ', i), exec_red2(args));
}
