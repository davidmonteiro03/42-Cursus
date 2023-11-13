/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:04:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 17:36:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_jointfree2(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	multiple_free("%a%a", s1, s2);
	return (tmp);
}

char	*ft_jointfree(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	multiple_free("%a", s1);
	return (tmp);
}
