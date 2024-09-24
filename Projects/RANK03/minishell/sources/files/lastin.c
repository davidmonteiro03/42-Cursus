/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:35:29 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 14:38:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_files	*files_lastin(t_files *const files)
{
	t_files	*iter;
	t_files	*ret;

	if (files == NULL)
		return (NULL);
	ret = NULL;
	iter = files_first(files);
	while (iter != NULL)
	{
		if (iter->type == REDIN_TYPE || iter->type == HEREDOC_TYPE)
			ret = iter;
		iter = iter->next;
	}
	return (ret);
}
