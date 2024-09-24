/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:41:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:26:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_files	*files_first(t_files *const files)
{
	if (files == NULL)
		return (NULL);
	if (files->prev == NULL)
		return (files);
	return (files_first(files->prev));
}
