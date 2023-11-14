/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:04:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/14 07:30:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_jointfree_1(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

char	*ft_jointfree_2(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s2);
	return (tmp);
}

char	*ft_jointfree_all(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	multiple_free("%a%a", s1, s2);
	return (tmp);
}
