/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:12:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_joint_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s2);
	free(s1);
	return (tmp);
}

char	*struct_to_str(char *key, char *value)
{
	char	*str;

	if (!value && key)
		return (ft_strdup(key));
	if (key)
		str = ft_joint_free(ft_strdup(key), ft_strdup("=\""));
	if (value)
		str = ft_joint_free(str, ft_strdup(value));
	str = ft_joint_free(str, ft_strdup("\""));
	return (str);
}

char	*struct_to_str_env(char *key, char *value)
{
	char	*str;

	if (!value && key)
		return (ft_strdup(key));
	if (key)
		str = ft_joint_free(ft_strdup(key), ft_strdup("="));
	if (value)
		str = ft_joint_free(str, ft_strdup(value));
	return (str);
}

int	list_len_input(t_input *list)
{
	int	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
