/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:03:39 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 14:35:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*getkey(char *const str)
{
	char	*key;
	size_t	len;

	if (str == NULL || *str == '\0')
		return (NULL);
	len = 0;
	while (str[len] != '\0' && str[len] != '=')
		len++;
	if (len == 0)
		return (NULL);
	key = (char *)ft_calloc(len + 1, sizeof(char));
	if (key == NULL)
		return (NULL);
	ft_strlcpy(key, str, len + 1);
	return (key);
}

static char	*getvalue(char *const str)
{
	char	*value;
	char	*find;

	if (str == NULL || *str == '\0')
		return (NULL);
	find = ft_strchr(str, '=');
	if (find == NULL)
		return (NULL);
	value = ft_strdup(find + 1);
	if (value == NULL)
		return (NULL);
	return (value);
}

t_vars	*vars_new(char *const str)
{
	t_vars	*node;

	node = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (node == NULL)
		return (NULL);
	node->key = getkey(str);
	if (node->key == NULL)
		return (free(node), NULL);
	node->value = getvalue(str);
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
