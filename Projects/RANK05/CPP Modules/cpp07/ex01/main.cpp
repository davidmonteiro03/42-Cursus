/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:44:42 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/28 12:09:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void print(T& elem)
{
	std::cout << elem << std::endl;
}

int main(void)
{
	std::string names[] = {"David", "Paul", "John", "Tom"};
	int grades[] = {20, 16, 15, 19, 20, 14};

	std::cout << "Array of strings:" << std::endl;
	::iter(names, 4, &print);
	std::cout << std::endl;
	std::cout << "Array of ints:" << std::endl;
	::iter(grades, 6, &print);
	return (0);
}
