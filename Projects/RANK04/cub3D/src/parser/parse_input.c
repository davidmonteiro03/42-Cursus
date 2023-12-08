/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:07:57 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 19:35:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	cub_check_argv(int i, int argc, char **argv, int count)
{
	if (argc != 2)
		cub_error(ft_strdup(ERROR_INPUT), false);
	while (argv[++i] && argv[i][0])
		count++;
	if (count != 2)
		cub_error(ft_strdup(ERROR_INPUT), false);
}

char	*cub_check_extension(char *arg, char *extension)
{
	char	*input_extension;
	char	*new_arg;
	size_t	extension_len;

	extension_len = ft_strlen(extension);
	new_arg = ft_strtrim(arg, " ");
	if (ft_strlen(new_arg) < extension_len + 1)
		return (free(new_arg), cub_error(ft_strdup(ERROR_LENGTH), false), NULL);
	input_extension = ft_substr(new_arg, ft_strlen(new_arg) - \
		extension_len, extension_len);
	if (cub_strcmp(input_extension, extension))
		return (free(new_arg), free(input_extension), \
			cub_error(ft_strdup(ERROR_EXTENSION), false), NULL);
	return (free(input_extension), new_arg);
}

char	*cub_check_input(int argc, char **argv)
{
	cub_check_argv(-1, argc, argv, 0);
	return (cub_check_extension(argv[1], ".cub"));
}
