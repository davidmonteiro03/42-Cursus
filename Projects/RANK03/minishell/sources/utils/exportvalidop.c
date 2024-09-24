/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportvalidop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:31:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/20 14:31:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	utils_exportvalidop(char const curr, char const next)
{
	return ((curr == '+' && next == '=') || curr == '=');
}
