/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocexpand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:37:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	expandvar(int fd, t_env *env, char *const str, size_t *i)
{
	size_t	k;
	char	*key;
	char	*value;

	if (fd == -1 || env == NULL || str == NULL || i == NULL || str[*i] == '\0'
		|| str[*i] != '$')
		return ;
	k = ++(*i);
	if (str[*i] == '?')
		return ((*i)++, ft_putnbr_fd(g_exit_status, fd));
	while (str[*i] != '\0' && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	if (*i <= k)
		return (ft_putchar_fd('$', fd));
	key = ft_substr(str, k, *i - k);
	if (key == NULL)
		return ;
	value = vars_getvalue(env, key);
	free(key);
	if (value == NULL)
		return ;
	ft_putstr_fd(value, fd);
}

void	parse_heredocexpand(int fd, t_env *env, char *const str)
{
	size_t	i;

	if (fd == -1 || env == NULL || str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			expandvar(fd, env, str, &i);
			continue ;
		}
		while (str[i] != '\0' && str[i] != '$')
			ft_putchar_fd(str[i++], fd);
	}
	ft_putchar_fd('\n', fd);
}
