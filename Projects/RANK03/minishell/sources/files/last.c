/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:43:07 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_files	*files_last(t_files *const files)
{
	if (files == NULL)
		return (NULL);
	if (files->next == NULL)
		return (files);
	return (files_last(files->next));
}
