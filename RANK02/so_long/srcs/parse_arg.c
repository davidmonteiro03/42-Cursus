/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:31:47 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 12:26:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*parse_extension(char *arg, char *ext)
{
	char	*tmp;
	char	*tmp_ext;
	size_t	len_ext;

	tmp = specialtrim(arg, ext);
	len_ext = ft_strlen(ext);
	tmp_ext = ft_substr(tmp, ft_strlen(tmp) - len_ext, len_ext);
	if (ft_strncmp(tmp_ext, ext, len_ext) != 0)
	{
		multiple_free("%a%a", tmp_ext, tmp);
		simperror(EXTENSION_ERROR);
	}
	multiple_free("%a", tmp_ext);
	return (tmp);
}

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
