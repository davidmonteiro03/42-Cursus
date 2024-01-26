/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:41:46 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/26 21:24:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (!*argv[1])
		return (1);
	std::string arg = argv[1];
	ScalarConverter::convert(arg);
	return (0);
}
