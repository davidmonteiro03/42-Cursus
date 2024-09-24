/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:58:41 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 15:18:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*extractkey(char *const str, size_t *i)
{
	size_t	len;
	char	*key;

	if (str == NULL || i == NULL || *str == '\0' || str[*i] == '\0'
		|| ft_isdigit(str[*i]) != 0)
		return (NULL);
	len = 0;
	while (str[*i] != '\0' && utils_exportvalidop(str[*i], str[*i
				+ 1]) == false)
	{
		if (ft_isalnum(str[*i]) == false && str[*i] != '_')
			return (NULL);
		(*i)++;
		len++;
	}
	if (len == 0)
		return (NULL);
	key = (char *)ft_calloc(len + 1, sizeof(char));
	if (key == NULL)
		return (NULL);
	ft_strlcpy(key, str, len + 1);
	return (key);
}

static char	*extractop(char *const str, size_t *i)
{
	if (str == NULL || i == NULL || *str == '\0' || str[*i] == '\0')
		return (NULL);
	if (str[*i] == '+' && str[*i + 1] == '=')
		return (*i += 2, ft_strdup("+="));
	if (str[*i] == '=')
		return ((*i)++, ft_strdup("="));
	return (NULL);
}

void	exp_init(t_exp *exp, char *const str)
{
	size_t	i;

	if (exp == NULL)
		return ;
	exp->key = NULL;
	exp->op = NULL;
	exp->value = NULL;
	if (str == NULL)
		return ;
	i = 0;
	exp->key = extractkey(str, &i);
	exp->op = extractop(str, &i);
	if (exp->op != NULL)
		exp->value = ft_strdup(&str[i]);
	else
		exp->value = NULL;
}
