/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:05:42 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/31 10:08:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*specialtrim(char *str, char *ext)
{
	char	*s;
	char	*t;

	s = ft_strtrim(str, " \n\t");
	if (ft_strchr(s, ' ') || ft_strchr(s, '\n') || ft_strchr(s, '\t'))
	{
		multiple_free("%a", s);
		simperror(ARGUMENT_ERROR);
	}
	t = ft_substr(s, 0, ft_strlen(s) - ft_strlen(ext));
	if (ft_strchr(t, '.'))
	{
		multiple_free("%a%a", s, t);
		simperror(ARGUMENT_ERROR);
	}
	multiple_free("%a", t);
	return (s);
}

char	*ft_jointfree2(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	multiple_free("%a%a", s1, s2);
	return (tmp);
}
