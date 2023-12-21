/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:39:19 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	call_error(char *str)
{
	ft_fprintf(2, "bash: export: `%s': not a valid identifier\n", str);
	get_exit_code(1, 1);
	return (1);
}

static int	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '!' || str[i] == '@' || str[i] == '#'
			|| str[i] == '$' || str[i] == '%' || str[i] == '^'
			|| str[i] == '&' || str[i] == '*' || str[i] == '('
			|| str[i] == ')' || str[i] == '-' || str[i] == '+'
			|| str[i] == '{' || str[i] == '}' || str[i] == '['
			|| str[i] == ']' || str[i] == '|' || str[i] == '\\'
			|| str[i] == ';' || str[i] == ':' || str[i] == '\''
			|| str[i] == '"' || str[i] == '<' || str[i] == '>'
			|| str[i] == ',' || str[i] == '.' || str[i] == '/'
			|| str[i] == '?' || str[i] == '=' || str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	export_parser(char *str)
{
	if (ft_isdigit(str[0]))
		return (call_error(str), free(str), 1);
	if (check_char(str))
		return (call_error(str), free(str), 1);
	return (0);
}

int	check_options(char **args, char *str)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '-')
		{
			ft_fprintf(2, "bash: %s: `%s': invalid option\n",
				str, args[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_export(t_mini *mini, t_input *input)
{
	int		i;
	char	*key;
	char	*value;

	if (!get_exit_code(0, 1) && !input->command->args)
		return (print_export(mini), 0);
	i = -1;
	if (check_options(input->command->args, "export") || mini->input->next)
		return (get_exit_code(2, 1), 1);
	while (input->command->args[++i])
	{
		if (input->command->args[i][0] == '='
			&& call_error(input->command->args[i]))
			continue ;
		key = retkey(input->command->args[i]);
		if (export_parser(key))
			continue ;
		value = retval(input->command->args[i]);
		if (!value)
			add_exp(mini, key);
		else
			add_env(mini, key, value);
	}
	return (0);
}
