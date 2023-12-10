/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 08:41:26 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 08:41:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	*cub_get_config(char *str, int i)
{
	while (str[i] && ft_strchr("\t ", str[i]))
		i++;
	if (!ft_isalpha(str[i]))
		return (NULL);
	while (str[i] && !ft_strchr("\t ", str[i]))
		i++;
	if (!str[i])
		return (NULL);
	return (ft_strdup(str));
}

char	*cub_get_map(char *str, int i)
{
	while (str[i] && ft_strchr("\t ", str[i]))
		i++;
	if (!str[i])
		return (NULL);
	while (str[i] && !ft_strchr("\t ", str[i]))
		i++;
	if (ft_isalpha(str[i - 1]) && ft_strchr("\t ", str[i]))
		return (NULL);
	return (ft_strdup(str));
}
