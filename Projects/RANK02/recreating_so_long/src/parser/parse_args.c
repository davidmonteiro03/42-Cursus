/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:19:13 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 20:12:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	so_long_valid_name(char *name)
{
	char	**tmp;
	char	*argument;
	bool	status;

	tmp = ft_split(name, '/');
	if (!tmp)
		return (false);
	if (!*tmp)
		return (free_strs(tmp, -1), false);
	argument = ft_strdup(so_long_last_str(tmp));
	status = so_long_check_extension(argument, ".ber");
	return (free(argument), free_strs(tmp, -1), status);
}

void	so_long_check_args(int argc, char **argv)
{
	if (argc != 2)
		return (so_long_usage(), exit(1));
	if (ft_strlen(argv[1]) < 1)
		return (so_long_error(ERROR_ARG), exit(1));
	if (!so_long_open_file(argv[1]))
		return (so_long_error_file(argv[1]), exit(1));
	if (!so_long_valid_name(argv[1]))
		return (so_long_error(ERROR_ARG), exit(1));
}
