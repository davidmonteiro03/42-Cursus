/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:51:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:27:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	syntax_error(t_error error_code, char *const token)
{
	g_exit_status = 2;
	if (error_code == EOF_ERROR)
		display_fprintf(STDERR_FILENO,
			NAME ": syntax error: unexpected end of file\n");
	else
		display_fprintf(STDERR_FILENO,
			NAME ": syntax error near unexpected token `%s'\n", token);
	return (EXIT_FAILURE);
}
