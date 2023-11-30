/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:23:11 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 10:08:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_lib_3.h"

char	*get_arg(t_gb *gb, char **strs, int i, char *last_file)
{
	if (access(strs[0], F_OK))
		return (strs[0]);
	if (!stat(strs[0], &gb->st) && \
		(!S_ISDIR(gb->st.st_mode) && \
		!S_ISREG(gb->st.st_mode)))
		return (strs[0]);
	while (strs[++i])
	{
		if (strs[i][0] != '.')
		{
			if (stat(strs[i], &gb->st) == 0)
			{
				if (S_ISDIR(gb->st.st_mode))
					return (strs[i]);
				else if (S_ISREG(gb->st.st_mode))
					last_file = strs[i];
			}
		}
	}
	if (last_file)
		return (last_file);
	return (strs[0]);
}
