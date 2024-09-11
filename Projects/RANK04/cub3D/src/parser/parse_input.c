/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:07:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/11 13:56:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	cub_check_argv(t_cub *cub, int argc, char **argv, int count)
{
	if (argc != 2)
		return (free(cub), cub_error(ERROR_INPUT));
	while (argv[count] && argv[count][0])
		count++;
	if (count != 2)
		return (free(cub), cub_error(ERROR_INPUT));
}

char	*cub_check_extension(t_cub *cub, char *arg, char *extension)
{
	char	*input_extension;
	char	*new_arg;
	size_t	extension_len;

	extension_len = ft_strlen(extension);
	new_arg = ft_strtrim(arg, " ");
	if (ft_strlen(new_arg) < extension_len + 1)
		return (free(cub), free(new_arg), \
			cub_error(ERROR_LENGTH), NULL);
	input_extension = ft_substr(new_arg, ft_strlen(new_arg) - \
		extension_len, extension_len);
	if (cub_strcmp(input_extension, extension))
		return (free(cub), free(new_arg), free(input_extension), \
			cub_error(ERROR_EXTENSION), NULL);
	return (free(input_extension), new_arg);
}

void	cub_check_input(t_cub *cub, int argc, char **argv)
{
	cub_check_argv(cub, argc, argv, 0);
	cub->config.filename = cub_check_extension(cub, argv[1], ".cub");
}
