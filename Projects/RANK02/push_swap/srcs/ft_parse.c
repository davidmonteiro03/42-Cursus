/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:45:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/27 18:15:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	ft_atol(const char *nptr)
{
	long int	num;
	long int	sign;
	size_t		i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	if (nptr[i] == '\0')
		return (-2147483649);
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + nptr[i++] - '0';
	if (nptr[i] != '\0')
		return (-2147483649);
	return (num * sign);
}

char	*ft_joinfree(char *s1, char *s2)
{
	char	*ret;

	ret = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}

char	**ft_acumulate(char **args)
{
	char	*buffer;
	char	**ret;

	if (args == NULL || *args == NULL)
		return (NULL);
	buffer = ft_strdup("");
	while (*args != NULL)
	{
		buffer = ft_joinfree(buffer, ft_strdup(*args++));
		buffer = ft_joinfree(buffer, ft_strdup(" "));
	}
	ret = ft_split(buffer, ' ');
	free(buffer);
	if (ret == NULL)
		return (NULL);
	if (*ret == NULL)
		return (free(ret), NULL);
	return (ret);
}

void	ft_check(char *arg, bool *flag)
{
	char	*tmp;

	if (arg == NULL)
	{
		*flag = false;
		return ;
	}
	tmp = ft_strtrim(arg, "\t\n\v\f\r");
	if (ft_atol(tmp) < INT_MIN || ft_atol(tmp) > INT_MAX)
		*flag = false;
	free(tmp);
}

void	ft_parse(char **argv)
{
	char	**tmp;
	int		i;
	bool	flag;

	flag = true;
	tmp = ft_acumulate(argv);
	if (tmp == NULL)
		ft_error();
	i = 0;
	while (tmp[i])
	{
		ft_check(tmp[i], &flag);
		if (flag == false)
			break ;
		i++;
	}
	free_strs(tmp);
	if (flag == false)
		ft_error();
}
