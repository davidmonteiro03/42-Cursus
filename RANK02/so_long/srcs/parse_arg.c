/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:31:47 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 19:29:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_extension(char *arg, char *extension)
{
	char	*tmp;
	char	*tmp_extension;
	size_t	len_extension;

	if (!arg)
		simperror(NULL);
	len_extension = ft_strlen(extension);
	tmp = ft_strtrim(arg, " \n\t");
	tmp_extension = ft_substr(tmp, ft_strlen(tmp) - len_extension, len_extension);
	if (ft_strncmp(tmp_extension, extension, 4) != 0)
	{
		multiple_free("%p%p", tmp_extension, tmp);
		simperror(NULL);
	}
	multiple_free("%p%p", tmp_extension, tmp);
}

void	parse_arg(char *arg)
{
	parse_extension(arg, ".ber");
}
