/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:56:08 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/12 19:57:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*so_long_last_str(char **strs)
{
	char	*ret;

	ret = NULL;
	while (*strs)
		ret = *strs++;
	return (ret);
}
