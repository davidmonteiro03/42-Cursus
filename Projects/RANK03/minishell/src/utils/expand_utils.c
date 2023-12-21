/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:22:20 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*exp_adv(char *line)
{
	char	*value;

	if (line[0] == '$' && !line[1])
		return (free(line), ft_strdup("$"));
	if (line[0] == '$' && line[1] != '?')
	{
		value = ft_getenv(line + 1);
		if (value)
			return (free(line), ft_strdup(value));
		return (free(line), ft_strdup(""));
	}
	return (line);
}

static int	check_char(char c)
{
	if (ft_isdigit(c))
		return (1);
	if (c == '!' || c == '@' || c == '#'
		|| c == '$' || c == '%' || c == '^'
		|| c == '&' || c == '*' || c == '('
		|| c == ')' || c == '-' || c == '+'
		|| c == '{' || c == '}' || c == '['
		|| c == ']' || c == '|' || c == '\\'
		|| c == ';' || c == ':' || c == '\''
		|| c == '"' || c == '<' || c == '>'
		|| c == ',' || c == '.' || c == '/'
		|| c == '?' || c == '=' || c == ' ')
		return (1);
	return (0);
}

char	*expand_arg_adv(char *arg, int i, int j)
{
	char	*tmp;

	tmp = ft_strdup("");
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			tmp = ft_joint_free(tmp, ft_substr(arg, j, i - j));
			j = i++;
			if (arg[i] == '?')
			{
				tmp = ft_joint_free(tmp, ft_itoa(get_exit_code(0, 0)));
				j = ++i;
				continue ;
			}
			while (arg[i] && !check_char(arg[i]))
				i++;
			tmp = ft_joint_free(tmp, exp_adv(ft_substr(arg, j, i - j)));
			j = i;
			continue ;
		}
		i++;
	}
	tmp = ft_joint_free(tmp, ft_substr(arg, j, i - j));
	return (free(arg), tmp);
}
