/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:00:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:28:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	tokens_isoper(char const c)
{
	if (c == '\0')
		return (false);
	return (ft_strchr("<>|", c) != NULL);
}
