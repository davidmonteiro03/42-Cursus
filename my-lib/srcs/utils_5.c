/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:00:02 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 17:03:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_5.h"

int	skip(char *str, char c, int i)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	skip_pro(char *str, char *charset, int i)
{
	while (str[i] && !ft_strchr(charset, str[i]))
		i++;
	return (i);
}

char	*expand(char *str, int i, int j)
{
	char	*tmp;
	char	*buff;

	buff = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) || str[i + 1] == '?'))
		{
			j = ++i;
			if (str[i] == '?')
			{
				buff = buildfree(buff, ft_itoa(100), &ft_strjoin);
				i++;
				continue ;
			}
			while (str[i] && ft_isalnum(str[i]))
				i++;
			tmp = ft_substr(str, j, i - j);
			if (getenv(tmp))
				buff = buildfree(buff, ft_strdup(getenv(tmp)), &ft_strjoin);
			free(tmp);
			continue ;
		}
		buff = buildfree(buff, ft_substr(str, i++, 1), &ft_strjoin);
	}
	return (free(str), buff);
}

char	*special_print(char *str, int i, int j)
{
	char	*buff;

	buff = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '\"')
		{
			j = ++i;
			i = skip(str, '\"', i);
			buff = buildfree(buff, expand(ft_substr(str, j, i++ - j), 0, 0), \
				&ft_strjoin);
			continue ;
		}
		if (str[i] == '\'')
		{
			j = ++i;
			i = skip(str, '\'', i);
			buff = buildfree(buff, ft_substr(str, j, i++ - j), &ft_strjoin);
			continue ;
		}
		j = i;
		i = skip_pro(str, "\'\"", i);
		buff = buildfree(buff, expand(ft_substr(str, j, i - j), 0, 0), \
			&ft_strjoin);
	}
	return (buff);
}

void	valid_args(t_global *global, int k, int i, bool init)
{
	char	*tmp;

	while (global->args[++i])
	{
		if (!init)
		{
			tmp = special_print(global->args[i], 0, 0);
			if (tmp && *tmp)
				global->valid++;
			free(tmp);
		}
		else
		{
			tmp = special_print(global->args[i], 0, 0);
			if (tmp && *tmp)
				global->args2[k++] = tmp;
			else
				free(tmp);
		}
	}
}

void	print_strs(char **strs, int i)
{
	while (strs[++i])
	{
		ft_putstr(strs[i]);
		ft_putstr("\n");
	}
}
