/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscallerror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:06:09 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/23 09:16:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	utils_syscallerror(char *const func)
{
	char	*output;

	if (func == NULL)
		return (EXIT_FAILURE);
	output = ft_strjoin(func, ": ");
	output = utils_joinfree(output, ft_strdup(strerror(errno)));
	output = utils_joinfree(output, ft_strdup("\n"));
	if (output != NULL)
	{
		write(STDERR_FILENO, output, ft_strlen(output));
		free(output);
	}
	return (EXIT_FAILURE);
}
