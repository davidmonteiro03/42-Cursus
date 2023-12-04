/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:28:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 17:03:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/my_lib_5.h"

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

void	parse_input(t_global *global)
{
	char	*tmp;

	while (1)
	{
		if (!check_quotes(global->tmp, &global->c, -1, 0))
			break ;
		global->tmp = buildfree(global->tmp, ft_strdup("\n"), &ft_strjoin);
		tmp = readline("> ");
		if (!tmp)
		{
			rl_replace_line("", 0);
			rl_on_new_line();
			printf("\n");
			continue ;
		}
		global->tmp = buildfree(global->tmp, tmp, &ft_strjoin);
	}
}

void	count_args(t_global *global, int i)
{
	while (global->line[++i])
	{
		if (global->line[i] == '\"')
		{
			while (global->line[++i] && global->line[i] != '\"')
				global->count++;
			global->count += 2;
			continue ;
		}
		if (global->line[i] == '\'')
		{
			while (global->line[++i] && global->line[i] != '\'')
				global->count++;
			global->count += 2;
			continue ;
		}
		if (global->line[i] == ' ' && global->line[i - 1] != ' ')
			global->count++;
		else if (global->line[i] != ' ')
			global->count++;
	}
}

void	construct_args(t_global *global, int i, int k)
{
	while (global->line[++i])
	{
		if (global->line[i] == '\"')
		{
			global->buff[k++] = '\"';
			while (global->line[++i] && global->line[i] != '\"')
				global->buff[k++] = global->line[i];
			global->buff[k++] = '\"';
			continue ;
		}
		if (global->line[i] == '\'')
		{
			global->buff[k++] = '\'';
			while (global->line[++i] && global->line[i] != '\'')
				global->buff[k++] = global->line[i];
			global->buff[k++] = '\'';
			continue ;
		}
		if (global->line[i] == ' ' && global->line[i - 1] != ' ')
			global->buff[k++] = '\v';
		else if (global->line[i] != ' ')
			global->buff[k++] = global->line[i];
	}
}

int	main(void)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	global->c = '\0';
	global->line = readline("shell $ ");
	if (!global->line)
		return (0);
	global->line = buildfree(global->line, ft_strdup(" "), &ft_strtrim);
	if (check_quotes(global->line, &global->c, -1, 0))
	{
		global->tmp = ft_strdup(global->line);
		parse_input(global);
		global->tmp2 = global->line;
		global->line = buildfree(global->tmp, ft_strdup(""), &ft_strjoin);
		free(global->tmp2);
	}
	global->count = 0;
	count_args(global, -1);
	global->buff = malloc(sizeof(char) * (global->count + 1));
	global->buff[global->count] = '\0';
	construct_args(global, -1, 0);
	global->args = ft_split(global->buff, '\v');
	global->valid = 0;
	valid_args(global, 0, -1, false);
	global->args2 = malloc(sizeof(char *) * (global->valid + 1));
	global->args2[global->valid] = NULL;
	valid_args(global, 0, -1, true);
	print_strs(global->args2, -1);
	return (multiple_free("%b%b%a%a%a", global->args2, global->args, global->buff, \
		global->line, global), 0);
}
