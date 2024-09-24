/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unexpected_eof_match.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:25:18 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/06 09:27:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	syntax_unexpected_eof_match(char const c)
{
	display_fprintf(STDERR_FILENO,
		NAME ": unexpected EOF while looking for matching `%c'\n", c);
	return (syntax_error(EOF_ERROR, NULL));
}
