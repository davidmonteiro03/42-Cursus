/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:59:45 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 20:03:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	so_long_check_extension(char *filename, char *extension)
{
	char	*extension_in;

	if (ft_strlen(filename) <= ft_strlen(extension))
		return (false);
	extension_in = ft_substr(filename, ft_strlen(filename) - ft_strlen(extension),
			ft_strlen(extension));
	if (!extension_in)
		return (false);
	if (ft_strncmp(extension_in, extension, ft_strlen(extension)))
		return (free(extension_in), false);
	return (free(extension_in), true);
}
