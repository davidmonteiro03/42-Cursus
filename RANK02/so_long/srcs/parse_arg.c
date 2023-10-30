/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:31:47 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 19:38:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*parse_extension(char *arg, char *ext)
{
	char	*tmp;
	char	*tmp_ext;
	size_t	len_ext;

	if (!arg)
		simperror(NULL);
	len_ext = ft_strlen(ext);
	tmp = ft_strtrim(arg, " \n\t");
	tmp_ext = ft_substr(tmp, ft_strlen(tmp) - len_ext, len_ext);
	if (ft_strncmp(tmp_ext, ext, 4) != 0)
	{
		multiple_free("%p%p", tmp_ext, tmp);
		return (NULL);
	}
	multiple_free("%p", tmp_ext);
	return (tmp);
}

void	parse_arg(char *arg)
{
	char	*tmp;

	tmp = parse_extension(arg, ".ber");
	multiple_free("%p", tmp);
}
