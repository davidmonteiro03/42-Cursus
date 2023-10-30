/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:31:47 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 18:26:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_extension(char *arg, char *extension)
{
	char	*tmp;

	if (!arg)
		simperror(NULL);
	tmp = ft_strtrim(arg, " \n\t");
	ft_printf("%s => %s\n", tmp, extension);
	free(tmp);
}

void	parse_arg(char *arg)
{
	parse_extension(arg, ".ber");
}
