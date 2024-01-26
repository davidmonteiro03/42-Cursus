/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:07:25 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/26 22:25:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int i = std::rand() % 3;
	if (i == 0)
		return (new A());
	if (i == 1)
		return (new B());
	return (new C());
}

void identify(Base* p)
{
	if (!p)
	{
		std::cout << "NULL" << std::endl;
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unkown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		if (dynamic_cast<A*>(&p))
		{
			std::cout << "A" << std::endl;
			return ;
		}
	}
	catch(std::exception& e) {}
	try
	{
		if (dynamic_cast<B*>(&p))
		{
			std::cout << "B" << std::endl;
			return ;
		}
	}
	catch(std::exception& e) {}
	try
	{
		if (dynamic_cast<C*>(&p))
		{
			std::cout << "C" << std::endl;
			return ;
		}
	}
	catch(std::exception& e) {}
}

int	main(void)
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 10; i++)
	{
		if (i > 0)
			std::cout << std::endl;
		Base* base = generate();
		std::cout << "Identify by pointer  : ";
		identify(base);
		std::cout << "Identify by reference: ";
		identify(*base);
		delete base;
	}
	return (0);
}
