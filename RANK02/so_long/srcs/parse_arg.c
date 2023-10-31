/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:31:47 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 11:00:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_arg(char *arg)
{
	char	*file;
	char	**lines;

	if (!arg)
		simperror(ARGUMENT_ERROR);
	file = parse_extension(arg, ".ber");
	lines = read_file(file);
	multiple_free("%a", file);
	parse_contents(lines);
	multiple_free("%b", lines);
}
