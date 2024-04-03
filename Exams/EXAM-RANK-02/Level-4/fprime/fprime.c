/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:43:31 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/03 12:55:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_isprime(int nbr)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (i++ < nbr)
		if (nbr % i == 0)
			t++;
	return (t == 2);
}

void	fprime(int nbr)
{
	int	i;
	int	count;

	if (ft_isprime(nbr) || nbr == 1)
	{
		printf("%d", nbr);
		return ;
	}
	i = 0;
	count = 0;
	while (i++ < nbr)
	{
		if (ft_isprime(i) == 0)
			continue ;
		if (nbr % i != 0)
			continue ;
		nbr /= i;
		if (count > 0)
			printf("*");
		printf("%d", i);
		i = 0;
		count++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
