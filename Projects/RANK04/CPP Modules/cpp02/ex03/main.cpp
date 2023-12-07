/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:31:19 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 13:55:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

# define BGRN "\033[1;32m"
# define BRED "\033[1;31m"
# define BCYN "\033[1;36m"
# define RESET "\033[0m"

void	test(Point a, Point b, Point c, Point point, \
			int const num, bool result)
{
	std::cout << BCYN "Test " << num << RESET ": ";
	if (bsp(a, b, c, point) == result)
		std::cout << BGRN "OK" RESET << std::endl;
	else
		std::cout << BRED "KO" RESET << std::endl;
}

int	main(void)
{
	test(Point(1, 3), Point(5, 2), Point(3, 6), Point(4, 4), 1, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(3, 2), 2, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(5, 3), 3, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(4, 4), 4, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(2, 5), 5, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(6, 1), 6, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(4, 2), 7, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(3, 3), 8, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(5, 4), 9, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(4, 3), 10, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(4, 5), 11, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(3, 4), 12, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(5, 2), 13, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(5, 5), 14, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(3, 5), 15, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(3, 1), 16, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(5, 1), 17, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(2, 4), 18, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(4, 3.5f), 19, true);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(4, 4.5f), 20, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(4, 2.5f), 21, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(3.5f, 4), 22, true);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(4.5f, 4), 23, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(3.5f, 3.5f), 24, false);
	test(Point(2, 5), Point(6, 1), Point(4, 4), Point(3.5f, 4.5f), 25, false);
	return (0);
}
